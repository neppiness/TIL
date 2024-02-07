#include <stdio.h>

int search(int i, int *answer) {
    int result = 0;
    int case1 = 1111111;
    int case2 = 1111111;
    int case3 = 1111111;

    if (i == 1) {
        return result;
    }

    if (i % 2 == 0) case1 = answer[i/2] + 1;
    if (i % 3 == 0) case2 = answer[i/3] + 1;
    case3 = answer[i - 1] + 1;

    int min = case1;
    if (min > case2) min = case2;
    if (min > case3) min = case3;
    result = min;

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int i = 1;
    int answer[n] = {0};

    for (; i <= n; ++i) {
        answer[i] = search(i, answer);
    }
    printf("%d", answer[i-1]);
}

/*
dragon20002's answer:

#include <stdio.h>
using namespace std;

int one(int i) {
	if (i < 2)
		return 0;

	int f = one(i / 3) + i % 3 + 1;
	int s = one(i / 2) + i % 2 + 1;

	return (f < s) ? f : s;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", one(n));
} */