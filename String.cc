#include "String.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout; using std::endl;

String::String(){ //默认构造函数
    m_str = new char[1];
    m_str[0] = '\0';
}

String::String(const char *str){ //带参构造函数
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

String::String(const String &rhs) //拷贝构造函数
    : m_str(new char[strlen(rhs.m_str) + 1]){
        strcpy(m_str, rhs.m_str);
    }

String::~String(){ //析构函数
    if(m_str != NULL){
        delete [] m_str;
    }
}

String& String::operator=(const String &rhs){ //操作符=函数
    if(&rhs != this){ //自赋值
        free(m_str);  //销毁之前的
        m_str = new char[strlen(rhs.m_str) + 1];
        strcpy(m_str, rhs.m_str);
    }

    return *this;
}

void String::print(){
    cout << m_str << endl;
}

int main(){
    String str1; //调用默认构造函数
    str1.print();

    String str2 = "Hello,world"; //调用拷贝构造函数
    str2.print();       
    
    String str3("wangdao"); //调用拷贝构造函数
    str3.print();   

    String str4 = str3; //调用拷贝构造函数
    str4.print();

    str4 = str2; //调用赋值运算符函数
    str4.print();

    return 0;
}
