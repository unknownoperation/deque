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
}

template <typename DEQUE_DATA_TYPE> 
void dsDEQUE<DEQUE_DATA_TYPE>::PushFront (const DEQUE_DATA_TYPE & newData)
{
  if (head == NULL) {
    head = new DLIST;
    tail = head;
  } else {
    DLIST * newNode = new DLIST;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  head->data = newData;
  head->prev = NULL;
}

template <typename DEQUE_DATA_TYPE> 
DEQUE_DATA_TYPE dsDEQUE<DEQUE_DATA_TYPE>::PopBack (void)
{
  assert(tail != NULL);

  DEQUE_DATA_TYPE returnData = tail->data;  DLIST * p = tail;  tail = tail->prev;  delete(p);

  if (tail == NULL) {
    head = NULL;
  }

  return returnData;
}

template <typename DEQUE_DATA_TYPE> 
DEQUE_DATA_TYPE dsDEQUE<DEQUE_DATA_TYPE>::PopFront (void)
{
  assert(head != NULL);

  DEQUE_DATA_TYPE returnData = head->data;  DLIST * p = head;  head = head->next;  delete(p);
  head->prev = NULL;

  if (head == NULL) {
    tail = NULL;
  }

  return returnData;
}

template <typename DEQUE_DATA_TYPE> 
bool dsDEQUE<DEQUE_DATA_TYPE>::IsDataContains (const DEQUE_DATA_TYPE & data)
{
  DLIST * p = head;

  if (Head == NULL) {
     return false;
  }

  while (p != tail) {
     if (p->data == data) {
        return true;
     }
  }

  return false;
}

template <typename DEQUE_DATA_TYPE>
void dsDEQUE<DEQUE_DATA_TYPE>::Clear (void)
{
  while (head != NULL) {
     PopFront();
  }
}

#endif // _DEQUE_HPP_
