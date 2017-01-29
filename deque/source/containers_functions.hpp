#ifndef _CONTAINERS_FUNCTIONS_HPP_
#define _CONTAINERS_FUNCTIONS_HPP_

#include "common.h"

template <class DEST_CONTAINER_TYPE, class SRC_CONTAINER_TYPE>
void AppendContainer (DEST_CONTAINER_TYPE & dest, const SRC_CONTAINER_TYPE & src)
{
   SRC_CONTAINER_TYPE::CONST_ITERATOR it = src.Begin();

   for (; it != (src.End()); ++it) {
      dest.PushBack(*(it));
   }

}

template <class SRC_CONTAINER_TYPE, class CONTAINER_DATA_TYPE>
int FindIndexByData (const SRC_CONTAINER_TYPE & src, const CONTAINER_DATA_TYPE & data)
{
   SRC_CONTAINER_TYPE::CONST_ITERATOR it = src.Begin();

   for (int i = 0; it != (src.End()); ++it, ++i) {
      if ((*it) == data) {
         return i;
      }
   }

   return -1;
}

#endif // _CONTAINERS_FUNCTIONS_HPP_
