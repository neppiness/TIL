#include <bits/stdc++.h>
using namespace std;

int path[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int res_path[8];
int cost[10][10];
int res = 0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int u, v, co;
  cin >> u >> v >> co;
  while(u != 0) {
    cost[u][v] = co;
    cost[v][u] = co;
    cin >> u >> v >> co;
  }

  chrono::high_resolution_clock::time_point st
      = chrono::high_resolution_clock::now();

  do {
    int tmp = cost[1][path[0]] + cost[path[7]][1];
    for(int i = 1; i < 8; i++) {
      int prv = path[i - 1];
      int cur = path[i];
      tmp += cost[prv][cur];
    }
    if(res < tmp) continue;
    res = tmp;
    for(int i = 0; i < 8; i++)
      res_path[i] = path[i];
  } while(next_permutation(path, path + 8));

  chrono::high_resolution_clock::time_point en
      = chrono::high_resolution_clock::now();

  chrono::duration<double> time_span
      = chrono::duration_cast<chrono::duration<double>>(en - st);

  cout << res << '\n';
  cout << 1;
  for(int i = 0; i < 8; i++)
    cout << res_path[i];
  cout << 1 << '\n';
  cout << "Duration: " << time_span.count()*1000 << " ms";
}

/*
INPUT

1 2 22020
1 3 34650
1 4 20640
1 5 18350
1 6 17550
1 7 10500
1 8 18000
1 9 8700

2 3 32770
2 4 13050
2 5 18500
2 6 10300
2 7 18500
2 8 43350
2 9 23950

3 4 34750
3 5 39650
3 6 34250
3 7 26300
3 8 54850
3 9 44750

4 5 14800
4 6 27400
4 7 15200
4 8 46600
4 9 30400

5 6 15100
5 7 17200
5 8 40600
5 9 22500

6 7 13900
6 8 37900
6 9 19200

7 8 31400
7 9 11900

8 9 36700
0 0 0
*/