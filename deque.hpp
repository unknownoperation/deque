#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

template <typename DEQUE_DATA_TYPE> 
void dsDEQUE<DEQUE_DATA_TYPE>::PushBack (const DEQUE_DATA_TYPE & newData)
{
  if (Tail == NULL) {
     Tail = static_cast<DLIST *>(malloc(sizeof(DLIST)));
     Head = Tail;
     Tail->Prev = NULL;
  } else {
     Tail->Next = static_cast<DLIST *>(malloc(sizeof(DLIST)));
     DLIST *tempPointer = Tail;
     Tail = Tail->Next;
     Tail->Prev = tempPointer;
  }

  Tail->Data = newData;
  Tail->Next = NULL;
}

template <typename DEQUE_DATA_TYPE> 
void dsDEQUE<DEQUE_DATA_TYPE>::PushFront (const DEQUE_DATA_TYPE & newData)
{
  if (Head == NULL) {
    Head = static_cast<DLIST *>(malloc(sizeof(DLIST)));
    Tail = Head;
  } else {
    DLIST *newNode = static_cast<DLIST *>(malloc(sizeof(DLIST)));
    newNode->Next = Head;
    Head->Prev = newNode;
    Head = newNode;
  }

  Head->Data = newData;
  Head->Prev = NULL;
}

template <typename DEQUE_DATA_TYPE> 
DEQUE_DATA_TYPE dsDEQUE<DEQUE_DATA_TYPE>::PopBack (void)
{
  assert(Tail != NULL);

  DEQUE_DATA_TYPE returnData = Tail->Data;  DLIST *p = Tail;  Tail = Tail->Prev;  free(p);

  if (Tail == NULL)
    Head = NULL;

  return returnData;
}

template <typename DEQUE_DATA_TYPE> 
DEQUE_DATA_TYPE dsDEQUE<DEQUE_DATA_TYPE>::PopFront (void)
{
  assert(Head != NULL);

  DEQUE_DATA_TYPE returnData = Head->Data;  DLIST *p = Head;  Head = Head->Next;  free(p);
  Head->Prev = NULL;

  if (Head == NULL)
    Tail = NULL;

  return returnData;
}

template <typename DEQUE_DATA_TYPE> 
bool dsDEQUE<DEQUE_DATA_TYPE>::IsDataContains (const DEQUE_DATA_TYPE & newData)
{
  //TODO: finish IsDataContains
}

template <typename DEQUE_DATA_TYPE>
void dsDEQUE<DEQUE_DATA_TYPE>::Clear (void)
{
  while (Head != NULL)
     PopFront();
}

#endif // _DEQUE_HPP_
