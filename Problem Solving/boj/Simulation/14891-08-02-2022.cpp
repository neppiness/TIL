#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int wheel[4] = {0};
int ans = 0;

void move(int idx, int dir) {
    if(dir == 1) {
        if(wheel[idx] % 2 == 1) wheel[idx] += 256;
        wheel[idx] = (wheel[idx] >> 1);
    } else {
        wheel[idx] = (wheel[idx] << 1);
        if(wheel[idx] / 256 == 1) wheel[idx]++;
        wheel[idx] %= 256;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    string str;

    for(int i = 0; i < 4; i++) {
        cin >> str;

        int mul = 1;
        for(int j = 7; j >= 0; j--) {
            if(str[j] == '1') wheel[i] += mul;
            mul *= 2;
        }
    }
    
    int K; cin >> K;

    queue<pair<int, int>> Q;

    while(K--) {
        int idx, dir; cin >> idx >> dir;

        idx--;

        Q.push({idx, dir});

        int tmp = idx; int tempDir = dir;
        while(++tmp < 4) {
            tempDir = - tempDir;
            int leftThree = (wheel[tmp - 1] & 32) / 32;
            int rightNine = (wheel[tmp] & 2) / 2;

            if(leftThree != rightNine) Q.push({tmp, tempDir});
            else break;
        }
        tmp = idx; tempDir = dir;
        while(--tmp >= 0) {
            tempDir = - tempDir;
            int leftThree = (wheel[tmp] & 32) / 32;
            int rightNine = (wheel[tmp + 1] & 2) / 2;

            if(leftThree != rightNine) Q.push({tmp, tempDir});
            else break;
        }
        
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            move(cur.first, cur.second);
        }
    }

    int mul = 1;
    for(int i = 0; i < 4; i++) {
        ans += (wheel[i] / 128) * mul;
        mul *= 2;
    }
    cout << ans;
}