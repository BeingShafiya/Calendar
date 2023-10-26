#include <stdio.h>

int isLeapYear(int year) {
    // A simple leap year calculation
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int getDaysInMonth(int year, int month) {
    // Array to store the number of days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // If it's a leap year and the month is February, return 29 days
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return daysInMonth[month];
}

int getStartingDay(int year, int month) {
    // Zeller's Congruence algorithm to find the day of the week for the first day of the month
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (1 + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - 2 * j) % 7;
    return ((h + 5) % 7) + 1;
}

void printCalendar(int year, int month) {
    // Define the names of the months
    char *monthNames[] = {
        "Invalid Month",
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int daysInMonth = getDaysInMonth(year, month);
    int startingDay = getStartingDay(year, month);

    // Print the calendar
    printf("\n---------------------------\n");
    printf("   %s %d\n", monthNames[month], year);
    printf("---------------------------\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int day;
    for (day = 1; day < startingDay; day++) {
        printf("    ");
    }

    for (day = 1; day <= daysInMonth; day++) {
        printf("%3d ", day);
        if ((day + startingDay - 1) % 7 == 0 || day == daysInMonth) {
            printf("\n");
        }
    }

    printf("\n");
}

int main() {
    int year, month;

    // Input
    printf("Enter year (e.g., 2023): ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    // Validate input
    if (year < 1 || month < 1 || month > 12) {
        printf("Invalid input. Please enter a valid year and month.\n");
        return 1; // Exit with an error code
    }

    // Output the calendar
    printCalendar(year, month);

    return 0;
}
