#include <SPI.h>           // Biblioteca SPI para comunicação serial
#include <MFRC522.h>       // Biblioteca para controle do módulo RFID

#define RST_PIN 9          // Pino de reset do módulo RFID
#define SS_PIN 10          // Pino de seleção do módulo RFID

MFRC522 rfid(SS_PIN, RST_PIN);   // Instância da classe MFRC522

void setup() {
  Serial.begin(9600);   // Inicia a comunicação serial a 9600 bps
  SPI.begin();          // Inicia a comunicação SPI
  rfid.PCD_Init();      // Inicia o módulo RFID
}

void loop() {
  // Verifica se um cartão RFID está presente
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Lê o UID do cartão
    Serial.print("UID do cartao: ");

    String codigo = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
      

      codigo += String(rfid.uid.uidByte[i], HEX);

     
      
    }
    Serial.println(codigo);
    if(codigo == "25534211"){
      digitalWrite(7,1);
      delay(15);
      digitalWrite(7,0);
      delay(15);
    }
    // Aguarda 1 segundo
    delay(1000);
  }

}