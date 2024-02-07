#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int noCases;

    cin >> noCases;

    while(noCases--){
        // input
        int result = 0;

        int N; cin >> N;
        int graph[N+1]; graph[0] = 0;

        for(int i = 1; i <= N; i++){
            cin >> graph[i];
        }

        bool vis[N+1]={false};
        int cnt = 0;

        // searching
        for(int i = 1; i <= N; i++){
            stack<int> STK;

            if(vis[i] == false) {STK.push(i); vis[i] = true;}
            else continue;

            while(true) {
                int cur = STK.top();
                int nxt = graph[cur];

                if(vis[nxt] == true) {
                    if(nxt == i) cnt += STK.size();
                    else {
                        while(!STK.empty()) {
                            int del = STK.top();
                            vis[del] = false;
                            STK.pop();
                        }
                    }
                    break;
                } 
                vis[nxt] = true;
                STK.push(nxt);
            }
        }
        result = N - cnt;

        cout << result << '\n';
    }
}