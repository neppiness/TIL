#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int N; 
ll A[5002];
int a1, a2, a3;
ll RES = 0x7ffffff;

int LB(int begin, int end, int val) {
    while(begin < end) {
        int mid = (begin + end)/2;
        if(A[mid] > val) end = mid;
        else begin = mid + 1;
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
            int idx = LB(j+1, N, tar) - 1;
            
            if(idx != i && idx != j) {
                ll res = A[idx] - tar;
                if(res < 0) res = -res;
                if(res < RES) {
                    RES = res;
                    a1 = i; a2 = j; a3 = idx;
                }
            }
            if(idx + 1 < N) {
                idx++;
                if(idx != i && idx != j) {
                    ll res = A[idx] - tar;
                    if(res < 0) res = -res;
                    if(res < RES) {
                        RES = res;
                        a1 = i; a2 = j; a3 = idx;
                    }
                }
            }
        }

    int arr[] = {a1, a2, a3}; sort(arr, arr+3);
    for(int i = 0; i < 3; i++) cout << A[arr[i]] << ' ';
}