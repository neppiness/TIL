#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1010], len[1010];

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    fill(len, len+N, 1);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++)
            if(A[i] > A[j]) len[i] = max(len[i], len[j] + 1);

    cout << *max_element(len, len+N);
}