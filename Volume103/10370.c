#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_STUDENTS_IN_CLASS 1001



int main(void)
{
 int NumCase;
 int IdxCase;
 int Grade;
 int StudentGrade[MAX_STUDENTS_IN_CLASS];
 int SumGrade;
 int NumStudents;
 int IdxStudent;
 int NumStudentsAboveAverage;
 double PercentAboveAverage;
  
/*
 freopen("p10370_in.txt", "r", stdin);
 freopen("p10370_out.txt", "w", stdout);
*/
 scanf("%d", &NumCase);
 
 for ( IdxCase = 0; IdxCase < NumCase; IdxCase++) {
    scanf("%d", &NumStudents);
	SumGrade = 0;
	for ( IdxStudent = 0; IdxStudent < NumStudents; IdxStudent++) {
	   scanf("%d", &Grade);
	   StudentGrade[IdxStudent] = Grade;
	   SumGrade += Grade;	   
	}	
	NumStudentsAboveAverage = 0;
	for ( IdxStudent = 0; IdxStudent < NumStudents; IdxStudent++) {
	   if  (  (StudentGrade[IdxStudent] * NumStudents) > SumGrade ) {
	      NumStudentsAboveAverage++;
	   }
 	}
	PercentAboveAverage =  ((double) NumStudentsAboveAverage / (double) NumStudents)*100.0;
    printf("%.3lf%%\n", 	PercentAboveAverage);	
 }
  

 return 0;
}
