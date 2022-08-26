#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt;
int num[500002];

int bsidx(int begin, int end, int value) {
    int mid = begin + (end - begin)/2;
    if(num[mid] == value) return mid;
    else if(end - begin == 1) return -1;
    else if(num[mid] > value) return bsidx(begin, mid, value);
    else return bsidx(mid, end, value);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    sort(num, num+N);

    int M; cin >> M;
    while(M--) {
        int a; cin >> a;
        cnt = 0;

        int idx = bsidx(0, N, a);
        if(idx != -1) {
            cnt++;
            int idxup = idx;
            while(num[++idxup] == a) cnt++;
            while(num[--idx] == a) cnt++;
        }
        cout << cnt << ' ';
    }
}