#include <Servo.h> 
Servo myservo;  //创建一个舵机控制对象

int pos = 75;    // 该变量用与存储舵机中值的角度位置,各个车的不一样
int lift = 40;   //舵机打角限幅
int right = 100;

// 舵机PWM引脚9，左电机PWM引脚5,右电机PWM引脚6；
int servo = 9;  int motor1=5;  int motor2=6;

// 红外对管左->右引脚为2,4,7,8
int infrared[7]={2,4,7,3,8,12,13};

float err,last_err;   //pid 参数定义

int white = 0;   // 对光管检测状态
int black = 1;


void setup(){
  Serial.begin(9600);//串口初始化
  myservo.attach(servo);  // 该舵机由arduino第九脚控制

  //电机pwm引脚初始化，模式设置为输出模式
  pinMode(motor1,OUTPUT);  
  pinMode(motor2,OUTPUT);

  //红外对管引脚模式设置为输入上拉模式
  pinMode(infrared[0],INPUT_PULLUP);
  pinMode(infrared[1],INPUT_PULLUP);
  pinMode(infrared[2],INPUT_PULLUP);
  pinMode(infrared[3],INPUT_PULLUP);
  pinMode(infrared[4],INPUT_PULLUP);
  pinMode(infrared[5],INPUT_PULLUP);
  pinMode(infrared[6],INPUT_PULLUP);

  myservo.write(pos);

  //初始速度
  analogWrite(motor1,90);
  analogWrite(motor2,90);
}

void loop(){
  sensor();
  int control_turn =pos + pid();
  myservo.write(control_turn);  
}

void sensor(){
  int a_1 = digitalRead(infrared[0]);
  int a_2 = digitalRead(infrared[1]);
  int a_3 = digitalRead(infrared[2]);
  int a_4 = digitalRead(infrared[3]);
  int a_5 = digitalRead(infrared[4]);
  int a_6 = digitalRead(infrared[5]);
  int a_7 = digitalRead(infrared[6]); 
  if(a_1==white && a_2==white && a_3==white && a_4==black && a_5==white && a_6==white && a_7 ==white){
      err = 0;
  }
  else if(a_1==white && a_2==white && a_3==black && a_4==white && a_5==white && a_6==white && a_7 ==white){
      err = -1;
  }
  else if(a_1==white && a_2==black && a_3==white && a_4==white && a_5==white && a_6==white && a_7 ==white){
      err = -2;
  }
  else if(a_1==black && a_2==white && a_3==white && a_4==white && a_5==white && a_6==white && a_7 ==white){
      err = -3;
  }
  else if(a_1==white && a_2==white && a_3==white && a_4==white && a_5==black && a_6==white && a_7 ==white){
      err = 1;
  }
  else if(a_1==white && a_2==white && a_3==white && a_4==white && a_5==white && a_6==black && a_7 ==white){
      err = 2;
  }
  else if(a_1==white && a_2==white && a_3==white && a_4==white && a_5==white && a_6==white && a_7 ==black){
      err = 3;
  }  
}

int pid(){
  int output;
  float kp=10,ki=0.001,kd=0;
  float P,I,D;
  P = err;
  I += err;
  D = err - last_err;
  output = kp*P + ki*I + kd*D;
  last_err = err;
  return output;
}


