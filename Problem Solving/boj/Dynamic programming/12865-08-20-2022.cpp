#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int W[102], V[102];
int ans[100002]; // value indexed by [weight]
bool vis[100002];

vector<int> wV;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> W[i] >> V[i];

    for(int i = 0; i < N; i++) {
        int weight = W[i], value = V[i];

        vector<int>::iterator it = wV.begin();
        for(; it < wV.end(); it++) {
            int nW = *it + weight;
            if(nW > K) continue;
            ans[nW] = max(ans[*it] + value, ans[nW]);
            if(!vis[nW]) {wV.push_back(nW); vis[nW] = true;}
        }

        ans[weight] = max(value, ans[weight]);
        if(!vis[weight]) wV.push_back(weight);
    }
    cout << *max_element(ans+1, ans+K+1);
}