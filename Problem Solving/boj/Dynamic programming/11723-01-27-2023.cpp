#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 20) - 1;
int bits;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  while(m--) {
    string str;
    cin >> str;
    if(str == "all") { bits = MX; continue; }
    else if(str[0] == 'e') { bits = 0; continue; }

    int x; cin >> x;
    x = (1 << (x - 1));

    if(str[0] == 'r') { bits &= ~x; }
    else if(str[0] == 'c') { cout << (bool)(bits & x) << '\n'; }
    else if(str[0] == 't') { bits ^= x; }
    else { bits |= x; }
  }
}