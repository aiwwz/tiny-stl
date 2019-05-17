#ifndef __STRING_H__
#define __STRING_H__

class String{
public:
    String();
    String(const char *str);
    String(const String &rhs);
    ~String();
    String & operator=(const String &rhs);

    void print();

private:
    char *m_str;
};

#endif /* __STRING_H__ */ 


