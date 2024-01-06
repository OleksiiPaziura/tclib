#ifndef TC_LISTING_DATA_STRUCTURE_H
#define TC_LISTING_DATA_STRUCTURE_H

#include "DataStructure.h"

namespace tc
{
    template<typename Type>
    class ListingDataStructure : public DataStructure<Type>
    {
    public:
        virtual void push_back(Type value) = 0;

        virtual void push_front(Type value) = 0;

        virtual void pop_back() = 0;

        virtual void pop_front() = 0;

        virtual int find(Type item) = 0;

        virtual void erase(size_t index) = 0;
    };
}

#endif // TC_LISTING_DATA_STRUCTURE_H
