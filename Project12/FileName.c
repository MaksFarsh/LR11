#include <stdio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

struct worker {
	char name;
	char post;
	int start_day;
	int start_month;
	int period;
	int paycheck;
};

struct day {
	int day;
	int month;
};

typedef struct worker Worker;
typedef struct day Day;

Day dayNew(Day d);
int deadline(Worker w, Day d1);

void main() {
	setlocale(LC_ALL, "RUS");
	Day d, end;
	Worker w;
	w = (Worker){ "v", "v", 28, 1, 8, 54033};
	end = (Day){ w.start_day + w.period, w.start_month };
	end = dayNew(end);
	int day, month;
	puts("Какой сегодня день и месяц?");
	scanf("%d %d", &day, &month);
	d = (Day){ day, month };
	if (deadline(w, d))
		printf("У работника %c (должность: %c) через 5 дней истекает срок действия контракта \nСегоднешняя дата: %d.%d\tДата окончания контракта: %d.%d", w.name, w.post, d.day, d.month, end.day, end.month);
}

int deadline(Worker w,Day d1) {
	Day end, d;
	d = (Day){ w.start_day, w.start_month };
	d = dayNew(d);
	end = (Day){ d.day + w.period - 5, d.month };
	end = dayNew(end);
	if (d1.day == end.day && d1.month == end.month)
		return 1;
	return 0;
}

Day dayNew(Day d) {
	Day new;
	new = (Day){ d.day,d.month };
	if (d.day > 31 && d.month == 1) {
		new.day = d.day - 31;
		new.month = 2;
		return new;
	}
	else if (d.day > 28 && d.month == 2) {
		new.day = d.day - 28;
		new.month = 3;
		return new;
	}
	else if (d.day > 31 && d.month == 3) {
		new.day = d.day - 31;
		new.month = 4;
		return new;
	}
	else if (d.day > 30 && d.month == 4) {
		new.day = d.day - 30;
		new.month = 5;
		return new;
	}
	else if (d.day > 31 && d.month == 5) {
		new.day = d.day - 31;
		new.month = 6;
		return new;
	}
	else if (d.day > 30 && d.month == 6) {
		new.day = d.day - 30;
		new.month = 7;
		return new;
	}
	else if (d.day > 31 && d.month == 7) {
		new.day = d.day - 31;
		new.month = 8;
		return new;
	}
	else if (d.day > 31 && d.month == 8) {
		new.day = d.day - 31;
		new.month = 9;
		return new;
	}
	else if (d.day > 30 && d.month == 9) {
		new.day = d.day - 30;
		new.month = 10;
		return new;
	}
	else if (d.day > 31 && d.month == 10) {
		new.day = d.day - 31;
		new.month = 11;
		return new;
	}
	else if (d.day > 30 && d.month == 11) {
		new.day = d.day - 30;
		new.month = 12;
		return new;
	}
	else if (d.day > 31 && d.month == 12) {
		new.day = d.day - 31;
		new.month = 1;
		return new;
	}
	if (d.day < 0 && d.month == 1) {
		new.day = d.day + 31;
		new.month = 12;
		return new;
	}
	else if (d.day < 0 && d.month == 2) {
		new.day = d.day + 28;
		new.month = 1;
		return new;
	}
	else if (d.day < 0 && d.month == 3) {
		new.day = d.day + 31;
		new.month = 2;
		return new;
	}
	else if (d.day < 0 && d.month == 4) {
		new.day = d.day + 30;
		new.month = 3;
		return new;
	}
	else if (d.day < 0 && d.month == 5) {
		new.day = d.day + 31;
		new.month = 4;
		return new;
	}
	else if (d.day < 0 && d.month == 6) {
		new.day = d.day + 30;
		new.month = 5;
		return new;
	}
	else if (d.day < 0 && d.month == 7) {
		new.day = d.day - 31;
		new.month = 6;
		return new;
	}
	else if (d.day < 0 && d.month == 8) {
		new.day = d.day + 31;
		new.month = 7;
		return new;
	}
	else if (d.day < 0 && d.month == 9) {
		new.day = d.day + 30;
		new.month = 8;
		return new;
	}
	else if (d.day > 31 && d.month == 10) {
		new.day = d.day - 31;
		new.month = 9;
		return new;
	}
	else if (d.day < 0 && d.month == 11) {
		new.day = d.day + 30;
		new.month = 10;
		return new;
	}
	else if (d.day < 0 && d.month == 12) {
		new.day = d.day + 31;
		new.month = 11;
		return new;
	}
}