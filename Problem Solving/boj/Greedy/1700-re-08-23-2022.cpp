#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
bool con[102]; // 1-indexed number count
int cnt[102];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    int num[K], mult[N];

    fill(mult+1, mult+N+1, 0);

    for(int i = 0; i < K; i++) {cin >> num[i]; cnt[num[i]]++;}

    int ans = 0;
    for(int i = 0; i < K; i++) {
        bool isFound = false;
        for(int j = 0; j < N; j++) {
            if(mult[j] == 0) {
                mult[j] = num[i];
                con[num[i]] = true;
                cnt[num[i]]--;
                isFound = true;
                break;
            } else if(mult[j] == num[i]) {
                con[num[i]] = true;
                cnt[num[i]]--;
                isFound = true;
                break;
            }
        }
        if(!isFound){
            int j = 1;
            for(; j <= N; j++) if(!cnt[mult[j]]) break;
            if (j == N) {
                while(j--) {
                    bool isDone = false;
                    for(int k = 0; k < N; k++) {
                        if(num[j] == mult[k]) {
                            mult[k] = num[i];
                            con[num[i]] = true;
                            cnt[num[i]]--;
                            ans++;
                            isDone = true;
                            break;
                        }
                    }
                    if(isDone) break;
                }
            } else {
                mult[j] = num[i];
                con[num[i]] = true;
                cnt[num[i]]--;
                ans++;
            }
        }
    }
    cout << ans;
}