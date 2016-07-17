#include <iostream>

using namespace std;

int main() {

    char c;
    cin>>c;
    string ret;
    ret = ((c - 'A') / 3) + '2';
    cout << (int)c  << endl;
    cout << ret<< endl;
}
