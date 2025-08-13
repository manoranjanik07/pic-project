/*
 * File:   tempsensor.c
 * Author: ranja
 *
 * Created on June 23, 2025, 4:51 PM
 */


#include <xc.h>

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

#include<xc.h>

void delay(unsigned int t)
{
    while(t--);
}

void enable()
{
    RE1=1;
    delay(500);
    RE1=0;
    delay(500);
}

void lcd(char rs,char data)
{
    RE0=rs;
    PORTD=data;
    enable();
}

void main() 
{
    
    PORTA=PORTD=PORTE=0X00;
    TRISA=0X09;
    TRISD=TRISE=0X00;
    ANSEL=0X01;
    ANSELH=0X00;
    ADCON0=0X81;
    ADCON1=0XB0;
    lcd(0,0X38);
    lcd(0,0X0E);
    lcd(0,0X0C);
  //  lcd(0,0X01);
    lcd(0,0X80);
        
    int high,low,val;
    
    while(1)
    {
        GO=1;
        while(GO==1);
        {
            low=ADRESL;
            high=ADRESH;
            
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
        }
        
        lcd(0,0X80);
        //float volt=val*5/1023;
        
        int a=val%1000;
        int b=a/100;
        int c=a%100;
        int d=c/10;
        int e=c%10;
        
        lcd(1,((val/1000)+48));
        
        lcd(1,b+48);
        //lcd(1,46);
        lcd(1,d+48);
        lcd(1,e+48);
        
        lcd(0,0X85);
        float p=(float)val*150.0/1023.0;
            int q=(int)p*10;
            //lcd(1,(q/100)+48);
            int t=q%100;
            //lcd(1,(t/10)+48);
            lcd(1,'5');
            lcd(1,46);
            //lcd(1,(t%10)+48);
            if(1023>=150)
            {
                lcd(1,'0');
            }
            
            lcd(0,0X89);
            a=150/100;
            b=150%100;
            c=b/10;
            d=b%10;
            lcd(1,a+48);
            lcd(1,c+48);
            lcd(1,d+48);
            //lcd(0,0XDF);
            lcd(1,248);
            lcd(1,'C');
         
            
    }
}
            
            
        
        //int a=volt*10;
        //int b=a/10;
        //int c=a%10;
        
        /*lcd(1,b+48);
        lcd(1,46);
        lcd(1,c+48);*/
 