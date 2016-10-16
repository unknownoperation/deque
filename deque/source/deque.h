#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "common.h"
#include "containersFunctions.h"

template <class DEQUE_DATA_TYPE> 
class dsDEQUE {
   friend void ::AppendContainer (dsDEQUE<DEQUE_DATA_TYPE> & dest, dsDEQUE<DEQUE_DATA_TYPE> & src);
   friend int  ::FindIndexByData (const dsDEQUE<DEQUE_DATA_TYPE> & src, const DEQUE_DATA_TYPE & data);
public:
   dsDEQUE  (void) : head(NULL), tail(NULL), length(0) {}
   dsDEQUE  (const dsDEQUE & src);
   dsDEQUE  (dsDEQUE && src) : head(src.head), tail(src.tail), length(src.length) { src.head = src.tail = NULL; }
   ~dsDEQUE (void) { Clear(); }

   void              PushBack    (const DEQUE_DATA_TYPE & newData);
   void              PushFront   (const DEQUE_DATA_TYPE & newData);
   DEQUE_DATA_TYPE   PopBack     (void);
   DEQUE_DATA_TYPE   PopFront    (void);
   DEQUE_DATA_TYPE & Front       (void)                             { return head->data; }
   DEQUE_DATA_TYPE & Back        (void)                             { return tail->data; }
  
   DEQUE_DATA_TYPE       & operator[]  (int index);
   const DEQUE_DATA_TYPE & operator[]  (int index) const;

   int  GetLength       (void) const                         { return length; }
   bool IsEmpty         (void) const;
   void Clear           (void);

private:
   struct DLIST {
      DEQUE_DATA_TYPE data;
      DLIST * next;
      DLIST * prev;
   };

   DLIST * head;
   DLIST * tail;

   int length;
};

template <class DEQUE_DATA_TYPE>
void AppendContainer (dsDEQUE<DEQUE_DATA_TYPE> & dest, dsDEQUE<DEQUE_DATA_TYPE> & appendedDeque);

template <class CONTAINER_DATA_TYPE>
int FindIndexByData (const dsDEQUE<CONTAINER_DATA_TYPE> & src, const CONTAINER_DATA_TYPE & data);

#include "deque.hpp"

#endif // _DEQUE_H_
