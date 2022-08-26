#include <iostream>
#include <algorithm>
using namespace std;

int A[100002];
int N, M;

bool BS(int x, int begin, int end) {
    while(end - begin != 1) {
        int mid = begin + (end-begin)/2;
        if(A[mid] == x) return true;
        else if(A[mid] > x) end = mid;
        else begin = mid;
    } 
    if(A[begin]==x) return true;
    else return false;
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