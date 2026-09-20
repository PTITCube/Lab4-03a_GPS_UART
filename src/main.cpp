/**
 * VÍ DỤ 4-3a: ĐỌC DỮ LIỆU ĐỊNH VỊ (GPS NMEA) BẰNG UART THUẦN
 */
#include <Arduino.h>

// GPS thường sử dụng Serial2 trên ESP32, với tốc độ Baud 9600
#define GPS_RX 16
#define GPS_TX 17
#define GPS_BAUD 9600

void setup() {
    Serial.begin(115200);
    while (!Serial) { delay(10); }

    Serial.println("\n[RAW] Đọc dữ liệu NMEA trực tiếp từ module GPS qua UART2...");
    
    // Khởi tạo Serial2 cho GPS
    Serial2.begin(GPS_BAUD, SERIAL_8N1, GPS_RX, GPS_TX);
}

void loop() {
    // Đọc byte thô từ GPS và in thẳng ra Serial màn hình
    while (Serial2.available() > 0) {
        char c = Serial2.read();
        Serial.print(c);
    }
}
