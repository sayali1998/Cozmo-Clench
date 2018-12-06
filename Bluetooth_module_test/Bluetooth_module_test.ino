char data = 0;            //Variable for storing received data

int rightforward=3;
int rightbackward=4;
int leftforward=5;
int leftbackward=6

void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(rightforward,OUPUT);
    pinMode(rightbackward,OUPUT);
    pinMode(leftforward,OUPUT);
    pinMode(leftbackward,OUPUT);
    digitalWrite(rightforward,LOW);
    digitalWrite(rightbackward,LOW);
    digitalWrite(leftforward,LOW);
    digitalWrite(leftbackward,LOW);
}



void releaseBlock()
{
  
  }


void pickBlock()
{
  
  }


void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      switch(data)
      {
        case '1'://Forward
                {
                  digitalWrite(rightforward,HIGH);
                  digitalWrite(leftforward,HIGH);
                  digitalWrite(rightbackward,LOW);
                  digitalWrite(leftbackward,LOW);
                  break;
                  }
        case '2'://Backward
                {
                  digitalWrite(rightforward,LOW);
                  digitalWrite(leftforward,LOW);
                  digitalWrite(rightbackward,HIGH);
                  digitalWrite(leftbackward,HIGH);
                  break;
                  }
        case '3'://HardLeft
                {
                  digitalWrite(rightforward,HIGH);
                  digitalWrite(leftforward,LOW);
                  digitalWrite(rightbackward,LOW);
                  digitalWrite(leftbackward,HIGH);
                  break;
                  }
        case '4'://HardRight
                {
                  digitalWrite(rightforward,LOW);
                  digitalWrite(leftforward,HIGH);
                  digitalWrite(rightbackward,HIGH);
                  digitalWrite(leftbackward,LOW);
                  break;
                  }
        case '5'://SoftLeft
                {
                  digitalWrite(rightforward,HIGH);
                  digitalWrite(leftforward,LOW);
                  digitalWrite(rightbackward,LOW);
                  digitalWrite(leftbackward,LOW);
                  break;
                  }
        case '6'://SoftRight   
                 {
                  digitalWrite(rightforward,LOW);
                  digitalWrite(leftforward,HIGH);
                  digitalWrite(rightbackward,LOW);
                  digitalWrite(leftbackward,LOW);
                  break;
                  }
        case '7'://Stop
                 {
                  digitalWrite(rightforward,LOW);
                  digitalWrite(leftforward,LOW);
                  digitalWrite(rightbackward,LOW);
                  digitalWrite(leftbackward,LOW);
                  break;
                  }     
        }
        if(data=='8')
        {
          releaseBlock();
          }
        if(data=='9')
        {
          pickBlock();
          }
   }
}

