#include <bits/stdc++.h>
using namespace std;

const int MX = 40002;
const int PRSZ = 4205;
vector<int> prs, ans;
set<int> ans2;

int mxidx;
int cnt[PRSZ];
bool ispr[MX];

void pr() {
  fill(ispr, ispr + MX, 1);
  for(int i = 2; i < MX; i++) {
    if(!ispr[i]) continue;
    prs.push_back(i);
    for(int j = i; i*j < MX; j++)
      ispr[i*j] = 0;
  }
}

int gcd(int a, int b) {
  return a ? gcd(b%a, a) : b;
}

void div(int g) {
  int idx = 0;
  while(g != 1 && idx < MX) {
    int d = prs[idx];
    if(g % d == 0) {
      g /= d;
      ans.push_back(d);
      cnt[idx]++;
      mxidx = max(idx, mxidx);
      continue;
    }
    idx++;
  }
}

void makingans2(int mul) {
  for(int i = 0; i <= mxidx; i++) {
    if(!cnt[i]) continue;
    cnt[i]--;
    ans2.insert(prs[i] * mul);
    makingans2(prs[i] * mul);
    cnt[i]++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  pr();

  vector<int> a;
  int n; cin >> n;
  int x; cin >> x;
  a.push_back(x);
  while(--n) {
    int x; cin >> x;
    a.push_back(abs(x - a[0]));
  }

  int g = 0;
  for(int i = 1; i < a.size(); i++)
    g = gcd(g, a[i]);

  div(g);
  makingans2(1);
  
  for(auto it = ans2.begin(); it != ans2.end(); it++)
    cout << *it << ' ';
}
