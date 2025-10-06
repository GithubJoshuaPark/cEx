#include <stdio.h>
#include "enumsEx.h"
#include "hello.h" // For printLine

// 1. Define an enumeration (enum).
// Enums assign names to integer constants, making code more readable.
// By default, SUNDAY is 0, MONDAY is 1, and so on.
typedef enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Day;

// Helper function to convert enum to string for printing
const char* getDayName(Day d) {
    switch (d) {
        case SUNDAY:    return "Sunday";
        case MONDAY:    return "Monday";
        case TUESDAY:   return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY:  return "Thursday";
        case FRIDAY:    return "Friday";
        case SATURDAY:  return "Saturday";
        default:        return "Invalid Day";
    }
}

void enumsEx(void) {
    printLine("Demonstrating Enums");

    // 2. Declare a variable of the enum type and use it.
    Day today = WEDNESDAY;
    printf("Today is %s (value %d).\n", getDayName(today), today);
    printf("This is much more readable than checking if 'today == 3'.\n");
}