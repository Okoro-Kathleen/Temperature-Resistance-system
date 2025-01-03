#include <Thermometer.h>

void main()
{
   sys_init();
   
   while(TRUE)
   {
     lcd_clear();
     
     anVal = read_adc();
     delay_ms(100);
     
     Kath= anVal*5;
     bernie = kath/255;
     Ebi=bernie * 100;
     delay_ms(10);
     
     output_high(pin_c2);
     delay_ms(1000);
     
     
    
     lcd_clear();
     lcd_line2();
     printf(lcd_putc "Temp: %lu C", Ebi);
     lcd_gotoxy(9,2);
     lcd_putc(deg);
     delay_ms(1000);
  }
}
