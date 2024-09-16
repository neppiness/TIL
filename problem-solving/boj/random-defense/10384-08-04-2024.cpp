#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();
  for (int i = 1; i <= n; i++) {
    int a[26] = {};
    string s; getline(cin, s);
    for (char &c : s) {
      if (c >= 'a' && c <= 'z') {
        a[c - 'a']++;
      } else if (c >= 'A' && c <= 'Z') {
        a[c - 'A']++;
      }
    }
    int mn = 3;
    for (int j = 0; j < 26; j++) {
      mn = min(mn, a[j]);
    }
    cout << "Case " << i << ": ";
    switch (mn) {
      case 0: 
        cout << "Not a pangram" << '\n';
        break;
      case 1: 
        cout << "Pangram!" << '\n';
        break;
      case 2: 
        cout << "Double pangram!!" << '\n';
        break;
      case 3: 
        cout << "Triple pangram!!!" << '\n';
        break;
      default:
        break;
    }
  }
}
