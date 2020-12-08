/*
 * Ejemplo de como recibir los mensajes de IR
 * para poder verlos en el monitor Serie.
 */

#include <IRremote.h>
 
const int RECV_PIN = 10;
 
IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup()
{
   Serial.begin(9600);
   irrecv.enableIRIn();
}
 
void loop()
{
  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } 
    
    else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    }
    
    else if(results.decode_type == SAMSUNG){
      Serial.print("SAMSUNG: ");
    }
    
    else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } 
    
    else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } 
    else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    
    Serial.println(results.value, HEX);
    delay(200);
    //Después de recibir un mensaje IR, se tiene que volver a llamar
    //a la función resume() para resetear el receptor y prepararlo
    //para recibir el siguiente mensaje IR.
    irrecv.resume(); 
  }
}
