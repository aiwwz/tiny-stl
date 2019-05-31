#include <iostream>
#include "tinyQueue.h"
using std::cout; using std::endl;

int main(){
    tinyQueue<int> q;
    cout << "Create a queue!" << endl;

    q.push(1);
    cout << "Push 1" << endl;

    q.push(2);
    cout << "Push 2" << endl;

    q.push(3);
    cout << "Push 3" << endl;
    
    cout << "Front of queue: " << q.front() << endl;
    cout << "Back of queue: " << q.back() << endl;

    q.pop();
    cout << "Pop!" << endl;
    cout << "Front of queue: " << q.front() << endl;
    cout << "Back of queue: " << q.back() << endl;

    return 0;
}

