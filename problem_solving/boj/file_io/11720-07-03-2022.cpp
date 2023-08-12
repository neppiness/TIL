#include <stdio.h>

int main() {
    int count;
    char letter;

    scanf("%d\n", &count);
    int result[count];

    for (int i = 0; i < count; i++) {
        scanf("%c", &letter);
        result[i] = int(letter) - 48;
    }

    int temp = 0;
    for (int i = 0; i < count; i++) {
        temp += result[i];
    }
    printf("%d", temp);

    return 0;
}