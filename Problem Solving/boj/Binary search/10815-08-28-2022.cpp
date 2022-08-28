#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int n[500002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> n[i];
    sort(n, n+N);

    cin >> M;
    while(M--) {
        int a; cin >> a;
        cout << binary_search(n, n+N, a) << ' ';
    }
}