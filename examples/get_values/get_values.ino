#include <SPI.h>
#include <IAM20380.h>

SPISettings settings(1000000, MSBFIRST, SPI_MODE0);
IAM20380 gyro(&SPI, settings, PA1);

void setup() {
    Serial.setTx(PA2);
    Serial.setRx(PA3);
    Serial.begin(115200);
    Serial.println("GYRO EXAMPLE");
    SPI.setMISO(PA6);
    SPI.setMOSI(PA7);
    SPI.setSCLK(PA5);
    gyro.begin();
}

void loop() {
    Serial.print("GRYO X:");
    Serial.println(gyro.gyro_x());
    Serial.print("GRYO Y:");
    Serial.println(gyro.gyro_y());
    Serial.print("GRYO Z:");
    Serial.println(gyro.gyro_z());
    Serial.println();
    delay(1000);
}