//Agustin Menechino 6°1 PUNTO 6 Multiplexado de displays

//Agrego las librerias que voy a necesitar
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define PRENDER_DISPLAY_1 DDRB = 0b0000001;
#define PRENDER_DISPLAY_2 DDRB = 0b0000010;
#define PRENDER_DISPLAY_3 DDRB = 0b0000100;
#define PRENDER_DISPLAY_4 DDRB = 0b0001000;

#define NUMERO_0 PORTD = 0b0111111;
#define NUMERO_1 PORTD = 0b0000110;
#define NUMERO_2 PORTD = 0b1011011;
#define NUMERO_3 PORTD = 0b1001111;
#define NUMERO_4 PORTD = 0b1100110;
#define NUMERO_5 PORTD = 0b1101101;
#define NUMERO_6 PORTD = 0b1111101;
#define NUMERO_7 PORTD = 0b0000111;
#define NUMERO_8 PORTD = 0b1111111;
#define NUMERO_9 PORTD = 0b1100111;

char sum = 0; //Inicializo sum con el valor 0

void config_TIMER0(void)
{
  TCCR0A = (1 << WGM01);                //Activa el bit CTC (clear timer on compare match)
                                        //del TCCR0A (timer counter/control register)
    OCR0A = 155;                        //valor de comparacion de int cada 10ms
    TCCR0B = (1 << CS00) | (1 << CS01); 
    TIMSK0 = (1 << OCIE0A);             //Habilita las interrupciones en timer compare
}

void FUNCION_DISPLAY(char NUM_DISPLAY, char NUM)
{

  if (NUM_DISPLAY == 1) //Utilizo un if para preguntar si NUM_DISPLAY vale 1
  {
    PRENDER_DISPLAY_1; //si es verdadero prende el dIsplay 1
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

  if (NUM == 0) //Pregunto si num es igual a 0
  {
    NUMERO_0; //Si es verdadero muestra el numero 0
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
//Creo la funcion de NUMERO_MILES_CENTENA_DECENA_UNIDAD
void NUMERO_MCDU(char Mil, char Cent, char Dec, char Unid)
{
//Hasta que el char sum no sea 20 siempre va a pasar por ISR
//y el ISR lo va a sumar hasta que logre el numero pedido
  if (sum == 20)
  {
    FUNCION_DISPLAY(1, Mil);
  }

  if (sum == 40)
  {
    FUNCION_DISPLAY(2, Cent);
  }

  if (sum == 60)
  {
    FUNCION_DISPLAY(3, Dec);
  }

  if (sum == 80)
  {
    sum = 0;  //Cuando llegue hasta aca se reinicia el contador llevandolo a 0, empezando el ciclo otra vez
    FUNCION_DISPLAY(4, Unid);
  }
}

//Aca creo la funcion para descomponer un numero de 4 digitos
void NUM_ENTERO(int num)
{
  int Mil, Cent, Dec, Unid;

  Mil = num / 1000;
  Cent = (num - (Mil * 1000)) / 100;
  Dec = (num - (Mil * 1000 + Cent * 100)) / 10;
  Unid = (num - (Mil * 1000 + Cent * 100 + Dec * 10));

  if (sum == 20)   //Hasta que el char sum no sea 20 siempre va a pasar por ISR 
   {               //y el ISR lo va a sumar hasta que logre el numero pedido
    FUNCION_DISPLAY(1, Mil);
  }

  if (sum == 40)
  {
    FUNCION_DISPLAY(2, Cent);
  }

  if (sum == 60)
  {
    FUNCION_DISPLAY(3, Dec);
  }

  if (sum == 80)
  {
    sum = 0; //Cuando llegue hasta aca se reinicia el contador llevandolo a 0, empezando el ciclo otra vez
    FUNCION_DISPLAY(4, Unid);
  }
}

int main()
{

  config_TIMER0(); //Habilito timer
  sei();//interrupciones globales

  DDRD = 0XFF; //Pone todo el puerto "D" en 1

  while (1)
  {
    NUM_ENTERO(1730);
  }
}

ISR(TIMER0_COMPA_vect)
{
  sum++;
}