//Agustin Menechino 6°1 PUNTO 4 Multiplexado de displays

//Agrego las librerias que voy a necesitar
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>


#define PRENDER_DISPLAY_1  DDRB = 0b0000001;
#define PRENDER_DISPLAY_2  DDRB = 0b0000010;
#define PRENDER_DISPLAY_3  DDRB = 0b0000100;
#define PRENDER_DISPLAY_4  DDRB = 0b0001000;

#define NUMERO_0           PORTD = 0b0111111;
#define NUMERO_1           PORTD = 0b0000110;
#define NUMERO_2           PORTD = 0b1011011;
#define NUMERO_3           PORTD = 0b1001111;
#define NUMERO_4           PORTD = 0b1100110;
#define NUMERO_5           PORTD = 0b1101101;
#define NUMERO_6           PORTD = 0b1111101;
#define NUMERO_7           PORTD = 0b0000111;
#define NUMERO_8           PORTD = 0b1111111;
#define NUMERO_9           PORTD = 0b1100111;

//Creo una funcion para luego definir que dIsplay voy a utilizar y que numero voy a mostrar en el dIsplay                                                   
void FUNCION_DISPLAY (char NUM_DISPLAY , char NUM) 
{

 if (NUM_DISPLAY == 1)        //Utilizo un if para preguntar si NUM_DISPLAY vale 1 
 {
   PRENDER_DISPLAY_1;         //si es verdadero prende el dIsplay 1
 }

  if (NUM_DISPLAY == 2)
 {
   PRENDER_DISPLAY_2;
 }

  if (NUM_DISPLAY == 3)
 {
   PRENDER_DISPLAY_3;
 }

  if (NUM_DISPLAY == 4)
 {
   PRENDER_DISPLAY_4;
 }

 if (NUM == 0)                //Pregunto si num es igual a 0
 {
   NUMERO_0;                  //Si es verdadero muestra el numero 0
 }

  if (NUM == 1)
 {
   NUMERO_1;
 }

  if (NUM == 2)
 {
   NUMERO_2;
 }

  if (NUM == 3)
 {
   NUMERO_3;
 }

  if (NUM == 4)
 {
   NUMERO_4;
 }

  if (NUM == 5)
 {
   NUMERO_5;
 }

  if (NUM == 6)
 {
   NUMERO_6;
 }

  if (NUM == 7)
 {
   NUMERO_7;
 }

  if (NUM == 8)
 {
   NUMERO_8;
 }

  if (NUM == 9)
 {
   NUMERO_9;
 }
 
}

int main()
{
DDRD = 0XFF; //Pone todo el puerto "D" en 1

while (1)
{
FUNCION_DISPLAY (1 , 1); //Procedo a elegir que display y numero quiero mostrar
}
}