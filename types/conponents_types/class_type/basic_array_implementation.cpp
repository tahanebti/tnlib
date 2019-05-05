#include <iostream>
using namespace std;

class IntArray
{
public:
explicit IntArray(size_t size)
: size_(size), data_(new int[size])
{}
~IntArray() { delete [] data_; }
int & get(size_t i) { return data_[i]; }
size_t size() { return size_; }

void resize(size_t nsize)
{
int * ndata = new int[nsize];
size_t n = nsize > size_ ? size_ : nsize;
for (size_t i = 0; i != n; ++i)
ndata[i] = data_[i];
delete [] data_;
data_ = ndata;
size_ = nsize;
}

IntArray(IntArray const& a)
: size_(a.size_), data_(new int[size_])
{
for (size_t i = 0; i != size_; ++i)
data_[i] = a.data_[i];
}

IntArray & operator=(IntArray const& a) {
if (this != &a) {
delete [] data_;
size_ = a.size_;
data_ = new int[size_];
for (size_t i = 0; i != size_; ++i)
data_[i] = a.data_[i];
}
return *this;
}

void swap(IntArray & a) {
size_t const t1 = size_;
size_ = a.size_;
a.size_ = t1;
int * const t2 = data_;
data_ = a.data_;
a.data_ = t2;
}


private:
size_t size_;
int * data_;
};
int main() {
    IntArray a1(10);
IntArray a2(20);
IntArray a3 = a1; // копирование
a2 = a1; // присваивание
    return 0;
}
