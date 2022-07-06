#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int noA[26] = {0};
    char str[101] = {0};
    cin >> str;

    for (int i = 0; i < 100; i++) {
        int idx = str[i] - 97;
        if (idx >= 0) noA[str[i] - 97] += 1;
    }
    for (int i = 0; i < 26; i++) {
        cout << noA[i];
        cout << ' ';
    }
}