#include <cstdio>

int main() {
	int month, day, x;
	int sum_days = 0;

	scanf("%d %d", &month, &day);

	month--;
	while (month > 0) {
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			x = 30;
		}
		else if (month == 2) {
			x = 28;
		}
		else {
			x = 31;
		}
		sum_days += x;
		month--;
	}

	sum_days += day;
	switch (sum_days % 7) {
	case 0:
		printf("SUN");
		break;
	case 1:
		printf("MON");
		break;
	case 2:
		printf("TUE");
		break;
	case 3:
		printf("WED");
		break;
	case 4:
		printf("THU");
		break;
	case 5:
		printf("FRI");
		break;
	case 6:
		printf("SAT");
		break;
	}
	return 0;
}