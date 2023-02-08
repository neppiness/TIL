#include <bits/stdc++.h>
using namespace std;

vector<int> perm;
string s[10];

int used, ans, n;
int apb_id[26];

int toInt(char c) { return c - 'A'; }

void solve() {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    string &str = s[i];
    int tmp = 0;
    for(char c : str) {
      tmp *= 10;
      tmp += perm[apb_id[toInt(c)]];
    }
    sum += tmp;
  }
  ans = max(sum, ans);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(apb_id, -1, sizeof(apb_id));

  for(int i = 0; i < 10; i++)
    perm.push_back(i);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> s[i];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < s[i].size(); j++) {
      int &id = apb_id[toInt(s[i][j])];
      if(id == -1) id = used++;
    }
  do { solve(); } while(next_permutation(perm.begin(), perm.end()));
  cout << ans;
}