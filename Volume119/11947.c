#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUMMONTHAYEAR 13
#define NUMDAYWEEK 7
#define NUMDAYFOURTYWEEK 280

int DaysInMonthNormalYear[NUMMONTHAYEAR] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int DaysInMonthLeapYear[NUMMONTHAYEAR] = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *Zodiac[NUMMONTHAYEAR] = { "NA", "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};

int WhichZodica(int Month, int Day)
{
    if ( (Month == 1 &&  Day >= 21) || (Month == 2 && Day <= 19)) {
       return 1;
    } else if ( (Month == 2 &&  Day >= 20) || (Month == 3 && Day <= 20) ) {
       return 2;           
    } else if ( (Month == 3 &&  Day >= 21) || (Month == 4 && Day <= 20) ) {
       return 3;           
    } else if ( (Month == 4 &&  Day >= 21) || (Month == 5 && Day <= 21) ) {
       return 4;           
    } else if ( (Month == 5 &&  Day >= 22) || (Month == 6 && Day <= 21) ) {
       return 5;           
    } else if ( (Month == 6 &&  Day >= 22) || (Month == 7 && Day <= 22) ) {
       return 6;           
    } else if ( (Month == 7 &&  Day >= 23) || (Month == 8 && Day <= 21) ) {
       return 7;           
    } else if ( (Month == 8 &&  Day >= 22) || (Month == 9 && Day <= 23) ) {
       return 8;           
    } else if ( (Month == 9 &&  Day >= 24) || (Month == 10 && Day <= 23) ) {
       return 9;           
    } else if ( (Month == 10 &&  Day >= 24) || (Month == 11 && Day <= 22) ) {
       return 10;           
    } else if ( (Month == 11 &&  Day >= 23) || (Month == 12 && Day <= 22) ) {
       return 11;           
    } else {
       return 12;                      
    }                                                                                                   
           
}
                

typedef struct {
  int Month;
  int Day;
  int Year;
} MyDate;

int main(void)
{

int NumCase;
int IdxCase;

MyDate LastMenstrualCycle;
MyDate Birthday;
int DayPass;
char EndDate[10];
int IdxMonth;
int *DayInMonth;


/*
 freopen("p11947_in.txt", "r", stdin);
 freopen("p11947_out.txt", "w", stdout);
*/

 
scanf("%d", &NumCase);



for ( IdxCase = 0; IdxCase < NumCase ;IdxCase++) {
    
    /* Get the first day of last Menstrual Cycle from I/O */
    scanf("%s", EndDate);
    LastMenstrualCycle.Month = (EndDate[0] - '0') * 10 + (EndDate[1] - '0');
    LastMenstrualCycle.Day = (EndDate[2] - '0') * 10 + (EndDate[3] - '0');        
    LastMenstrualCycle.Year = (EndDate[4] - '0') * 1000 + (EndDate[5] - '0')* 100 + (EndDate[6] - '0') * 10 + (EndDate[7] - '0');    
    
    /* Set Birthday as the first day of last Menstrual Cycle  */
    Birthday = LastMenstrualCycle;
    
    /* Prepare The Array to count */
    if ( (LastMenstrualCycle.Month <= 2) && ((LastMenstrualCycle.Year%4) == 0)) {
       DayInMonth = DaysInMonthLeapYear;
    } else if ( (LastMenstrualCycle.Month >= 5) && (((LastMenstrualCycle.Year+1)%4) == 0)) {
       DayInMonth = DaysInMonthLeapYear;
    } else {
       DayInMonth = DaysInMonthNormalYear;
    }    
    /* Initialize Variables */
    DayPass = 0;
    IdxMonth = LastMenstrualCycle.Month;
    
    /* Calculate First Month */
    DayPass = DayInMonth[IdxMonth] - LastMenstrualCycle.Day + 1;
    Birthday.Day = 1;
    if ( IdxMonth== 12) {
       Birthday.Month = 1;
       Birthday.Year += 1;
       IdxMonth = 1;
    } else {
       Birthday.Month += 1;     
       IdxMonth++;
    }
    
    while ( DayPass + DayInMonth[IdxMonth] <= NUMDAYFOURTYWEEK) {
       DayPass += DayInMonth[IdxMonth];
       if ( IdxMonth== 12) {
          Birthday.Month = 1;
          Birthday.Year += 1;
          IdxMonth = 1;
        } else {
          Birthday.Month += 1;     
          IdxMonth++;
        }
    } 

    Birthday.Day =   NUMDAYFOURTYWEEK - DayPass + 1;  

    printf("%d %02d/%02d/%04d %s\n", (IdxCase+1), Birthday.Month, Birthday.Day, Birthday.Year, Zodiac[WhichZodica(Birthday.Month, Birthday.Day)]);
    
 
}

 return 0;
}
