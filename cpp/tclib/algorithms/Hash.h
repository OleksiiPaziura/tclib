#ifndef TC_HASH_H
#define TC_HASH_H

#include "ListingDataStructure.h"
#include "Vector.h"

namespace tc
{
    template<typename Key, typename Value>
    class Hash : ListingDataStructure<Vector<Pair<Key, Value>>>
    {
    private:
        size_t getHashIndex(Key key)
        {
            return key % this->structure_size;
        }

    public:
        Hash()
        {
            this->structure_size = 20;
            this->structure = new Vector<Pair<Key, Value>>[this->structure_size];
        }

        void clear() override
        {
            throw std::logic_error("Not implemented yet");
        }

        bool is_empty() override
        {
            throw std::logic_error("Not implemented yet");
        }

        size_t size() override
        {
            throw std::logic_error("Not implemented yet");
        }

        void reHash()
        {
            auto *new_hash_table = new Vector<Pair<Key, Value>>[this->structure_size *= 2];
            for (int i = 0; i < this->structure_size / 2; ++i)
            {
                for (int j = 0; j < this->structure[i].size(); ++j)
                {
                    Pair<Key, Value> new_pair(this->structure[i][j].getKey(), this->structure[i][j].getValue());
                    new_hash_table[getHashIndex(this->structure[i][j].getKey())].push_back(new_pair);
                }
            }
            delete[] this->structure;
            this->structure = new_hash_table;
        }

        void push_back(Pair<Key, Value> pair)
        {
            this->structure[getHashIndex(pair.getKey())].push_back(pair);
            if (this->structure[getHashIndex(pair.getKey())].size() >= 3)
                reHash();
        }

        void print()
        {
            for (int i = 0; i < this->structure_size; ++i)
            {
                std::cout << i << ":\t[ ";
                for (int j = 0; j < this->structure[i].size(); ++j)
                    std::cout << this->structure[i][j].getKey() << " ";
                std::cout << "]";
                std::cout << std::endl;
            }
        }

        void push_front(Vector<Pair<Key, Value>> value) override
        {
            throw std::logic_error("Not implemented yet");
        }

        void pop_back() override
        {
            throw std::logic_error("Not implemented yet");
        }

        void pop_front() override
        {
            throw std::logic_error("Not implemented yet");
        }

        bool find(Vector<Pair<Key, Value>> item) override
        {
            throw std::logic_error("Not implemented yet");
        }

        void erase(size_t index) override
        {
            throw std::logic_error("Not implemented yet");
        }
    };
}


#endif // TC_HASH_H
