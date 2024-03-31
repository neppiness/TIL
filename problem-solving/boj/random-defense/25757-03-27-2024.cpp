#include <bits/stdc++.h>
using namespace std;

const string GAME = "YFO";

unordered_map<string, bool> chk;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; string g;
  cin >> n >> g;
  int div = GAME.find(g) + 1;

  for (int i = 0; i < n; i++) {
    string id; cin >> id;
    chk[id] = 1;
  }
  cout << chk.size() / div;
}
