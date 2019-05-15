#ifndef __STACK_H__
#define __STACK_H__
#include <iostream> 
#include <stdlib.h>

class Stack{
public:
    Stack():m_top(-1), m_capacity(10) {}
    ~Stack() {}

    void push(int elem){ //入栈
        if(!full()){
            m_elems[++m_top] = elem;
        }
        else{
            std::cout << "Full stack!!!" << std::endl;
            exit(1);
        }
    }

    void pop(){ //出栈
        if(!empty()){
            m_top--;
        }
        else{
            std::cout << "Empty stack!!!" << std::endl;
            exit(1);
        }
    }

    int top() const { //获取栈顶元素
        if(!empty()){
            return m_elems[m_top];
        }
        else{
            std::cout << "Empty stack!!!" << std::endl;
            exit(1);
        }
    }

    bool empty() const { //栈空?
        return m_top == -1;
    }

    bool full() const { //栈满?
        return m_top + 1 == m_capacity;
    }


private:
    int m_elems[10]; //存储空间
    int m_top;       //栈顶位置
    int m_capacity;  //栈容量
};


#endif /* __STACK_H__ */

