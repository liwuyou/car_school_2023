// 设置对管状态
int white = 0;
int black = 1;
int err;

// 红外对管左->右引脚为2,4,7,8,12,13
int infrared[7]={2,4,7,3,8,12,13};

void setup(){
  Serial.begin(9600);//串口初始化
  //红外对管引脚模式设置为输入上拉模式
  pinMode(infrared[0],INPUT_PULLUP);
  pinMode(infrared[1],INPUT_PULLUP);
  pinMode(infrared[2],INPUT_PULLUP);
  pinMode(infrared[3],INPUT_PULLUP);
  pinMode(infrared[4],INPUT_PULLUP);
  pinMode(infrared[5],INPUT_PULLUP);
  pinMode(infrared[6],INPUT_PULLUP);
}

void loop(){
  sensor();  
}

void sensor(){
  //读取 信号电平状态
  int a_1 = digitalRead(infrared[0]);
  int a_2 = digitalRead(infrared[1]);
  int a_3 = digitalRead(infrared[2]);
  int a_4 = digitalRead(infrared[3]);
  int a_5 = digitalRead(infrared[4]);
  int a_6 = digitalRead(infrared[5]);
  int a_7 = digitalRead(infrared[6]);
  // 检测哪一个对管为黑 ，并赋值为err,用于pid
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
  Serial.println(err);  //测试代码
}




