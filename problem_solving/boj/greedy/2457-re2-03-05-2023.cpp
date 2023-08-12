#include <bits/stdc++.h>
using namespace std;

const int DAYS[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int LLIM = DAYS[3] + 1;
const int ULIM = DAYS[12] + 1;

vector<pair<int, int>> fl;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for(int i = 0; i < n; i++) {
    int sm, sd, em, ed;
    cin >> sm >> sd >> em >> ed;

    int stday = DAYS[sm] + sd;
    int edday = DAYS[em] + ed;

    stday = max(stday, LLIM);
    edday = min(edday, ULIM);
    if(edday <= LLIM) continue;
    fl.push_back({stday, edday});
  }
  fl.push_back({0, LLIM});
  sort(fl.begin(), fl.end());

  if(fl[0].first > LLIM) { cout << 0; return 0; }

  int cured = fl[0].second; // 현재 고른 꽃이 지는 날
  int tmped = -1; // 다음에 고르게 될 꽃이 지는 날
  int i = 1, ans = 0;
  while(i <= n) {
    auto [nxtst, nxted] = fl[i];
    if(nxtst <= cured) {
      // 확인 중인 꽃의 피는 날이 현재 고른 꽃의 지는 날보다 작거나 같은 경우
      // 꽃이 지는 날을 tmped 변수에 최댓값으로 갱신해둠
      tmped = max(tmped, nxted);
      i++;
      if(nxted == ULIM) { cout << ans + 1; return 0; }
    } else {
      // 확인 중인 꽃의 피는 날이 현재 고른 꽃의 지는 날보다 늦은 경우
      // 이전까지 골랐던 꽃이 없다면(tmp == -1) 0을 출력하고 main 함수 종료
      // 이전에 골라둔 가장 늦게 지는 꽃이 있었다면 cured를 갱신하고 tmp는 초기화
      // 꽃을 하나 더 골랐으므로 ans값 증가
      // 인덱스는 유지하여 해당 꽃에 대한 판단을 한 번 더 해야함.
      if(tmped == -1) { cout << 0; return 0; }
      cured = tmped;
      tmped = -1;
      ans++;
    }
  }
  cout << 0;
}