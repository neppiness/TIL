#include <iostream>
#include <string>
using namespace std;

int num[52];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string str; cin >> str;
    
    int nIdx = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '+' || str[i] == '-') continue;
        // For integer str[i]
        int j = 1;
        char c = str[i+j];
        while(c != '+' && c != '-' && (i+j < str.length())) {j++; c = str[i+j];}

        int M = j, p10 = 1;
        while(M--) {
            num[nIdx] += (str[i+M] - '0')*p10;
            p10 *= 10;
        }
        nIdx++; i = i + j - 1;
    }

    int ans = num[0];
    nIdx = 1;
    bool isMinus = false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '+') {
            if(isMinus) ans -= num[nIdx++];
            else ans += num[nIdx++];
        } else if(str[i] == '-') {
            ans -= num[nIdx++];
            isMinus = true;
        }
    }
    cout << ans;
}