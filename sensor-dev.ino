const int trigPin = 8, echoPin = 9, controller = A0, sinalPin = 11;
const int commutePin = 13;
long duration, cm, inches;

void setup(){
  Serial.begin(115200);
  pinMode(sinalPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(commutePin, OUTPUT);
}

void loop(){
  int sinal = analogRead(controller);
  int result;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  result = cm<sinal?1:0;

  Serial.print("sinal: "+String(sinal));
  Serial.print("\tDistance:\t");
  Serial.print(inches);
  Serial.print(" in\t");
  Serial.print(cm);
  Serial.print("cm");
  Serial.print("\t");
  Serial.println(result);
  digitalWrite(sinalPin, result);
  delay(250);
}
