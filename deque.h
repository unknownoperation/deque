#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <stdlib.h>
#include <assert.h>

#define NULL nullptr

template <typename DEQUE_DATA_TYPE> 
class dsDEQUE {
public:
   dsDEQUE  (void) : Head(NULL), Tail(NULL) {}
   ~dsDEQUE (void)                          { Clear(); }

   void              PushBack  (const DEQUE_DATA_TYPE & newData);
   void              PushFront (const DEQUE_DATA_TYPE & newData);
   DEQUE_DATA_TYPE PopBack     (void);
   DEQUE_DATA_TYPE PopFront    (void);

   bool IsDataContains    (const DEQUE_DATA_TYPE & Data);
   void Clear             (void);

private:
   struct DLIST {
     DEQUE_DATA_TYPE Data;
     DLIST *Next;
     DLIST *Prev;
   };

   DLIST *Head;
   DLIST *Tail;
};

#include "deque.hpp"

#endif // _DEQUE_H_
