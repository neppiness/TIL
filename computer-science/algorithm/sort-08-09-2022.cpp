#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] >= arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N = 9;
    int arr[N] = {6, 12, 8, 13, 15, -7, 7, -9, 1};

    int n = N/2, m = N - n;
    int a[n], b[m];
    for(int i = 0; i < N; i++) {
        if (i % 2 == 1) a[i/2] = arr[i];
        else {b[i/2] = arr[i];}
    }

    bubbleSort(a, n);
    bubbleSort(b, m);

    int aIdx = 0, bIdx = 0;
    int idx = 0;

    while(aIdx != n && bIdx != m) {
        if(a[aIdx] < b[bIdx]) arr[idx++] = a[aIdx++];
        else arr[idx++] = b[bIdx++];
    }
    for(int i = aIdx; i < n; i++) arr[idx++] = a[i++];
    for(int i = bIdx; i < m; i++) arr[idx++] = b[i++];
    /*
    // Equivalent code
    for(int i = 0; i < N; i++) {
        if(bIdx == m) arr[i] = a[aIdx++];
        else if(aIdx == n) arr[i] = b[bIdx++];
        else if(a[aIdx] <= b[bIdx]) arr[i] = a[aIdx++];
        else arr[i] = b[bIdx++];
    }
    */

    for(int i = 0; i < N; i++) cout << arr[i] << ' ';
}