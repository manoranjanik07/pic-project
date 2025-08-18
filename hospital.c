#include <stdio.h>
#include<string.h>

struct Patient
{
    char name[50];
    int age;
    char problem[100];
};
enum Doctor
 {
    CARDIOLOGIST=1,
    DENTIST,
    NEUROLOGIST,
    ORTHOPEDIC
};
int main()
{
    struct Patient p;
    int choice,available;
    int fees=0,c,amount,n,o,d,amount2,z,m;

    printf("KMCH Hospital Appointment\n");
    printf("Enter Patient Name: ");
    scanf("%s",p.name);
    printf("Enter Age: ");
    scanf("%d",&p.age);
    printf("Select Doctor for Appointment:\n");
    printf("1.Cardiologist\n2.Dentist\n3.Neurologist\n4.Orthopedic\n");
    printf("Enter choice:\n");
    scanf("%d",&choice);


   switch (choice)
    {
        case CARDIOLOGIST:
            printf("Dr.Ramesh\n");
            printf("Doctor:Cardiologist\n");
            printf("Dr.Suresh\n");
            printf("Doctor:Cardiologist\n");
            scanf("%d",&z);
            if (z==1)
            {
            printf("\nfees:500\n");
            scanf("%d",&c);
            if(c==500)
            {
              printf("Thank You!\n");
            }
            else if(c>500)
            {
              amount=c-500;
              printf("Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(c<500)
            {
                amount2=500-c;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                 printf("Insufficient amount");
                amount2=c-500;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                 }
            }
            }
            else
            {
            printf("Dr.Suresh\n");
            printf("Doctor:Cardiologist\n");
            printf("fees:100\n");
            scanf("%d",&c);
            if(c==100)
            {

              printf("Thank You!\n");
            }
            else if(c>100)
            {
              amount=c-500;
              printf("Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(c<100)
            {

                amount2=c-100;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                  printf("Insufficient amount");
                  amount2=c-500;
                  printf("balance amount:%d\n",amount2);
                 scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }

                 }
            }
            }
            break;
        case DENTIST:
            printf("Dr.Priya\n");
            printf("Doctor:Dentist\n");
            printf("Dr.Sudha\n");
            printf("Doctor:Dentist\n");
            scanf("%d",&z);
            if(z==1)
            {
            printf("fees:300\n");
            scanf("%d",&d);

            if(d==300)
            {
             printf("Thank You!\n");
            }
            else if(d>300)
            {
              amount=d-300;
              printf("Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(d<300)
            {
                amount2=d-300;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                  printf("Insufficient amount");
                 }
            }
           }
           else
           {
            printf("Dr.Sudha\n");
            printf("Doctor:Dentist\n");
            if(d==350)
            {
             printf("Thank You!\n");
            }
            else if(d>350)
            {
              amount=d-350;
              printf("Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(d<350)
            {
                amount2=350-d;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                  printf("Insufficient amount");
                 }
            }
           }
            break;
        case NEUROLOGIST:
            printf("Dr.Karthick\n");
            printf("Doctor:Neurologist\n");
            printf("Dr.Kumar\n");
            printf("Doctor:Neurologist\n");
            scanf("%d",&z);
            if(z==1)
            {
             printf("fees:700\n");
             scanf("%d",&n);

            if(n==700)
            {
             printf("Thank You!\n");
            }
           else if(n>700)
            {
              amount=n-700;
              printf("Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(n<700)
            {
                amount2=700-n;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                  printf("Insufficient amount");
                 }
            }
            }
            else
            {
               if(n==650)
            {
             printf("Thank You!\n");
            }
           else if(n>650)
            {
              amount=n-650;
              printf("Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(n<650)
            {
                amount2=650-n;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                  printf("Insufficient amount");
                 }
            }
            }
            break;
        case ORTHOPEDIC:
            printf("Dr.John\n");
            printf("Doctor:Orthopedic\n");
            printf("Dr.Julie\n");
            printf("Doctor:Neurologist\n");
            scanf("%d",&z);
            if(z==1)
            {
            printf("fees:400\n");
            scanf("%d",&o);

            if(o==400)
            {
             printf("Thank You!\n");
            }
            else if(o>400)
            {
              amount=o-400;
              printf(" Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(o<400)
            {
                amount2=400-o;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                  printf("Insufficient amount");
                 }
            }
            }
            else
                {
                if(o==420)
                {
                 printf("Thank You!\n");
                }
            else if(o>420)
            {
              amount=o-420;
              printf(" Take your balance amount:%d\n",amount);
              printf("Thank You!\n");

            }
            else if(o<420)
            {
                amount2=o-420;
                printf("balance amount:%d\n",amount2);
                scanf("%d",&m);
                if(m==amount2)
                {
                 printf("Thank You!\n");
                }
                else
                 {
                  printf("Insufficient amount");
                 }
            }
                }

        default:
            {
            printf("Appointment not booked\n");
            }
}

    printf("\nAppointment Confirmed\n");
    printf("Patient Name:%s\n",p.name);
    printf("Age:%d\n",p.age);
   // printf("Problem:%s\n",p.problem);
    printf("Your Appointment has been booked");
}
