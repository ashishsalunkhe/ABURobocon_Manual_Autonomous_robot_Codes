
int count = 0;
//int speed = 0;
//int flag = 0;


volatile int lastEncoded = 0;
volatile long encoderValue = 0;





void encoder()
{
  count++;
}

void setup() {
  Serial.begin(115200);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
  attachInterrupt(digitalPinToInterrupt(2),encoder, CHANGE); 
}

void loop() {
  Serial.print("count = ");
  Serial.println(count);

}
