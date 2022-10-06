#include <bits/stdc++.h>
using namespace std;

long long a = 0, b = 1, c = 1;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  


  long long n; cin >> n;
  if(n == 1) cout << b;
  else if(n == 2) cout << c;
  else {
    n -= 2;
    while(n--) {
      a = (b + c) % 1'000'000'007;
      swap(a, b);
      swap(b, c);
    }
    cout << c;
  }
}