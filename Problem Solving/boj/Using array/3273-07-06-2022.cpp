#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt[100005] = {0};

    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        cnt[nums[i]] += 1;
    }

    int x;
    cin >> x;

    int count = 0;

    for (int i = 0; i < n; ++i) {
        if ((x - nums[i] > 0) && (cnt[x - nums[i]] != 0)) {
            cnt[x - nums[i]] -= 1;
            count++;
        }
        cnt[nums[i]] -= 1;
    }

    cout << count;
}