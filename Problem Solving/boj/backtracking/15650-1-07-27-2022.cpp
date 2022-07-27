#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int num[10];
bool isUsed[10];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> num[i];

    do {
        bool isDuplicated = false;
        for(int i = 0; i < M; i++) if(isUsed[i]) isDuplicated = true;
        if(isDuplicated) continue;

        for(int i = 0; i < M; i++) isUsed[i] = 1;
        for(int i = 0; i < M; i++) cout << num[i] << ' ';
        cout << '\n';
        
    } while(next_permutation(num, num + M));
}