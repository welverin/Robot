int JoyStick_X = 2; //x
int JoyStick_Y = 3; //y
  void setup() 
{
  Serial.begin(9600); // 9600 bps
}
void loop() 
{
  int x,y;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  Serial.print(x ,DEC);
  Serial.print(",");
  Serial.println(y ,DEC);
  delay(100);
}
