#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1'000'000;
const int ROOT = 1;

int n, m, k;
int i, j, idx;
ll sum[4*MX + 2], a[MX + 2], tar;

ll init(int st, int en, int node) {
  if(st == en) return sum[node] = a[st]; // base case
  int mid = (st + en) / 2;
  return sum[node] = init(st, mid, node * 2) + init(mid + 1, en, node * 2 + 1);
}

ll update(int st, int en, int node) {
  if(idx < st || en < idx) return sum[node];
  if(st == en) return sum[node] = tar;
  int mid = (st + en) / 2;
  return sum[node] = update(st, mid, node * 2) + update(mid + 1, en, node * 2 + 1);
}

ll calcAndPr(int st, int en, int node) {
  if(st > j || en < i) return 0;
  if(i <= st && en <= j) return sum[node];
  int mid = (st + en) / 2;
  return calcAndPr(st, mid, node * 2) + calcAndPr(mid + 1, en, node * 2 + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++)
    cin >> a[i];

  init(1, n, ROOT);

  m += k;
  int code;
  while(m--) {
    cin >> code;
    if(code == 1) {
      // idx번째 숫자를 tar로 바꾸고 세그 트리 노드 갱신
      cin >> idx >> tar;
      update(1, n, ROOT);
    } else {
      // i번째부터 j번째 부분 합 출력
      cin >> i >> j;
      cout << calcAndPr(1, n, ROOT) << '\n'; 
    }
  }
}