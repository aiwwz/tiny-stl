#include "Stack.h"
#include <iostream>
using std::cout; using std::endl;

int main(){
    Stack st;
    cout << "Create a stack!" << endl;

    st.push(10);
    cout << "Push 10" << endl;

    st.push(12);
    cout << "Push 12" << endl;

    st.push(14);
    cout << "Push 14" << endl;

    cout << "top of stack: " << st.top() << endl;
    st.pop();
    cout << "Pop!" << endl;

    cout << "top of stack: " << st.top() << endl;

    return 0;
}

