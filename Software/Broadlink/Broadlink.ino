/*
 * Ejemplo de como controlar un electrodoméstico
 * que funcione con IR con Arduino. En este caso se controla
 * una televisión de marca Samsung, aunque el código se puede
 * modificar fácilmente para controlar otros dispositivos.
 */

#include <IRremote.h>

//Mensajes IR del mando universal (NEC)
const unsigned long OnOff = 0xFF629D;
const unsigned long channelUp = 0xFFE21D;
const unsigned long channelDown = 0xFFA25D;
const unsigned long volumeUp = 0xFFA857;
const unsigned long volumeDown = 0xFFE01F;

//Mensajes IR Samsung TV
const unsigned long tvOnOff = 0xE0E040BF;
const unsigned long tvChannelUp = 0xE0E048B7;
const unsigned long tvChannelDown = 0xE0E008F7;
const unsigned long tvVolumeUp = 0xE0E0E01F;
const unsigned long tvVolumeDown = 0xE0E0D02F;

const int RECV_PIN = 8;


IRrecv irrecv(RECV_PIN);
decode_results results;
IRsend irsend;

//Prototipos de las funciones
void samsungTVControl(unsigned long IRValue);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) { 
    samsungTVControl(results.value);
    //Hay que volver a llamar a enableIRIn
    //porque al utilizar el emisor se desactiva el receptor
    irrecv.enableIRIn();
    delay(200);
    //Después de recibir un mensaje IR, se tiene que volver a llamar
    //a la función resume() para resetear el receptor y prepararlo
    //para recibir el siguiente mensaje IR.
    irrecv.resume();
  }
  delay(200);
}

void samsungTVControl(unsigned long IRValue){
  switch(IRValue){
    case OnOff:
      irsend.sendSAMSUNG(tvOnOff, 32);
      break;

    case channelUp:
      irsend.sendSAMSUNG(tvChannelUp, 32);
      break;

    case channelDown:
      irsend.sendSAMSUNG(tvChannelDown, 32);
      break;

    case volumeUp:
      irsend.sendSAMSUNG(tvVolumeUp, 32);
      break;

    case volumeDown:
      irsend.sendSAMSUNG(tvVolumeDown, 32);
      break;
    
    default:
      Serial.println("Not Samsung TV IR Control");   
      break;
  }
}
