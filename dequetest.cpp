#include <cstdio>

#include "deque.h"
#include "dequetest.h"

void DequeTest (void)
{
   dsDEQUE<int> q;

   q.PushBack(1);
   q.PushBack(2);
   q.PushFront(10);
   q.PushBack(3);

   return;
}
