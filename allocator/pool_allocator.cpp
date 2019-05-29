//
//  pool allocator
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
#include <stdexcept>

class pool_allocator
{

public:
    explicit pool_allocator(std::size_t memory_size, std::size_t chunk_size);
    explicit pool_allocator(pool_allocator&& another) noexcept;
    pool_allocator& operator = (pool_allocator&& another) noexcept;
    explicit pool_allocator(const pool_allocator& another) = delete;
    pool_allocator& operator = (const pool_allocator& another) = delete;
    void* allocate(std::size_t chunk_size);
    void deallocate(void* pointer) noexcept;
    ~pool_allocator();
private:
    std::size_t mTotalSize = 0;
    std::size_t mchunk_size = 0;
    std::size_t mMemoryUsed = 0;
    void* mBasePointer = nullptr;
    // Stack linked list for free chunks
    struct Chunk { Chunk* next; };
    Chunk *mChunksHead = nullptr;
};

pool_allocator::pool_allocator(std::size_t memory_size, std::size_t chunk_size)
    : mTotalSize(memory_size), mchunk_size(chunk_size)
{
    if (mTotalSize == 0 || chunk_size == 0)
        throw std::runtime_error("Could not allocate 0 byte of the memory.");

    mBasePointer = malloc(mTotalSize);
    if (!mBasePointer)
        throw std::runtime_error("Memory was not allocated for allocator.");

    for (std::size_t i = 0; i < memory_size / chunk_size; i++)
    {
        const std::size_t chunkAddress = reinterpret_cast<std::size_t>(mBasePointer) + i * mchunk_size;
        Chunk* newFreeChunk = reinterpret_cast<Chunk*>(chunkAddress);
        newFreeChunk->next = mChunksHead;
        mChunksHead = newFreeChunk;
    }
}

pool_allocator::pool_allocator(pool_allocator&& another) noexcept
{
    mTotalSize = another.mTotalSize;
    mchunk_size = another.mchunk_size;
    mMemoryUsed = another.mMemoryUsed;
    mBasePointer = another.mBasePointer;
    another.mBasePointer = nullptr;
    another.mMemoryUsed = another.mchunk_size = another.mTotalSize = 0;
}

pool_allocator& pool_allocator::operator = (pool_allocator&& another) noexcept
{
    if (this != &another)
    {
        mTotalSize = another.mTotalSize;
        mchunk_size = another.mchunk_size;
        mMemoryUsed = another.mMemoryUsed;
        mBasePointer = another.mBasePointer;
        another.mBasePointer = nullptr;
        another.mMemoryUsed = another.mchunk_size = another.mTotalSize = 0;
    }
    return *this;
}

void* pool_allocator::allocate(std::size_t chunk_size)
{
    if (mchunk_size != chunk_size)
        throw std::invalid_argument("Incorrect chuck size for allocation");

    if (mMemoryUsed + mchunk_size > mTotalSize)
        return nullptr; // Allocator is full

    mMemoryUsed += mchunk_size;
    Chunk* freeChunk = mChunksHead;
    mChunksHead = mChunksHead->next;
    return reinterpret_cast<void*>(freeChunk);
}

void pool_allocator::deallocate(void* pointer) noexcept
{
    if (mMemoryUsed == 0)
        return; // Allocator is empty

    mMemoryUsed -= mchunk_size;
    Chunk* newFreeChunk = reinterpret_cast<Chunk*>(pointer);
    newFreeChunk->next = mChunksHead;
    mChunksHead = newFreeChunk;
}

pool_allocator::~pool_allocator()
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
        pool_allocator allocator(sizeof(Vector4d) * 3, sizeof(Vector4d));
        Vector4d* vector1 = static_cast<Vector4d*>(allocator.allocate(sizeof(Vector4d)));
        Vector4d* vector2 = static_cast<Vector4d*>(allocator.allocate(sizeof(Vector4d)));
        Vector4d* vector3 = static_cast<Vector4d*>(allocator.allocate(sizeof(Vector4d)));
        allocator.deallocate(vector2);
        allocator.deallocate(vector3);
        allocator.deallocate(vector1);
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error! Cause: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
