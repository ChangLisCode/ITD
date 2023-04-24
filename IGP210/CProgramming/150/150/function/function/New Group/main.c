//
//  main.c
//  169 struct pointer
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

void readDate(struct date *mydate);
void printDate(struct date mydate);

int main() {
    struct date d;

    readDate(&d);
    d = advanceDay(d);
    printDate(d);
    
    return 0;
}

void readDate(struct date *mydate){
    printf("please input the date.\n");
    scanf("%d %d %d\n", &(*mydate).year, &(*mydate).month, &(*mydate).day);
}

void printDate(struct date mydate){
    printf("%02d/%02d/%d\n", mydate.month, mydate.day, mydate.year);
}
