#ifndef _DEQUE_ARRAY_H_
#define _DEQUE_ARRAY_H_

#include "common.h"
#include "containers_functions.h"

template <class DEQUE_DATA_TYPE> 
class dsDEQUE_ARRAY_ITERATOR;

template <class DEQUE_DATA_TYPE> 
class dsDEQUE_ARRAY_CONST_ITERATOR;

template <class DEQUE_DATA_TYPE> 
class dsDEQUEARRAY {
   friend void ::AppendContainer (dsDEQUEARRAY<DEQUE_DATA_TYPE> & dest, const dsDEQUEARRAY<DEQUE_DATA_TYPE> & src);
   friend int  ::FindIndexByData (const dsDEQUEARRAY<DEQUE_DATA_TYPE> & src, const DEQUE_DATA_TYPE & data);

   friend dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE>;
   friend dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE>;
public:
   using ITERATOR       = dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE>;
   using CONST_ITERATOR = dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE>;

   dsDEQUEARRAY  (void) : head(0), tail(0), allocatedSize(0), reallocSize(5), data(NULL) {}
   dsDEQUEARRAY  (const dsDEQUEARRAY<DEQUE_DATA_TYPE> &  src);
   dsDEQUEARRAY  (dsDEQUEARRAY<DEQUE_DATA_TYPE>       && src) : head(src.head), tail(src.tail), allocatedSize(src.allocatedSize), reallocSize(src.reallocSize), data(src.data) { src.head = src.tail = src.allocatedSize = 0; src.data = NULL; }
   ~dsDEQUEARRAY (void) { Clear(); }

   void            PushBack  (const DEQUE_DATA_TYPE & newData);
   void            PushFront (const DEQUE_DATA_TYPE & newData);
   DEQUE_DATA_TYPE PopBack   (void);
   DEQUE_DATA_TYPE PopFront  (void);

   DEQUE_DATA_TYPE       & Front (void)       { return data[(head + 1) % allocatedSize]; }
   DEQUE_DATA_TYPE       & Back  (void)       { return data[tail]; }
   const DEQUE_DATA_TYPE & Front (void) const { return data[(head + 1) % allocatedSize]; }
   const DEQUE_DATA_TYPE & Back  (void) const { return data[tail]; }

   DEQUE_DATA_TYPE               & operator[] (int index);
   const DEQUE_DATA_TYPE         & operator[] (int index) const;
   dsDEQUEARRAY<DEQUE_DATA_TYPE> & operator=  (dsDEQUEARRAY<DEQUE_DATA_TYPE>       && src);
   dsDEQUEARRAY<DEQUE_DATA_TYPE> & operator=  (const dsDEQUEARRAY<DEQUE_DATA_TYPE> &  src);

   int  GetLength (void) const;
   bool IsEmpty   (void) const;
   void Clear     (void);
   void Compact   (void)       { Linearize(0); }

   ITERATOR       Begin (void)       { return *(new ITERATOR(head + 1, *this)); }
   CONST_ITERATOR Begin (void) const { return *(new CONST_ITERATOR(head + 1, *this)); }

   ITERATOR       End (void)       { return *(new ITERATOR(tail + 1, *this)); }
   CONST_ITERATOR End (void) const { return *(new CONST_ITERATOR(tail + 1, *this)); }

private:
   int head;
   int tail;
   int allocatedSize;
   int reallocSize;

   DEQUE_DATA_TYPE * data;

   void Linearize (size_t additionalSize);
};

template <class DEQUE_DATA_TYPE> 
class dsDEQUE_ARRAY_ITERATOR {
public:
   dsDEQUE_ARRAY_ITERATOR () : dq(NULL) {};
   dsDEQUE_ARRAY_ITERATOR (int ind, const dsDEQUEARRAY<DEQUE_DATA_TYPE> & dq) : index(ind), deque(dq) {};

   dsDEQUE_ARRAY_ITERATOR                   (const dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE> & it) = default;
   ~dsDEQUE_ARRAY_ITERATOR                  ()                                                   = default;

   dsDEQUE_ARRAY_ITERATOR & operator=  (const dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE> & it) = default;
   DEQUE_DATA_TYPE        & operator*  (void);
   dsDEQUE_ARRAY_ITERATOR & operator++ (void);

   bool operator== (const dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (&deque == &(it.deque) && index == it.index); }
   bool operator!= (const dsDEQUE_ARRAY_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (&deque != &(it.deque) || index != it.index); }
private:
   int index;
   dsDEQUEARRAY<DEQUE_DATA_TYPE> & deque;
};

template <class DEQUE_DATA_TYPE> 
class dsDEQUE_ARRAY_CONST_ITERATOR {
public:
   dsDEQUE_ARRAY_CONST_ITERATOR () : dq(NULL) {};
   dsDEQUE_ARRAY_CONST_ITERATOR (int ind, const dsDEQUEARRAY<DEQUE_DATA_TYPE> & dq) : index(ind), deque(dq) {};

   dsDEQUE_ARRAY_CONST_ITERATOR                 (const dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) = default;
   ~dsDEQUE_ARRAY_CONST_ITERATOR                ()                                                   = default;
   dsDEQUE_ARRAY_CONST_ITERATOR   &   operator= (const dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) = default;

   const DEQUE_DATA_TYPE        & operator*  (void) const;
   dsDEQUE_ARRAY_CONST_ITERATOR & operator++ (void);

   bool operator== (const dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (&deque == &(it.deque) && index == it.index); }
   bool operator!= (const dsDEQUE_ARRAY_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (&deque != &(it.deque) || index != it.index); }
private:
   int index;
   const dsDEQUEARRAY<DEQUE_DATA_TYPE> & deque;
};


#include "deque_array.hpp"

#endif // _DEQUE_ARRAY_H_
