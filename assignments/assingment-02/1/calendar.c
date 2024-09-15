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
  /*
    TODO: Add a loop here to compute the number of mondays that fall on the first of the month between January 1st of startYear and dec 31st of endYear. Note that janFirstWeekday is the weekday of january 1st of startYear.
   */
  return 0;
}
