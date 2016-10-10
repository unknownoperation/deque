#include "gtest/gtest.h"
#include "../../deque/source/deque.h"

#pragma comment (lib, "GoogleTestCompilingLibrary.lib")

TEST (changeData, pushBack)
{
   dsDEQUE<int> q;

   q.PushBack(20);
   ASSERT_EQ(q.GetTailData(), 20);

}

TEST (changeData, pushFront)
{
   dsDEQUE<int> q;

   q.PushFront(30);
   ASSERT_EQ(q.GetHeadData(), 30);
}

TEST (changeData, popBack)
{
   dsDEQUE<int> q;

   q.PushBack(20);

   ASSERT_EQ(q.PopBack(), 20); 
   ASSERT_EQ(q.IsEmpty(), true);
}

TEST (changeData, popFront)
{
   dsDEQUE<int> q;

   q.PushFront(30);

   ASSERT_EQ(q.PopFront(), 30);

   ASSERT_EQ(q.IsEmpty(), true);
}

TEST (changeData, length)
{
   dsDEQUE<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushFront(30);
   }

   ASSERT_EQ(q.GetLength(), 30);
}

TEST (changeData, getDataByIndex)
{
   dsDEQUE<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushBack(i);
   }

   ASSERT_EQ(q[4], 4);
}

TEST (changeData, findData)
{
   dsDEQUE<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushBack(i);
   }

   ASSERT_EQ(q.GetIndexByData(10), q[10]);
   ASSERT_EQ(q.GetIndexByData(100), -1);
}

/*
TEST (changeData, appendDequeue)
{
   dsDEQUE<int> q1;
   dsDEQUE<int> q2;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
      q2.PushBack(i);
   }

}
*/


