#include <algorithm>
#include <iostream>

using namespace std;

int num[2000002];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    fill(num, num + 2000002, 0);

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        num[a+1000000]++;
    }

    for(int i = 0; i < 2000002; i++) while(num[i]--) cout << i-1000000 << '\n';
}