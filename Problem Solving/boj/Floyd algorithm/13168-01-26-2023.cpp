#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

unordered_map<string, int> city_to_id;
int citycnt = 0;

vector<int> dest; // destination
int d[2][MX + 2][MX + 2]; // d[is_railro][u][v] = (cost for u to v)

int trans_code(string &str) {
  if(str[0] == 'S' && str[1] == '-') return 1; // S-train: 50% 할인
  else if(str[0] == 'V') return 1; // V-train: 50% 할인
  else if(str[0] == 'I' || str[0] == 'M') return 2; // ITX, 무궁화: 공짜
  return 0; // 가격 변동 없음
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, diff;
  cin >> n >> diff;
  diff *= 2;
  for(int i = 0; i < n; i++) {
    string name; cin >> name;
    auto it = city_to_id.find(name);
    if(it == city_to_id.end()) 
      city_to_id[name] = citycnt++;
  }

  cin >> n;
  for(int i = 0; i < n; i++) {
    string name; cin >> name;
    dest.push_back(city_to_id[name]);
  }

  memset(d, 0x3f, sizeof(d));
  for(int i = 0; i < citycnt; i++) {
    d[0][i][i] = 0;
    d[1][i][i] = 0;
  }

  cin >> n;
  for(int i = 0; i < n; i++) {
    string tr, uname, vname; int cost;
    cin >> tr >> uname >> vname >> cost;
    cost *= 2;
    int u = city_to_id[uname];
    int v = city_to_id[vname];

    cost = min(d[0][u][v], cost);
    d[0][u][v] = d[0][v][u] = cost;

    int trcode = trans_code(tr);
    if(trcode == 1) cost /= 2;
    else if(trcode == 2) cost = 0;

    cost = min(d[1][u][v], cost);
    d[1][u][v] = d[1][v][u] = cost;
  }

  for(int k = 0; k < citycnt; k++)
    for(int i = 0; i < citycnt; i++)
      for(int j = 0; j < citycnt; j++)
        for(int m = 0; m < 2; m++)
          d[m][i][j] = min(d[m][i][j], d[m][i][k] + d[m][k][j]);

  for(int i = 1; i < dest.size(); i++) {
    int u = dest[i - 1];
    int v = dest[i];
    diff -= d[0][u][v];
    diff += d[1][u][v];
  }

  if(diff < 0) cout << "Yes";
  else cout << "No";
}