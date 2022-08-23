#include <iostream>
using namespace std;

bool isPrime(int n){
    int a = 2;
        while(a*a <= n) {
            if(n%a == 0) return false;
            a++;
        }
    return true;
}

int main(){
    ios::sync_with_stdio(0);

    int N; cin >> N;
    int cnt = 0;

    while(N--) {
        int num; cin >> num;
        if(num == 1) continue;
        if(isPrime(num)) cnt++;
    }

    cout << cnt;
}