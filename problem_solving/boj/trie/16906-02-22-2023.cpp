#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000 + 2;
const int ROOT = 1;
const char ALP[] = {'0', '1'};

queue<string> words[MX];
stack<char> st;

int nxt[MX][2];
int unused = 2;
bool chk[MX];

bool insert(int l, int cur) {
  if(l == 0) {
    chk[cur] = 1;
    return 1;
  }
  for(char a : ALP) {
    int &nx = nxt[cur][a - '0'];
    if(nx == -1) nx = unused++;
    if(chk[nx]) continue;
    st.push(a);
    if(insert(l - 1, nx)) return 1;
    st.pop();
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(nxt, -1, sizeof(nxt));

  int n; cin >> n;
  vector<int> original_len(n);
  for(int i = 0; i < n; i++)
    cin >> original_len[i];

  vector<int> len = original_len;
  sort(len.begin(), len.end());

  // insert 시도 로직
  for(auto l : len) {
    bool is_inserted = insert(l, ROOT);
    if(!is_inserted) { cout << -1; return 0; }

    char str[st.size() + 1] = {};
    for(int i = (int)st.size() - 1; i >= 0; i--) {
      str[i] = st.top(); st.pop();
    }
    words[l].push(str);
  }

  // 성공 시 로직
  cout << 1 << '\n';
  for(auto l : original_len) {
    cout << words[l].front() << '\n';
    words[l].pop();
  }
}
