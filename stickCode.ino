const int trigger_front = 8; // front ultrasonic sensor
const int echo_front = 9; // front ultrasonic sensor
long distance_front;
const int Buzzer=4;
const int m=6;
   
void setup()
{
  Serial.begin(9600);
  pinMode(trigger_front, OUTPUT);
  pinMode(echo_front, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(m, OUTPUT);

  digitalWrite(Buzzer,LOW);
  digitalWrite(m,LOW);

}

void check_distance_front()
{
  long dis;
  digitalWrite(trigger_front, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_front, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger_front, LOW);
  dis = pulseIn(echo_front, HIGH);
  distance_front = dis/29/2;
  Serial.print("distance front:");
  Serial.println(distance_front);
}

void loop()
{
  check_distance_front();
  if(distance_front <=20)
  {
  digitalWrite(Buzzer,HIGH);
  digitalWrite(m,HIGH);
delay(1000);
  }
  else
  {
  digitalWrite(m,LOW);
  digitalWrite(Buzzer,LOW);
  }
 delay(100);
}
