#ifndef ALLOCATOR_H
#define ALLOCATOR_H

template <typename T>
class Allocator
{
public:
   Allocator() = default;
   virtual ~Allocator() = default;
   T* allocate( size_t size );
   void deallocate( T* ptr, size_t size );
};

template <typename T>
T* Allocator<T>::allocate( size_t size )
{
   return reinterpret_cast< T* >( new char[size * sizeof( T )] );
}

template <typename T>
void Allocator<T>::deallocate( T* ptr, size_t size )
{
   delete[] ptr;
}
#endif // ALLOCATOR_H