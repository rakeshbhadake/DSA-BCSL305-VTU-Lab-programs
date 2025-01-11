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