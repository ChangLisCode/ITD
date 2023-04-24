//
//  main.c
//  170_struct_leapYear_date_calculate
//
//  Created by Chang on 2023-04-11.
//


#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

struct date advanceDay(struct date d) {
    int daysInMonth[] = {31, 28 + isLeapYear(d.year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.day < daysInMonth[d.month - 1]) {
        d.day++;
    } else {
        d.day = 1;
        if (d.month == 12) {
            d.month = 1;
            d.year++;
        } else {
            d.month++;
        }
    }

    return d;
}

int main() {
    struct date d;
    
    printf("please input the date.\n");
    scanf("%d %d %d\n", &d.year, &d.month, &d.day);
    
    printf("%02d/%02d/%d\n", d.month, d.day, d.year);

    d = advanceDay(d);
    printf("%02d/%02d/%d\n", d.month, d.day, d.year);
    
    return 0;
}

