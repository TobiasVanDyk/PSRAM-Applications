#include <SPI.h>

const int SS_PIN = 6;

// set up the speed in hertz, mode and endianness of each device
SPISettings SPI23LC1024_RAM(30000000, MSBFIRST, SPI_MODE0 ); // Teensy 3.1 can only generate 30 MHz SPI when running at 120 MHz (overclock)

//Configuración SRAM
/*
#define RDSR        5
#define WRSR        1
#define READ        3
#define WRITE       2
*/
#define  OPCODE_RDSR   B00000101     /*05h Read Status Register */
#define  OPCODE_WRSR   B00000001     /*01h Write Status Register */
#define  OPCODE_READ   B00000011     /*03h Read Memory  | Addr Bytes 3 | 1 to ∞ */
#define  OPCODE_WRITE  B00000010     /*02h Write Memory | Addr Bytes 3 | 1 to ∞ */

//Byte transfer functions

uint8_t READ_RAM(uint32_t address) {
  uint8_t read_byte;

  SPI.beginTransaction(SPI23LC1024_RAM);
  digitalWriteFast(SS_PIN, LOW); // Enables SPI communication
  SPI.transfer(OPCODE_READ);

  SPI.transfer((uint8_t)(address >> 16)); // 24bit addr
  SPI.transfer((uint8_t)(address >> 8));
  SPI.transfer((uint8_t)(address & 0xFF));
  read_byte = SPI.transfer(0x00);
  digitalWriteFast(SS_PIN, HIGH); // Disable the SPI communication
  SPI.endTransaction();
  return read_byte;
}

void WRITE_RAM(uint32_t address, uint8_t data_byte) {
  SPI.beginTransaction(SPI23LC1024_RAM);
  digitalWriteFast(SS_PIN, LOW); // Enables SPI communication
  SPI.transfer(OPCODE_WRITE);  // We put the RAM in write mode
  SPI.transfer((uint8_t)(address >> 16)); // 24bit addr
  SPI.transfer((uint8_t)(address >> 8));
  SPI.transfer((uint8_t)(address & 0xFF));
  SPI.transfer(data_byte);   // We send the data to the RAM
  digitalWriteFast(SS_PIN, HIGH); //  Disable the SPI communication
  SPI.endTransaction();
}

void setup(void) {
  pinMode(SS_PIN, OUTPUT); // SPI 23LC1024_RAM / Set pin to Output.
  digitalWrite(SS_PIN, HIGH); // SPI 23LC1024_RAM / Set pin HIGH Disable.

  uint32_t i;
  uint8_t value;

  Serial.begin(9600);
  SPI.begin();

  while (!Serial) {
    ; // wait for serial port to connect.
  }
  delay(500);
  Serial.println(1);
  delay(500);
  Serial.println(2);
  delay(500);
  Serial.println(3);
  delay(500);
  Serial.println(4);
  delay(500);
  Serial.println(5);
  delay(500);

  for (i = 0; i < 40; i++) {

    WRITE_RAM(i, i + 5);
    value = READ_RAM(i);
    Serial.println((uint16_t)value);
  }
}

void loop() {
}
