#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

template <class DEQUE_DATA_TYPE>
dsDEQUE<DEQUE_DATA_TYPE>::dsDEQUE (const dsDEQUE & src)
{
   head = tail = NULL;
   length = 0;

   DLIST * it = src.head;
   while (it != NULL) {
      PushBack(it->data);
      it = it->next;
   }
}

template <class DEQUE_DATA_TYPE>
dsDEQUE<DEQUE_DATA_TYPE> & dsDEQUE<DEQUE_DATA_TYPE>::operator= (dsDEQUE<DEQUE_DATA_TYPE> && src)
{
   if (this != &src) {
      Clear();

      head   = src.head;
      tail   = src.tail;
      length = src.length;

      src.head   = NULL;
      src.tail   = NULL;
      src.length = 0;
   }
   return *this;
}

template <class DEQUE_DATA_TYPE> 
dsDEQUE<DEQUE_DATA_TYPE> & dsDEQUE<DEQUE_DATA_TYPE>::operator= (const dsDEQUE<DEQUE_DATA_TYPE> & src)
{
   if (this != &src) {
      Clear();
      DLIST * it = src.head;

      while (it != NULL) {
         PushBack(it->data);
         it = it->next;
      }
   }
   return *this;
}

template <class DEQUE_DATA_TYPE> 
void dsDEQUE<DEQUE_DATA_TYPE>::PushBack (const DEQUE_DATA_TYPE & newData)
{
   if (tail == NULL) {
      tail = new DLIST;
      head = tail;
      tail->prev = NULL;
   } else {
      tail->next = new DLIST;
      DLIST * tempPointer = tail;
      tail = tail->next;
      tail->prev = tempPointer;
   }

   tail->data = newData;
   tail->next = NULL;
   length++;
}

template <class DEQUE_DATA_TYPE> 
void dsDEQUE<DEQUE_DATA_TYPE>::PushFront (const DEQUE_DATA_TYPE & newData)
{
   if (head == NULL) {
      head = new DLIST;
      tail = head;
      head->next = NULL;
   } else {
      DLIST * newNode = new DLIST;
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
   }
  
   head->data = newData;
   head->prev = NULL;
   length++;
}

template <class DEQUE_DATA_TYPE> 
DEQUE_DATA_TYPE dsDEQUE<DEQUE_DATA_TYPE>::PopBack (void)
{
   assert(tail != NULL);

   DEQUE_DATA_TYPE returnData = tail->data;
   DLIST * p = tail;
   tail = tail->prev;
   delete(p);

   if (tail == NULL) {
      head = NULL;
   }

   length--;

   return returnData;
}

template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE dsDEQUE<DEQUE_DATA_TYPE>::PopFront (void)
{
   assert(head != NULL);
  
   DEQUE_DATA_TYPE returnData = head->data;
   DLIST * p = head;
   if (head != NULL) {
      head = head->next;
   }
   delete(p);
   
   if (head == NULL) {
      tail = NULL;
   } else {
      head->prev = NULL;
   }
  
   length--;
  
   return returnData;
}

template <class DEQUE_DATA_TYPE>
void dsDEQUE<DEQUE_DATA_TYPE>::Clear (void)
{
   while (head != NULL) {
      PopFront();
   }
}

template <class DEQUE_DATA_TYPE>
bool dsDEQUE<DEQUE_DATA_TYPE>::IsEmpty (void) const
{
   if (head == NULL) {
      assert(tail == NULL);
      return true;
   }
   return false;
}

template <class DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE & dsDEQUE<DEQUE_DATA_TYPE>::operator[] (int index)
{
   assert(length > index);

   int i = 0;
   DLIST * temp = head;

   while (i++ < index) {
      temp = temp->next;
   }

   return temp->data;
}

template <class DEQUE_DATA_TYPE>
const DEQUE_DATA_TYPE & dsDEQUE<DEQUE_DATA_TYPE>::operator[] (int index) const
{
   assert(length > index);

   int i = 0;
   DLIST * temp = head;

   while (i++ < index) {
      temp = temp->next;
   }

   return temp->data;
}

template <class DEQUE_DATA_TYPE>
void AppendContainer (dsDEQUE<DEQUE_DATA_TYPE> & dest, const dsDEQUE<DEQUE_DATA_TYPE> & src)
{
   dsDEQUE<DEQUE_DATA_TYPE>::DLIST * it = src.head;

   while (it != NULL) {
      dest.PushBack(it->data);
      it = it->next;
   }
}

template <class DEQUE_DATA_TYPE> 
int FindIndexByData (const dsDEQUE<DEQUE_DATA_TYPE> & src, const DEQUE_DATA_TYPE & data)
{
   dsDEQUE<DEQUE_DATA_TYPE>::DLIST * it = src.head;

   int i = 0;
   while (it != src.tail) {
      if (it->data == data) {
         return i;
      }
      it = it->next;
      i++;
   }
   return -1;
}

#endif // _DEQUE_HPP_
