#ifndef TC_STACK_H
#define TC_STACK_H

#include "LinearDataStructure.h"

namespace tc
{
    template<typename Type>
    class Stack : public LinearDataStructure<Type>
    {
    public:
        void push(Type value) override
        {
            Type *new_stack = new Type[++this->structure_size];
            for (int i = 0; i < this->structure_size - 1; ++i)
                new_stack[i] = this->structure[i];
            new_stack[this->structure_size - 1] = value;
            delete[] this->structure;
            this->structure = new_stack;
        }

        void pop() override
        {
            if (!this->is_empty())
            {
                Type *new_stack = new Type[--this->structure_size];
                for (int i = 0; i < this->structure_size; ++i)
                    new_stack[i] = this->structure[i];
                delete[] this->structure;
                this->structure = new_stack;
            }
        }

        Type top() override
        {
            if (!this->is_empty())
                return this->structure[this->structure_size - 1];
            else
                throw std::runtime_error("Top when stack is empty");
        }
    };
}

#endif // TC_STACK_H
