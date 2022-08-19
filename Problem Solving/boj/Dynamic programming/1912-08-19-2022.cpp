#include <iostream>
#include <algorithm>
using namespace std;

int N;
int SEQ[100002], D[100002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> SEQ[i];
    
    D[1] = SEQ[1];
    for(int i = 2; i <= N; i++) {
        D[i] = SEQ[i] + max(0, D[i-1]);
    }
    cout << *max_element(D+1, D+N+1);
}