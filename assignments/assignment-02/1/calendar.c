#include <stdio.h>
#include "calendar.h"

int numDaysInMonth(int month, int year){
  switch(month){

  case JAN:
  case MAR: 
  case MAY:
  case JUL:
  case AUG:
  case OCT:
  case DEC:
    return 31;

  case APR:
  case JUN:
  case SEP:
  case NOV:
    return 30;

  case FEB:
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      return 29;
    } else {
      return 28;
    }
  default:
    return -1;
  }
}

int numFirstMondays(int startYear, int endYear, int janFirstWeekday)
{
    int count = 0;
    int weekDay = janFirstWeekday;

    for (int year = startYear; year <= endYear; year++) {
        for (int month = JAN; month <= DEC; month++) {
            if (weekDay == 1) { 
                count++;
            }
            weekDay = (weekDay + numDaysInMonth(month, year)) % 7;
        }
    }
    
    return count;
}