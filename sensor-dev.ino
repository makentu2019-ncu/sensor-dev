const int trigPin = 8, echoPin = 9, controller = 10;
long duration, cm, inches;

void setup(){
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  int sinal = analogRead(controller);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  Serial.print("sinal: "+String(sinal));
  Serial.print("\tDistance:\t");
  Serial.print(inches);
  Serial.print(" in\t");
  Serial.print(cm);
  Serial.print("cm");
  Serial.print("\t");
  Serial.println(cm<sinal);
  delay(250);
}
