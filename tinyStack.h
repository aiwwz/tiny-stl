#ifndef __TINY_STACK_H__
#define __TINY_STACK_H__
#include <iostream> 
#include <stdlib.h>
#include <deque>

template <typename _Tp, typename _Seq = std::deque<_Tp>> //默认基于deque实现
class tinyStack{
    /* 声明友元函数 */
    template <typename _T, typename _S>
    friend bool operator==(const tinyStack<_T, _S> &lhs, const tinyStack<_T, _S> &rhs);

    template <typename _T, typename _S>
    friend bool operator<(const tinyStack<_T, _S> &lhs, const tinyStack<_T, _S> &rhs);

    /* 定义类型别名 */
    using value_type        =   typename _Seq::value_type;
    using size_type         =   typename _Seq::size_type;
    using container_type    =   _Seq;
    using reference         =   typename _Seq::reference;
    using const_reference   =   typename _Seq::const_reference;

public:
    /* 构造函数 */
    tinyStack() : m_seq() {}
    tinyStack(const _Seq &seq) : m_seq(seq) {}

    /* 成员函数 */
    bool empty() { return m_seq.empty(); }

    size_type size() { return m_seq.size(); }

    reference top() { return m_seq.back(); }

    const_reference top() const { return m_seq.back(); }

    void push(const value_type &elem) { m_seq.push_back(elem); }

    void pop(){ m_seq.pop_back(); }

private:
    _Seq m_seq; //底层容器
};

/* 定义友元函数 */
template <typename _Tp, typename _Seq>
bool operator==(const tinyStack<_Tp, _Seq> &lhs, const tinyStack<_Tp, _Seq> &rhs) {
    return lhs.m_seq == rhs.m_seq;
}

template <typename _Tp, typename _Seq>
bool operator<(const tinyStack<_Tp, _Seq> &lhs, const tinyStack<_Tp, _Seq> &rhs) {
    return lhs.m_seq < rhs.m_seq;
}

/* 定义普通函数 -- 重用上面定义的友元函数 */
template <typename _Tp, typename _Seq>
bool operator!=(const tinyStack<_Tp, _Seq> &lhs, const tinyStack<_Tp, _Seq> &rhs) {
    return !(lhs == rhs);
}

template <typename _Tp, typename _Seq>
bool operator>(const tinyStack<_Tp, _Seq> &lhs, const tinyStack<_Tp, _Seq> &rhs) {
    return rhs < lhs; //左右位置互换, 重用'<'
}

template <typename _Tp, typename _Seq>
bool operator<=(const tinyStack<_Tp, _Seq> &lhs, const tinyStack<_Tp, _Seq> &rhs) {
    return !(lhs > rhs);
}

template <typename _Tp, typename _Seq>
bool operator>=(const tinyStack<_Tp, _Seq> &lhs, const tinyStack<_Tp, _Seq> &rhs) {
    return !(lhs < rhs);
}

#endif /* __TINY_STACK_H__ */

