#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Define variables to store the start and end dates
    struct tm start_date = {0};
    struct tm end_date = {0};

    // Get start date from user input
    printf("Enter start date in YYYY-MM-DD format: ");
    scanf("%d-%d-%d", &start_date.tm_year, &start_date.tm_mon, &start_date.tm_mday);
    start_date.tm_year -= 1900; // adjust for year since 1900
    start_date.tm_mon -= 1; // adjust for month (0-11)

    // Get end date from user input
    printf("Enter end date in YYYY-MM-DD format: ");
    scanf("%d-%d-%d", &end_date.tm_year, &end_date.tm_mon, &end_date.tm_mday);
    end_date.tm_year -= 1900; // adjust for year since 1900
    end_date.tm_mon -= 1; // adjust for month (0-11)

    // Calculate difference in days
    time_t start_time = mktime(&start_date);
    time_t end_time = mktime(&end_date);
    int diff_days = difftime(start_time, end_time) / (60 * 60 * 24);

    printf("Number of days between the two dates: %d", diff_days);

    return 0;
}

