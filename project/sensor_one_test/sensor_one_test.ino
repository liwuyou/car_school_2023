int white = 0;
int black = 1;

void setup(){
  Serial.begin(9600);//串口初始化
  pinMode(2,INPUT_PULLUP);//红外对管引脚模式设置为输入上拉模式
}

void loop(){
  int a_1 = digitalRead(2);
  Serial.println(a_1);
}

