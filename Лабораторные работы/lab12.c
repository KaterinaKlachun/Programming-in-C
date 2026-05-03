#include <stdio.h>
#include <string.h>
#include <time.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return days[month - 1];
}

int isValidDate(int year, int month, int day) {
    if (year < 1) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > daysInMonth(year, month)) return 0;

    return 1;
}

int dayOfWeek(int year, int month, int day) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (month < 3) {
        year--;
    }

    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

void printDayOfWeek(int year, int month, int day) {
    char *weekDays[] = {
        "Воскресенье",
        "Понедельник",
        "Вторник",
        "Среда",
        "Четверг",
        "Пятница",
        "Суббота"
    };

    int w = dayOfWeek(year, month, day);

    printf("%04d.%02d.%02d — %s\n", year, month, day, weekDays[w]);
}

void printMonthCalendar(int year, int month) {
    int days = daysInMonth(year, month);
    int firstDay = dayOfWeek(year, month, 1);

    int start = firstDay;
    if (start == 0) {
        start = 6;
    } else {
        start--;
    }

    printf("\nКалендарь на %04d.%02d\n", year, month);
    printf("Пн Вт Ср Чт Пт Сб Вс\n");

    for (int i = 0; i < start; i++) {
        printf("   ");
    }

    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);

        if ((start + day) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

void printYearCalendar(int year) {
    printf("\nКалендарь на %04d год\n", year);

    for (int month = 1; month <= 12; month++) {
        printMonthCalendar(year, month);
    }
}

void printNow() {
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    printf("Текущая дата:\n");
    printDayOfWeek(year, month, day);
}

int countDots(char str[]) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            count++;
        }
    }

    return count;
}

int main() {

    char input[50];
    int year, month, day;
    int dots;

    printf("Введите дату в формате гггг, гггг.мм, гггг.мм.дд или now:\n");
    fgets(input, 50, stdin);

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "now") == 0) {
        printNow();
        return 0;
    }

    dots = countDots(input);

    if (dots == 0) {
        if (sscanf(input, "%d", &year) == 1 && year > 0) {
            printYearCalendar(year);
        } else {
            printf("Ошибка: неверный формат года\n");
        }
    }
    else if (dots == 1) {
        if (sscanf(input, "%d.%d", &year, &month) == 2 &&
            year > 0 && month >= 1 && month <= 12) {
            printMonthCalendar(year, month);
        } else {
            printf("Ошибка: неверный формат месяца\n");
        }
    }
    else if (dots == 2) {
        if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3 &&
            isValidDate(year, month, day)) {
            printDayOfWeek(year, month, day);
        } else {
            printf("Ошибка: неверная дата\n");
        }
    }
    else {
        printf("Ошибка: неверный формат ввода\n");
    }

    return 0;
}