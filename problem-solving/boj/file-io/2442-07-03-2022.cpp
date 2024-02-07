#include <stdio.h>

int main() {
	int n;
    scanf("%d", &n);
    
    int m = 2*n + 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            printf(" ");
        }
        for (int j = 1; j <= 2*(i - 1) + 1; ++j) {
            printf("*");
        }
        puts("");
    }
    return 0;
}