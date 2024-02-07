#include <bits/stdc++.h>
using namespace std;

const string NUMBERS[10][5] = {
    {"###", "#.#", "#.#", "#.#", "###"}, // 0
    {"#", "#", "#", "#", "#"},           // 1
    {"###", "..#", "###", "#..", "###"}, // 2
    {"###", "..#", "###", "..#", "###"}, // 3
    {"#.#", "#.#", "###", "..#", "..#"}, // 4
    {"###", "#..", "###", "..#", "###"}, // 5
    {"###", "#..", "###", "#.#", "###"}, // 6
    {"###", "..#", "..#", "..#", "..#"}, // 7
    {"###", "#.#", "###", "#.#", "###"}, // 8
    {"###", "#.#", "###", "..#", "###"}, // 9
};

int n;
string s, b[5];
vector<string> splitted_str[5];

vector<string> split(string& s, vector<int> bl_idx) {
  vector<string> ret;
  int pos = 0;
  for (int nxt_pos : bl_idx) {
    if (nxt_pos - pos > 0)
      ret.push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + 1; // 1: 구분자 최소 크기
  }
  ret.push_back(s.substr(pos, s.size() - pos));
  return ret;
}

void analyze_array(int idx) {
  for (int no = 0; no < 10; no++) {
    bool is_found = 1;
    for (int i = 0; i < 5; i++) {
      if (splitted_str[i][idx] == NUMBERS[no][i]) continue;
      is_found = 0; break;
    }
    if (!is_found) continue;
    cout << no; return;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  n /= 5;

  for (int i = 0; i < 5; i++)
    b[i].resize(n);

  int idx = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < n; j++)
      b[i][j] = s[idx++];
  
  vector<int> bl_idx;
  for (int j = 0; j < n; j++) {
    bool is_all_blank = 1;
    for (int i = 0; i < 5; i++)
      if (b[i][j] != '.') is_all_blank = 0;
    if (is_all_blank) bl_idx.push_back(j);
  }

  for (int i = 0; i < 5; i++)
    splitted_str[i] = split(b[i], bl_idx);

  for (int idx = 0; idx < splitted_str[0].size(); idx++)
    analyze_array(idx);
}