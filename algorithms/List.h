#ifndef TC_LIST_H
#define TC_LIST_H

#include "ListingDataStructure.h"

namespace tc
{
    template<typename Type>
    class List : public ListingDataStructure<Type>
    {
    private:
        class Node
        {
        public:
            Node *pNext;
            Type data;

            Node(Type data = Type(), Node *pNext = nullptr)
            {
                this->data = data;
                this->pNext = pNext;
            }
        };

        Node *head;
        size_t count;

    public:
        List()
        {
            count = 0;
            head = nullptr;
        }

        void clear() override
        {
            throw std::logic_error("Not implemented yet");
        }

        bool is_empty() override
        {
            if (count <= 0)
                return true;
            else
                return false;
        }

        size_t size() override
        {
            return count;
        }

        void push_back(Type value) override
        {
            if (head == nullptr)
            {
                head = new Node(value);
            } else
            {
                Node *current = head;

                while (current->pNext != nullptr)
                {
                    current = current->pNext;
                }

                current->pNext = new Node(value);
            }
            ++count;
        }

        void print_all()
        {
            Node *current = head;

            while (true)
            {
                if (current->pNext != nullptr)
                {
                    std::cout << current->data << " ";
                    current = current->pNext;
                } else
                {
                    std::cout << current->data << " ";
                    break;
                }
            }
        }

        void push_front(Type value) override
        {
            if (head == nullptr)
            {
                head = new Node(value);
            } else
            {
                Node *tempNode = head;
                head = new Node(value);
                head->pNext = tempNode;
            }
            ++count;
        }

        void pop_back() override
        {
            if (head != nullptr && head->pNext != nullptr)
            {
                Node *current = head;

                while (true)
                {
                    if (current->pNext->pNext == nullptr)
                    {
                        delete current->pNext->pNext;
                        current->pNext = nullptr;
                        break;
                    }
                    current = current->pNext;
                }

                --count;
            }
        }

        void pop_front() override
        {
            if (head != nullptr)
            {
                head = head->pNext;
            }
            --count;
        }

        int find(Type item) override
        {
            if (head->pNext != nullptr)
            {
                int index = 0;
                Node *current = head;

                while (true)
                {
                    if (current->pNext != nullptr)
                    {
                        if (current->data == item)
                            return index;
                        current = current->pNext;
                        ++index;
                    } else
                    {
                        if (current->data == item)
                            return index;

                        break;
                    }
                }
            }

            return -1;
        }

        void erase(size_t index) override
        {
            throw std::logic_error("Not implemented yet");
        }
    };
}

#endif // TC_LIST_H
