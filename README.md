# Lab4-03a_GPS_UART

**Đọc Dữ liệu Định vị NMEA Thô bằng UART Thuần**

Bài thực hành thuộc Phân hệ Cảm biến & Định vị (Lab 4) trong hệ thống PTITCube.

## 1. Mục tiêu
- Khởi tạo cổng truyền thông nối tiếp phần cứng **UART2** (GPIO 16 RX / GPIO 17 TX) với tốc độ baud `9600 bps`.
- Điều khiển IC chuyển mạch tương tự **MUX 74HC4066** (chọn GPS: GPIO 12 HIGH, ngắt Camera: GPIO 14 LOW).
- Đọc trực tiếp luồng byte ký tự ASCII từ module GPS và in thẳng ra Serial Monitor.
- Quan sát và nhận diện các bản tin NMEA 0183 thô nguyên bản (`$GNRMC`, `$GNGGA`, `$GNVTG`, `$GNGSA`, `$GNGSV`).

## 2. Phần cứng sử dụng
- **ESP32 NodeMCU OBC**
- **Module định vị GNSS:** Quectel L76X (tích hợp ăng-ten gốm Patch Antenna).
- **IC chuyển mạch:** 74HC4066 (chân chọn GPS: GPIO 12, chân chọn Camera: GPIO 14).
- **Cổng giao tiếp:** UART2 (RX2 = GPIO 16, TX2 = GPIO 17, Baudrate: `9600`).
- **Serial Monitor:** USB UART (Baudrate: `115200`).
