#include <iostream>
using namespace std;

int N, K;
int CO[1000002];
int cnt;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    int i = 0;
    for(; i < N; i++) cin >> CO[i];

    while(i--) {
        cnt += K/CO[i];
        K %= CO[i];
    }
    cout << cnt;
}