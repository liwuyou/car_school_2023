/*
servo类下有以下成员函数
attach()//连接舵机
write()//角度控制
writeMicroseconds()//
read()//读上一次舵机转动角度
attached()//
detach()//断开舵机连接
*/

#include <Servo.h> 
Servo myservo;  //创建一个舵机控制对象
                          // 使用Servo类最多可以控制8个舵机
int pos = 0;    // 该变量用与存储舵机角度位置
/*~~~~~~~~~~~~~~~~~~~~~~~~~~华丽的分割线~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void setup() 
{ 
  myservo.attach(9);  // 该舵机由arduino第九脚控制
} 
/*~~~~~~~~~~~~~~~~~~~~~~~~~~华丽的分割线 ~~~~~~~~~~~~~~~~~~~~~~~~~~ */ 
void loop() 
{ 
  myservo.write(0); // 复位
  for(pos = 50; pos < 130; pos += 1)  // 从50度到130度运动 
  {                                                     // 每次步进一度
    myservo.write(pos);        // 指定舵机转向的角度
    delay(15);                       // 等待15ms让舵机到达指定位置
    
  } 
  for(pos = 130; pos>=50; pos-=1)   //从130度到50度运动  
  {                                
    myservo.write(pos);         // 指定舵机转向的角度 
    delay(15);                        // 等待15ms让舵机到达指定位置 
    Serial.println(myservo.read());
  } 


}

