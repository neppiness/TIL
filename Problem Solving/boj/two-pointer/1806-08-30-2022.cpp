#include <algorithm>
#include <iostream>
using namespace std;

int N, S;
int A[100002];
int minLen = 2123123123;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> A[i];

    int tot = 0;
    int st = 0, en = 0;

    for(st = 0; st < N; st++) {
        while(en < N && tot < S) tot += A[en++];
        if(tot >= S) {
            minLen = min(en - st, minLen);
            tot -= A[st];
        }
    }
    if(minLen == 2123123123) cout << 0;
    else cout << minLen;
}