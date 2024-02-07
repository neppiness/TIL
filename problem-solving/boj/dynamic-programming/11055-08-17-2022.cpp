#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1002], memo[1002];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        memo[i] = A[i];
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(A[i] > A[j]) {memo[i] = max(memo[i], memo[j] + A[i]);}
        }
    }

    cout << *max_element(memo, memo+N);
}