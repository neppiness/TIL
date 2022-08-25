#include <iostream>
using namespace std;

int A, B;
int num[1002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int no = 1, idx = 1;
    while(1) {
        int limit = no;
        while(limit--) {
            num[idx++] = no;
            if(idx > 1000) break;
        }
        if(idx > 1000) break;
        no++;
    }

    cin >> A >> B;

    int ans = 0;
    for(int i = A; i <= B; i++) ans += num[i];
    cout << ans;
}