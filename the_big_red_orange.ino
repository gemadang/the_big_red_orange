#include <IRremote.h>
 
#define up_key  5355
#define left_key  29835
#define right_key  21675
#define repeat_key  65535

int receiver_pin = 8;   

int first_led_pin = 7;
int second_led_pin = 6;
int third_led_pin = 5;
int fourth_led_pin = 4;

int led[] = {0,0,0,0}; 
IRrecv receiver(receiver_pin); 
decode_results output;
 
void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();  
  /*
   * pinMode(first_led_pin, OUTPUT);
  pinMode(second_led_pin, OUTPUT);
  pinMode(third_led_pin, OUTPUT);
  pinMode(fourth_led_pin, OUTPUT);
   */
}
void up(){
  
}
void left(){
  
}
void right(){
  
}
void loop() {
  //save_state =
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    char key_code = "default";
    switch(value) {
       case up_key: 
         Serial.println("up");
         up();
         break; 
       case left_key:
         Serial.println("left");
         left()
          break;
       case right_key:
         Serial.println("right");
         right()
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
    
    //Serial.println(value); 
 
    //Serial.println(key_code); 
   
    receiver.resume(); 
  }
}
