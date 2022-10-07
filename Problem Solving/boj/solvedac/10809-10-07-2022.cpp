#include <bits/stdc++.h>
using namespace std;

int a[26];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(a, a + 26, -1);

  string s; cin >> s;
  for(int i = 0; i < s.size(); i++)
    if(a[s[i] - 'a'] == -1) a[s[i] - 'a'] = i;
    
  for(int i = 0; i < 26; i++) cout << a[i] << ' ';
}