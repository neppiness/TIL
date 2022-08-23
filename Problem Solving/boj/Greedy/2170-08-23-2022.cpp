#include <iostream>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;

pair<int,int> coord[1000001];
int N; int a, b;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        coord[i] = {a,b};
    }

    sort(coord, coord + N);

    int ans = 0;
    int A = coord[0].X, B = coord[0].Y;
    for(int i = 1; i < N; i++) {
        if(coord[i].X <= B) B = max(B, coord[i].Y);
        else {
            ans += (B - A);
            A = coord[i].X;
            B = coord[i].Y;
        }
    }
    ans += (B - A);
    cout << ans;
}