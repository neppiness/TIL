#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if ((a == b) && (b == c)) cout << a*1000 + 10000;
    else if ((a == b) || (b == c) || (a == c)) cout << 1000+100*(a==c ? a : (b==c ? b: a));
    else cout << max({a,b,c}) * 100;
}