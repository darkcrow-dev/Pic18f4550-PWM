#include <PwmPic.h>
#use delay(clock = 8000000)

int i;

void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   
   set_tris_C(0b00000000);

   output_low(PIN_C2);

   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DIV_BY_16, 249, 1);   // Set PWM frequency to 500Hz
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   
   setup_ccp1(CCP_PWM);                   // Configure CCP1 as a PWM

   setup_oscillator(OSC_8MHZ);            // Set internal oscillator to 8MHz
//Setup_Oscillator parameter not selected from Intr Oscillator Config tab

   while(TRUE)
   {
      for(i = 0; i < 250; i++)
      {
         set_pwm1_duty(i);
         delay_ms(50);
      }
   }
}
