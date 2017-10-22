int humidityPin = A0;
int tempPin = A1;
// alimentation du capteur d'humidité
// prendre une resistance de 270 ohms entre DigitalPin 7 et la broche Vcc du capteur
// ainsi, on a une étendue non saturée mais proche de 1024 lors de l'arrosage du capteur
int powerPin = 7;
int sensorValue = 0;

const int NB_MESURES = 40;
const int LOOP_TIME = 30000;
const int ARROSAGE_TIME = 5000;
const int HUMIDITY_THRESHOLD = 700;

const byte PWMA = 3;  // PWM control (speed) for pump
const byte DIRA = 12; // Direction control for pump

void setup() {
  Serial.begin(9600);
  pinMode(powerPin, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(DIRA, LOW);

  // amélioration de la précision de mesure
  analogReference(INTERNAL);
}

void loop() {
  digitalWrite(powerPin, HIGH);
  sensorValue = 0;
  for(int i = 0 ; i < NB_MESURES ; i++)
  {
    sensorValue += analogRead(humidityPin);
    delay(10);
  }
  digitalWrite(powerPin, LOW);
  sensorValue/=NB_MESURES;

  if(sensorValue < HUMIDITY_THRESHOLD)
  {
    StartArrosage();
  } else {
    StopArrosage();
  }

  // température
  int valeur_brute = analogRead(tempPin);
  float temperature_celcius = valeur_brute * (1.1 / 1023.0 * 100.0);
  
  // on envoie tout en JSON
  Serial.print("{\"humidity\":");
  Serial.print(sensorValue);
  Serial.print(", \"temperature\":");
  Serial.print(temperature_celcius);
  Serial.print ("}");
  Serial.println ();
  delay(LOOP_TIME);
}

void StartArrosage() {
  digitalWrite(DIRA, 1);
  analogWrite(PWMA, 20);
  delay(ARROSAGE_TIME);
  StopArrosage();
}

void StopArrosage() {
  digitalWrite(DIRA, 1);
  analogWrite(PWMA, 0);
}