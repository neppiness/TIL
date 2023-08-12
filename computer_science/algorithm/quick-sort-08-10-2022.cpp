#include <iostream>

using namespace std;

void quick_sort(int arr[], int begin, int end) {
    int step = 0, size = end - begin;
    if(size == 1) return;

    int* fiv = &arr[begin];
    int* L = &arr[begin+1];
    int* R = &arr[end-1];

    bool LFound = 0, RFound = 0;
    L++;

    while(true) {
        if(L >= R) {
            if(LFound) {
                swap(*fiv, *L);
                quick_sort(arr, begin, L - fiv);
                quick_sort(arr, L - fiv, end);
            } else if(RFound) {
                swap(*fiv, *R);
                quick_sort(arr, begin, R - fiv);
                quick_sort(arr, R - fiv, end);
            }
            break;
        }
        if(!LFound) {
            L++;
            if(*L > *fiv) LFound = 1;
        }
        if(!RFound) {
            R--;
            if(*R < *fiv) RFound = 1;
        }
        if(LFound && RFound) {
            swap(*L, *R);
            LFound = 0, RFound = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N = 5;
    int arr[N] = {1, -5, 7, -9, 11};

    quick_sort(arr, 0, N);

    for(int i = 0; i < N; i++) cout << arr[i] << ' ';
}