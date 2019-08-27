// motor one
int enA = 9;
int in1 = 8;
int in2 = 7;
// motor two
int enB = 6;
int in3 = 5;
int in4 = 4;

/*
//analogpins
int a0 = 0;
int a1 = 1;
int a2 = 2;
int a3 = 3;
int a4 = 4;
*/

//analogvalues
int val0 = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
//we want a1 and a2 to sense the black part

void setup()
{
  Serial.begin(9600);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop()
{
  sense_line();

  if (val0 > 300){
    move_car();
  }
  else{
    stop_car();
  }
  
 delay(10);
}


void sense_line()
{
  val0 = analogRead(A0);
  Serial.println(val0);
}


void move_car()
{
  // move forward
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 120);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 120);
  delay(10);
}

/*
  // now change motor directions (reverse)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  delay(2000);

*/


void stop_car()
{
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
