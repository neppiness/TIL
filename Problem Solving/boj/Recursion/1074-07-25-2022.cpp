#include <iostream>

using namespace std;

int cnt = 0;

int zSearch(int N, int r, int c){
    int inc = (1 << (N-1));
    
    int R = r/inc, C = c/inc;

    if(R == 0) {
        if(C == 1) cnt += inc * inc;
    } else {
        if(C == 0) cnt += 2*inc*inc;
        else cnt += 3*inc*inc;
    }
    if(N == 1) return cnt;
    else return zSearch(N-1, r%inc, c%inc);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, r, c; cin >> N >> r >> c;

    cout << zSearch(N, r, c);
}