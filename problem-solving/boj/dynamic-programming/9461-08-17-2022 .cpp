#include <iostream>

using namespace std;

long long P[101] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i = 0; i < N; i++) if(!P[i]) P[i] = P[i-1] + P[i-5];
        cout << P[N-1] << '\n';
    }
}