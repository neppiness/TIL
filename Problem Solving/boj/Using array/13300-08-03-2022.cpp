#include <iostream>

using namespace std;

int N, K;

int student[2][7] = {0};

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> K;

    int S, Y;
    for(int i = 0; i < N; i++){
        cin >> S >> Y;
        student[S][Y]++;
    }

    int ans = 0;
    for(int s = 0; s <= 1; s++) {
        for(int y = 1; y <= 6; y++) {
            if(!student[s][y]) continue;
            ans += (student[s][y] - 1) / K + 1;
        }
    }

    cout << ans;
}