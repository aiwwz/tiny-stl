#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#define INIT_CAPACITY 15
#define Max(a, b) a>b?a:b

class String{
public:
    String();
    String(const char *str);
    String(const String &rhs);
    ~String();
    String& operator=(const String &rhs);
    String& operator=(const char *str);

    String& operator+=(const String &rhs);
    String& operator+=(const char *str);

    char& operator[](std::size_t index);
    const char& operator[](std::size_t index) const;

    std::size_t size() const;
    std::size_t capacity() const;
    const char* c_str() const;

    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);

    friend std::ostream& operator<<(std::ostream &os, const String &rhs);
    friend std::istream& operator>>(std::istream &is, String &rhs);

private:
    char *m_str;
    std::size_t m_size;
    std::size_t m_capacity;
};

String operator+(const String &lhs, const String &rhs);
String operator+(const String &lhs, const char *str);
String operator+(const char *str, const String &rhs);

#endif /* __STRING_H__ */ 
