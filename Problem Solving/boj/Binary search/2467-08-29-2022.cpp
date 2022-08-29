#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
int a[100002];
vector<tuple<int,int,int>> V;

int solve(int m){
    int tar = -m;
    int begin = 0, end = N-1;
    while(begin < end) {
        int mid = (begin + end + 1)/2;
        if(a[mid] > tar) end = mid - 1;
        else begin = mid;
    }
    return begin;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    for(int i = 0; i < N; i++) {
        int idx = solve(a[i]);
        if(idx == i) continue;

        int res1 = a[i] + a[idx];
        if(res1 < 0) res1 = -res1;
        V.push_back({res1, a[i], a[idx]});

        if(idx + 1 < N && idx + 1 != i) { 
            idx++;
            int res2 = a[i] + a[idx];
            if(res2 < 0) res2 = -res2;
            V.push_back({res2, a[i], a[idx]});
        }
    }

    sort(V.begin(), V.end());

    int a, b;
    tie(ignore, a, b) = V.front();
    cout << min(a, b) << ' ' << max(a, b);
}