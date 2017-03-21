#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)
#use standard_io(b)
#define retardo 500

void error();

void main (void){
   set_tris_a(0b00010000); //habilito port como input
   set_tris_e(0b00000000); //habilito port como input
   
   int16 resultado=0;
   int8 operacion=0;
   int8 operando1=0,operando2=0;
   setup_oscillator(OSC_32MHZ);
   //SETUP_ADC_PORTS(0X00);
   while(True){
   operando1=input_c();
   operando2=input_d();
   //output_an(0b00000000);
   /*si el pushboton es precionado, esto tendra un valor decimal o binario
   como se quiera representar y cada valor tendra su operacion
   8 es +, 16 es -, 32 es * y 64 es /
   */
   operacion=input(PIN_B3); // guarda valor 0b00001000;+
   operacion=input(PIN_B4); // guarda valor 0b00010000;-
   operacion=input(PIN_B5); // guarda valor 0b00100000;*
   operacion=input(PIN_B6); // guarda valor 0b01000000;/
   if(operacion == 8)
   {
   operacion=input(PIN_B3);
   operacion=input(PIN_B4);
   operacion=input(PIN_B5);
   operacion=input(PIN_B6);
   
   //operando2=input_d();
<<<<<<< HEAD
<<<<<<< HEAD
   if(input(PIN_B3) == 1)
   {
=======
   if(input(PIN_B3) == 1){
>>>>>>> parent of 6964812... operacion if
=======
   if(input(PIN_B3) == 1){
>>>>>>> parent of 6964812... operacion if
   resultado = operando1 + operando2;
   }
   if(input(PIN_B4) == 1)
   {
   resultado = operando1 - operando2;
   }
   if(input(PIN_B5) == 1)
   {
   resultado = operando1 * operando2;
   }
   if(input(PIN_B6) == 1)
   {
   if(input_d()==0)
   {
   error();
   break;
   }
   resultado = operando1 / operando2;
   }
   }
}   
void error()
{
   int i;
   for(i=0;i<5;i++)
   {
   output_a(0b11111111);
   output_b(0b10000111);
   output_e(1);
   delay_ms(retardo);
   output_a(0b00000000);
   output_b(0b00000000);
   output_e(0);
   delay_ms(retardo);
   }
}
