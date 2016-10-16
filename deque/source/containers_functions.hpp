#ifndef _CONTAINERSFUNCTIONS_HPP_
#define _CONTAINERSFUNCTIONS_HPP_

#include "common.h"

template <class DEST_CONTAINER_TYPE, class SRC_CONTAINER_TYPE>
void AppendContainer (DEST_CONTAINER_TYPE & dest, const SRC_CONTAINER_TYPE & src)
{
   int srclenght = src.GetLength();

   for (int i = 0; i < srclenght; i++) {
      dest.PushBack(src[i]);
   }
}

template <class SRC_CONTAINER_TYPE, class CONTAINER_DATA_TYPE>
int FindIndexByData (const SRC_CONTAINER_TYPE & src, const CONTAINER_DATA_TYPE & data)
{
   int srclenght = src.GetLength();

   for (int i = 0; i < srclenght; i++) {
      if (src[i] == data)
         return i;
   }

   return -1;
}

#endif // _CONTAINERSFUNCTIONS_HPP_
