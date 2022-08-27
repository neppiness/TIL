#include <algorithm>
#include <iostream>
using namespace std;

int num[1002];
int idx[3];

int BS(int begin, int end, int value){
    end--;
    while(begin <= end) {
        int mid = (begin + end)/2;
        if(num[mid] == value) return value;
        else if(num[mid] < value) begin = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];

    sort(num, num+N);

    for(int i = N-2; i >= 0; i--)
        for(int j = i-1; j >= 0; j--)
            for(int k = j-1; k >= 0; k--) {
                int val = num[i] + num[j] + num[k];
                int res = BS(i, N, val);
                if(res != -1) {cout << res; return 0;}
            }
}