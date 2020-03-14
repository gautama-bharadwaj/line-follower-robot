int data;                                     //Declaring Variables//
int data1;
int IN1 = 13;
int IN2 = 12;
int IN3 = 10;
int IN4 = 11;
void setup() {           
 pinMode(IN1, OUTPUT);        //Declaring input pins from the controller
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(7, OUTPUT);          //Declaring pins for power supply
 pinMode(6, OUTPUT);
digitalWrite(7, HIGH);       //Supplying power for the controller to make it start working
 digitalWrite(6, HIGH);
}

void loop() {

data = digitalRead(A0);  //A0 is right IR sensor// //Data read from the IR sensor//
data1 = digitalRead(A1); //A1 is left IR sensor//
    if(data==1 && data1==1)         //If data is one from both sensors, make the robot move forward//
    {
      forward();
    }
   else if(data==0 && data1==1)    //If data is one on the left and zero on the right, make it move right//
   {
    right();
   }
   else if(data==1 && data1==0)    //If data is zero on the left and one on the right, make it move right//
   {
   left();
   }
   else 
   {
    stop();
   }
}    
void forward()           //IN1 and IN2 controls the motor on the right and IN3 and IN4 controls the motor on the left//
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void left()                    //Function to make the robot move left//
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void right()                   //Function to make the robot move right//
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void stop()                    //Function to stop the robot from moving//
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
