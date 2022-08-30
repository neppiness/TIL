#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int n;
int A[4002], B[4002], C[4002], D[4002];
int AB[16000002], CD[16000002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            AB[cnt] = A[i] + B[j];
            CD[cnt++] = C[i] + D[j];
        }

    sort(AB, AB+n*n); sort(CD, CD+n*n);

    ll ans = 0;
    for(int i = 0; i < n*n; i++)
        ans += upper_bound(CD, CD+n*n, -AB[i]) - lower_bound(CD, CD+n*n, -AB[i]);

    cout << ans;
}