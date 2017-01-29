#ifndef _CONTAINERS_FUNCTIONS_H_
#define _CONTAINERS_FUNCTIONS_H_

#include "common.h"


template <class DEST_CONTAINER_TYPE, class SRC_CONTAINER_TYPE>
void AppendContainer (DEST_CONTAINER_TYPE & dest, const SRC_CONTAINER_TYPE & appendedDeque);

template <class SRC_CONTAINER_TYPE, class CONTAINER_DATA_TYPE>
int FindIndexByData (const SRC_CONTAINER_TYPE & src, const CONTAINER_DATA_TYPE & data);

#include "containers_functions.hpp"

#endif // _CONTAINERS_FUNCTIONS_H_