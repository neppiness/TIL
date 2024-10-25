#include <bits/stdc++.h>
using namespace std;

int n, l, d; 
int song_cycle;
int bell_cycle;

bool getCanHear(int t) {
  if (t / song_cycle >= n) return 1;
  return t % song_cycle >= song_cycle - 5;
}

bool getBellRing(int t) {
  return t % d == 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l >> d;
  // 전화벨 주기 d
  // 노래 주기 L + 5
  // n곡이니까 L + 5로 나눈 몫이 n보다 크다면 항상 받을 수 있는 것
  song_cycle = l + 5;
  bell_cycle = d + 1;

  int t = 1;
  while (1) {
    bool can_hear = getCanHear(t);
    bool bell_ring = getBellRing(t);
    if (getCanHear(t) && getBellRing(t)) {
      cout << t; return 0;
    }
    t++;
  }
}
