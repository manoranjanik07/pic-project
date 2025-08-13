/*
 * File:   pictask.c
 * Author: ranja
 *
 * Created on June 24, 2025, 3:57 PM
 */


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
#pragma config WRT= OFF

#include <xc.h>

void delay(unsigned int t)
{
    while(t--);
}
int i,a=0,s=0;

void enable()
{
    RD1=1;
    delay(500);
    RD1=0;
    delay(500);
}

void lcd(char RS,char data)
{
    RD0=RS;
    PORTC=data;
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
    PORTA=PORTB=PORTC=PORTD=PORTE=0X00;
    TRISA=0X0F;
    TRISB=0X0F;
    TRISC=TRISD=TRISE=0X00;
    ANSEL=ANSELH=0X00;
    lcd(0,0X38);
    lcd(0,0X0E);
    lcd(0,0X80);
    
    while(1)
    {
        if(RA0==1)
        {
            a=0;
            lcd(0,0X01);
            lcd(0,0X80);
            string("GROUND FLOOR");
            
        }
    
             if(RA1==1)
               {
                 a=1;
                lcd(0,0X01);
                lcd(0,0X80);
                
                string("FIRST FLOOR");
                }
               
              if(RA2==1)
                    {
                        a=2;
                        lcd(0,0X01);
                        lcd(0,0X80);
                        string("SECOND FLOOR");
                    }
                if(RA3==1)
                {
                    a=3;
                    lcd(0,0X01);
                    lcd(0,0X80);
                    string("THIRD FLOOR");
                }
                      
                       if(RB0==1)
                         {
                           s=0;
                         }
                     
                
                      if(RB1==1)
                      {
                          s=1;
                      }
                        if(RB2==1)
                         {
                             s=2;
                         }
                          if(RB3==1)
                          {
                              s=3;
                          }
                if(a>s)
                {
                    RD5=1;
                    RD6=0;
                }
                if(a<s)
                {
                    RD6=1;
                    RD5=0;
                }
                if(a==s)
                {
                    RD5=0;
                    RD6=0;
                }
    }
                
}
