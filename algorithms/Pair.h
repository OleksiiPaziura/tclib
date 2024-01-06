#ifndef TC_PAIR_H
#define TC_PAIR_H

namespace tc
{
    template<typename Key, typename Value>
    class Pair
    {
    protected:
        Key key;
        Value value;

    public:
        Pair()
        {}

        Pair(Key key, Value value)
        {
            this->key = key;
            this->value = value;
        }

        void setValue(Value value)
        { this->value = value; }

        void setKey(Key key)
        { this->key = key; }

        Value getValue()
        { return value; }

        Key getKey()
        { return key; }
    };
}

#endif // TC_PAIR_H
