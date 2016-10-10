#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "common.h"

template <typename DEQUE_DATA_TYPE> 
class dsDEQUE {
public:
   dsDEQUE  (void) : head(NULL), tail(NULL), length(0) {}
   ~dsDEQUE (void)                                    { Clear(); }

   void              PushBack    (const DEQUE_DATA_TYPE & newData);
   void              PushFront   (const DEQUE_DATA_TYPE & newData);
   DEQUE_DATA_TYPE   PopBack     (void);
   DEQUE_DATA_TYPE   PopFront    (void);
   DEQUE_DATA_TYPE   GetHeadData (void)                             { return head->data; }
   DEQUE_DATA_TYPE   GetTailData (void)                             { return tail->data; }
   DEQUE_DATA_TYPE   operator[]  (int index);

   int  GetLength      (void)                           { return length; }
   bool IsEmpty        (void);
   void Clear          (void);
   int  GetIndexByData (const DEQUE_DATA_TYPE & data);
   void AppendDeque    (const dsDEQUE & appendedDeque);

private:
   struct DLIST {
     DEQUE_DATA_TYPE data;
     DLIST * next;
     DLIST * prev;
   };

   int length;

   DLIST * head;
   DLIST * tail;
};

#include "deque.hpp"

#endif // _DEQUE_H_
