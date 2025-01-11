/**** 1. Develop a Program in C for the following:
 a. Declare a calendar as an array of 7 elements (A dynamically Created array) to
 represent 7 days of a week. Each Element of the array is a structure having three
 fields. The first field is the name of the Day (A dynamically allocated String), The
 second field is the date of the Day (A integer), the third field is the description of
 the activity for a particular day (A dynamically allocated String).
 b. Write functions create(), read() and display(); to create the calendar, to read the
 data from the keyboard and to print weeks activity details report on screen.****/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NO_OF_DAYS 7
typedef struct
{
    char *name_of_the_day;
    int date_of_day;
    char *activity_descr;
    

}CALENDAR;

void create_calender(CALENDAR a[],int i,char name[],int date,char activity[])
{
    a[i].name_of_the_day=(char *)malloc(strlen(name)+1);
    strcpy(a[i].name_of_the_day,name);
    a[i].date_of_day=date;
    a[i].activity_descr=(char *)malloc(strlen(activity)+1);
    strcpy(a[i].activity_descr,activity);
}
void read_calender(CALENDAR a[])
{
    
int date,i;
char name[20];
char activity[20];
for(i=0;i<NO_OF_DAYS;i++)
{
    scanf("%s",name);
    scanf("%d",&date);
    scanf("%s",activity);
    create_calender(a,i,name,date,activity);

}
}
void print_weeks_activity(CALENDAR a[])
{
    int i;
    printf("\n weeks activity:");
    for(i=0;i<NO_OF_DAYS;i++)
{
    printf("\n%s\t%d\t%s\n",a[i].name_of_the_day,a[i].date_of_day,a[i].activity_descr);

}
}
void main()
{
    CALENDAR a[NO_OF_DAYS];
    printf("enter day date activity of the day:\n");
    read_calender(a);
    print_weeks_activity(a);


}
