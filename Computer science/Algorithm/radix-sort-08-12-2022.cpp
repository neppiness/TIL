#include <iostream>
#include <vector>

using namespace std;

int N = 10, M = 3;

void radSort(int arr[], int rad){
    if(rad == M) return;

    vector<int> radV[10];
    int mod = 10;
    for(int i = 0; i < rad; i++) mod *= 10;

    for(int i = 0; i < N; i++) {
        int a = arr[i] % mod;
        a /= (mod/10);
        radV[a].push_back(arr[i]);
    }

    int i = 10; int idx = N - 1;
    while(i--) {
        while(!radV[i].empty()) {
            int cur = radV[i].back();
            radV[i].pop_back();
            arr[idx--] = cur;
        }
    }
    radSort(arr, rad + 1);
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    int arr[10] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545};

    radSort(arr, 0);
    for(int i = 0; i < N; i++) cout << arr[i] << ' ';
}