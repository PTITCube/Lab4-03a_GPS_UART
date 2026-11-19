/**
 * LAB 4 - VÍ DỤ 03a: ĐỌC DỮ LIỆU ĐỊNH VỊ NMEA THÔ BẰNG UART THUẦN
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;

#define GPS_BAUD    9600
#define GPS_RX      16
#define GPS_TX      17

#define MUX_GPS_PIN 12
#define MUX_CAM_PIN 14

void setup() {
    cdh.begin(115200);

    // Cấu hình chân MUX 74HC4066: Chọn kênh GPS
    pinMode(MUX_GPS_PIN, OUTPUT);
    pinMode(MUX_CAM_PIN, OUTPUT);
    digitalWrite(MUX_CAM_PIN, LOW);
    delayMicroseconds(50);
    digitalWrite(MUX_GPS_PIN, HIGH);

    Serial2.begin(GPS_BAUD, SERIAL_8N1, GPS_RX, GPS_TX);
}

void loop() {
    while (Serial2.available() > 0) {
        char c = (char)Serial2.read();
        cdh.print(c);
    }
}
