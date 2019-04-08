#include <LiquidCrystal.h>

#include "DHT.h"   // Incluimos la librería

#define DHTPIN 2   // Definimos el valor de DHTPIN con el numero de puerto Analógico al que hayamos conectado el sensor.

#define DHTTYPE DHT11 //Definimos  el valor de DHTTYPE con el modelo del sensor

DHT sensort (DHTPIN, DHTTYPE); //Indicamos que usaremos un elemento de tipo DHT que se llamará sensort dentro de los paréntesis indicamos los valores definidos antes.

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Define los puertos a los que conectamos la pantalla es muy importante que los pongamos en el Orden que es empezando por el pin RS.

void setup() {
sensort.begin();  // Iniciamos el sensor.

Serial.begin(9600);  //Establecemos la velocidad de transmisión

lcd.begin(16, 2);   //Definimos el tamaño de nuestra pantalla para iniciarla.
}
void loop() {
int h = sensort.readHumidity();  //Lee la humedad y la guarda en la variable h
int t= sensort.readTemperature();//Lee la temperatura y la guarda en la variable t
        
lcd.setCursor(0,0);

lcd.print("Temperatura:");                  

lcd.setCursor(13,0);

lcd.print(t);//Escribe la temperatura

lcd.setCursor(15,0);

lcd.print("C");   

lcd.setCursor(0,1);

lcd.print("Humedad:");  

lcd.setCursor(10,1);

lcd.print(h);//Escribe la humedad

lcd.setCursor(12,1);

lcd.print("%");   
}
