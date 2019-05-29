//
//  linear allocator
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
#include <stdexcept>

class linear_allocator
{
public:
    explicit linear_allocator(std::size_t memorySize);
    explicit linear_allocator(linear_allocator&& another) noexcept;
    linear_allocator& operator = (linear_allocator&& another) noexcept;
    explicit linear_allocator(const linear_allocator& another) = delete;
    linear_allocator& operator = (const linear_allocator& another) = delete;
    void* allocate(std::size_t allocatedSize) noexcept;
    void deallocate() noexcept;
    ~linear_allocator();
private:
    std::size_t mMemorySize = 0;
    std::size_t mMemoryOffset = 0;
    void* mBasePointer = nullptr;
};

linear_allocator::linear_allocator(std::size_t memorySize) : mMemorySize(memorySize)
{
    if (mMemorySize == 0)
        throw std::runtime_error("Could not allocate 0 byte of the memory.");

    mBasePointer = malloc(mMemorySize);
    if (!mBasePointer)
        throw std::runtime_error("Memory was not allocated for allocator.");
}

linear_allocator::linear_allocator(linear_allocator&& another) noexcept
{
    mMemorySize = another.mMemorySize;
    mMemoryOffset = another.mMemoryOffset;
    mBasePointer = another.mBasePointer;
    another.mBasePointer = nullptr;
    another.deallocate();
}

linear_allocator& linear_allocator::operator = (linear_allocator&& another) noexcept
{
    if (this != &another)
    {
        mMemorySize = another.mMemorySize;
        mMemoryOffset = another.mMemoryOffset;
        mBasePointer = another.mBasePointer;
        another.mBasePointer = nullptr;
        another.deallocate();
    }
    return *this;
}

void* linear_allocator::allocate(std::size_t allocatedSize) noexcept
{
    if (mMemoryOffset + allocatedSize > mMemorySize)
        return nullptr; // Allocator is full

    const std::size_t allocatedAddress = reinterpret_cast<std::size_t>(mBasePointer) + mMemoryOffset;
    mMemoryOffset += allocatedSize;
    return reinterpret_cast<void*>(allocatedAddress);
}

void linear_allocator::deallocate() noexcept
{
    mMemorySize = mMemoryOffset = 0;
}

linear_allocator::~linear_allocator()
{
    free(mBasePointer);
}

int main()
{
    // Test structure for checking allocator
    struct Vector4d
    {
        double x, y, z, w;
    };

    try
    {
        linear_allocator allocator(sizeof(Vector4d) * 3);
        Vector4d* vector1 = static_cast<Vector4d*>(allocator.allocate(sizeof(Vector4d)));
        Vector4d* vector2 = static_cast<Vector4d*>(allocator.allocate(sizeof(Vector4d)));
        Vector4d* vector3 = static_cast<Vector4d*>(allocator.allocate(sizeof(Vector4d)));
        allocator.deallocate();
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error! Cause: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
