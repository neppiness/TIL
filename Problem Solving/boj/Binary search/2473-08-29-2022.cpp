#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int N; 
int A[5002];
int a1, a2, a3, RES = 0x7ffffff;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++) {
            ll tar = -(A[i] + A[j]);
            int idx = lower_bound(A+j+1, A+N, tar) - &A[0] - 1;
            ll res = A[idx] - tar;
            if(res < 0) res = -res;
            if(res < RES) {
                RES = res;
                a1 = i; a2 = j; a3 = idx;
            }
            if(idx + 1 < N) {
                idx++;
                ll res = A[idx] - tar;
                if(res < 0) res = -res;
                if(res < RES) {
                    RES = res;
                    a1 = i; a2 = j; a3 = idx;
                }
            }
        }

    int arr[] = {a1, a2, a3}; sort(arr, arr+3);
    for(int i = 0; i < 3; i++) cout << A[arr[i]] << ' ';
}