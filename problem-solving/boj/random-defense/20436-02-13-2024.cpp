#include <bits/stdc++.h>
using namespace std;

const string L_RANGE = "qwertasdfgzxcv";

pair<int, int> coord[26];
string s; 

int to_index(char c) {
  return c - 'a';
}

int solve(int l_index, int r_index, int seq) {
  if (seq == s.size()) return 0;

  char c = s[seq];
  int dest_index = to_index(c);
  pair<int, int> dest_coord = coord[dest_index];
  int pos = L_RANGE.find(c);

  // 왼손이 처리해야 하는 경우
  if (pos != -1) {
    pair<int, int> l_coord = coord[l_index];
    int dist = abs(l_coord.first - dest_coord.first)
        + abs(l_coord.second - dest_coord.second);
    return solve(dest_index, r_index, seq + 1) + dist;
  }
  // 오른손이 처리해야 하는 경우
  pair<int, int> r_coord = coord[r_index];
  int dist = abs(r_coord.first - dest_coord.first)
      + abs(r_coord.second - dest_coord.second);
  return solve(l_index, dest_index, seq + 1) + dist;
}

void setup() {
  coord[to_index('q')] = {0, 0};
  coord[to_index('w')] = {0, 1};
  coord[to_index('e')] = {0, 2};
  coord[to_index('r')] = {0, 3};
  coord[to_index('t')] = {0, 4};
  coord[to_index('y')] = {0, 5};
  coord[to_index('u')] = {0, 6};
  coord[to_index('i')] = {0, 7};
  coord[to_index('o')] = {0, 8};
  coord[to_index('p')] = {0, 9};

  coord[to_index('a')] = {1, 0};
  coord[to_index('s')] = {1, 1};
  coord[to_index('d')] = {1, 2};
  coord[to_index('f')] = {1, 3};
  coord[to_index('g')] = {1, 4};
  coord[to_index('h')] = {1, 5};
  coord[to_index('j')] = {1, 6};
  coord[to_index('k')] = {1, 7};
  coord[to_index('l')] = {1, 8};

  coord[to_index('z')] = {2, 0};
  coord[to_index('x')] = {2, 1};
  coord[to_index('c')] = {2, 2};
  coord[to_index('v')] = {2, 3};
  coord[to_index('b')] = {2, 4};
  coord[to_index('n')] = {2, 5};
  coord[to_index('m')] = {2, 6};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();

  char l, r;
  cin >> l >> r >> s;
  cout << solve(to_index(l), to_index(r), 0) + s.size();
}
