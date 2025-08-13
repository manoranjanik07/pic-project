/*
 * File:   ultrasonic sensor.c
 * Author: ranja
 *
 * Created on July 1, 2025, 3:48 PM
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
//#define __XTAL_FREQ 4000000

void delay(unsigned int t)
{
    while(t--);
}

int time=0;float distance;

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
    PORTA=PORTB=PORTC=PORTD=PORTD=PORTD=PORTE=0X00;
    TRISB=TRISC=TRISD=TRISE=0X00;
    T1CON=0X07;
    TRISA=0X01;
    TMR1=0;
    
     lcd(0,0X38);
     lcd(0,0X0C);
     lcd(0,0X80);
        
        
    while(1)
    {
        TMR1=0;
        RA1=0;  //TR
        delay(10);
        RA1=1;
        delay(10);
        RA0=0;
        while(RA0==0);
        TMR1ON=1;
        while(RA0==0);   //ECHO
        TMR1ON=1;
        while(RA0==1)
        {
            TMR1ON=0;
            time=TMR1;
            delay(1000);
            distance=(float) time*0.0343/2;
            lcd(0,0X80);
            lcd(1,'A');
        }
    }
}
