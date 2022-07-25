#include <iostream>

using namespace std;

int minusOne = 0, zero = 0, one = 0;
int N;
int board[2187][2187];

void search(int n, int x, int y){
    int a = board[x][y];
    bool isValid = true;
    for(int i = x; i < x + n;i++)
        for(int j = y; j < x + n; j++) {
            if(a != board[i][j]) {
                isValid = false;
                for(int p = x; p < x + n; p += n/3)
                    for(int q = y; q < y + n; q += n/3) search(n/3, p, q);
            }
    }

    if(isValid) {
        if(a == -1) minusOne++;
        else if(a == 0) zero++;
        else one++;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) cin >> board[i][j];

    search(N, 0, 0);

    cout << minusOne << '\n';
    cout << zero << '\n';
    cout << one << '\n';
}