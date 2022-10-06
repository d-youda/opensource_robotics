/*
 * 초음파 센서를 이용하여 거리 측정하는 아두이노 코드
 */
//변수 선언
const unsigned int TRIG_PIN = 9;
const unsigned int ECHO_PIN = 8;

void setup() {
  pinMode(TRIG_PIN , OUTPUT);
  pinMode(ECHO_PIN , INPUT);
  Serial.begin(9600); 
}

void loop() {
  //pulse 만들기
 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIG_PIN , HIGH);
 delayMicroseconds(10);//최소 10
 digitalWrite(TRIG_PIN, LOW);

 //측정된 값 처리
 const unsigned long duration = pulseIn(ECHO_PIN , HIGH);//pulse값을 재는 함수(pulseIn)
 int distance = duration/29/2;//microsecond -> cm/2(왕복 측정이기 때문)
 if(duration == 0)
 Serial.println("no pulse../n");
 else{
  Serial.print("distance :");
  Serial.print(distance);
  Serial.println("cm");
 }
 delay(100);
 
}
