#include <iostream>
#include <algorithm>
using namespace std;

int nums[10][10]; // [radix][number]
int tot[10];
int comb[10];
int main(){
    int nos = 0;
    fill(nums[0] + 1, nums[0] + 10, 1);

    for(int n = 1; n < 10; n++)
        for(int i = 0; i < 10 - n; i++)
            for(int j = i+1; j < 10; j++)
                nums[n][i] += nums[n-1][j];

    for(int n = 0; n < 10; n++)
        for(int i = 0; i < 10; i++) tot[n] += nums[n][i];

    int N; cin >> N;
    int seq = N, len = 0;

    for(; len < 10; len++) {
        if(seq <= tot[len]) {break;}
        seq -= tot[len];
    }
    
    len++;

    cout << len << '\n';
}