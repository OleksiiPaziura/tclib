#ifndef TC_DATA_STRUCTURE_H
#define TC_DATA_STRUCTURE_H

#include "Pair.h"
#include <cstdlib>
#include <iostream>

namespace tc
{
    template<typename Type>
    class DataStructure
    {
    protected:
        Type *structure;
        size_t structure_size;

    public:
        DataStructure()
        {
            structure_size = 0;
            structure = new Type[structure_size];
        }

        ~DataStructure()
        {
            delete structure;
        }

        virtual void clear()
        {
            delete[] structure;
            structure_size = 0;
            structure = new Type[structure_size];
        }

        virtual bool is_empty()
        {
            if (structure_size <= 0)
                return true;
            else
                return false;
        }

        virtual size_t size()
        {
            return structure_size;
        }
    };
}

#endif // TC_DATA_STRUCTURE_H
