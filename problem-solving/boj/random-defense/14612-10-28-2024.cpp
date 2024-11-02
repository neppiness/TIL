#include <bits/stdc++.h>
using namespace std;

int timing[1002];
vector<int> v; 

bool cmp(int &a, int &b) {
  if (timing[a] == timing[b]) {
    return a < b;
  }
  return timing[a] < timing[b];
}

void print() {
  if (v.size() == 0) {
    cout << "sleep";
  } else {
    for (int x : v) cout << x << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q, m; cin >> q >> m;
  while (q--) {
    string s; cin >> s;
    if (s == "sort") {
      sort(v.begin(), v.end(), cmp);
    } else if (s == "order") {
      int n, t; cin >> n >> t;
      timing[n] = t;
      v.push_back(n);
    } else {
      int n; cin >> n;
      for (int i = 0; i < v.size(); i++) {
        if (v[i] != n) continue;
        v.erase(v.begin() + i);
        break;
      }
    }
    print();
  }
}
