#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int ans[100002];

vector<int> wV;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    fill(ans+1, ans+K+1, -1);
    
    wV.push_back(0);

    int weight, value;
    while(N--) {
        cin >> weight >> value;

        int sz = wV.size();
        for(int i = 0; i < sz; i++) {
            int nW = wV[i] + weight;
            if(nW > K) continue;
            if(ans[nW] == -1 && nW < K) wV.push_back(nW);
            ans[nW] = max(ans[wV[i]] + value, ans[nW]);
        }
    }
    cout << *max_element(ans, ans+K+1);
}