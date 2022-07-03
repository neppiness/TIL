#include <stdio.h>

int main(void) {
    int count;
    scanf("%d", &count);
    int x[count], y[count], arr[count];

    for (int i = 0; i < count; i++) {
        scanf("%d %d", &x[i], &y[i]);
        arr[i] = x[i] + y[i];
    }
    for (int i = 0; i < count; i++) {
        printf("Case #%d: %d + %d = %d\n", i+1, x[i], y[i], arr[i]);
    }

    return 0;
}