#include <bits/stdc++.h>
using namespace std;

vector<int> pr;
bool ispr[202];

void init() {
  fill(ispr + 2, ispr + 202, 1);
  for(int p = 2; p < 202; p++) {
    if(!ispr[p]) continue;
    pr.push_back(p);
    for(int q = p; p * q < 202; q++)
      ispr[p * q] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  init();
  for(int i = 1; i < 202; i++) {
    if(pr[i] * pr[i - 1] <= n) continue;
    cout << pr[i] * pr[i - 1];
    return 0;
  }
}