#ifndef _CONTAINERSFUNCTIONS_H_
#define _CONTAINERSFUNCTIONS_H_

#include "common.h"


template <class DEST_CONTAINER_TYPE, class SRC_CONTAINER_TYPE>
void AppendContainer (DEST_CONTAINER_TYPE & dest, const SRC_CONTAINER_TYPE & appendedDeque);

template <class SRC_CONTAINER_TYPE, class CONTAINER_DATA_TYPE>
int FindIndexByData (const SRC_CONTAINER_TYPE & src, const CONTAINER_DATA_TYPE & data);

#include "containers_functions.hpp"

#endif // _CONTAINERSFUNCTIONS_H_