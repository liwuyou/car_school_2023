// 设置对管状态
int white = 0;
int black = 1;
int err;

// 红外对管左->右引脚为2,4,7,8,12
int infrared[7]={2,4,7,8,12};

void setup(){
  Serial.begin(9600);//串口初始化
  //红外对管引脚模式设置为输入上拉模式
  pinMode(infrared[0],INPUT_PULLUP);
  pinMode(infrared[1],INPUT_PULLUP);
  pinMode(infrared[2],INPUT_PULLUP);
  pinMode(infrared[3],INPUT_PULLUP);
  pinMode(infrared[4],INPUT_PULLUP);
}

void loop(){
  sensor();  
}
void sensor(){
  int a_1 = digitalRead(infrared[0]);
  int a_2 = digitalRead(infrared[1]);
  int a_3 = digitalRead(infrared[2]);
  int a_4 = digitalRead(infrared[3]);
  int a_5 = digitalRead(infrared[4]);
  if(a_1==black && a_2==white && a_3==white && a_4==white && a_5==white){
      err = -2;
  }
  else if(a_1==white && a_2==black && a_3==white && a_4==white && a_5==white){
      err = -1;
  }
  else if(a_1==white && a_2==white && a_3==black && a_4==white && a_5==white){
      err = 0;
  }
  else if(a_1==white && a_2==white && a_3==white && a_4==black && a_5==white){
      err = 1;
  } 
  else if(a_1==white && a_2==white && a_3==white && a_4==white && a_5==black){
      err = 2;
  }
  Serial.println(err);  //测试代码
}





