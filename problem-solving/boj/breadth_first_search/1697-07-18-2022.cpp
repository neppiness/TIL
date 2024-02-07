#include <queue>
#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, K;
    cin >> N >> K;

    int max = 200001;
    int time[200001];

    for(int i = 0; i < 200001; i++){
        time[i] = -1;
    }

    queue<int> Q;
    Q.push(N); time[N] = 0;
    if(K == N) {cout << time[K]; return 0;}

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int dCur[3] = {cur + 1, cur - 1, 2*cur};

        for(int i = 0; i < 3; i++) {
            int nxt = dCur[i];
            if(nxt > max || nxt < 0) continue;
            if(time[nxt] != -1) continue;

            time[nxt] = time[cur] + 1;

            if(nxt == K) {cout << time[nxt]; return 0;}
            Q.push(nxt);
        }
    }
}