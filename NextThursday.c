// An algorithm that computes the doomsday of the year. It returns a 1
// if it is a leap year and 0 if it is not.
// Matthew Bruck 17/03/2012
// test cases: 13/12/2000, 1/1/1995

#include <stdio.h>
#define GREG_CALENDER 1582
#include <assert.h>
#include "NextThursday.h"

int tests (void);

int tests (void) {
  assert(isLeapYear(2012) == 1);
  assert(isLeapYear(2042) == 0);
  assert(isLeapYear(2000) == 1);
  assert(isLeapYear(1900) == 0);
  assert(isLeapYear(1933) == 0);

  assert(yearToDoomsday(2005) == 4);
  assert(yearToDoomsday(2006) == 5);
  assert(yearToDoomsday(2015) == 2);

  assert(dayOfWeek(6, 1, 3, 7) == 6);
  assert(dayOfWeek(6, 1, 8, 16) == 0);
  assert(dayOfWeek(6, 1, 4, 1) == 3);
  assert(dayOfWeek(5, 0, 12, 25) == 4);
  assert(dayOfWeek(6, 1, 3, 31) == 2);
 

  assert(daysToNextThursday(1856, 9, 22) == 3);
  assert(daysToNextThursday(1899, 3, 21) == 2);
  assert(daysToNextThursday(1899, 9, 14) == 7);
  assert(daysToNextThursday(1899, 11, 12) == 4);
  assert(daysToNextThursday(2048, 2, 29) == 5);
  assert(daysToNextThursday(2048, 3, 1) == 4);
  assert(daysToNextThursday(2048, 3, 2) == 3);
 
  return 0;
}

/*


int main(int argc, char *argv[]){

 int year;
 int month = 0;
 int day = 0;

 
    tests();


    printf("Please enter a year\n");
    scanf("%d", &year);
    printf("Please enter a month\n");
    scanf("%d", &month);
    printf("Please enter a day (in numerical form)\n");
    scanf("%d", &day);

    int c;
    c = yearToDoomsday(year);
    int d;
    d = isLeapYear(year);
    printf("yeartoDoomsDay: %d\n", yearToDoomsday(year)); 
    printf("Day of Week: %d", dayOfWeek(c, d, month, day));
    printf("Days to nestThursday: %d", daysToNextThursday(year, month, day));
 

  
return 0;
}
*/

int yearToDoomsday (int year){
int doomsday = 0;

doomsday = 2 + year%7 + ((year/4))%7 - (year/100)%7 + ((year/400)%7);
doomsday = doomsday + 3;
doomsday = doomsday%7;

return doomsday;
}


int dayOfWeek (int doomsday, int leapYear, int month, int day){ 

  int daysToDoomsDay = 0; 
  int DOW = 0;

// These cascading if's will calculate the month's Doomsday
  if(month == 5) {
     month = 9;
  }  else if(month == 9) {
     month = 5;
  }  else if(month == 7) {
     month = 11;
  }  else if(month == 11) { 
     month = 7;
  }  else if(month == 3) {
     month = 0;
  }  else if(month % 2 == 0 && month != 2){
  }  else if(month == 2 && leapYear == 0){
     month = 0;
  }  else if(month == 2 && leapYear == 1){
     month = 1;
  }  else if(month == 1 && leapYear == 0){
     month = 3;
  }  else if(month == 1 && leapYear == 1){
     month = 4;
  }   
   
  daysToDoomsDay = day - month;
  daysToDoomsDay = daysToDoomsDay%7;
  if(daysToDoomsDay < 0) {
      daysToDoomsDay = daysToDoomsDay + 7;
  }    
  
  DOW = doomsday + daysToDoomsDay;
  DOW = DOW%7;

  return DOW;
}

 
int daysToNextThursday(int year, int month, int day){

  int e;
  e = yearToDoomsday(year);
  int f;
  f = isLeapYear(year);
  int A;
  A = dayOfWeek (e,f,month,day);

    if(A == 0){
        return 7;
    } else if(A == 1){ 
        return 6;
    } else if(A == 2){ 
        return 5;
    } else if(A == 3){ 
        return 4;
    } else if(A == 4){ 
        return 3;
    } else if(A == 5){
        return 2;
    } 
    //else if(yearToDoomsDay == 3){ 
    return 1;
}



int isLeapYear(int year) {
  int leapYear = 0;
//Returns 1 if year is a Leap Year, returns 0 otherwise
	int answer = 0;
	if(year >= GREG_CALENDER){
		if(year%4 == 0){
            answer = 1;
			if(year%100 == 0){
                answer = 0;
				if(year%400 == 0){
					answer = 1;
				}
			}
		}
	}
  leapYear = answer;
	return leapYear;
}



