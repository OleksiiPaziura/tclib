#ifndef TC_LINEAR_DATA_STRUCTURE_H
#define TC_LINEAR_DATA_STRUCTURE_H

#include "DataStructure.h"

namespace tc
{
    template<typename Type>
    class LinearDataStructure : public DataStructure<Type>
    {
        virtual void push(Type value) = 0;

        virtual void pop() = 0;

        virtual Type top() = 0;
    };
}

#endif // TC_LINEAR_DATA_STRUCTURE_H
