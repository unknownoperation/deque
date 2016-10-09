#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "common.h"

template <typename DEQUE_DATA_TYPE> 
class dsDEQUE {
public:
   dsDEQUE  (void) : head(NULL), tail(NULL) {}
   ~dsDEQUE (void)                          { Clear(); }

   void              PushBack  (const DEQUE_DATA_TYPE & newData);
   void              PushFront (const DEQUE_DATA_TYPE & newData);
   DEQUE_DATA_TYPE   PopBack   (void);
   DEQUE_DATA_TYPE   PopFront  (void);

   bool IsDataContains    (const DEQUE_DATA_TYPE & data);
   void Clear             (void);

private:
   struct DLIST {
     DEQUE_DATA_TYPE data;
     DLIST * next;
     DLIST * prev;
   };

   DLIST * head;
   DLIST * tail;
};

#include "deque.hpp"

#endif // _DEQUE_H_
