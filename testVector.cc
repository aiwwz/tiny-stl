#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec(10);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    return 0;
}

