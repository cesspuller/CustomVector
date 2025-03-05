#ifndef VECTOR_H
#define VECTOR_H

#include "Allocator.h"

template<typename T, class AllocatorT = Allocator<T>>
class Vector
{
   T* data_;
   size_t size_;
   size_t capacity_;

public:
   Vector();
   Vector(size_t size);
};

template<typename T, class AllocatorT>
Vector<T, AllocatorT>::Vector() : data_(nullptr), size_(0), capacity_(0)
{ 

}

template<typename T, class AllocatorT>
Vector<T, AllocatorT>::Vector( size_t size ) : data_( nullptr ), size_( size ), capacity_( static_cast<size_t>( std::pow(2, std::ceil( std::log2(size) ) ) ) )
{
   AllocatorT allocator;
   data_ = allocator.allocate( size );
   
   for ( size_t constructed = 0; constructed < size_; ++constructed)
      allocator.construct(); // TODO: construct() & destroy() for Allocator
}

#endif