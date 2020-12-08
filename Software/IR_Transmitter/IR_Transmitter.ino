/*
 * Ejemplo sencillo de como enviar un mensaje IR. 
 * 
 * El emisor de IR hay que conectarlo al pin digital 3.
 * No se puede utilizar otro pin digital.
 * La principal desventaja del IR es que no sabes si el 
 * electrodoméstico o dispositivos electrónico ha recibido
 * el mensaje y ha hecho lo que tenía que hacer.
 * Básicamente no hay feedback.
 */

#include <IRremote.h>

IRsend irsend;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irsend.sendNEC(0x20DF10EF, 32); //Envia un mensaje IR de tipo NEC
  //irsend.sendSAMSUNG(0xE0E040BF, 32); //Envia un mensaje IR de tipo SAMSUNG
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
}
