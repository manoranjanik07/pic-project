
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<stdio.h>
#include<string.h>

void delay(unsigned int t)
{
    while(t--);
}
int low,high,val=0,f,j;
float v;
char s[20];
void enable()
{
    RE1=1;
    delay(5000);
    RE1=0;
    delay(5000);
}

void lcd(char rs,char data)
{
    RE0=rs;
    PORTD=data;
    enable();
}
 void string(char *str)
 {
     while(*str)
     {
         lcd(1,*str++);
     }
 }
void main()
 
{
    
    PORTA=PORTB=PORTD=PORTE=0X00;
    TRISD=TRISE=0X00;
    TRISB=0X01;
    ADCON0=0XB1;      //ADC AND AN12 CHANNEL ENABLE
    ADCON1=0X80;
    TRISA=0X03;
    ANSEL = 0X00;
    ANSELH = 0X10;
     lcd(0,0X38);
     lcd(0,0X0C);
     lcd(0,0X80);
     lcd(0,0X0E);
        
    while(1)
     {
      low=ADRESL;
      high=ADRESH;
      GO=1;
    while(GO==1)
    {
            
            lcd(0,0X80);
            if(high==0)
            {
                val=low; 
            }
            
            lcd(0,0X80);
            if(high==1)
            {
                val=low+256;
                 
            }
            
            lcd(0,0X80);
            if(high==2)
            {
                val=low+512;
                 
            }
            
            lcd(0,0X80);
            if(high==3)
            {
                val=low+768;
            }
      
            if(RA0==1)
            {
        lcd(0,0X80);
        v =(val*5.0)/1023.0;   //voltage
		
        string("CELCIUS:");
        j=v*100;                  // CELSIUS VALUE
        lcd(1,(j/100)%10+48);
        lcd(1,(j/10)%10+48);
        lcd(1,(j%10)+48);
        
         }
            if(RA1==1)
            {
                lcd(0,0xC0);
                string("FARENHEIT:");
                f=(j*9)/5+32;      //FARAENHEIT FORMULA
                /*lcd(1,(f/100)%10+48);
                lcd(1,(f/10)%10+48);
                lcd(1,(f%10)+48);*/
                sprintf(s,"%d",f);
                string(s);
            }
            if(f>98)
            {
                RB1=1;      //ABOVE BODY TEMPERATURE
            }
     }
}
}
