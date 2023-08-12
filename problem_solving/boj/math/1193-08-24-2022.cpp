#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int X; cin >> X;

    int N = 1;
    while(X > N*(N+1)/2) N++;
    N--;

    int idx = X - N*(N+1)/2;

    if(N%2 != 0) cout << idx << '/' << N+2-idx;
    else cout << N+2-idx << '/' << idx;
}