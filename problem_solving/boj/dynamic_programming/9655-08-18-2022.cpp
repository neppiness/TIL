#include <iostream>
using namespace std;

bool winner[1002]; // 0: SK, 1: CY, 1-indexed

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    winner[0] = 1; winner[2] = 1;
    int N; cin >> N;
    for(int i = 4; i <= N; i++) winner[i] = winner[i-4];

    if(winner[N]) cout << "CY";
    else cout << "SK";
}