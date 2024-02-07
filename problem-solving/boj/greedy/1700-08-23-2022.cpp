#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int cnt[102], num[102];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;

    int a;
    for(int i = 0; i < K; i++){
        cin >> a;
        num[i] = a; cnt[a]++;
    }

    int ans = 0;
    int con[N + 1];
    fill(con + 1, con + N + 1, 0);

    for(int i = 0; i < K; i++) {
        bool isFound = false;
        for(int j = 1; j <= N; j++) {
            if(con[j] == 0) {
                con[j] = num[i];
                cnt[num[i]]--;
                isFound = true;
                break;
            } else if(con[j] == num[i]) {
                cnt[num[i]]--;
                isFound = true;
                break;
            }
        }
        if(!isFound) {
            int tmp = 103, idx;
            for(int j = 1; j <= N; j++)
                if(cnt[con[j]] < tmp) {tmp = cnt[con[j]]; idx = j;}
            con[idx] = num[i];
            cnt[num[i]]--;
            ans++;
        }
    }
    cout << ans;
}