#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool arr[1000001] = {0};

    int str[3];

    for (int i = 0; i < 3; ++i) {
        cin >> str[i];
    }

    for (int i = 0; i < 3; ++i) {
        arr[str[i]] = 1;
    }

    for (int i = 0; i < sizeof(arr); ++i) {
        if (arr[i] == 1) cout << i << ' ';
    }
}