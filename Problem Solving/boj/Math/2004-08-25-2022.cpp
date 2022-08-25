#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int no5;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    int k = n - m;

    int M = min(k,m);

    int i = n;
    while(i % 5 != 0) i--;
    for(;i > n - M; i -= 5) {
        int num = i;
        while(num % 5 == 0) {no5++; num /= 5;}
    }

    for(int i = 2; i <= M; i += 5) {
        int num = i;
        while(num % 5 == 0) {no5--; num /= 5;}
    }
    cout << no5;
}