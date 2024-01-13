#ifndef TC_VECTOR_H
#define TC_VECTOR_H

#include "DataStructure.h"

namespace tc
{
    template<typename Type>
    class Vector : public DataStructure<Type>
    {
    public:
        Vector()
        {};

        Vector<Type>(size_t size)
        {
            this->structure_size = size;
            this->structure = new Type[size]{};
        }

        void push_back(Type value)
        {
            Type *new_vector = new Type[++this->structure_size];
            for (int i = 0; i < this->structure_size - 1; ++i)
                new_vector[i] = this->structure[i];
            new_vector[this->structure_size - 1] = value;
            delete[] this->structure;
            this->structure = new_vector;
        }

        void push_front(Type value)
        {
            Type *new_vector = new Type[++this->structure_size];

            new_vector[0] = value;
            for (int i = 1; i < this->structure_size; ++i)
                new_vector[i] = this->structure[i - 1];

            delete[] this->structure;
            this->structure = new_vector;
        }

        void remove(int index)
        {
            if (!this->is_empty())
            {
                Type *new_vector = new Type[--this->structure_size];
                for (int i = 0, j = 0; i < this->structure_size + 1; ++i, ++j)
                {
                    if (i != index)
                        new_vector[j] = this->structure[i];
                    else
                        --j;
                }
                delete[] this->structure;
                this->structure = new_vector;
            }
        }

        Type operator[](int index)
        {
            if (index < this->structure_size)
                return this->structure[index];
            else
                throw std::runtime_error("Out of bounds in vector");
        }
    };
}

#endif // TC_VECTOR_H
