#include <main.h>

#define BUT_1   input(PIN_B4)
#define BUT_2   input(PIN_B5)
#define BUT_3   input(PIN_B6)
#define BUT_4   input(PIN_B7)
int a=0,b=0,c=0,d=0;
#INT_RB
void interrupt()
{
   if(BUT_1==0)
   {
      a=1;
      while(BUT_1==0)
         {delay_ms(1);}
      while(a==1)
      {
      int8 i,m = 0b11111110;
         for(i=0;i<8;i++)
         {
            output_d(m);
            if(BUT_1==0||BUT_2==0||BUT_3==0||BUT_4==0)
            {
               a=0;
               break;
            }
            delay_ms(100);
            m=m<<1;
         }
      }
   }
   if(BUT_2==0)
   {
      b=1;
      while(BUT_2==0)
         {delay_ms(1);}
      while(b==1)
      {
      int8 i,m = 0b01111111;
         for(i=0;i<8;i++)
         {
            output_d(m);
            if(BUT_1==0||BUT_2==0||BUT_3==0||BUT_4==0)
            {
               b=0;
               break;
            }
            delay_ms(100);
            m=m>>1;
         }
      }
   }
   if(BUT_3==0)
   {
      c=1;
      while(BUT_3==0)
         {delay_ms(1);}
      while(c==1)
      {
      int8 i,m = 0b00000000;
            output_d(m);
            if(BUT_3==0||BUT_1==0||BUT_2==0||BUT_4==0)
            {
               c=0;
               break;
               while(BUT_3==0||BUT_1==0||BUT_2==0||BUT_4==0)
               {delay_ms(1);}
            }
            delay_ms(100);
            output_d(0xFF);
            delay_ms(100);
      }
   }
   if(BUT_4==0)
   {
      if(d==0)
      d=1;
      else d=0;
      while(BUT_4==0)
      {delay_ms(1);}
   }
   
}

void main()
{
   output_d(0xFF);
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);  
}
