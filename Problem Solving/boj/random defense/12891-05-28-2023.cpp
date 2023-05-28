#include <bits/stdc++.h>
using namespace std;

int cnt[4], req[4];

int s, p, ans;
string str;

int ctoi(char c) {
  if (c == 'A') return 0;
  if (c == 'C') return 1;
  if (c == 'G') return 2;
  return 3;
}

bool check() {
  for (int i = 0; i < 4; i++)
    if (req[i] > cnt[i]) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int st = 0, en = 0;
  cin >> s >> p >> str;

  for (int i = 0; i < 4; i++)
    cin >> req[i];
  
  while (en < p)
    cnt[ctoi(str[en++])]++;
  
  while (en < s) {
    ans += check();
    cnt[ctoi(str[en++])]++;
    cnt[ctoi(str[st++])]--;
  }
  ans += check();

  cout << ans;
}