#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int N;
ll A[5002];
int a1, a2, a3;
ll RES = 0x7f7f7f7f7f7f;

int LB(int begin, int end, ll val) {
    while(begin < end) {
        int mid = (begin + end)/2;
        if(A[mid] < val) begin = mid + 1;
        else end = mid;
    }
    return begin;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++) {
            ll tar = -(A[i] + A[j]);
            int idx = LB(j+1, N, tar);
            for(int k = -1; k <= 0; k++) {
                int IDX = idx + k;
                if(IDX < 0 || IDX >= N) continue;
                if(IDX == j || IDX == i) continue;
                ll res = A[IDX] - tar;
                if(res < 0) res = -res;
                if(res < RES) {
                    RES = res;
                    a1 = i; a2 = j; a3 = IDX;
                }
            }
        }

    int arr[] = {a1, a2, a3}; sort(arr, arr+3);
    for(int i = 0; i < 3; i++) cout << A[arr[i]] << ' ';
}