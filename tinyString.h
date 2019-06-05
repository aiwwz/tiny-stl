#ifndef __TINY_STRING_H__
#define __TINY_STRING_H__

#include <iostream>
#define INIT_CAPACITY 15
#define Max(a, b) a>b?a:b

class tinyString{
public:
    tinyString();
    tinyString(const char *str);
    tinyString(const tinyString &rhs);
    ~tinyString();
    tinyString& operator=(const tinyString &rhs);
    tinyString& operator=(const char *str);

    tinyString& operator+=(const tinyString &rhs);
    tinyString& operator+=(const char *str);

    char& operator[](std::size_t index);
    const char& operator[](std::size_t index) const;

    std::size_t size() const;
    std::size_t capacity() const;
    const char* c_str() const;

    friend bool operator==(const tinyString &lhs, const tinyString &rhs);
    friend bool operator!=(const tinyString &lhs, const tinyString &rhs);
    friend bool operator<(const tinyString &lhs, const tinyString &rhs);
    friend bool operator>(const tinyString &lhs, const tinyString &rhs);
    friend bool operator<=(const tinyString &lhs, const tinyString &rhs);
    friend bool operator>=(const tinyString &lhs, const tinyString &rhs);

    friend std::ostream& operator<<(std::ostream &os, const tinyString &rhs);
    friend std::istream& operator>>(std::istream &is, tinyString &rhs);

private:
    char *m_str;
    std::size_t m_size;
    std::size_t m_capacity;
};

tinyString operator+(const tinyString &lhs, const tinyString &rhs);
tinyString operator+(const tinyString &lhs, const char *str);
tinyString operator+(const char *str, const tinyString &rhs);

#endif /* __TINY_STRING_H__ */ 
