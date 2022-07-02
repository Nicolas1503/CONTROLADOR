/*
  Programa que almacena en direccion cero un valor de punto flotante y en direccion diez
  una cadena de caracteres y luego muestra en monitor serie.


*/

#include <EEPROM.h>       // libreria EEPROM

float temperatura = 27.50;      // asigna valor a variable de punto flotante
char cadena[] = "Hola esta es una prueba";  // crea cadena de caracteres con un texto

void setup() {
  Serial.begin(9600);       
  
  EEPROM.put(0, temperatura);     // almacena en direccion cero el punto flotante
  EEPROM.put(10, cadena);     // almacena en direccion diez la cadena

  Serial.println("Valor de punto flotante en direccion 0:");  // imprime texto
  Serial.println( EEPROM.get(0, temperatura) );     // obtiene valor de punto flotante
                // en direccion cero y muestra
  Serial.println(" ");            // espacio en blanco

  Serial.println("Valor de la cadena en direccion 10:");  // imprime texto
  Serial.println( EEPROM.get(10, cadena) );     // obtiene cadena de caracteres en 
}               // direccion diez y muestra

void loop() {         
}
