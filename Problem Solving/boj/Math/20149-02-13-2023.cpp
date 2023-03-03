#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll deno;

struct vec {
  ll x, y;
  explicit vec(ll x_ = 0, ll y_ = 0): x(x_), y(y_) {}

  vec operator -(vec r) { return vec(x - r.x, y - r.y); }
  bool operator <(vec &r) { return (x != r.x ? x < r.x : y < r.y); }
  bool operator ==(vec &r) { return ((x == r.x) && (y == r.y)); }

  ll cross(vec r) { return (x * r.y - y * r.x); }
} v[5], v21, v31, v43; // v1, v2, v3, v4로 1-indexed 인덱싱

void printAns(vec &v_ans) {
  cout << 1 << '\n';
  cout << v_ans.x << ' ' << v_ans.y;
}

void solveCaseNp() {
  // p, q가 0이상 1이하면 교점 출력
  // 그렇지 않다면 만나지 않는다고 결과 출력.
  ll nu_p = v31.cross(v43);
  ll nu_q = v31.cross(v21);

  if((nu_p != 0) && (signbit(deno) != signbit(nu_p))) cout << 0;
  else if((nu_q != 0) && (signbit(deno) != signbit(nu_q))) cout << 0;
  else if(abs(deno) < abs(nu_p) || abs(deno) < abs(nu_q)) cout << 0;
  else {
    double p = (double)nu_p / (double)deno;
    double ans_x = v[1].x + p*(v21.x);
    double ans_y = v[1].y + p*(v21.y);
    cout << 1 << '\n';
    cout << ans_x << ' ' << ans_y;
  }
}

void solveCaseP() { 
  ll area_213 = abs(v31.cross(v21));
  // 일직선 상에 있지 않은 경우.
  if(area_213 != 0) { cout << 0; return; }
  
  // 선분이 일직선 상에 있음
  // 점 위치 대소비교 후, 위치에 따라 답을 출력함.
  if(v[4] < v[1] || v[2] < v[3]) cout << 0;
  else if(v[2] == v[3]) printAns(v[2]);
  else if(v[1] == v[4]) printAns(v[1]);
  else cout << 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(10);
  cout << fixed;

  for(int i = 1; i <= 4; i++) {
    ll x, y; cin >> x >> y;
    tie(v[i].x, v[i].y) = {x, y};
  }

  if(v[2] < v[1]) swap(v[1], v[2]);
  if(v[4] < v[3]) swap(v[3], v[4]);
  
  v21 = v[2] - v[1]; // 점 1에서 점 2로 가는 방향 벡터
  v31 = v[3] - v[1]; // 점 1에서 점 3으로 가는 방향 벡터
  v43 = v[4] - v[3]; // 점 3에서 점 4로 가는 방향 벡터

  deno = v21.cross(v43);
  if(deno != 0) solveCaseNp(); // 두 방향 벡터가 평행하지 않은 경우
  else solveCaseP(); // 두 방향 벡터가 평행한 경우
}