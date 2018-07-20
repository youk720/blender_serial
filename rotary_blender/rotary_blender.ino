volatile uint8_t prev = 0;
bool flag_left = false;
bool flag_right = false;

#define led_1 7
#define led_2 6

void setup(){
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);

  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);
 // digitalWrite(2, HIGH);
 // digitalWrite(3, HIGH);

  Serial.begin(9600);
}

void updateEncoder(){
  uint8_t a = digitalRead(2);
  uint8_t b = digitalRead(3);

  uint8_t ab = (a << 1) | b;
  uint8_t encoded  = (prev << 2) | ab;




  if(encoded > 7){
  Serial.println(encoded, BIN);
//  char left_candidate[] = {0b1100, 0b1111};
//  char right_candidate[] = {0b1101, 0b1111};

  if(encoded == 0b1100){
    flag_left = true;
  }else if(encoded == 0b1110){
    flag_left = false;
  }else{
    flag_left = false;
  }
  if(encoded == 0b1110){
    flag_right = true;
//    }else if(encoded == 0b1100){
//    flag_right = false;
      }else{
     flag_right = false;
      }


//    for(int i=0; i<2; i++){
//      if(left_candidate[i] == encoded){
//        flag_left = true;
//          }else if(left_candidate[i - 1] == encoded || left_candidate[i + 1] == encoded){
//            flag_left = true;
////            }else if(right_candidate[i] == encoded){
////            flag_left = false;
//            }else{
//        flag_left = false;
//        break;
//      }
//    }
//    for(int m=0; m<2; m++){
//      if(right_candidate[m] == encoded){
//        flag_right = true;
//          }else if(right_candidate[m - 1] == encoded || right_candidate[m + 1] == encoded){
//            flag_right = true;
////            }else if(left_candidate[m] == encoded){
////            flag_right = false;
//            }else{
//        flag_right = false;
//        break;
//      }
//    }


  if(flag_left == true){
//    Serial.println("-0.5");
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
    delay(100);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
//    Serial.println("left");
  }
  if(flag_right == true){
//    Serial.println("+0.5");
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    delay(100);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
//    Serial.println("right");
  }
//  Serial.println(ab, BIN);
  //シリアル出力の部分の第二引数にBINを指定することで2進数で出力できる
  }
  prev = ab;
}

void loop()
{}
