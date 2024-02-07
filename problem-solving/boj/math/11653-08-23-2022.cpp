#include <iostream>
using namespace std;

int N;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if(N == 1) return 0;
    int num = N;
    for(int i = 2; i <= N; i++) {
        if(num%i == 0) {
            cout << i << '\n';
            num /= i; i--;
        }
    }
}