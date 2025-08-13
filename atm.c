#include<stdio.h>
int main()
{
 char a[10];
 int b,B=1000,d,e,f,count=0,i,y;
 printf("WELCOME TO INDIAN OVERSEAS BANK");
 printf("\nEnter the username:\t");
 scanf("%c",&a);

 if((a[0]=='r') &&(a[1]=='a')&&(a[2]=='n')&&(a[3]=='j')&&(a[4]=='a')&&(a[5]=='n')&&(a[6]=='i'))
 {
  printf("\nEnter the password:\t");
  scanf("%d",&b);
  if(b==123)
  {
    printf("ATM menu\n1)check balance\n2)deposit\n3)withdraw\n4)Exit");
    scanf("%d",&d);

if(d==1)
{
 if(b==123)
 {
  printf("menu\n1)check balance\n2)deposit\n3)withdraw\n4)Exit");
  scanf("%d",&d);


  if(d==1)
  {
    printf("%d",B);
  }
  else if(d==2)
  {
   printf("Enter the amount:");
   scanf("%d",&e);
  }
   if(e>B)
   {
    printf("Insufficient amount");
   }
   else
   {
     B=B-e;
     printf("Take your cash");
     printf("Balance Amount%d",B);
   }
  }
  else if(d==3)
  {
  printf("Enter the Amount:");
  scanf("%d",&f);
  B=B+f;
  printf("Balance Amount=%d",B);

  }

  else
  {
   printf("EXIT");
  }

 int z;
 scanf("%d",&z);
 if(z==1)
 {
    goto y;

 }
 else
    {
     printf("quit");
    }

 else
 {
  printf("Incorrect Password");
  count++;
  if(count<=2)
  {
      goto i;
  }

  else
  {
   printf("\nBlocked User ID");
  }
  }
 }
}
