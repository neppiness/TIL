#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kMInf = (1 << 31);

int n; string eq;
ll ans = -0x7f7f7f7f7f7f;

bool is_op_selected[10];
int pre_calc_val[10];
int no_of_numbers, no_of_ops;

void calc() {
  for (int i = 0; i < no_of_ops; i++) {
    if (!is_op_selected[i]) continue;
    int idx = i * 2 + 1;
    pre_calc_val[i] = (eq[idx - 1] - '0');
    if (eq[idx] == '+')
      pre_calc_val[i] += (eq[idx + 1] - '0');
    else if (eq[idx] == '-')
      pre_calc_val[i] -= (eq[idx + 1] - '0');
    else
      pre_calc_val[i] *= (eq[idx + 1] - '0');
  }

  ll res = eq[0] - '0';
  if (is_op_selected[0]) res = pre_calc_val[0];
  for (int i = 0; i < no_of_ops; i++) {
    if (is_op_selected[i]) continue;
    int idx = i * 2 + 1;
    ll rval = eq[idx + 1] - '0';
    if (i + 1 < no_of_ops && is_op_selected[i + 1])
      rval = pre_calc_val[i + 1];
    if (eq[idx] == '+') res += rval;
    else if (eq[idx] == '-') res -= rval;
    else res *= rval;
  }
  ans = max(ans, res);
}

void solve(int lv, int st) {
  if (lv == 0) { calc(); return; }
  for (int i = st; i < no_of_ops; i++) {
    is_op_selected[i] = 1;
    solve(lv - 1, i + 2);
    is_op_selected[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> eq;
  no_of_numbers = n / 2 + 1;
  no_of_ops = n - no_of_numbers;

  int max_no_of_pars = no_of_numbers / 2;
  for (int i = 0; i <= max_no_of_pars; i++)
    solve(i, 0);
  cout << ans;
}