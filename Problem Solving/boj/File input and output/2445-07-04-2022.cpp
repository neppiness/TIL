#include <stdio.h>

int main() {
	int n;
    scanf("%d", &n);
    
    int m = 2*n - 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        for (int j = i+1; j <= 2*n - i; ++j) {
            printf(" ");
        }
        for (int j = 2*n - i + 1; j <= 2*n; ++j) {
            printf("*");
        }
        puts("");
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            printf("*");
        }
        for (int j = i+1; j <= 2*n - i; ++j) {
            printf(" ");
        }
        for (int j = 2*n - i + 1; j <= 2*n; ++j) {
            printf("*");
        }
        puts("");
    }
    return 0;
}