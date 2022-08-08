#include <iostream>
#include <algorithm>

using namespace std;

int N;
int MIN = 1000000000, MAX = -1000000000;

int num[13];
int opt[12];

void solve(int times, int val){
    if(times == N-1) {
        MIN = min(MIN, val); MAX = max(MAX, val);
        return;
    }

    times++;
    for(int type = 0; type < 4; type++) {
        if(opt[type] == 0) continue;

        opt[type]--;
        if(type == 0) {solve(times, val + num[times]);}
        else if(type == 1) {solve(times, val - num[times]);}
        else if(type == 2) {solve(times, val * num[times]);}
        else {solve(times, val / num[times]);}
        opt[type]++;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N;

    for(int i = 0; i < N; i++) cin >> num[i];
    for(int type = 0; type < 4; type++) cin >> opt[type];

    solve(0, num[0]);

    cout << MAX << '\n' << MIN; 
}