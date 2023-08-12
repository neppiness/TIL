#include <bits/stdc++.h>
using namespace std;

int n, ans = -0x7fffffff;
string eq;

list<int> no_origin, no;
vector<bool> par_origin; list<bool> par;
list<char> op_origin, op;

void solve() {
  auto vit = par_origin.begin();
  auto lit = par.begin();
  while (vit != par_origin.end() && lit != par.end())
    (*(lit++)) = (*(vit++));

  op = op_origin;
  no = no_origin;

  auto pit = par.begin();
  auto nit = no.begin();
  auto oit = op.begin();
  while (pit != par.end()) {
    if (*pit) {
      int tmp = *nit;
      nit++;
      if (*oit == '*') tmp *= *(nit--);
      else if (*oit == '/') tmp /= *(nit--);
      else if (*oit == '+') tmp += *(nit--);
      else tmp -= *(nit--);
      *(nit++) = tmp;
      no.erase(nit);
    }
    oit++; pit++;
  }
}

void setup(int lv, int st) {
  if (lv == 0) { solve(); return; }

  for (int i = st; i < n/2; i++) {
    if (par_origin[st]) continue;
    par_origin[i] = 1;
    par_origin[i + 1] = 1;
    setup(lv - 1, i + 2);
    par_origin[i] = 0;
    par_origin[i + 1] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> eq;
  par_origin.resize(n/2 + 1);
  par.resize(n/2 + 1);

  for (int i = 0; i < eq.size(); i++) {
    if (i % 2) op.push_back(eq[i]);
    else no.push_back(eq[i]);
  }

  // 괄호는 최대 n/2개
  for (int i = 0; i <= n/2; i++)
    setup(i, 0);

  cout << ans;
}