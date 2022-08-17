#include <iostream>
using namespace std;

int N;
int ans[102][10]; // ans[level][num]
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for(int num = 1; num < 10; num++) ans[1][num] = 1;

    for(int lev = 1; lev < N; lev++) {
        for(int num = 0; num < 10; num++) {
            if(num - 1 >= 0) ans[lev+1][num-1] = (ans[lev+1][num-1]  + ans[lev][num])%1000000000;
            if(num + 1 < 10) ans[lev+1][num+1] = (ans[lev+1][num+1] + ans[lev][num])%1000000000;
        }
    }

    int ret = 0;
    for(int num = 0; num < 10; num++) {ret += ans[N][num]; ret%=1000000000;}
    cout << ret;
}