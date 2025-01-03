#include <16F876A.h>
#device ADC=8

#FUSES hs,NOWDT,PUT,NOBROWNOUT,NOLVP,PROTECT                    
#use fast_IO(A)
#use fast_IO(B)
#use fast_IO(C)
#use delay(crystal=20000000)

//#define LCD_DATA_PORT getenv("SFR:PORTB")
#define LCD_ENABLE_PIN  PIN_B3                                  
#define LCD_RS_PIN      PIN_B1                                    
#define LCD_RW_PIN      PIN_B2                                   
#define LCD_DATA4       PIN_B4                                  
#define LCD_DATA5       PIN_B5                                   
#define LCD_DATA6       PIN_B6                                    
#define LCD_DATA7       PIN_B7             

#include <lcd.c>


unsigned int8 anVal=0, deg=242;
unsigned int16 Ebi=0;
float Kath=0, bernie= 0;

void lcd_clear(){ 
     lcd_putc('\f');
     delay_ms(10);
}

//void lcd_line(unsigned int8 w){
//    if(w < 1) w = 1;
//    if(w > 2) w = 2;
//    lcd_gotoxy(1,w);
//    delay_ms(10);
//}

void lcd_line1(){
        lcd_gotoxy(1,1);
        delay_ms(10);
}

void lcd_line2(){
        lcd_gotoxy(1,2);
        delay_ms(10);
}
   
void sys_init(){
    output_a(0b00000000);
    output_b(0b00000000);
    output_c(0b00000000);
    set_tris_a(0b11111111);
    set_tris_b(0b00000000);
    set_tris_c(0b00000000);
    output_a(0b00000000);
    output_b(0b00000000);
    output_c(0b00000000);
    
    lcd_init();
    
    SETUP_ADC(ADC_CLOCK_INTERNAL);
    SETUP_ADC_PORTS(AN0);
    SET_ADC_CHANNEL(0);
   
    lcd_clear();
    lcd_line1();
    lcd_putc("     Digital");
    lcd_line2();
    lcd_putc("   Thermometer");
    delay_ms(2000);
}
         
