#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[1002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    sort(num, num+N);

    int ans = 0;
    for(int i = 0; i < N; i++) ans += (N-i) * num[i];
    cout << ans;
}