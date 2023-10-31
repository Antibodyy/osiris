int right_front = 6;
int left_front = 7;
int right_back = 9;
int left_back = 10;

int execInterval = 50;
char inp = 's';

void setup() {
  pinMode(right_front,OUTPUT);
  pinMode(left_front,OUTPUT);
  pinMode(right_back,OUTPUT);
  pinMode(left_back,OUTPUT);
  Serial.begin(115200);
}


  
  void forwardMotion(int execInterval)
  {
    digitalWrite(right_front,HIGH);
    digitalWrite(left_front,HIGH);
    digitalWrite(right_back,HIGH);
    digitalWrite(left_back,HIGH);
    delay(execInterval);
  }

  void forwardRightMotion(int execInterval)
  {
    digitalWrite(right_front,LOW);
    digitalWrite(left_front,HIGH);
    digitalWrite(right_back,HIGH);
    digitalWrite(left_back,HIGH);
    delay(execInterval);
  }

  void forwardLeftMotion(int execInterval)
  {
    digitalWrite(right_front,HIGH);
    digitalWrite(left_front,LOW);
    digitalWrite(right_back,HIGH);
    digitalWrite(left_back,HIGH);
    delay(execInterval);
  }

  // NEED TO IMPLEMENT H-BRIDGE TO FACILITATE TRUE MOTION IN REVERSE DIRECTION

   void backwardLeftMotion(int execInterval)
  {
    digitalWrite(right_front,HIGH);
    digitalWrite(left_front,HIGH);
    digitalWrite(right_back,HIGH);
    digitalWrite(left_back,LOW);
    delay(execInterval);
  }

  void backwardRightMotion(int execInterval)
  {
    digitalWrite(right_front,HIGH);
    digitalWrite(left_front,HIGH);
    digitalWrite(right_back,LOW);
    digitalWrite(left_back,HIGH);
    delay(execInterval);
  }

  void backwardMotion(int execInterval)
  {
    digitalWrite(right_front,LOW);
    digitalWrite(left_front,LOW);
    digitalWrite(right_back,LOW);
    digitalWrite(left_back,LOW);
    delay(execInterval);
  }

  void station(char inp)
  {
    switch(inp)
    {
      case 'w':
        forwardMotion(execInterval);
        break;
      case 's':
        backwardMotion(execInterval);
        break;
      case 'q':
        forwardLeftMotion(execInterval);
        break;
      case 'e':
        forwardRightMotion(execInterval);
        break; 
      case 'a':
        backwardLeftMotion(execInterval);
        break;
      case 'd':
        backwardRightMotion(execInterval);
        break;  
      default :
        Serial.print("No Shit Sherlock\n");  
    }

  }

  void loop() {

  if (Serial.available() > 0)
  {
    inp = Serial.read();
  }
  else
  {
    backwardMotion(execInterval);
  }
    station(inp);

}

