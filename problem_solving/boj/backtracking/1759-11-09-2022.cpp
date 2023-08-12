#include <bits/stdc++.h>
using namespace std;

int len, noChar;
bool comb[17];
int vow, conso;

vector<char> chars;
char ans[17];

bool isvow(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> len >> noChar;

  char c;
  for(int i = 0; i < noChar; i++) {
    cin >> c;
    chars.push_back(c);
  }

  for(int i = 0; i < len; i++)
    comb[i] = 1;

  sort(chars.begin(), chars.end());

  int lev;
  do {
    vow = conso = lev = 0;
    for(int i = 0; i < noChar; i++) {
      if(comb[i]) {
        ans[lev++] = chars[i];
        vow += isvow(chars[i]);
        conso += !isvow(chars[i]);
      }
    }
    if(vow >= 1 && conso >= 2) {
      for(int i = 0; i < lev; i++)
        cout << ans[i];
      cout << '\n';
    }
  } while(prev_permutation(comb, comb + noChar));
}