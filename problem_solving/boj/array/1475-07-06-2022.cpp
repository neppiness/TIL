#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 1;
    
    int num;
    int nums[10] = {0};
    cin >> num;

    while(num) {
        nums[num % 10] += 1;
        num /= 10;
    }

    nums[6] += nums[9];
    nums[6] = nums[6] % 2 + nums[6] / 2;
    nums[9] = nums[6];

    for (int i = 0; i < 10; i++) {
        ans = max(ans, nums[i]);
    }

    cout << ans;
}