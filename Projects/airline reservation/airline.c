#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


void book();
void check();
char* options();
int calendar();
void start(){
    start:
    printf("Welcome to OMG AirLines..!\n");
    printf("\n----------------------------------\n");
    printf("Press 1 to BookTickets!\n");
    printf("Press 2 to check Upcoming flights!\n");
    printf("Press 3 to exit...!!\n");
    printf("\n----------------------------------\n");
    int a;
    scanf("%d",&a);
    if(a==3){
        printf("Exiting...!!\n");
        return ;
    }
    switch(a){
        case 1:
            book();
            break;
        case 2:
            check();
            break;
        default:
            printf("Please Choose correct option!\n");
            goto start;
            break;
    }
}
int calendar(int mon,int dat){
    int year = 2024;
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_mon=mon-1;
    mktime(&date);
    printf("\n----------------------------------\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < date.tm_wday; i++) {
        printf("    ");
    }
    int c=0;
    while (date.tm_mon == mon-1) {
        printf("%3d ", date.tm_mday);
        if(dat==date.tm_mday){
            c=dat;
        }
        if (date.tm_wday == 6) {
            printf("\n");
        }
        date.tm_mday++;
        mktime(&date);
    }
    printf("\n----------------------------------\n");
    return dat;
}
char* options(int a){
    if(a==1){
        return "BBSR";
    }
    else if(a==2){
        return "banglore";
    }
    else if(a==3){
        return "chennai";
    }
    else if(a==4){
        return "delhi";
    }
    return "NULL";
}
void book(){
    char *source[4]={"BBSR", "banglore", "chennai","delhi"};
    char *destination[4]={"BBSR", "Banglore", "chennai","Delhi"};
    choose:
    printf("\nChoose your Starting Location: \n");
    printf("\n----------------------------------\n");
    printf("\n Press 1 for BBSR");
    printf("\nPress 2 for Banglore");
    printf("\nPress 3 for chennai");
    printf("\nPress 4 for delhi");
    printf("\n----------------------------------\n");
    int a;
    scanf("%d",&a);
    char *so=options(a);
    printf("\nChoose your Destination: ");
    printf("\n-----------------------------------");
    printf("\n Press 1 for BBSR");
    printf("\nPress 2 for Banglore");
    printf("\nPress 3 for chennai");
    printf("\nPress 4 for delhi");
    printf("\n-----------------------------------\n");
    int a1;
    scanf("%d",&a1);
    char *de=options(a1);
    if(strcmp(de,so)==0){
        system ("cls");
        printf("Both source and destination must be different\n");
        printf("\n----------------------------------\n");
        goto choose;
    }
    else{
        printf("Okay...\n");
        date:
        printf("\nEnter the month and date to travel:");
        int mon,dat;
        scanf("%d %d",&mon,&dat);
       int c= calendar(mon,dat);
       FILE *ptr;
       ptr=fopen("air_line.txt","r");
       if(ptr==NULL){
            printf("Error opening a file");
            return ;
       }
       char res[100];
       char *date;
       sprintf(date,"%d",dat);
       while(fgets(res,sizeof(res),ptr)){
            if(strstr(res,"source:")&& strstr(res,so)&&strstr(res,"destination:")&& strstr(res,de)&&strstr(res,"date:") && strstr(res,date)){
                printf("\n----------------------------------\n");
                printf("\nFlights Found Based on Your Search\n");
                printf("\n----------------------------------\n");
                printf("%s\n",res);
                printf("--------------------------------------------------\n");

                printf("\nThank You for visiting OMG Airlines.......!\n");
                return ;
            }
       }
       printf("\nNo Flights are available on that dates\n\n");
       printf("\n--------------------------------------------------\n");
       printf("\nThank You for visiting OMG Airlines.......!\n");
       fclose(ptr);
    }
}
void check(){

}
int main(){
    start();
    return 0;
}
