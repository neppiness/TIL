#include <bits/stdc++.h>
using namespace std;

int al[26];
int gr[] = {3, 6, 9, 12, 15, 19, 22, 26};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a = 0;
  for(int i = 0; i < 8; i++)
    for(; a < gr[i]; a++)
      al[a + 'A'] = (i + 2) + 1;

  string s; cin >> s;
  int sum = 0;
  for(char c : s)
    sum += al[c];
    cout << sum;
}