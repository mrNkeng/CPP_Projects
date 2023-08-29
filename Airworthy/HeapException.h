/*

 */


#ifndef HEAPEXCEPTION_H
#define HEAPEXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class HeapException : public logic_error {
public:
    HeapException(const string& msg = "");
};

#endif /* HEAPEXCEPTION_H */

