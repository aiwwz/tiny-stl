#include <iostream>
#include "Queue.h"
using std::cout; using std::endl;

int main(){
    Queue q;
    cout << "Create a queue!" << endl;

    q.enqueue(1);
    cout << "Enqueue 1" << endl;

    q.enqueue(2);
    cout << "Enqueue 2" << endl;

    q.enqueue(3);
    cout << "Enqueue 3" << endl;
    
    cout << "Front of queue: " << q.front() << endl;
    cout << "Rear of queue: " << q.back() << endl;

    q.dequeue();
    cout << "Dqueue!" << endl;
    cout << "Front of queue: " << q.front() << endl;
    cout << "Rear of queue: " << q.back() << endl;


    return 0;
}

