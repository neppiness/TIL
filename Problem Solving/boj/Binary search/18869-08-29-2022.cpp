#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int A[10002], sA[10002];
int B[10002];

vector<int> V[102];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> M >> N;
    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N; i++) {cin >> A[i]; sA[i] = A[i];}

        sort(sA, sA+N);
        
        for(int i = 0; i < N; i++) {
            int *it = sA;
            int rank = lower_bound(it, it + N, A[i]) - it;
            V[j].push_back(rank);
        }
    }
    sort(V, V+M);

    int cnt = 0;
    for(int i = 0; i < M-1; i++) {
        int j = i + 1;
        if(V[i] == V[j]) {
            cnt++;
            while(j < N && V[i] == V[j]) j++;
            i = j - 1;
        }
    }
    cout << cnt;
} 