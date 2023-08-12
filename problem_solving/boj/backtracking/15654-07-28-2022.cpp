#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, num[10], ans[10];
bool isUsed[10] = {false};

void search(int m, vector<int> &intV) {
    if (M == m) {
        for (int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else for(int i = 0; i < N; i++) {
        if(isUsed[intV[i]] == true) continue;
        ans[m] = intV[i];
        isUsed[intV[i]] = true;
        search(m+1, intV);
        isUsed[intV[i]] = false;
    }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> num[i];

    vector<int> intV(num, num + N);
    sort(intV.begin(), intV.end());

    search(0, intV);
}