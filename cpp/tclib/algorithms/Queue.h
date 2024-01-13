#ifndef TC_QUEUE_H
#define TC_QUEUE_H

#include "LinearDataStructure.h"

namespace tc
{
    template<typename Type>
    class Queue : public LinearDataStructure<Type>
    {
    public:
        void push(Type value) override
        {
            Type *new_structure = new Type[++this->structure_size];
            for (int i = 0; i < this->structure_size - 1; ++i)
                new_structure[i] = this->structure[i];
            new_structure[this->structure_size - 1] = value;
            delete[] this->structure;
            this->structure = new_structure;
        }

        void pop() override
        {
            Type *new_structure = new Type[--this->structure_size];
            for (int i = 1; i < this->structure_size + 1; ++i)
                new_structure[i - 1] = this->structure[i];
            delete[] this->structure;
            this->structure = new_structure;
        }

        Type top() override
        {
            if (!this->is_empty())
                return this->structure[0];
            else
                throw std::runtime_error("Top when stack is empty");
        }
    };
}

#endif // TC_QUEUE_H
