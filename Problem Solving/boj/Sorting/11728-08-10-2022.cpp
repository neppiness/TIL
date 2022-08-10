#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    int N, M; cin >> N >> M;

    int a[N], b[M];

    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];

    int aidx = 0, bidx = 0;
    while(aidx != N && bidx != M) {
        if(a[aidx] >= b[bidx]) cout << b[bidx++] << ' ';
        else cout << a[aidx++] << ' ';
    }
    for(int i = aidx; i < N; i++) cout << a[i] << ' ';
    for(int i = bidx; i < M; i++) cout << b[i] << ' ';
}