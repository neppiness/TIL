#include <bits/stdc++.h>
using namespace std;

const string VOWELS = "aeiou";

int n, m;
int noa[10'002];
int cnt[10'002];
bool al_is_used[26][10'002]; // [alpha][no];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (char c : s)
      al_is_used[c - 'a'][i] = 1;
    for (int j = 0; j < 26; j++)
      noa[i] += al_is_used[j][i];
  }

  for (int i = 0; i < n; i++)
    cnt[i] = noa[i];

  while (m--) {
    int co; char c;
    cin >> co >> c;
    switch(co) {
      int vowcheck;
      case 1 :
        vowcheck = VOWELS.find(c);
        if (vowcheck != -1) break;
        for (int i = 0; i < n; i++)
          cnt[i] -= al_is_used[c - 'a'][i];
        break;
      default: 
        for (int i = 0; i < n; i++)
          cnt[i] += al_is_used[c - 'a'][i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += (noa[i] == cnt[i]);
    cout << ans << '\n';
  }
}
