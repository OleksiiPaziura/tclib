#include "String.h"
using namespace tc;

// CONSTRUCTORS
String::String(const char *string)
{
    m_size = strlen(string);
    m_string = new char[m_size + 1];
    strcpy(m_string, string);
}
String::String(const String &string)
{
    m_size = string.m_size;
    m_string = new char[m_size + 1];
    strcpy(m_string, string.m_string);
}
String::~String()
{
    delete[] m_string;
}


// OPERATOR OVERLOADINGS
String& String::operator=(const String &string)
{
    if (this == &string)
        return *this;

    m_size = string.m_size;
    delete[] m_string;
    m_string = new char[m_size + 1];
    strcpy(m_string, string.m_string);

    return *this;
}
String& String::operator=(const char *string)
{
    m_size = strlen(string);
    delete[] m_string;
    m_string = new char[m_size + 1];
    strcpy(m_string, string);

    return *this;
}
const String& String::operator+=(const String &string)
{
    m_size += string.m_size;
    char *new_string = new char[m_size + 1];
    strcpy(new_string, m_string);
    strcat(new_string, string.m_string);
    delete[] m_string;
    m_string = new_string;

    return *this;
}
const String& String::operator+=(const char *string)
{
    m_size += strlen(string);
    char *new_string = new char[m_size + 1];
    strcpy(new_string, m_string);
    strcat(new_string, string);
    delete[] m_string;
    m_string = new_string;

    return *this;
}
const String String::operator+(const String &string) const
{
    char *new_string = new char[m_size + string.m_size + 1];
    strcpy(new_string, m_string);
    strcat(new_string, string.m_string);
    return String(new_string);
}
const String String::operator+(const char *string) const
{
    char *new_string = new char[m_size + strlen(string) + 1];
    strcpy(new_string, m_string);
    strcat(new_string, string);
    return String(new_string);
}
const String tc::operator+(const char *literal, const String &string)
{
    char *new_string = new char[string.m_size + strlen(literal) + 1];
    strcpy(new_string, literal);
    strcat(new_string, string.m_string);
    return String(new_string);
}
std::ostream& tc::operator<<(std::ostream &out, const String &string)
{
    out << string.m_string;
    return out;
}
