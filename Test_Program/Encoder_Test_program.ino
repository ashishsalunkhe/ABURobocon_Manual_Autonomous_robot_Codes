
/*volatile int count = 0;
int speed = 0;
int flag = 0;


volatile int lastEncoded = 0;
volatile long encoderValue = 0;


void updateEncoder(){
  int MSB = digitalRead(2); //MSB = most significant bit
  int LSB = digitalRead(3); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) count ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) count --;

  lastEncoded = encoded; //store this value for next time
}


void encoder()
{
  
  updateEncoder();
}
void setup() {
  Serial.begin(115200);
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  pinMode(2,INPUT);
  pinMode(3,INPUT);

  digitalWrite(2, HIGH); //turn pullup resistor on
  digitalWrite(3, HIGH); //turn pullup resistor on
  
  attachInterrupt(digitalPinToInterrupt(2),encoder, LOW); 
}

void loop() {
  Serial.print("count = ");
  Serial.println(count);
  if (Serial.available())
  {
    char a = Serial.read();
    switch(a)
    {
      case 'a':
      speed+=5;
      analogWrite(4,speed);
      Serial.println(speed);
      break;

      case 's':
      speed-=5;
      analogWrite(4,speed);
      Serial.println(speed);
      break;

      case 'z':
      count = 0;
      break;

      case 't':
      //analogWrite(4,0);
      flag = 0;
      digitalWrite(5,LOW);
      break;

      case 'g':
      //analogWrite(4,0);
      flag = 1;
      digitalWrite(5,HIGH);
      break;
    }
  }
  
delay(100);
}*/
