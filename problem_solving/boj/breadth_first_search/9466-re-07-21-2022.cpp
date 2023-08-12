#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int noCases; cin >> noCases;

    while(noCases--){
        int N; cin >> N;
        
        int dat[N+1];
        bool isInTeam[N+1] = {false};
        int result = N;

        // input
        for(int i = 1; i <= N; i++){
            cin >> dat[i];
        }

        // solving logic
        bool vis[N+1] = {false};
        for(int i = 1; i <= N; i++) {
            bool needRecording = true;
            if(vis[i] == true) {continue;}
            vis[i] = true;

            stack<int> STK;
            STK.push(i);

            int cur, nxt;
            while(true){
                cur = STK.top();
                nxt = dat[cur];

                if(vis[nxt] == true) {
                    if(isInTeam[nxt] == true){needRecording = false; break;}
                    else break;
                }

                STK.push(nxt); vis[nxt] = true;
            }

            while(needRecording){
                int cur = STK.top(); STK.pop();
                isInTeam[cur] = true;
                result--;
                if(cur == nxt) break;
            }
        }

        int cnt = 0;
        for(int i = 1; i <= N; i++) cout << isInTeam[i] << ' ';
        cout << result << '\n';
    }
}