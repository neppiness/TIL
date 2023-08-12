#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int a[500002];
bool is[500002];

int cnt;

int bsidx(int val) {
    int begin = 0, end = N-1;
    while(begin < end) {
        int mid = (begin + end)/2;
        if(val > a[mid]) begin = mid + 1;
        else end = mid;
    }
    int res = a[begin];
    if(res == val) {cnt--; return begin;}
    else return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    cnt = N;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);

    while(M--) {
        int val; cin >> val;
        int idx = bsidx(val);
        if(idx != -1) is[idx] = true;
    }

    cout << cnt << '\n';
    if(cnt) for(int i = 0; i < N; i++)
        if(!is[i]) cout << a[i] << ' ';
}