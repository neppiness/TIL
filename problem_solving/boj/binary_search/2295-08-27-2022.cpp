#include <algorithm>
#include <iostream>
using namespace std;

int num[1002];
int idx[3];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];

    sort(num, num+N);

    for(int i = N-1; i >= 0; i--)
        for(int j = i-1; j >= 0; j--)
            for(int k = 0; k <= j; k++) {
                int val = num[i] - num[j] - num[k];
                if(val <= 0) break;
                bool isVal = binary_search(num, num+k+1, val);
                if(isVal) {cout << num[i]; return 0;}
            }
}