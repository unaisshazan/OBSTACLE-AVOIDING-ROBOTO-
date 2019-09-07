/*
Code by: www.munphurid.com
M.Hashir

This is a code for OBSTACLE AVOIDING CAR.. It moves forward until an obstacle comes in its way.... When an obstacle comes in the way of car, it turns right

Hardware:
Is bought from www.munphurid.com
-Arduino UNO
-Motor driver module L298N
-Munphurid Chassis MN CS01 (Light weight 3 wheeler chassis can also be used)
-HC SR-04 ULTRASONIC SENSOR MODULE
-7V to 12V battery
-10 male to female wires

Connections:
Motor driver module and Arduino
-Connect IN1 to pin 8 of Arduino
-Connect IN2 to pin 13 of Arduino
-Connect IN3 to pin 9 of Arduino
-Connect IN4 to pin 6 of Arduino
-Connect ENA to pin 2 of Arduino
-Connect ENB to pin 7 of Arduino
-Connect 5V of module to 5V of Arduino
-Connect GND of module to GND of Arduino


Ultrasonic sensor module module and Arduino
-Connect ECHO of Bluetooth module to pin 10 of Arduino
-Connect TRIGGER of Bluetooth module to pin 11 of Arduino
-Connect VCC of Bluetooth module to 5V of Arduino
-Connect GND of Bluetooth module to GND of Arduino

Motors
Connect motors to motor driver module

Battery and all circuits
-Connect +ve wire of battery to 12V of motor driver module
-Connect -ve wire of battery to GND of motor driver module
*/


#define IN1 8      //IN1
#define IN2 13        //IN2
#define ENA 2          //ENA
#define ENB 7        //ENB
#define IN3 9          //IN3
#define IN4 6          //IN4
#define trigger 11      //Trigger
#define echo 10        //Echo


void stopm(void);
void forward(void);
void inputs(void);
void sharpright(void);

int duration;
float distance;

void setup(void)
{
  Serial.begin (9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
 }


void loop(void) {
 inputs();
if(distance<24){
  sharpright();
}
else
{
forward();
}
}



void forward(void)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void sharpright()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(400);
}




void stopm(void)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


void inputs()
{
      digitalWrite(trigger, LOW);
      delayMicroseconds(2); 
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);
      duration = pulseIn(echo, HIGH);
      distance = (duration / 2) / 29.1;
      digitalWrite(trigger, LOW); 
      
      Serial.print("forward Distance: ");
      Serial.println(distance);
}
