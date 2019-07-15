#include "tinyString.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cin; using std::cout; using std::endl;

tinyString::tinyString() //默认构造函数
    : m_str(new char[INIT_CAPACITY] ())
    , m_size(0)
    , m_capacity(INIT_CAPACITY){ }

tinyString::tinyString(const char *str) //带参构造函数
    : m_str(new char[strlen(str) + 1] ()) 
    , m_size(strlen(str))
    , m_capacity(Max(strlen(str), INIT_CAPACITY)){ 
          strcpy(m_str, str);
}

tinyString::tinyString(const tinyString &rhs) //拷贝构造函数
    : m_str(new char[strlen(rhs.m_str) + 1])
    , m_size(rhs.m_size)
    , m_capacity(Max(rhs.m_capacity, INIT_CAPACITY)){
          strcpy(m_str, rhs.m_str);
}

tinyString::~tinyString(){ //析构函数
    if(m_str != NULL){
        delete [] m_str;
    }
}

/* 考虑facebook的方法 */
tinyString& tinyString::operator=(const tinyString &rhs){ //操作符=函数:String字符串版本
    if(&rhs != this){ //自赋值
        m_size = rhs.m_size;
        if(m_size > m_capacity){ //原始空间不足, 则申请新空间, 否则直接使用原始空间
            if(m_size > m_capacity * 2){
                m_capacity = m_size;
            }
            else{ //capacity扩大为原来的2倍
                m_capacity *= 2;
            }
            delete [] m_str;
            m_str = new char[m_capacity + 1] ();
        }
        strcpy(m_str, rhs.m_str);
    }

    return *this;
}

tinyString& tinyString::operator=(const char *str){ //操作符=函数:C语言字符串版本
    *this = tinyString(str); //重用

    return *this;
}

tinyString& tinyString::operator+=(const tinyString &rhs){
    m_size += rhs.m_size;
    if(m_size > m_capacity){ //原始空间不足, 则申请新空间 
        if(m_size > m_capacity * 2){
            m_capacity = m_size;
        }
        else{ //否则将capacity扩大为原来的2倍
            m_capacity *= 2;
        }
        char *tmp_str = new char[m_capacity + 1] ();
        strcpy(tmp_str, m_str); //保存原来的字符串
        strcat(tmp_str, rhs.m_str); //在末尾追加新字符串
        delete [] m_str; //释放原来的空间
        m_str = tmp_str; //指向新空间
    }
    else{ //否则直接使用原始空间
        strcat(m_str, rhs.m_str);
    }

    return *this;
}

tinyString& tinyString::operator+=(const char *str){
    *this += tinyString(str); //重用

    return *this;
}

char& tinyString::operator[](std::size_t index){
    return m_str[index];
}

const char& tinyString::operator[](std::size_t index) const {
    return m_str[index];
}

std::size_t tinyString::size() const {
    return m_size;
}

std::size_t tinyString::capacity() const {
    return m_capacity;
}

const char* tinyString::c_str() const {
    return m_str;
}


/* 关系运算符 */
bool operator==(const tinyString &lhs, const tinyString &rhs){
    if(lhs.m_size != rhs.m_size){ //提升性能
        return false;
    }

    return (strcmp(lhs.m_str, rhs.m_str) == 0);
}

bool operator!=(const tinyString &lhs, const tinyString &rhs){
    return !(lhs == rhs); //重用==操作符函数
}

bool operator<(const tinyString &lhs, const tinyString &rhs){
    return (strcmp(lhs.m_str, rhs.m_str) < 0);
}

bool operator>(const tinyString &lhs, const tinyString &rhs){
    return (strcmp(lhs.m_str, rhs.m_str) > 0);
}

bool operator<=(const tinyString &lhs, const tinyString &rhs){
    return !(lhs > rhs);
}

bool operator>=(const tinyString &lhs, const tinyString &rhs){
    return !(lhs < rhs);
}

/* 输入输出 */
std::ostream& operator<<(std::ostream &os, const tinyString &rhs){
    return os << rhs.m_str;
}

std::istream& operator>>(std::istream &is, tinyString &rhs){
    char buf[4096] = {0}; 
    is >> buf; //有溢出风险!!!
    rhs = buf;
    return is;
}


/* 三类加法重载 */
tinyString operator+(const tinyString &lhs, const tinyString &rhs){
    return tinyString(lhs) += rhs;
}

tinyString operator+(const tinyString &lhs, const char *str){
    return tinyString(lhs) += str;
}

tinyString operator+(const char *str, const tinyString &rhs){
    return tinyString(str) += rhs;
}


int main(){
    //测试
    tinyString str1; //调用默认构造函数
    cout << str1 << endl;

    tinyString str2 = "Hello,world"; //调用拷贝构造函数
    cout << str2 << endl;

    tinyString str3("wangdao"); //调用拷贝构造函数
    cout << str3 << endl;

    tinyString str4 = str3; //调用拷贝构造函数
    cout << str4 << endl;

    str4 = str2; //调用赋值运算符函数
    cout << str4 << endl;

    str1 = "how";
    str2 = " are ";
    cout << str1 + str2 + "you?" << endl;

    str1 = "I";
    str1 += " am ";
    str2 = "fine!";
    str1 += str2;
    cout << str1 << endl;

    str1 = "aab";
    str2 = "aaa";
    cout << "str1: " << str1 << endl
         << "str2: " << str2 << endl; 
    if(str1 < str2){
        cout << "str1 < str2" << endl;
    }
    else if(str1 > str2){
        cout << "str1 > str2" << endl;
    }
    else{
        cout << "str1 == str2" << endl;
    }

    cin >> str1;
    cout << str1 << endl;

    return 0;
}
