#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int p10Calc(int m) {
    if(m == 1) return 1;
    return 10 * p10Calc(m-1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string str;
    int N; cin >> N;

    vector<int> V;

    while(N--){
        cin >> str;

        string::iterator it = str.end(); it--;
        int len = str.length();

        while(*it == '0') {it--; len--;}

        int p10 = p10Calc(len);
        int num = 0;
        while(it >= str.begin()) {
            num += (*it - '0') * p10;
            p10 /= 10;
            it--;
        }
        V.push_back(num);
    }

    sort(V.begin(), V.end());
    for(auto a : V) cout << a << '\n';
}