//제어에 필요한 변수들
//회전 방향 정의
#define CW 1 //시계 방향
#define CCW 0 // 반시계방향

//바퀴 위치
#define MOTOR_LEFT 0 //왼쪽 바퀴
#define MOTOR_RIGHT 1//오른쪽 바퀴

//모터 제어 핀 번호
const byte PWMA = 3; //moter A 속도 제어
const byte DIRA = 12; // Moter A 회전 방향 제어
const byte PWMB = 11; //moter B 속도 제어
const byte DIRB = 13; // Moter B 회전 방향 제어

void setup() {
  // put your setup code here, to run once:
  pinMode(PWMA , OUTPUT);
  pinMode(PWMB , OUTPUT);
  pinMode(DIRA , OUTPUT);
  pinMode(DIRB , OUTPUT);

  //핀 상태 초기 0으로 설정-> 오작동 방지
  digitalWrite(PWMA , LOW);
  digitalWrite(PWMB , LOW);
  digitalWrite(DIRA , LOW);
  digitalWrite(DIRB , LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //오른쪽 모터를 시계 방향, 스피드 80으로 돌림
  //driveArdumoto(MOTOR_RIGHT , CCW, 80);
  //driveArdumoto(MOTOR_RIGHT , CW, 80);
  robotFoward(100);
  robotBackward(80);
}

//전진함수
void robotFoward(unsigned char velocity){
  driveArdumoto(MOTOR_RIGHT , CW , velocity);
  driveArdumoto(MOTOR_LEFT , CCW , velocity);
}

//후진 함수
void robotBackward(unsigned char velocity){
   driveArdumoto(MOTOR_RIGHT , CCW , velocity);
  driveArdumoto(MOTOR_LEFT , CW , velocity);
}

//우회전
void robotRight(unsigned char velocity){
  driveArdumoto(MOTOR_RIGHT , CCW , velocity);
  driveArdumoto(MOTOR_LEFT , CCW , velocity);
}

//좌회전
void robotaLeft(unsigned char velocity){
  driveArdumoto(MOTOR_RIGHT , CW , velocity);
  driveArdumoto(MOTOR_LEFT , CW , velocity);
}

//정지
void robotStop(){
  driveArdumoto(MOTER_RIGHT,CW,0);
  driveArdumoto(MOTER_LEFT,CW,0);
}

//기본 모터 활용 함수
void driveArdumoto(byte motor , byte dir , byte spd){
  if(motor == MOTOR_LEFT){
    digitalWrite(DIRA , dir);//DIRA의 회전 방향 dir로 변경
    analogWrite(PWMA , spd); // 아날로그 스피드 변경
  }
  else if(motor == MOTOR_RIGHT){
    digitalWrite(DIRB , dir);
    analogWrite(PWMB , spd);
  }
}
