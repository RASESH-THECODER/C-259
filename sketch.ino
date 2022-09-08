#include <Keypad.h>

#define row_num 4
#define col_num 4

String password="111111";
String input="";



char keys [row_num][col_num]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte row_pins [row_num]={19,18,5,17};
byte col_pins [col_num]={16,4,2,15};

Keypad keypad=Keypad(makeKeymap(keys),row_pins,col_pins,row_num,col_num);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("enter password:");
}

void loop() {
  char key=keypad.getKey();
  if(key){
    if(key=='#'){
      Serial.println();
      if(input.compareTo(password)==0){
        Serial.println("Acess Granted,Welcome");
        while(true);

      }
      else{
        Serial.println("Acess Denied");
        Serial.print("Try Again:");

      }
      input="";
    }
    else if(key=='*'){
      input="";
      Serial.println();
      Serial.print("password clear,try again");
    }
    else{
      input.concat(key);
      Serial.print(key);
    }
   

  }
}
