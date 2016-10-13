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
   DEQUE_DATA_TYPE & Front       (void)      const                  { return head->data; }
   DEQUE_DATA_TYPE & Back        (void)      const                  { return tail->data; }
   DEQUE_DATA_TYPE & operator[]  (int index) const;

   int  GetLength       (void) const                         { return length; }
   bool IsEmpty         (void) const;
   void Clear           (void);
   int  FindIndexByData (const DEQUE_DATA_TYPE & data) const;

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

template <typename DEST_CONTAINER_TYPE, typename SRC_CONTAINER_TYPE>
void AppendContainer (DEST_CONTAINER_TYPE & dest, const SRC_CONTAINER_TYPE & appendedDeque);

#include "deque.hpp"

#endif // _DEQUE_H_
