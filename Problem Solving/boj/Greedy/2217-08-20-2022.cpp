#include <iostream>
#include <algorithm>
using namespace std;

int N;
int R[100002];

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> R[i];

    sort(R, R+N, cmp);
    int MX = 0;
    
    for(int i = 0; i < N; i++) MX = max(R[i] * (i+1), MX);
    cout << MX;
}