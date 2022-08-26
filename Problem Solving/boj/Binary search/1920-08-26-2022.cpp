#include <iostream>
#include <algorithm>
using namespace std;

int A[100002];
int N, M;

bool BS(int x, int begin, int end) {
    int idx = begin + (end-begin)/2;

    if(A[idx] == x) return true;
    else if(end - begin == 1) return false;
    else if(A[idx] > x) return BS(x, begin, idx);
    else return BS(x, idx, end);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    cin >> M;
    while(M--) {
        int x; cin >> x;
        cout << BS(x, 0, N) << '\n';
    }
}