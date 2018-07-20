byte rotA = 2;
byte rotB = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(rotA, INPUT);
  pinMode(rotA, INPUT);

  attachInterrupt(0, encoder, CHANGE);
  attachInterrupt(1, encoder, CHANGE);

  digitalWrite(rotA, HIGH);
  digitalWrite(rotB, HIGH);

  Serial.begin(9600);
}

void encoder(){

  
  Serial.println(rotA);
  Serial.println(rotB);
  
  }


void loop() {
  // put your main code here, to run repeatedly:
}
