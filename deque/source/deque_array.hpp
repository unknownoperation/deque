#ifndef _DEQUE_ARRAY_HPP_
#define _DEQUE_ARRAY_HPP_

#include <stdlib.h>
template <class DEQUE_DATA_TYPE>
void dsDEQUEARRAY<DEQUE_DATA_TYPE>::PushBack (const DEQUE_DATA_TYPE & newData)
{
   if (allocatedSize == 0) {
      int reallocSize = 5;
      data = static_cast<DEQUE_DATA_TYPE *>(malloc(sizeof(DEQUE_DATA_TYPE) * reallocSize));
      allocatedSize = reallocSize;
   } else if (head == (tail + 1) % allocatedSize || tail == (head + 1) % allocatedSize) {
      int reallocSize = 2 * GetLength();
      Linearize(reallocSize);
   }
   new (data + (++tail)) DEQUE_DATA_TYPE(newData);
}

template <class DEQUE_DATA_TYPE>
void dsDEQUEARRAY<DEQUE_DATA_TYPE>::PushFront (const DEQUE_DATA_TYPE & newData)
{
   if (allocatedSize == 0) {
      int reallocSize = 5;
      data = static_cast<DEQUE_DATA_TYPE *>(malloc(sizeof(DEQUE_DATA_TYPE) * reallocSize));
      allocatedSize = reallocSize;
   } else if (head == (tail + 1) % allocatedSize || tail == (head - 1 + allocatedSize) % allocatedSize) {
      int reallocSize = 2 * GetLength();
      Linearize(reallocSize);
   }
   new (data + (head)) DEQUE_DATA_TYPE(newData);
   head = (head - 1 + allocatedSize) % allocatedSize;
}

template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE dsDEQUEARRAY<DEQUE_DATA_TYPE>::PopBack (void)
{
   assert(!IsEmpty());

   DEQUE_DATA_TYPE el(std::move(data[tail]));
   data[tail].~DEQUE_DATA_TYPE();

   tail = (tail - 1 + allocatedSize) % allocatedSize;

   return el;
}

template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE dsDEQUEARRAY<DEQUE_DATA_TYPE>::PopFront (void)
{
   assert(!IsEmpty());

   DEQUE_DATA_TYPE el(std::move(data[(head + 1) % allocatedSize]));
   data[(head + 1) % allocatedSize].~DEQUE_DATA_TYPE();

   head = (head + 1) % allocatedSize;

   return el;
}

template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE & dsDEQUEARRAY<DEQUE_DATA_TYPE>::operator[] (int index)
{
   assert(index >= 0);

   int length = GetLength();
   assert(index < length);

   return data[(head + 1 + index) % allocatedSize];
}

template <class DEQUE_DATA_TYPE>
const DEQUE_DATA_TYPE & dsDEQUEARRAY<DEQUE_DATA_TYPE>::operator[] (int index) const
{
   assert(index >= 0);

   int length = GetLength();
   assert(index < length + 1);

   return data[(head + 1 + index) % allocatedSize];
}

template <class DEQUE_DATA_TYPE>
dsDEQUEARRAY<DEQUE_DATA_TYPE> & dsDEQUEARRAY<DEQUE_DATA_TYPE>::operator=  (dsDEQUEARRAY<DEQUE_DATA_TYPE> && src)
{
   if (this != &src) {
      Clear();

      length        = src.length;
      allocatedSize = src.allocatedSize;
      data          = src.data;

      src.length        = 0;
      src.allocatedSize = 0;
      src.data          = NULL;
   }
   return *this;
}

template <class DEQUE_DATA_TYPE>
dsDEQUEARRAY<DEQUE_DATA_TYPE> & dsDEQUEARRAY<DEQUE_DATA_TYPE>::operator=  (const dsDEQUEARRAY<DEQUE_DATA_TYPE> & src)
{
   Clear();

   dsDEQUEARRAY<DEQUE_DATA_TYPE>::CONST_ITERATOR it = src.Begin();

   for (; it != (src.End()); ++it) {
      PushBack(*(it));
   }

   return *this;
}

template <class DEQUE_DATA_TYPE>
bool dsDEQUEARRAY<DEQUE_DATA_TYPE>::IsEmpty (void) const
{
   return GetLength() == 0;
}

template <class DEQUE_DATA_TYPE>
int dsDEQUEARRAY<DEQUE_DATA_TYPE>::GetLength (void) const
{
   if (tail < head) {
      return allocatedSize - (head - tail);
   }
   return tail - head;
}


template <class DEQUE_DATA_TYPE>
void dsDEQUEARRAY<DEQUE_DATA_TYPE>::Clear (void)
{
   while (head != tail) {
      PopBack();
   }
}

template <class DEQUE_DATA_TYPE>
void dsDEQUEARRAY<DEQUE_DATA_TYPE>::Linearize (size_t additionalSize)
{
   int length = GetLength();
   DEQUE_DATA_TYPE * temp = static_cast<DEQUE_DATA_TYPE *>(malloc(sizeof(DEQUE_DATA_TYPE) * (length + 1 + additionalSize)));

   int j = 0;
   for (int i = head; i != tail; i = (i + 1) % allocatedSize, j++) {
      new (temp + j) DEQUE_DATA_TYPE(std::move(data[i]));
   }
   new (temp + j) DEQUE_DATA_TYPE(std::move(data[tail]));

   for (int i = head; i != tail; i = (i + 1) % allocatedSize) {
      data[i].~DEQUE_DATA_TYPE();
   }
   free(data);

   allocatedSize = length + 1 + additionalSize;
   data = temp;
   head = 0;
   tail = j;
}


template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE & dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE>::operator* (void)
{
   return deque.data[index];
}

template <class DEQUE_DATA_TYPE>
dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE> & dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE>::operator++ (void)
{
   if (index == deque->allocatedSize - 1 && index != tail) {
      index = 0;
   } else {
      ++index;
   }
   
   return *this;
}

template <class DEQUE_DATA_TYPE>
dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE> dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE>::operator++ (int)
{
   dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE> temp = *this;

   ++(*this);

   return temp;
}

template <class DEQUE_DATA_TYPE>
const DEQUE_DATA_TYPE & dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE>::operator* (void) const
{
   return deque.data[index];
}

template <class DEQUE_DATA_TYPE>
dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE> & dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE>::operator++ (void)
{
   if (index == deque.allocatedSize - 1) {
      index = 0;
   } else {
      ++index;
   }

   return *this;
}

template <class DEQUE_DATA_TYPE>
dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE> dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE>::operator++ (int)
{
   dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE> temp = *this;

   ++(*this);

   return temp;
}

#endif // _DEQUE_ARRAY_HPP_
