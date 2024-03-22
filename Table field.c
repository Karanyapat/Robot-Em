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
int SPEED = 130;  // ความเร็ว PWM (ค่าที่ลดลง)
int SPEED2 = 130;
int a = 0; //นับเส้นที่เจอ

void setup() {
  Serial.begin(9600);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
}
void forward(){
  analogWrite(PWM1, SPEED);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(PWM2, SPEED);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void left(){
  analogWrite(PWM1, SPEED);                      
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  analogWrite(PWM2, SPEED);                        
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

}

void right(){
  analogWrite(PWM1, SPEED);                        
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(PWM2, SPEED);                      
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

}

void stop(){                      
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);                   
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

}

void right_90(){
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  analogWrite(PWM1, SPEED);
  digitalWrite(RM1, 120);
  digitalWrite(RM2, LOW);
  delay(530);
 
}

void left_90(){
  digitalWrite(LM1, 120);
  digitalWrite(LM2, LOW);
  analogWrite(PWM2, SPEED);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  delay(530);

}

void spin(){
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(PWM2, SPEED);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
  delay(600);
}


void loop() {

  if (!(digitalRead(LS)) && !(digitalRead(RS))) {    //เดินหน้า
    forward();
  }if (!(digitalRead(LS)) && digitalRead(RS)) {  // เลี้ยวขวา
    left();
  }if (digitalRead(LS) && !(digitalRead(RS))) {  // เลี้ยวซ้าย
    right();
  } 

  // เงื่อนไข เปลี่ยนตามต้องการ
  if (digitalRead(LS) && digitalRead(RS)){                     
    a = a + 1;
    stop();

    if (a == 1) {
      stop();
      delay(500);
      forward();
    }
    if (a == 2) {
      stop();
      delay(500);
      forward();
    }
    if (a == 3) {
      stop();
      delay(500);
      left_90();                
    }
    if (a == 4) { 
      stop();
      delay(500);
      forward();             
    }
    if (a == 5) {
      stop();
      delay(500);
      forward();
    }
    if (a == 6) {
      stop();
      delay(500);
      left_90();                
    }
    if (a == 7) {
      stop();
      delay(500);
      forward();                
    }
    if (a == 8) { 
      stop();
      delay(500);
      left_90();             
    }
    if (a == 9) { 
      stop();
      delay(500);
      forward();             
    }
    if (a == 10) { 
      stop();
      delay(500);
      forward();             
    }
    if (a == 11) { 
      stop();
      delay(500);
      forward();             
    }
    if (a == 12) { 
      stop();
      delay(500);
      forward();             
    }
    if (a == 13) { 
      stop();
      delay(500);
      forward();             
    }
    if (a == 14) {
      stop();
      delay(500);
      forward(); 
    }
    if (a == 15) {
      stop();
      delay(15000);
    }
  }
}