int StateSwitch = 0 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT); 
// призначення пінів 
void loop() {
   StateSwitch = digitalRead(2);// зчитуємо інформацію з другого піна
  if (StateSwitch == LOW) { // кнопка не натиснута
    digitalWrite(3, HIGH); // горить зелений світлодіод 
    digitalWrite(4, LOW); //  не горить червоний діод 
    digitalWrite(5, LOW); // не горить червоний діод 
  }
  else { // якщо кнопка увімкнена
    digitalWrite(3, LOW); // не горить зелений діод 
    digitalWrite(4, LOW);//  не горить червоний діод
    digitalWrite(5, HIGH);// горить червоний світлодіод 

    delay(250); // затримка в чверть секунди

    digitalWrite(4,HIGH); // горить червоний світлодіод 
    digitalWrite(5,LOW); // не горить зелений діод 
    delay(250);  // затримка в чверть секунди 
  }
} 
