#include <stdio.h>
#include <iostream>
using namespace std;

void insert(int idx, int num, int arr[], int& len) {
    int no = len - idx;
    int tempArr[no];

    for (int i = 0; i < no; i++) {
        tempArr[i] = arr[i + idx];
    }
    arr[idx] = num;
    for (int i = 0; i < no; i++) {
        arr[i + 1 + idx] = tempArr[i];
    }
    len++;
}

void erase(int idx, int arr[], int& len) {
    int no = len - idx;
    int tempArr[no];

    for (int i = 0; i < no; i++) {
        tempArr[i] = arr[i + idx];
    }
    for (int i = 0; i < no; i++) {
        arr[i - 1 + idx] = tempArr[i];
    }
    len--;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;

    insert(3, 60, arr, len);
    erase(4, arr, len);
    
    for (int i = 0; i < len; ++i) {
        if(i == len - 1) cout << arr[i];
        else {
            cout << arr[i];
            cout << ',';
            cout << ' ';
        }
    }
}