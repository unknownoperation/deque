#include "gtest/gtest.h"
#include "../../deque/source/deque.h"

#pragma comment (lib, "GoogleTestCompilingLibrary.lib")


TEST (push_pop, one_in_one_out)
{
   dsDEQUE<int> q;

   q.PushBack(30);
   q.PopFront();
   ASSERT_EQ(q.PopFront(), 30);
}
