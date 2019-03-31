const int trig[3] = {2,3,4};
const int Echo[3] = {5,6,7};
const int out[3] = {8,9,10};
const int Size = 3;
const int switcher = A0;

void setup() {
  Serial.begin(115200);
  pinMode(trig[0],OUTPUT);
  pinMode(trig[1],OUTPUT);
  pinMode(trig[2],OUTPUT);
  pinMode(Echo[0],INPUT);
  pinMode(Echo[1],INPUT);
  pinMode(Echo[2],INPUT);
  pinMode(out[0],OUTPUT);
  pinMode(out[1],OUTPUT);
  pinMode(out[2],OUTPUT);
}

void loop() {
  int i = 0;
  long cm,duration;
  int state[Size];
  int sinal = analogRead(switcher);
  for(i=0;i<Size;i++)
  {
    sinal = analogRead(switcher);
    delayMicroseconds(5);
    digitalWrite(trig[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trig[i], LOW);
    pinMode(Echo[i], INPUT);
    
    duration = pulseIn(Echo[i], HIGH);
    cm = (duration/2) / 29.1;
    state[i] = (cm >= sinal)?1:0;
    Serial.print("Sensor No. ");
    Serial.print(i);
    Serial.print(" ; ");
    Serial.println((state[i]==1)?1:0);
    delay(200);
  }
  
  Serial.print("the all state are: ");
  int j=0;
  for(j=0;j<Size;j++){
    digitalWrite(out[j], (state[j]==1)?HIGH:LOW );
    Serial.print(state[j]);
    Serial.print("\t");
  }
  Serial.print("\n");
  delay(3000);
}
