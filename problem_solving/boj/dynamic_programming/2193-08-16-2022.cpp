#include <iostream>
using namespace std;

int N;
long long PN[92];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    PN[0] = 1; // 0
    PN[1] = 1; PN[2] = 1; // the number of single and double digit pinary numbers

    if(N < 3) {cout << PN[N]; return 0;}

    for(int i = 3; i <= N; i++)
        for(int j = 0; j <= i-2; j++) PN[i] += PN[j];

    cout << PN[N]; return 0;
}