#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int mm[102][102][102];

int w(int a, int b, int c) {
  int A = a + 50;
  int B = b + 50;
  int C = c + 50;

  if(mm[A][B][C] != INF) return mm[A][B][C];
  if(a <= 0 || b <= 0 || c <= 0) return mm[A][B][C] = 1;
  if(a > 20 || b > 20 || c > 20) {
    if(mm[70][70][70] != INF) return mm[70][70][70];
    mm[70][70][70] = w(20, 20, 20);
    return mm[70][70][70];
  }

  if(a < b && b < c) {
    int &p = mm[A][B][C - 1];
    int &q = mm[A][B - 1][C - 1];
    int &r = mm[A][B - 1][C];
    if(p == INF) p = w(a, b, c - 1);
    if(q == INF) q = w(a, b - 1, c - 1);
    if(r == INF) r = w(a, b, c - 1);
    return p + q - r;
  }

  int &p = mm[A - 1][B][C];
  int &q = mm[A - 1][B - 1][C];
  int &r = mm[A - 1][B][C - 1];
  int &s = mm[A - 1][B - 1][C - 1];
  if(p == INF) p = w(a - 1, b, c);
  if(q == INF) q = w(a - 1, b - 1, c);
  if(r == INF) r = w(a - 1, b, c - 1);
  if(s == INF) s = w(a - 1, b - 1, c - 1);
  return p + q + r - s;
}

int main() {
  memset(mm, INF, sizeof(mm));

  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  while(a != -1 || b != -1 || c != -1) {
    printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    scanf("%d %d %d", &a, &b, &c);
  }
}