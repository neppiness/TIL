#include <iostream>

using namespace std;

void merge_sort(int begin, int end, int arr[]) {
    if(end - begin == 1) return;

    int mid = (begin + end) / 2;
    merge_sort(begin, mid, arr); merge_sort(mid, end, arr);

    // merge
    int idx = 0;
    int ans[end-begin];
    int aidx = begin, bidx = mid;
    while(aidx != mid && bidx != end) {
        if(arr[aidx] < arr[bidx]) ans[idx++] = arr[aidx++];
        else ans[idx++] = arr[bidx++];
    }
    for(; aidx < mid; aidx++) ans[idx++] = arr[aidx];
    for(; bidx < end; bidx++) ans[idx++] = arr[bidx];

    while(idx--) arr[--end] = ans[idx];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    merge_sort(0, n, arr);

    for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}