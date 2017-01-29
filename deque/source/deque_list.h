#ifndef _DEQUE_LIST_H_
#define _DEQUE_LIST_H_

#include "common.h"
#include "containers_functions.h"

template <class DEQUE_DATA_TYPE> 
class dsDEQUE_LIST_ITERATOR;

template <class DEQUE_DATA_TYPE> 
class dsDEQUE_LIST_CONST_ITERATOR;

template <class DEQUE_DATA_TYPE> 
class dsDEQUELIST {
   friend void ::AppendContainer (dsDEQUELIST<DEQUE_DATA_TYPE> & dest, const dsDEQUELIST<DEQUE_DATA_TYPE> & src);
   friend int  ::FindIndexByData (const dsDEQUELIST<DEQUE_DATA_TYPE> & src, const DEQUE_DATA_TYPE & data);

   friend dsDEQUE_LIST_ITERATOR<DEQUE_DATA_TYPE>;
   friend dsDEQUE_LIST_CONST_ITERATOR<DEQUE_DATA_TYPE>;
public:
   using ITERATOR       = dsDEQUE_LIST_ITERATOR<DEQUE_DATA_TYPE>;
   using CONST_ITERATOR = dsDEQUE_LIST_CONST_ITERATOR<DEQUE_DATA_TYPE>;

   dsDEQUELIST  (void) : head(NULL), tail(NULL), length(0) {}
   dsDEQUELIST  (const dsDEQUELIST & src);
   dsDEQUELIST  (dsDEQUELIST && src) : head(src.head), tail(src.tail), length(src.length) { src.head = src.tail = NULL; }
   ~dsDEQUELIST (void) { Clear(); }

   void            PushBack  (const DEQUE_DATA_TYPE & newData);
   void            PushFront (const DEQUE_DATA_TYPE & newData);
   DEQUE_DATA_TYPE PopBack   (void);
   DEQUE_DATA_TYPE PopFront  (void);

   DEQUE_DATA_TYPE       & Front (void)       { return head->data; }
   DEQUE_DATA_TYPE       & Back  (void)       { return tail->data; }
   const DEQUE_DATA_TYPE & Front (void) const { return head->data; }
   const DEQUE_DATA_TYPE & Back  (void) const { return tail->data; }

   DEQUE_DATA_TYPE       & operator[] (int index);
   const DEQUE_DATA_TYPE & operator[] (int index) const;
   dsDEQUELIST               & operator=  (dsDEQUELIST && src);
   dsDEQUELIST               & operator=  (const dsDEQUELIST & src);

   int  GetLength (void) const  { return length; }
   bool IsEmpty   (void) const;
   void Clear     (void);

   ITERATOR       Begin (void)       { return *(new ITERATOR(head)); }
   CONST_ITERATOR Begin (void) const { return *(new CONST_ITERATOR(head)); }
   
   ITERATOR       End (void)       { return *(new ITERATOR(NULL)); }
   CONST_ITERATOR End (void) const { return *(new CONST_ITERATOR(NULL)); }

private:
   struct DLIST {
      DEQUE_DATA_TYPE data;

      DLIST * next;
      DLIST * prev;
   };

   DLIST * head;
   DLIST * tail;

   int length;
};

template <class DEQUE_DATA_TYPE> 
class dsDEQUE_LIST_ITERATOR {
public:
   dsDEQUE_LIST_ITERATOR () : curElement(NULL) {};
   dsDEQUE_LIST_ITERATOR (typename dsDEQUELIST<DEQUE_DATA_TYPE>::DLIST * el) : curElement(el) {};

   dsDEQUE_LIST_ITERATOR  (const dsDEQUE_LIST_ITERATOR<DEQUE_DATA_TYPE> & it) = default;
   ~dsDEQUE_LIST_ITERATOR ()                                                  = default;

   dsDEQUE_LIST_ITERATOR & operator=  (const dsDEQUE_LIST_ITERATOR<DEQUE_DATA_TYPE> & it) = default;
   DEQUE_DATA_TYPE       & operator*  (void);
   dsDEQUE_LIST_ITERATOR & operator++ (void);

   bool operator== (const dsDEQUE_LIST_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (curElement == it.curElement); }
   bool operator!= (const dsDEQUE_LIST_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (curElement != it.curElement); }
private:
   typename dsDEQUELIST<DEQUE_DATA_TYPE>::DLIST * curElement;
};

template <class DEQUE_DATA_TYPE>
class dsDEQUE_LIST_CONST_ITERATOR {
public:
   dsDEQUE_LIST_CONST_ITERATOR () : curElement(NULL) {};
   dsDEQUE_LIST_CONST_ITERATOR (typename dsDEQUELIST<DEQUE_DATA_TYPE>::DLIST * el) : curElement(el) {};

   dsDEQUE_LIST_CONST_ITERATOR  (const dsDEQUE_LIST_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) = default;
   ~dsDEQUE_LIST_CONST_ITERATOR ()                                                        = default;
  
   dsDEQUE_LIST_CONST_ITERATOR & operator= (const dsDEQUE_LIST_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) = default;
   const DEQUE_DATA_TYPE       & operator*  (void) const;
   dsDEQUE_LIST_CONST_ITERATOR & operator++ (void);

   bool operator== (const dsDEQUE_LIST_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (curElement == it.curElement); }
   bool operator!= (const dsDEQUE_LIST_CONST_ITERATOR<DEQUE_DATA_TYPE> & it) const { return (curElement != it.curElement); }
private:
   typename dsDEQUELIST<DEQUE_DATA_TYPE>::DLIST * curElement;
};

#include "deque_list.hpp"

#endif // _DEQUE_LIST_H_
