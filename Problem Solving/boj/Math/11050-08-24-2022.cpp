#include <iostream>
using namespace std;

int N, K; 

long long permNK() {
    int ret = 1;
    for(int a = N; a > N-K; a--) ret *= a;
    return ret;
}

long long fact(int n) {
    if(n == 1 || n == 0) return 1;
    return n * fact(n-1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;

    cout << (permNK() / fact(K));
}