#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    for (int i = count; i > 0; i--) {
        printf("%d\n", i);
    }
}