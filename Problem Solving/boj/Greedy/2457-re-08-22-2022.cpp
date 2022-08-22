#include <algorithm>
#include <iostream>
#include <utility>

#define X first
#define Y second

using namespace std;

int N;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
pair<int,int> DAT[100002];
pair<int,int> G = {60, 335};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;

        for(int i = 0; i < m1 - 1; i++) d1 += days[i];
        for(int i = 0; i < m2 - 1; i++) d2 += days[i];

        DAT[i] = {max(G.X, d1), min(G.Y, d2)};
    }

    sort(DAT, DAT+N);

    int cnt = 0;
    int endDay = 0;
    for(int i = 0; i < N; i++) {
        if(G.X >= DAT[i].X) {
            endDay = max(endDay, DAT[i].Y);
            if(endDay >= G.Y) {cout << ++cnt; return 0;}
        } else {
            G.X = endDay;
            cnt++; i--;
        }
    }
    cout << 0;
}