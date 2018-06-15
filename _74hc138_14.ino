#define button_up 6
#define button_down 7

int val1 = 0;
int old_val1 = 0;
int val2 = 0;
int old_val2 = 0;

void setup(){
  pinMode(button_up, INPUT_PULLUP);
  pinMode(button_down, INPUT);
  Serial.begin(9600);
  }

void loop(){
  val1 = digitalRead(button_up);
  val2 = digitalRead(button_down);
  if(val1 == HIGH && old_val1 == LOW){
    Serial.println("1");
    }else if(val1 == LOW){
      val1 = old_val1;
      }
  if(val2 == HIGH && old_val2 == LOW){
    Serial.println("2");
    }else if(val2 == LOW){
      val2 = old_val2;
      }
    delay(100);
  }
