int Moteur1_sens1 = 8;   // Pin 8 Arduino vers broche A+ du L293D
int Moteur1_sens2 = 2;   // Pin 2 Arduino vers broche A- du L293D
int Moteur2_sens1 = 7;
int Moteur2_sens2 = 4;
int moteur1_PWM = 9;    // Pin 9 Arduino PWM vers EN1 du L293D
int moteur2_PWM = 10; 
int PWM = 0;            // Variable PWM pour contrôler la vitesse

void setup() {
  Serial.begin(9600); // Ouverture du port série à 9600 bauds
  pinMode(moteur1_PWM, OUTPUT);    // Pin 9 en sortie PWM
  pinMode(moteur2_PWM, OUTPUT);
  pinMode(Moteur1_sens1, OUTPUT);   // Pin 8 en sortie digitale
  pinMode(Moteur1_sens2, OUTPUT);   // Pin 2 en sortie digitale
  pinMode(Moteur2_sens1, OUTPUT);
  pinMode(Moteur2_sens2, OUTPUT);
  delay(1000); // Attendre 1 seconde avant le lancement de la fonction d'accélération
  Acceleration(); // Lancer la fonction d'accélération
}

void loop() {
  return; // Pas d'action continue dans loop
}

// Accélère progressivement le moteur
void Acceleration() {
  for (PWM = 0; PWM <= 255; PWM++) {
    delay(10); // Pause de 10 ms
    digitalWrite(Moteur1_sens1, HIGH); // Activation de la broche A+
    digitalWrite(Moteur1_sens2, LOW);  // Désactivation de la broche A-
    analogWrite(moteur1_PWM, PWM);    // Envoyer la valeur PWM
    Serial.print("Valeur PWM : ");
    Serial.println(PWM);
  }
  delay(3000); // Pause de 3 secondes
  Deceleration(); // Enchaîne avec la décélération
}

// Ralentit progressivement le moteur
void Deceleration() {
  for (PWM = 255; PWM >= 0; PWM--) {
    delay(10);
    digitalWrite(Moteur1_sens1, HIGH);
    digitalWrite(Moteur1_sens2, LOW);
    analogWrite(moteur1_PWM, PWM);
    Serial.print("Valeur PWM : ");
    Serial.println(PWM);
  }
  // Arrêt du moteur
  digitalWrite(Moteur1_sens1, LOW);
  digitalWrite(Moteur1_sens2, LOW);
  delay(3000);
  Acceleration(); // Relance l'accélération (boucle infinie)


// Accélère progressivement le moteur
void Acceleration() {
  for (PWM = 0; PWM <= 255; PWM++) {
    delay(10); // Pause de 10 ms
    digitalWrite(Moteur2_sens1, HIGH); // Activation de la broche A+
    digitalWrite(Moteur2_sens2, LOW);  // Désactivation de la broche A-
    analogWrite(moteur2_PWM, PWM);    // Envoyer la valeur PWM
    Serial.print("Valeur PWM : ");
    Serial.println(PWM);
  }
  delay(3000); // Pause de 3 secondes
  Deceleration(); // Enchaîne avec la décélération
}

// Ralentit progressivement le moteur
void Deceleration() {
  for (PWM = 255; PWM >= 0; PWM--) {
    delay(10);
    digitalWrite(Moteur2_sens1, HIGH);
    digitalWrite(Moteur2_sens2, LOW);
    analogWrite(moteur2_PWM, PWM);
    Serial.print("Valeur PWM : ");
    Serial.println(PWM);
  }
  // Arrêt du moteur
  digitalWrite(Moteur2_sens1, LOW);
  digitalWrite(Moteur2_sens2, LOW);
  delay(3000);
  Acceleration(); // Relance l'accélération (boucle infinie)
}

