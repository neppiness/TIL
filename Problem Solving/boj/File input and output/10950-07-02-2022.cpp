#include <stdio.h>

int main() {
    int x, y;
    int count;

    scanf("%d", &count);

    int z[count];
    for (int i = 0; i < count; i++) {
        scanf("%d %d", &x, &y);
        z[i] = x + y;
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", z[i]);
    }
}