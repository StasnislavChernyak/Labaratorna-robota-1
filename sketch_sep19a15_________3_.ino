const int sensorPin = A0;
const float baselineTemp = 25.0; //початкова температура  
void setup() {
  Serial.begin(9600);
  for(int pinNumber = 2;pinNumber < 5;pinNumber ++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: "); // інформація яку ми бачимо на моніторі порту
  Serial.print(sensorVal);
  float Voltage = (sensorVal/1024.0)*5.0; // переретворення даних в наругу з датчика температури
  Serial.print(", Volts: "); // виивід даних напруги
  Serial.print(Voltage);
  Serial.print(", degrees C: "); // вивід даних температури 
  float temperature = (Voltage - 0.5)*100; // перетворення напруги в температуру
  Serial.println(temperature);
  if(temperature < baselineTemp){ // якщо температура нижча за початкову
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    //не горить жоден світлодіод
  }else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4){ // якщо температура відрізняється на 2 градуси але не більше ніж на 4 градуси від початкової
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    // горить тільки один світлодіод
  }else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6){ // якщо температура відрізняється на 4 градуси але не більше ніж на 6 градусів від початкової
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    // горить два світлодіоди
  }else if (temperature >= baselineTemp+6){ // якщо температура відрізняється більше ніж на 6 градусів від початкової
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    // горять всі світолдіоди
  }
 
  delay(10);
}
