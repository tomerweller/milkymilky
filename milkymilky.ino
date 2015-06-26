int STEP_MUL = 4;
int stp = 8; 
int dir = 9;  
int pump = 7;
int notsleep = 6;


void setup() 
{               
  Serial.begin(9600);
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);   
  pinMode(pump, OUTPUT);
  pinMode(notsleep, OUTPUT);
  digitalWrite(dir, HIGH);
  digitalWrite(pump, LOW);
  digitalWrite(notsleep, LOW);
  delay(200);
}


void step() {
    digitalWrite(stp, HIGH);   
    delay(20);               
    digitalWrite(stp, LOW);  
    delay(20); 
}

void startPumping() {

}

void loop() {
  for (int i=0; i<12; i++) {
    digitalWrite(notsleep, HIGH);
    delay(100);
    int count = i%3 == 0 ? 16*STEP_MUL : 17*STEP_MUL; 
    Serial.println(count);
    for (int j=0; j<count; j++) {
      step();
    }
//    digitalWrite(notsleep, LOW);
//    digitalWrite(pump, HIGH);
//    delay(100);
//    digitalWrite(pump, LOW);
    delay(2000);
  }
}
