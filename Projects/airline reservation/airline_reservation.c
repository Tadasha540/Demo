#include<stdio.h>
#include<conio.h>
int dayOfWeek(int d, int m, int y) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}


void printCalendar(int month, int year) {
    int daysInMonth, i, currentDay;

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days[1] = 29;


    printf("  ****  Calendar - %d/%d  ****\n", month, year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");


    currentDay = dayOfWeek(1, month, year);

    for (i = 0; i < currentDay; i++)
        printf("     ");

    for (i = 1; i <= days[month-1]; i++) {
        printf("%5d", i);
        if (++currentDay > 6) {
            currentDay = 0;
            printf("\n");
        }
    }

    if (currentDay != 0)
        printf("\n");
}



void main(){

   int cho;
   system("cls");
   printf("**welocme to the airlines**\n");
   printf("1.check flight avalilablity\n");
   printf("2.book tickets\n");
   printf("enter your choice\n");
   scanf("%d",&cho);

  switch (cho)
   {
     case 1:
     {
       int month, year,da,mm;
       printf("Enter month and year (MM YYYY) in which you want to travel in the given format:");
       scanf("%d %d", &month, &year);
       printCalendar(month, year);
       printf("choose the date on which you want to travel(dd mm) in the given format");
       scanf("%d%d",&da,&mm);
       if(da==15||21||03){

                FILE *fp=fopen("air.txt", "r");

            if(fp==NULL){
                   printf("Error opening File\n");
                   return ;
                   }
            char a[70];
            while(fscanf(fp," %[^\n]",a)!=EOF){
                    printf("%s\n",a);
                 }
            break;
       }

   }
   }
}
/*Available flights from source to destination are:
source:mumbai
destination:paris
airline:fly emirates
prices:80,000-1,50,000*/
