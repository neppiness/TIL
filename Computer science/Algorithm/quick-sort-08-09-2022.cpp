#include <iostream>

using namespace std;

void quick_sort(int arr[], int* L, int* R) {
    int step = 0, size = R - L;
    if(size == 1) return;

    int* M = arr;
    bool LFound = 0, RFound = 0;

    int lcnt = 0, rcnt = 0;
    while(true) {
        if(R < L) {
            swap(*M, *L);
        }
        
        if(!LFound) {
            while(*L < *M) {lcnt++; L++;}
            LFound = 1;
        }
        else if(*L < *M) {
            lcnt++;
            if(lcnt >= size) L--;
            else L++;
        } else if(*R > *M) R--;
    }

    quick_sort(arr, M, L);
    quick_sort(arr, L, R);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N = 5;
    int arr[N] = {1, -5, 7, -9, 11};

    int* a = &arr[0];
    int* b = &arr[N-1];

    quick_sort(arr, a, b);
}