#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, MX;
int sum[100002];

vector<int*> addV;

void solve(){
    while(!addV.empty()) {
        int *MAX_idx = addV.front(); addV.pop_back();
        int *MIN_idx = min_element(sum, sum+n);
        int *min_idx = min_element(sum, MAX_idx);
        int *max_idx = max_element(MIN_idx+1, sum+n+1);

        MX = -0x7f7f7f7f;
        if(MAX_idx > MIN_idx) MX = *MAX_idx - *MIN_idx;
        MX = max(*MAX_idx - *min_idx, MX);
        MX = max(*max_idx - *MIN_idx, MX);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        sum[i] = sum[i-1] + num;
    }

    int *MAX_idx = max_element(sum+1, sum+n+1);
    int MAX_val = *MAX_idx;
    for(int i = 0; i <= n; i++) {
        if(sum[i] == MAX_val) addV.push_back(&sum[i]);
    }

    solve();
    cout << MX; return 0;
}