#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main ()
{
    int choice, a, b, result=0,y, rem;
    start:
        printf("\nWelcome to my calculator\n"); printf("\n 1. Add numbers");
        printf("\n 2. Subtract numbers");
        printf("\n 3. Multiply numbers");
        printf("\n 4. Divide Numbers");
        printf("\n 5. Exit");
        printf("\nEnter your choice:: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                {
                    add:
                        printf(" ******* Addition ********"); printf("\nEnter first number::");
                        scanf("%d", &a);
                        printf("\nEnter Second number::");
                        scanf("%d", &b); result = a+b; printf("\nAddition is :: %d", result);
                        printf("\n Do you want to continue ? (0/1)?\n");
                        scanf("%d",&y);
                        if (y==1)
                            {
                                system("cls");
                                goto add;
                            }
                            else
                                goto start;
                            break;
                            }
            case 2:
                {
                    sub:
                        printf(" ******* Subtraction ********"); printf("\nEnter first number::");
                        scanf("%d", &a);
                        printf("\nEnter Second number::");
                        scanf("%d", &b);
                        result = a-b;
                        printf("\nResult is :: %d", result);
                        printf("\n Do you want to continue ? (0/1)?\n");
                        scanf("%d",&y);
                         if (y==1)
                            {
                             system("cls");
                             goto sub;
                             }
                         else
                            goto start;
                         break;
                         }
         case 3:
             {
                 mul:
                     printf(" ******* Multiplication ********"); printf("\nEnter first number::");
                     scanf("%d", &a);
                     printf("\nEnter Second number::");
                     scanf("%d", &b);
                     result = a*b;
                     printf("\nResult is :: %d", result);
                     printf("\n Do you want to continue ? (0/1)?\n");
                     scanf("%d",&y);
                     if (y==1)
                        {
                            system("cls");
                            goto mul;
                        }
                     else
                        goto start;
                     break;
                     }
        case 4:
            {
                div:
                    printf(" ******* Division ********");
                    printf(" \n** Divisor must not be Zero **"); printf("\nEnter first number::");
                    scanf("%d", &a);
                    printf("\nEnter Second number::");
                    scanf("%d", &b);
                    if (b==0)
                        {
                            printf(" Its not possible");
                            goto start;
                        }
                    else
                        {
                          result = a/b; printf("\nQoutient is :: %d", result);
                          rem = a%b;
                          printf("\nRemainder is :: %d", rem);
                          }
                          printf("\n Do you want to continue ? (0/1)?\n");
                          scanf("%d",&y);
                          if (y==1)
                            {
                                system("cls");
                          goto div;
                          }
                          else
                            goto start;
                          break;
                          }
            default:
                printf("Bye");
                }
}

