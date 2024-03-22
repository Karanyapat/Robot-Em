int LS = 2;       // left sensor
int RS = 3;       // right sensor
//การกำหนดเอาท์พุท
int LM1 = 4;      // left motor
int LM2 = 5;      // left motor
int RM1 = 6;      // right motor
int RM2 = 7;      // right motor
//PWMสำหรับควบคุมความเร็วมอเตอร์
int PWM1 = 10;    // PWM left motor
int PWM2 = 11;    // PWM right motor
int SPEED = 255;
int SPEED_L = 225;
int a = 0; 

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void loop() {
  if (!(digitalRead(LS)) && !(digitalRead(RS))) {    //เดินหน้า
    analogWrite(PWM1, SPEED_L);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  } 
  else if (!(digitalRead(LS)) && digitalRead(RS)) {  // เลี้ยวขวา
    analogWrite(PWM1, SPEED_L);                      // ลดความเร็ว
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);                        // ความเร็วปกติ
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  } 
  else if (digitalRead(LS) && !(digitalRead(RS))) {  // เลี้ยวซ้าย
    analogWrite(PWM1, SPEED_L);                        // ความเร็วปกติ
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);                      // ลดความเร็ว
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  } 

  // จะหยุดเมื่อเจอจุดตัด 3 เส้น
  if(digitalRead(LS) && digitalRead(RS)){
    a=a+1;
    if (a == 1){
    analogWrite(PWM1, SPEED_L);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
    if (a == 2){
    analogWrite(PWM1, SPEED_L);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
    if (a == 3){
    analogWrite(PWM1, SPEED_L);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
    if (a == 4){
    analogWrite(PWM1, 255);  
    analogWrite(PWM2, 255);                                       
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH); 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    }
  }
}