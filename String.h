#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#define INIT_CAPACITY 15
#define Max(a, b) a>b?a:b

class String{
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);

    friend std::ostream& operator<<(std::ostream &os, const String &rhs);
    friend std::istream& operator>>(std::istream &is, String &rhs);

    using iterator = char*;
    using const_iterator = const char*;
    using size_type = uint32_t;

public:
    String(const char *str = nullptr);
    String(const String &rhs);
    ~String();
    String& operator=(const String &rhs);
    String& operator=(const char *str);

    String& operator+=(const String &rhs);
    String& operator+=(const char *str);

    char& operator[](size_type index);
    const char& operator[](size_type index) const;

    size_type size() const { return m_size; }
    size_type capacity() const { return m_capacity; }
    const char* c_str() const { return m_data; }

    const_iterator data() const;
    iterator begin() { return m_data; }
    iterator end() { return m_data + m_size; }

private:
    char *m_data;
    size_type m_size;
    size_type m_capacity;
};

String operator+(const String &lhs, const String &rhs);
String operator+(const String &lhs, const char *str);
String operator+(const char *str, const String &rhs);

#endif /* __STRING_H__ */ 
