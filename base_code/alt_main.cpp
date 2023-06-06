int moisture = 0; // משתנה לאחסון ערך הלחות
int temperature = 0; // משתנה לאחסון ערך הטמפרטורה
int light = 0; // משתנה לאחסון ערך התאורה

void setup()
{
  Serial.begin(9600); // הגדרת תקשורת סידורית במהירות 9600 ביטים לשנייה
  pinMode(A1, INPUT); // הגדרת כניסה אנלוגית A1 כקלט
  pinMode(A0, INPUT); // הגדרת כניסה אנלוגית A0 כקלט
  pinMode(A2, INPUT); // הגדרת כניסה אנלוגית A2 כקלט
}

void loop()
{
  delay(500); // השהייה של 500 מילישניות (חצי שנייה)

  Serial.println("--------------------------");
  Serial.println("your plant information:"); // מידע על הצמח שלך
  Serial.println("--------------------------");

  Serial.println("moisture:"); // לחות
  moisture = map(analogRead(A1), 1023, 0, 0, 100); // קריאת ערך הלחות והמיפוי לטווח 0-100
  Serial.println(moisture); // הדפסת ערך הלחות
  if (moisture >= 60) {
    Serial.println("too much moisture"); // רמת לחות גבוהה מדי
  }
  if (moisture <= 7) {
    Serial.println("the plant is too dry"); // הצמח יבש מדי
  }
  if (moisture > 7 && moisture < 60) {
    Serial.println("perfect moisture level"); // רמת לחות מתאימה
  }

  Serial.println("--------------------------");
  Serial.println("your temperature:"); // טמפרטורה
  temperature = map(analogRead(A0), 0, 1023, 0, 165); // קריאת ערך הטמפרטורה והמיפוי לטווח 0-165
  Serial.print(temperature);
  Serial.println("c*"); // הדפסת ערך הטמפרטורה עם יחידת מידה
  if (temperature > 26) {
    Serial.println("too hot"); // חם מדי
  }
  if (temperature < 22) {
    Serial.println("too cold"); // קר מדי
  }
  if (temperature <= 26 && temperature >= 22) {
    Serial.println("perfect temp"); // טמפרטורה מתאימה
  }

  Serial.println("--------------------------");
  Serial.println("light level:"); // רמת תאורה
  Serial.println(light); // הדפסת ערך התאורה
  light = map(analogRead(A2), 0, 1023, 0, 100); // קריאת ערך התאורה והמיפוי לטווח 0-100
  if (light > 60) {
    Serial.println("too bright"); // מואר מדי
  }
  if (light < 20) {
    Serial.println("too dim"); // חשוך מדי
  }
  if (light <= 60 && light >= 20) {
    Serial.println("perfect light"); // רמת תאורה מתאימה
  }

  Serial.println("--------------------------");
}
