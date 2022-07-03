#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    for (int i = count; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        puts("");
    }
}