#include <stdio.h>

int main(void) {
    int x, y;
    int count;

    scanf("%d", &count);
    int arr[count];

    for (int i = 0; i < count; i++) {
        scanf("%d %d", &x, &y);
        arr[i] = x + y;
    }
    for (int i = 0; i < count; i++) {
        printf("Case #%d: %d\n", i+1, arr[i]);
    }

    return 0;
}