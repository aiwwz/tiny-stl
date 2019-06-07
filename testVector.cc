#include <iostream>
#include <vector>
#include "tinyVector.h"
using namespace std;
using tiny::tinyVector;

int main() {
    vector<int> vec(10);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    tinyVector<int> tv(10);

    return 0;
}

