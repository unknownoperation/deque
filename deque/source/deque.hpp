#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

template <typename DEQUE_DATA_TYPE> 
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

template <typename DEQUE_DATA_TYPE> 
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

template <typename DEQUE_DATA_TYPE> 
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

template <typename DEQUE_DATA_TYPE>
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

template <typename DEQUE_DATA_TYPE> 
int dsDEQUE<DEQUE_DATA_TYPE>::FindIndexByData (const DEQUE_DATA_TYPE & data) const
{
  DLIST * p = head;

  if (head == NULL) {
     return -1;
  }

  int i = 0;
  while (p != tail) {
     if (p->data == data) {
        return i;
     }
     p = p->next;
     i++;
  }

  return -1;
}

template <typename DEQUE_DATA_TYPE>
void dsDEQUE<DEQUE_DATA_TYPE>::Clear (void)
{
  while (head != NULL) {
     PopFront();
  }
}

template <typename DEQUE_DATA_TYPE>
bool dsDEQUE<DEQUE_DATA_TYPE>::IsEmpty (void) const
{
  if (head == NULL) {
     assert(tail == NULL);
     return true;
  }
  return false;
}

template <typename DEQUE_DATA_TYPE>
DEQUE_DATA_TYPE & dsDEQUE<DEQUE_DATA_TYPE>::operator[] (int index) const
{
   assert(length > index);
   
   int     i    = 0;
   DLIST * temp = head;

   while (i++ < index) {
      temp = temp->next;
   }

   return temp->data;
}

template <typename DEST_CONTAINER_TYPE, typename SRC_CONTAINER_TYPE>
void AppendContainer (DEST_CONTAINER_TYPE & dest, const SRC_CONTAINER_TYPE & src)
{
   int srclenght = src.GetLength();

   for (int i = 0; i < srclenght; i++) {
      dest.PushBack(src[i]);
   }

}

#endif // _DEQUE_HPP_
