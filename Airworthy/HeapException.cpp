/*
 
 */



#include "HeapException.h"

HeapException::HeapException(const string& msg)
    : logic_error("Heap Exception: " + msg) {
}

