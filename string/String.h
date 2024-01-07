#ifndef TC_STRING_H
#define TC_STRING_H

#include <iostream>
#include <cstring>

namespace tc
{
    class String
    {
    private:
        char *m_string;
        std::size_t m_size;

    public:
        String(const char *string = "");
        String(const String &string);
        ~String();

        inline std::size_t size() const
        { return m_size; }

        const String& operator+=(String &string);
        const String& operator+=(const char *string);
        const String& operator+(String &string) const;
        const String& operator+(const char *string) const;
        friend const String& operator+(const char *literal, String &string);

        const String& operator=(String &string);
        const String& operator=(const char *string);
        friend std::ostream& operator<<(std::ostream &out, const String &string);
    };
}

#endif // TC_STRING_H
