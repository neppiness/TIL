#include <iostream>
using namespace std;

int P, L, V;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> L >> P >> V;
    int i = 1;
    while(P != 0 || L != 0 || V != 0) {
        cout << "Case " << i++ << ": " << (V/P * L + min(V%P, L)) << '\n';
        cin >> L >> P >> V;
    }
}