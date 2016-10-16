#include <gtest/gtest.h>

#include "deque.h"

TEST (changeData, pushBack)
{
   dsDEQUE<int> q;

   q.PushBack(20);
   ASSERT_EQ(q.Back(), 20);

}

TEST (changeData, pushFront)
{
   dsDEQUE<int> q;

   q.PushFront(30);
   ASSERT_EQ(q.Front(), 30);
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

   ASSERT_EQ(FindIndexByData(q, 10), 10);
   ASSERT_EQ(FindIndexByData(q, 100), -1);
}

TEST (changeData, appendDequeue)
{
   dsDEQUE<int> q1;
   dsDEQUE<int> q2;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
      q2.PushBack(30 - i);
   }

   AppendContainer(q1, q2);

   ASSERT_EQ(2 * q2.GetLength() == q1.GetLength(), true);
}

TEST (changeData, assignment)
{
   dsDEQUE<int> q1;
   dsDEQUE<int> q2;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
      q2.PushBack(30 - i);
   }

  q1 = q2;

   ASSERT_EQ(q1[5], q2[5]);

}

TEST (moveCheck, constructor)
{
  dsDEQUE<int> q1;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
   }

    dsDEQUE<int> q2(q1);

    dsDEQUE<int> q3(std::move(q1));

    ASSERT_EQ(q3[5], q2[5]);
}

TEST (moveCheck, assignment)
{
  dsDEQUE<int> q1;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
   }

    dsDEQUE<int> q2 = std::move(q1);

    ASSERT_EQ(q2[5], 5);
}
