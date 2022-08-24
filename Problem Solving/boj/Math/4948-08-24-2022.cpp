#include <iostream>
using namespace std;

bool check[250002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    while(n != 0) {
        int cnt = 0;

        for(int i = 2; i <= 2*n; i++) {
            if(!check[i]) {
                check[i] = 1;
                for(int j = 2; i*j <= 2*n; j++) check[i*j] = 1;
                if(i > n) cnt++;
            }
        }
        cout << cnt << '\n';
        fill(check, check + 2*n + 1, 0);
        cin >> n;
    }
}