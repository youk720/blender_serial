volatile uint8_t prev = 0;
#define led_1 7
#define led_2 6

void setup() 
{
  pinMode(2, INPUT); 
  pinMode(3, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  
  Serial.begin(9600);
}

void updateEncoder()
{
  uint8_t a = digitalRead(2);
  uint8_t b = digitalRead(3);
 
  uint8_t ab = (a << 3) | b;
  uint8_t encoded  = (prev << 4) | ab;

//  if(encoded == 0b1101 || encoded == 0b0100 || encoded == 0b0010 || encoded == 0b1011){
//    Serial.println(encoded);
//    digitalWrite(led_1, HIGH);
//    digitalWrite(led_2, LOW);
//    delay(2000);
//    digitalWrite(led_1, LOW);
//    digitalWrite(led_2, LOW);
//  } else if(encoded == 0b1110 || encoded == 0b0111 || encoded == 0b0001 || encoded == 0b1000) {
//    digitalWrite(led_1, LOW);
//    digitalWrite(led_2, HIGH);
//    delay(2000);
//    digitalWrite(led_1, LOW);
//    digitalWrite(led_2, LOW);
//  }

  if(ab == 0b0 && ab == 0b1000 && ab == 0b1001){
    }if(ab == 0b0){
      }if(ab == 0b0){
        } if(ab == 0b1000){
          }   if(ab == 0b1001){
                digitalWrite(led_1, HIGH);
                digitalWrite(led_2, LOW);
                delay(3000);
                digitalWrite(led_1, LOW);
                digitalWrite(led_2, LOW);
      }
   else if(ab == 0b0 && ab == 0b1001){  
       }if(ab == 0b0){
            }if(ab == 0b0){
              }if(ab == 0b1001){
                }if(ab == 0b1001){
                  digitalWrite(led_1, LOW);
                  digitalWrite(led_2, HIGH);
                  delay(3000);
                  digitalWrite(led_1, LOW);
                  digitalWrite(led_2, LOW);
        }
  
  Serial.println(ab, BIN);
//  Serial.println(encoded, BIN);
  prev = ab;
}

void loop()
{
   
}
