//Observer dos botoes e responsavel pelo controle BLE
#include <XboxSeriesXControllerESP32_asukiaaa.hpp>
// Notação para uso de codigo em C dentro de um codigo CPP
extern "C"   {
  #include "Servo.h"
}

// Necessario pois identifica o dispositivo bluethoot
XboxSeriesXControllerESP32_asukiaaa::Core xboxController("14:cb:65:aa:ae:72");

void setup() {

    Serial.begin(9600);

    //Biblioteca para controlar o controle sem fio BLE
    Serial.println("Starting NimBLE Client");
    xboxController.begin();

    initServoUm();
    initServoDois();
    initServoTres();
    initServoQuatro();

} //fim da configuração dos parametros

//Super loop
void loop() {

    xboxController.onLoop();
    if (xboxController.isConnected()) {

        if((servoUmPos > 70) && xboxController.xboxNotif.btnA) {
            servoUmPos--;
            delay(1);
        };
        if((servoUmPos < 120) && xboxController.xboxNotif.btnY) {
            servoUmPos++;
            delay(1);
        };
        servoUmWrite(servoUmPos);
        Serial.printf("servoUmPos: %i\n", servoUmPos);
        delay(100);

        if((servoDoisPos > 60) && xboxController.xboxNotif.btnX) {
            servoDoisPos--;
            delay(1);
        };
        if((servoDoisPos < 120) && xboxController.xboxNotif.btnB) {
            servoDoisPos++;
            delay(1);
        };
        servoDoisWrite(servoDoisPos);
        Serial.printf("servoDoisPos: %i\n", servoDoisPos);
        delay(100);

        //ATENÇÂO, GATILHOS DO CONTROLE TEM VALORES CONTINUOS

        if((servoTresPos > 0) && (xboxController.xboxNotif.btnLB != 0)) {
            servoTresPos--;
            delay(1);
        };
        if((servoTresPos < 180) && (xboxController.xboxNotif.btnRB != 0)) {
            servoTresPos++;
            delay(1);
        };
        servoTresWrite(servoTresPos);
        Serial.printf("servoTresPos: %i\n", servoTresPos);
        delay(100);

        if((servoQuatroPos > 0) && (xboxController.xboxNotif.btnLS =! 0)) {
            servoQuatroPos--;
            delay(1);
        };
        if((servoQuatroPos < 180) && (xboxController.xboxNotif.btnRS =! 0)) {
            servoQuatroPos++;
            delay(1);
        };
        servoQuatroWrite(servoQuatroPos);
        Serial.printf("servoQuatroPos: %i\n", servoTresPos);
        delay(100);


    } else {
        Serial.print("not connected");

        Serial.println(" at " + String(millis()));

    }
}
