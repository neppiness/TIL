#include <iostream>
#include <algorithm>
using namespace std;

int N;
int SQN[100002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    SQN[0] = 0; SQN[1] = 1;
    fill(SQN+2, SQN+N+1, 0x7f7f7f7f);

    for(int n = 2; n <= N; n++) {
        int i = 1;
        while(i*i <= n) {
            int x = n - i*i; i++;
            SQN[n] = min(SQN[n], SQN[x] + 1);
        }
    }
    cout << SQN[N];
}