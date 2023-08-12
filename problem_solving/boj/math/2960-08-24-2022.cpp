#include <iostream>
using namespace std;

int N, K;
bool visit[1002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    
    int cnt = 0;
    for(int i = 2; i <= N; i++) {
        int num = i;
        while(num <= N) {
            if(!visit[num]) {
                visit[num] = 1;
                cnt++;
                if(cnt == K) {cout << num; return 0;}
            }
            num += i;
        }
    }
}