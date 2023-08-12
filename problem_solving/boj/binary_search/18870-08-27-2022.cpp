#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[1000002], num2[1000002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {cin >> num[i]; num2[i] = num[i];}

    sort(num, num + N);

    int cur = 0;
    for(int i = 1; i < N; i++)
        if(num[cur] != num[i]) num[++cur] = num[i];

    for(int i = 0; i < N; i++)
        cout << (lower_bound(num, num + cur + 1, num2[i]) - num) << ' ';
}