#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    
    long long a[100002];
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);

    long long num[100002];
    int cnt[100002];
    int idx = 0;

    num[0] = a[0];
    for(int i = 1; i < N; i++) {
        if(a[i] != num[idx]) num[++idx] = a[i];
        else cnt[idx]++;
    }
    cout << num[max_element(cnt, cnt + N) - cnt];
}