#include <SD.h>

File myFile; // สร้างออฟเจค File สำหรับจัดการข้อมูล
String fileName = "cmlog.txt";
const int chipSelect = 4;

void setup(){

Serial.begin(9600);
 
 while (!Serial) {
   ; // รอจนกระทั่งเชื่อมต่อกับ Serial port แล้ว (สำหรับ Arduino Leonardo เท่านั้น)
 }

Serial.print("Initializing SD card...");
pinMode(SS, OUTPUT); // Slave select ตัว library มันจะขอให้เป็น OUTPUT เสมอ 

 if (!SD.begin(chipSelect)) {
  
Serial.println("initialization failed!");
 return;
 
 }
 
Serial.println("initialization done.");

 SD.remove(fileName); //ถ้าต้องการลบไฟล์ทิ้ง

// เปิดไฟล์ที่ชื่อ fileName เพื่อเขียนข้อมูล โหมด FILE_WRITE ===========================
myFile = SD.open(fileName, FILE_WRITE); 

 // ถ้าเปิดไฟล์สำเร็จ ให้เขียนข้อมูลเพิ่มลงไป
 if (myFile) {
Serial.print("Writing to " + fileName + "...");
myFile.println("arduino.codemobiles.com \ncounting.. 1, 2, 3."); // สั่งให้เขียนข้อมูล
myFile.close(); // ปิดไฟล์
Serial.println("done.");

 } else {
  
 // ถ้าเปิดไฟลืไม่สำเร็จ ให้แสดง error 
Serial.println("error opening "+fileName);
 }

 
 // เปิดไฟล์เพื่ออ่าน ==================================
myFile = SD.open(fileName); // สั่งให้เปิดไฟล์ชื่อ cmlog.txt เพื่ออ่านข้อมูล

 if (myFile) {
Serial.println(fileName + ":");
 // อ่านข้อมูลทั้งหมดออกมา
 
 while (myFile.available()) {
  
Serial.write(myFile.read());

 }
 
myFile.close(); // เมื่ออ่านเสร็จ ปิดไฟล์

 } else {
 // ถ้าอ่านไม่สำเร็จ ให้แสดง error 
Serial.println("error opening " + fileName);
 }
 
}

void loop(){
  

}
