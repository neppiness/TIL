#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; getline(cin, s);
  
  for (char c : s) {
    if (islower(c)) cnt[c - 'a']++;
    else if (isupper(c)) cnt[c - 'A']++;
  }

  for (int i = 0; i < 26; i++) {
    char h = (char)(i + 'A');
    cout << h << " | ";
    while (cnt[i]--)
      cout << '*';
    cout << '\n';
  }
}
