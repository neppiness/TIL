#include <iostream>
#include <string>
using namespace std;

int ans[5002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;

    for(int i = 0; i < str.length(); i++) str[i] -= '0';
    if(str[0] == 0) {cout << 0; return 0;}

    ans[0] = 1, ans[1] = 1; // 1-indexed

    for(int i = 1; i < str.length(); i++) {
        int num = str[i-1]*10 + str[i];
        if(num == 0) {cout << 0; return 0;}
        if(str[i] != 0) {
            ans[i+1] += ans[i] % 1000000;
            ans[i+1] %= 1000000;
        }
        if(str[i-1] != 0 && num <= 26) {
            ans[i+1] += ans[i-1] % 1000000;
            ans[i+1] %= 1000000;
        }
        if(str[i] == 0 && (num > 20)) {cout << 0; return 0;}
    }
    cout << ans[str.length()];
}