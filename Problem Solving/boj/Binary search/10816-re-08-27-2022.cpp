#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt;
int num[500002];

int LBSearch(int begin, int end, int value) {
    int mid = (begin + end)/2;
    if(end - begin == 1) {
        if(num[begin] == value) end--;
        return end;
    }
    else if(num[mid] < value) return LBSearch(mid, end, value);
    else return LBSearch(begin, mid, value);
}

int UBSearch(int begin, int end, int value) {
    int mid = (begin + end)/2;
    if(end - begin == 1) return end;
    else if(num[mid] > value) return UBSearch(begin, mid, value);
    else return UBSearch(mid, end, value);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    sort(num, num+N);

    int M; cin >> M;
    while(M--) {
        int a; cin >> a;

        int len = UBSearch(0, N, a) - LBSearch(0, N, a);
        cout << len << ' ';
    }
}