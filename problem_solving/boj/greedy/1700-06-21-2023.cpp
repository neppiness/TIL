#include <bits/stdc++.h>
using namespace std;

const int kMax = 101;
int ans, n, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  int a[k], pl[n] = {};
  for (int i = 0; i < k; i++)
    cin >> a[i];

  for (int i = 0; i < k; i++) { // i: 전기 용품 사용 시퀀스 인덱스
    int cur = a[i]; // 현재 넣고자 하는 전기 용품 번호

    bool is_plugged = 0;
    // 이미 플러그에 동일한 전기 용품이 꽂혀 있는 경우 처리
    // j: 플러그 번호, pl[j]: j번 플러그에 꽂힌 전기 용품 번호
    for (int j = 0; j < n; j++) {
      if (pl[j] != cur) continue;
      is_plugged = 1; break;
    }
    if (is_plugged) continue;

    // 플러그가 비어 있는 경우 꽂아버림
    for (int j = 0; j < n; j++) {
      if (pl[j]) continue;
      pl[j] = cur; is_plugged = 1; break;
    }
    if (is_plugged) continue;

    // 플러그가 가득 찬 경우 가장 늦게 사용되는 전기 용품을 뽑음
    // nxt는 전기 용품이 가장 빠르게 사용되는 시기를 기록하는 배열
    int nxt[k + 1] = {};
    fill(nxt, nxt + k + 1, kMax);
    for (int ii = i + 1; ii < k; ii++) { // ii: 전기 용품 사용 시퀀스 보조 인덱스
      int chk = a[ii];
      nxt[chk] = min(nxt[chk], ii);
    }

    // 사용하게 되는 순번과 그 플러그 번호를 저장.
    int mx = 0, tmp = 0;
    for (int j = 0; j < n; j++) {
      if (nxt[pl[j]] <= mx) continue;
      mx = nxt[pl[j]]; tmp = j;
    }
    pl[tmp] = cur; ans++;
  }
  cout << ans;
}