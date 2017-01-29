#ifndef _DEQUE_ARRAY_HPP_
#define _DEQUE_ARRAY_HPP_

#include <stdlib.h>

template <class DEQUE_DATA_TYPE>
dsDEQUEARRAY<DEQUE_DATA_TYPE>::dsDEQUEARRAY (const dsDEQUEARRAY<DEQUE_DATA_TYPE> & src)
{
   head = tail = 0;
   allocatedSize = 0;
   reallocSize = src.reallocSize;

   dsDEQUEARRAY<DEQUE_DATA_TYPE>::CONST_ITERATOR it = src.Begin();

   for (; it != (src.End()); ++it) {
      PushBack(*(it));
   }
}

template <class DEQUE_DATA_TYPE>
void dsDEQUEARRAY<DEQUE_DATA_TYPE>::PushBack (const DEQUE_DATA_TYPE & newData)
{
   if (allocatedSize == 0) {
      data = new DEQUE_DATA_TYPE[reallocSize];
      assert(data != NULL);
      allocatedSize = reallocSize;
   } else if (head == (tail + 1) % allocatedSize || tail == (head + 1) % allocatedSize) {
      Linearize(reallocSize);
   }
   data[++tail] = newData;
}

template <class DEQUE_DATA_TYPE>
void dsDEQUEARRAY<DEQUE_DATA_TYPE>::PushFront (const DEQUE_DATA_TYPE & newData)
{
   if (allocatedSize == 0) {
      data = new DEQUE_DATA_TYPE[reallocSize];
      assert(data != NULL);
      allocatedSize = reallocSize;
   } else if (head == (tail + 1) % allocatedSize || tail == (head - 1 + allocatedSize) % allocatedSize) {
      Linearize(reallocSize);
   }
   data[head] = newData;
   head = (head - 1 + allocatedSize) % allocatedSize;
}

template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE dsDEQUEARRAY<DEQUE_DATA_TYPE>::PopBack (void)
{
   assert(GetLength() > 0);

   DEQUE_DATA_TYPE el = data[tail];

   tail = (tail - 1 + allocatedSize) % allocatedSize;

   return el;
}

template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE dsDEQUEARRAY<DEQUE_DATA_TYPE>::PopFront (void)
{
   assert(GetLength() > 0);

   DEQUE_DATA_TYPE el = data[(head + 1) % allocatedSize];

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
      reallocSize   = src.reallocSize;
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

   reallocSize = src.reallocSize;

   dsDEQUEARRAY<DEQUE_DATA_TYPE>::CONST_ITERATOR it = src.Begin();

   for (; it != (src.End()); ++it) {
      PushBack(*(it));
   }

   return *this;
}

template <class DEQUE_DATA_TYPE>
bool dsDEQUEARRAY<DEQUE_DATA_TYPE>::IsEmpty (void) const
{
   if (GetLength() >= 1) {
      return false;
   }
   return true;
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
   head = tail = 0;
}

template <class DEQUE_DATA_TYPE>
void dsDEQUEARRAY<DEQUE_DATA_TYPE>::Linearize (size_t additionalSize)
{
   int length = GetLength();
   DEQUE_DATA_TYPE * temp = new DEQUE_DATA_TYPE[length + 1 + additionalSize];

   assert(temp != NULL);

   int j = 0;
   for (int i = head; i != tail; i = (i + 1) % allocatedSize, j++) {
      temp[j] = data[i];
   }
   temp[j] = data[tail];

   delete(data);

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
      index++;
   }
   
   return *this;
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
      index++;
   }

   return *this;
}

#endif // _DEQUE_ARRAY_HPP_
