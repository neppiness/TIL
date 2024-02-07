#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int num[52];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    sort(num, num+N);

    int nPosIdx = -1, posIdx = -1;
    for(int i = 0; i < N; i++) {
        if(num[i] <= 0) nPosIdx = i;
        else if(num[i] > 0) {posIdx = i; break;}
    }

    for(int i = 0; i <= nPosIdx; i++) {
        if(i != nPosIdx) {
            ans += (num[i] * num[i+1]);
            i++;
        } else ans += num[i];
    }
    for(int i = N-1; i >= posIdx; i--) {
        if(i != posIdx && num[i] != 1 && num[i-1] != 1) {
            ans += (num[i] * num[i-1]);
            i--;
        } else ans += num[i];
    }
    cout << ans;
}