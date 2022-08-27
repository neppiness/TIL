#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt;
int num[500002];

int lowerBoundSearch(int begin, int end, int value) {
    int mid = begin + (end - begin)/2;
    if(end - begin == 1) {
        if(num[begin] == value) end--;
        return end;
    }
    else if(num[mid] < value) return lowerBoundSearch(mid, end, value);
    else return lowerBoundSearch(begin, mid, value);
}

int upperBoundSearch(int begin, int end, int value) {
    int mid = begin + (end - begin)/2;
    if(end - begin == 1) return end;
    else if(num[mid] > value) return upperBoundSearch(begin, mid, value);
    else return upperBoundSearch(mid, end, value);
}

int bsrange(int begin, int end, int value) {
    int mid = begin + (end - begin)/2;
    if(num[mid] == value) {
        return upperBoundSearch(mid, end, value) - lowerBoundSearch(begin, mid, value);
    }
    else if(end - begin == 1) return 0;
    else if(num[mid] > value) return bsrange(begin, mid, value);
    else return bsrange(mid, end, value);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    sort(num, num+N);

    int M; cin >> M;
    while(M--) {
        int a; cin >> a;

        int len = bsrange(0, N, a);
        cout << len << ' ';
    }
}