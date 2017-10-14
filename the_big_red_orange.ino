#include <IRremote.h>
#include <Servo.h>

 
#define up_key  41565
#define rocket_key 53295
#define left_key  57885
#define right_key  4845
#define down_key  25245
#define repeat_key  65535

int receiver_pin = 12;   
int pin = 7;
IRrecv receiver(receiver_pin); 
decode_results output;

Servo myservo; 

int pos;
int max = 110;
int min = 70;

void setup()
{
  Serial.begin(9600);
  myservo.attach(4);  // attaches the servo on pin to the servo object
  receiver.enableIRIn();  

  //pos = 90;    // variable to store the servo position
  pos = 0;
  
}
void up(){
  //motorruns
}

int left(int pos){
   Serial.println("in left");
   int i;
   for (i = 0; i <= 5; i += 1){
    pos = pos + 1;
 
    myservo.write(pos);
  
   }
  return pos;
}
int right(int pos){
  Serial.println("in right");
  int i;
   for (i = 5; i>= 0; i -= 1){
    pos = pos - 1;
    
    myservo.write(pos);
   }
  return pos;
}

void loop() {
  //save_state =
  //int pos = 0;
  
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    switch(value) {
       case up_key: 
         Serial.println("up");
         up();
         break; 
       case left_key:
         Serial.println("left");
         if (pos<max-5){
          pos = left(pos);
          Serial.print("this is the ");
          Serial.println(pos);
         }
         break;
       case right_key:
         Serial.println("right");
         if (pos>min+5){
          pos = right(pos);
          Serial.print("this is the ");
          Serial.println(pos);
         }
       case rocket_key:
        pinMode(pin,OUTPUT);
        digitalWrite(pin,HIGH);
        break;
       case repeat_key:
         //key_code = value;
         /*
         if(led[4] == 1) {       
            digitalWrite(fourth_led_pin, LOW);
            led[4] = 0;           
         } else {                      
             digitalWrite(fourth_led_pin, HIGH); 
             led[4] = 1;          
         }
         */
          break;
          
        default:
          break;        
    }
    Serial.println(value);
    //Serial.println(value); 
 
    
    receiver.resume(); 
  }
}

