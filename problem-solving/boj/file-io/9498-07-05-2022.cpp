#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;
	char gr;

	if (x >= 90) gr = 'A';
	else if (x >= 80) gr = 'B';
	else if (x >= 70) gr = 'C';
	else if (x >= 60) gr = 'D';
	else gr = 'F';

	cout << gr;
}