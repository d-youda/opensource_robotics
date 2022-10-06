/*
 * 광센서를 사용하여 검정색과 흰색을 구분하는 아두이노 코드
 */
 //sensor 값 저장하는 value
 int sensorValue0 = 0;
 int sensorValue1 = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  sensorValue0 = analogRead(A0);
  sensorValue1 = analogRead(A1);
  delay(500);
  /*
  Serial.print("A0: ");
  Serial.print(sensorValue0);
  Serial.print(" A1: ");
  Serial.println(sensorValue1);
*/
  if(sensorValue0 >=300)
    Serial.println("오른쪽 광센서가 검은선 위에 있습니다.");
   else if(sensorValue0 < 300)
    Serial.println("오른쪽 광센서가 흰 색에 있습니다.");
    
   if(sensorValue1 >=300)
    Serial.println("왼쪽 광센서가 검은선 위에 있습니다.");
   else if(sensorValue1 < 300)
    Serial.println("왼쪽 광센서가 흰 색에 있습니다.");
}
