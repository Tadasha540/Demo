#include<stdio.h>
#include<string.h>
#include<math.h>
void start();
void convert();
void binary_Values();
int bin_to_dec();
void bin_to_oct();
void bin_to_hexa();

void decimal_values();
void dec_to_binary();
void dec_to_oct();
void dec_to_hexa();

void octal_values();
void oct_bin();

void hexa_values();
void hexa_bin();

void wish();

void wish(){
    wis:
    printf("----------------------------------\n");
    printf("Do you want to Continue?\n");
    printf("Press Y to continue or press N to cancel.\n");
    printf("----------------------------------\n");
    char c;
    scanf("%c", &c);
    if (c == 'Y' || c='y')
    {
        system("cls");
        start();
    }
    else if(c=='N' || c=='n') {
        printf("Exiting...\n");
        return ;
    }
    else{
        printf("Please enter a valid Keyword.\n");
        goto wis;
    }
}
void start(){
    start:
    printf("press 1 for Binary Conversions\n");
    printf("Press 2 for Decimal Conversions\n");
    printf("Press 3 for Octal Conversions\n");
    printf("Press 4 for HexDecimal Conversions\n");
    printf("Press 5 for Exit Conversions\n");
    printf("----------------------------------\n");
    int option;
    scanf("%d", &option);
    if(option ==5){
        printf("Exiting.....!\n");
        return ;
    }
    else if(option>4){
        printf("Choose the correct option\n");
        printf("----------------------------------\n");
        goto start;
    }
    else{
        convert(option);
    }
}
void convert(int a){
    switch (a)
    {
    case 1:
        binary_Values();
        wish();
        break;
    case 2:
        decimal_values();
        wish();
        break;
    case 3:
        octal_values();
        wish();
        break;
    case 4:
        hexa_values();
        wish();
        break;
    default:
        break;
    }
}
void binary_Values(){
    bin:
    printf("Please Enter the Binary Value\n");
    char a[20];
    scanf("%s",a);
    for(int i=0;i<20;i++)
    {
        if(!a[i]==0 && !a[i]==1){
            printf("Enter the Binary Values only\n");
            goto bin;
        }
    }
   printf("Decimal value of %s is : %d\n",a,bin_to_dec(a));
    bin_to_oct(a);
    bin_to_hexa(a);

}
int bin_to_dec(char a[]){
    int dec=0;
    int c=0;
    for(int i=strlen(a)-1;i>=0;i--){
        dec=dec+(a[i]-'0')*(int)pow(2,c);
        c++;
    }
    return dec;
}
void bin_to_oct(char a[]){
    int dec=bin_to_dec(a);
    char a1[20];
   sprintf(a1,"%o",dec);
   printf("Octal value of %s is : %s\n",a,a1);
}
void bin_to_hexa(char a[]){
    int dec=bin_to_dec(a);
    char a1[20];
    sprintf(a1,"%x",dec);
    printf("Hexa value of %s is: %s\n",a,a1);
}

void decimal_values(){
    printf("Enter a decimal value:\n");
    int i;
    scanf("%d",&i);
    if(!i>0){
        printf("Enter a decimal value\n");
    }
    dec_to_binary(i);
    dec_to_oct(i);
    dec_to_hexa(i);
}
void dec_to_binary(int a){
    int c=0;
    int bin[20];
    int temp=a;
    while(a>0){
        bin[c++]=a%2;
        a=a/2;
    }
    printf("Binary value of %d is :",temp);
    for(int i=c-1;i>=0;i--){

        printf("%d",bin[i]);
    }
    printf("\n");
}
void dec_to_oct(int a){
    char dec[20];
    sprintf(dec, "%o",a);
    printf("Octal value of %d is :%s\n",a,dec);
}
void dec_to_hexa(int a){
    char hex[20];
    sprintf(hex, "%x",a);
    printf("Hexadecimal value of %d is :%s\n",a,hex);
}
void octal_values(){
    printf("Enter your Octal Number:\n");
    char i[20];
    scanf("%s",i);
    oct_bin(i);
}
void oct_bin(char a[]){
    int dec=0;
    int c=0;
    for(int i=strlen(a)-1;i>=0;i--){
        dec=dec+(a[i]-'0')*(int)pow(8,c);
        c++;
    }
    printf("Decimal Value of %s is :%d\n",a,dec);
    dec_to_binary(dec);
    dec_to_hexa(dec);
}

void hexa_values(){
     hexa:
    printf("Enter the hexadecimal Values\n");
    char c[20];
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++){
            if((c[i]>='0' && c[i]<='9') || (c[i]>='a' && c[i]<='f')){
            }
            else{
                printf("Invalid hexadecimal value\n");
                // system("cls");
                goto hexa;
            }
    }
    hexa_bin(c);
}
void hexa_bin(char a[]){
    int dec=0;
    int c=0;
    for(int i=strlen(a)-1;i>=0;i--){
        if((a[i]>='0' && a[i]<='9')){
            dec=dec+(a[i]-'0')*(int)pow(16,c);
        }
        else{
            dec=dec+(a[i]-'a'+10)*(int)pow(16,c);
        }
        c++;
    }
    printf("Decimal Value of %s is: %d\n",a,dec);
    dec_to_binary(dec);
    dec_to_oct(dec);
}
int main(){
    printf("Welcome to number Conversions!\n");
    start();
}
