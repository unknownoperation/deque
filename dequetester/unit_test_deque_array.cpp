#include <gtest/gtest.h>

#include "deque_array.h"

TEST (dequeArray, pushBack)
{
   dsDEQUEARRAY<int> q;

   q.PushBack(20);
   ASSERT_EQ(q.Back(), 20);
}

TEST (dequeArray, pushFront)
{
   dsDEQUEARRAY<int> q;

   q.PushFront(30);
   ASSERT_EQ(q.Front(), 30);
}

TEST (dequeArray, popBack)
{
   dsDEQUEARRAY<int> q;

   q.PushBack(20);

   ASSERT_EQ(q.PopBack(), 20); 
   ASSERT_EQ(q.IsEmpty(), true);
}

TEST (dequeArray, popFront)
{
   dsDEQUEARRAY<int> q;

   q.PushFront(30);

   ASSERT_EQ(q.PopFront(), 30);

   ASSERT_EQ(q.IsEmpty(), true);
}

TEST (dequeArray, length)
{
   dsDEQUEARRAY<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushFront(30);
   }

   ASSERT_EQ(q.GetLength(), 30);
}

TEST (dequeArray, getDataByIndex)
{
   dsDEQUEARRAY<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushBack(i);
   }

   ASSERT_EQ(q[4], 4);
}

TEST (dequeArray, findData)
{
   dsDEQUEARRAY<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushBack(i);
   }

   ASSERT_EQ(FindIndexByData(q, 10), 10);
   ASSERT_EQ(FindIndexByData(q, 100), -1);
}

TEST (dequeArray, appendDequeue)
{
   dsDEQUEARRAY<int> q1;
   dsDEQUEARRAY<int> q2;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
      q2.PushBack(30 - i);
   }

   AppendContainer(q1, q2);

   ASSERT_EQ(2 * q2.GetLength() == q1.GetLength(), true);
}

TEST (dequeArray, assignment)
{
   dsDEQUEARRAY<int> q1;
   dsDEQUEARRAY<int> q2;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
      q2.PushBack(30 - i);
   }

  q1 = q2;

   ASSERT_EQ(q1[5], q2[5]);

}

TEST (dequeArray, moveConstructor)
{
   dsDEQUEARRAY<int> q1;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
   }

   dsDEQUEARRAY<int> q2(q1);

   dsDEQUEARRAY<int> q3(std::move(q1));

   ASSERT_EQ(q3[5], q2[5]);
}

TEST (dequeArray, moveAssignment)
{
  dsDEQUEARRAY<int> q1;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
   }

    dsDEQUEARRAY<int> q2 = std::move(q1);

    ASSERT_EQ(q2[5], 5);
}
