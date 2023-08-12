#include <iostream>
using namespace std;

int ans[502][2];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    
    ans[0][0] = ans[0][1] = 0;
    for(int i = 1; i <= N; i++) {
        ans[i][0] = ans[i-1][0];
        ans[i][1] = ans[i-1][1];
        int num = i;
        while(num % 2 == 0) {ans[i][0]++; num /= 2;}
        while(num % 5 == 0) {ans[i][1]++; num /= 5;}
    }
    cout << min(ans[N][0], ans[N][1]);
}