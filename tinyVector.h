#ifndef __TINY_VECTOR_H__
#define __TINY_VECTOR_H__
#include <memory>

namespace tiny {

template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
class tinyVector {
public:
    /* 定义类型别名 */
    using value_type        =       _Tp;
    using pointer           =       value_type *;
    using const_pointer     =       const value_type *;
    using iterator          =       value_type *;
    using const_iterator    =       const value_type *;
    using reference         =       value_type &;
    using const_reference   =       const value_type &;
    using size_type         =       size_t;
    using difference_type   =       std::ptrdiff_t;

    /* 构造函数 */
    tinyVector(size_type n) {  }
    ~tinyVector() {}

    /* 成员函数 */
   iterator begin() { return m_start; } 
   const_iterator begin() const { return m_start; } 

   iterator end() { return m_finish; } 
   const_iterator end() const { return m_finish; } 

   //iterator rbegin() { return m_finish; } 
   //const_iterator rbegin() const { return m_finish; } 
   //
   //iterator rend() { return m_finish; } 
   //const_iterator rend() const { return m_finish; } 

   size_type size() const { return (m_finish - m_start); }
   size_type max_size() const { return size_type(-1) / sizeof(_Tp); }
   size_type capacity() const { return (m_end_of_storage - m_start); }
   bool empty() const { return begin() == end(); }

   reference operator[](size_type n) { return *(begin() + n); } 
   const_reference operator[](size_type n) const { return *(begin() + n); } 

private:
    _Tp *m_start;
    _Tp *m_finish;
    _Tp *m_end_of_storage;
};

} //end of namespace tiny

#endif /* __TINY_VECTOR_H__ */

