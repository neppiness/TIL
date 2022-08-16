#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    vector<long long> V;

    while(N--){
        string str; cin >> str;

        int m = str.length() - 1;
        long long p10 = 1;

        long long num = 0;
        for(auto it = str.begin(); it < str.end(); it++) {
            num += (*it - '0') * p10;
            p10 *= 10;
        }
        V.push_back(num);
    }

    sort(V.begin(), V.end());
    for(auto a : V) cout << a << '\n';
}