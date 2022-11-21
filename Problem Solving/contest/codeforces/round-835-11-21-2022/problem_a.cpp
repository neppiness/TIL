#include <bits/stdc++.h>
using namespace std;

int t;
int table[3];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) {
    int a, b, c;
    cin >> a >> b >> c;
    table[0] = a;
    table[1] = b;
    table[2] = c;
    sort(table, table + 3);
    cout << table[1] << '\n';
  }
}