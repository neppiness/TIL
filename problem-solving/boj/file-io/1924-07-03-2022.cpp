#include <bits/stdc++.h>

int daysCalc(int mon, int day) {
    mon -= 1;
    if (mon == 0) {
        return day;
    } else if (mon == 2) {
        day += 28;
    } else if(((mon <= 7) && (mon % 2 == 1)) || ((mon >= 8) && (mon % 2 == 0))) {
        day += 31;
    } else {
        day += 30;
    }
    return daysCalc(mon, day);
}

void whatDay(int days) {
    char DAYS[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    printf("%s", &(DAYS[days % 7]));
}

int main() {
    int mon, day, days;
    scanf("%d %d", &mon, &day);
    days = daysCalc(mon, day);
    whatDay(days);
}

/*
hanbulkr's answer: https://www.acmicpc.net/source/43949023

#include <stdio.h>

int daysOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char *dayOfWeek[7] { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {
	int month, day;
	scanf("%d %d", &month, &day);
	for (int i = 1; i < month; ++i) {
		day += daysOfMonth[i];
	}
	printf("%s\n", dayOfWeek[day % 7]);
	return 0;
}
*/