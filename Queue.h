#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
#include <stdlib.h>

class Queue
{
public:
    Queue():m_front(0), m_rear(-1), m_size(0), m_capacity(10) {}
    ~Queue() {}

    void enqueue(int elem){ //入队
        if(!full()){
            m_rear = nextPosition(m_rear);
            m_elems[m_rear] = elem;
            m_size++;
        }
        else{
            std::cout << "Full queue!!!" << std::endl;
            exit(1);
        }
    }

    void dequeue(){ //出队
        if(!empty()){
            m_front = nextPosition(m_front);
            m_size--;
        }
        else{
            std::cout << "Empty queue!!!" << std::endl;
            exit(1);
        }
    }
    
    int front() const { //获取队首元素
        return m_elems[m_front];
    }

    int back() const { //获取对尾元素
        return m_elems[m_rear];
    }

    bool empty() const { //队列空?
        return m_size == 0;
    }
    
    bool full() const { //队列满?
        return m_size == m_capacity;
    }
    
    int nextPosition(int index) const {
        if(++index == m_capacity){
            index = 0;
        }
        return index;
    }

private:
    int m_elems[10]; //存储空间
    int m_front;       //队头
    int m_rear;        //对尾
    int m_size;        //队列实际元素数
    int m_capacity;    //队列容量
};

#endif /* __QUEUE_H__ */
