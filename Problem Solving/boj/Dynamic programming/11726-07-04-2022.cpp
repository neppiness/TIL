#include <stdio.h>
#include <math.h>

int factorial(int no) {
    if (no == 1) {
        return 1;
    }
    return factorial(no - 1) * no;
}

int main() {
    int n;
    int result = 1; // base case

    scanf("%d", &n);

    for (int noOf2 = 1; noOf2 <= n / 2; ++noOf2) {
        int no = n - noOf2 * 2;
        result += pow(no + 1, noOf2);
        printf("%d\n", result);
    }

    printf("%d", result);
}

/*

#include <iostream>
#include <vector>
using namespace std;

void find_ans(int n, vector<int> &dp)
{
    dp[n] = (dp[n - 1] + dp[n - 2]) % 10007;
}

int main()
{
    int n;
    cin	>> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        find_ans(i, dp);
    }
    cout << dp[n] << '\n';
    return 0;
}

*/