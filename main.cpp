int moisture = 0;

int temperature = 0;

int light = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
}

void loop()
{
  delay(500);
  Serial.println("--------------------------");
  Serial.println("your plant information:");
  Serial.println("--------------------------");
  Serial.println("moisture:");
  moisture = map(analogRead(A1), 1023, 0, 0, 100);
  Serial.println(moisture);
  if (moisture >= 60) {
    Serial.println("too much moisture");
  }
  if (moisture <= 7) {
    Serial.println("the plant is too dry");
  }
  if (moisture > 7 && moisture < 60 ) {
    Serial.println("perfect moisture level");
  }
  Serial.println("--------------------------");
  Serial.println("your temperature:");
  temperature = map(analogRead(A0), 0, 1023, 0, 165);
  Serial.print(temperature);
  Serial.println("c*");
  if (temperature > 26) {
    Serial.println("too hot");
  }
  if (temperature < 22) {
    Serial.println("too cold");
  }
  if (temperature <= 26 && temperature >= 22) {
    Serial.println("perfect temp");
  }
  Serial.println("--------------------------");
  Serial.println("light level:");
  Serial.println(light);
  light = map(analogRead(A2), 0, 1023, 0, 100);
  if (light > 60) {
    Serial.println("too bright");
  }
  if (light < 20) {
    Serial.println("too dim");
  }
  if (light <= 60 && light >= 20) {
    Serial.println("perfect light");
  }
  Serial.println("--------------------------");
}
