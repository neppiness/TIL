#include <iostream>
using namespace std;

int a[3];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    int b[3];

    for(auto i : a) cout << i << ' '; // 0 0 0 - Global variables are automatically initialized
    cout << '\n';
    for(auto i : b) cout << i << ' '; // random trash value
}