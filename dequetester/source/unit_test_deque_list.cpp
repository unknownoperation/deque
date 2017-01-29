#include <gtest/gtest.h>

#include "deque_list.h"

TEST (dequeList, pushBack)
{
   dsDEQUELIST<int> q;

   q.PushBack(20);
   ASSERT_EQ(q.Back(), 20);

}

TEST (dequeList, pushFront)
{
   dsDEQUELIST<int> q;

   q.PushFront(30);
   ASSERT_EQ(q.Front(), 30);
}

TEST (dequeList, popBack)
{
   dsDEQUELIST<int> q;

   q.PushBack(20);

   ASSERT_EQ(q.PopBack(), 20); 
   ASSERT_EQ(q.IsEmpty(), true);
}

TEST (dequeList, popFront)
{
   dsDEQUELIST<int> q;

   q.PushFront(30);

   ASSERT_EQ(q.PopFront(), 30);

   ASSERT_EQ(q.IsEmpty(), true);
}

TEST (dequeList, length)
{
   dsDEQUELIST<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushFront(30);
   }

   ASSERT_EQ(q.GetLength(), 30);
}

TEST (dequeList, getDataByIndex)
{
   dsDEQUELIST<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushBack(i);
   }

   ASSERT_EQ(q[4], 4);
}

TEST (dequeList, findData)
{
   dsDEQUELIST<int> q;

   for (int i = 0; i < 30; i++) {
      q.PushBack(i);
   }

   ASSERT_EQ(FindIndexByData(q, 10), 10);
   ASSERT_EQ(FindIndexByData(q, 100), -1);
}

TEST (dequeList, appendDequeue)
{
   dsDEQUELIST<int> q1;
   dsDEQUELIST<int> q2;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
      q2.PushBack(30 - i);
   }

   AppendContainer(q1, q2);

   ASSERT_EQ(2 * q2.GetLength() == q1.GetLength(), true);
}

TEST (dequeList, assignment)
{
   dsDEQUELIST<int> q1;
   dsDEQUELIST<int> q2;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
      q2.PushBack(30 - i);
   }

  q1 = q2;

   ASSERT_EQ(q1[5], q2[5]);

}

TEST (dequeList, moveConstructor)
{
   dsDEQUELIST<int> q1;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
   }

   dsDEQUELIST<int> q2(q1);

   dsDEQUELIST<int> q3(std::move(q1));

   ASSERT_EQ(q3[5], q2[5]);
}

TEST (dequeList, moveAssignment)
{
  dsDEQUELIST<int> q1;

   for (int i = 0; i < 30; i++) {
      q1.PushBack(i);
   }

    dsDEQUELIST<int> q2 = std::move(q1);

    ASSERT_EQ(q2[5], 5);
}
