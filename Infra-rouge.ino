#include <DIYables_IRcontroller.h> // DIYables_IRcontroller library
#define IR_RECEIVER_PIN 11 // Arduino Uno pin connecter au recepteur infrarouge
#define IR_VCC_PIN 10 // Definition de la pin d'alimetation du recepteur infrarouge

int motor1pin1 = 2;
int motor1pin2 = 9;

int motor2pin1 = 12;
int motor2pin2 = 8;

DIYables_IRcontroller_21 irController(IR_RECEIVER_PIN, 200); // debounce time is 200ms

void setup() {
  Serial.begin(9600);
  irController.begin();
  pinMode(IR_VCC_PIN, OUTPUT);
  digitalWrite(IR_VCC_PIN, HIGH); // Alimentation recepteur infrarouge

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  //Arrêt des moteurs
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void loop() {
  Key21 key = irController.getKey();
  if (key != Key21::NONE) {
    switch (key) {
      case Key21::KEY_CH_MINUS:
        Serial.println("ON/OFF");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_CH:
        Serial.println("CH");
        //TODO: YOUR CONTROL
        break;

      case Key21::KEY_CH_PLUS:
        Serial.println("MENU");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_PREV:
        Serial.println("TEST");
        
        //Gauche

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
        
        delay (3000);

        //Droite

        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);

        delay (3000);

        //Avance

        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);

        delay (150);

        //Recule

        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, HIGH);

        delay (150);

        //Arrêt du moteur
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);

        break;

      case Key21::KEY_NEXT:
        Serial.println("Avance >>");

        //Mise en route du moteur  
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);

        delay (150);

        //Arrêt du moteur
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);
        break;

      case Key21::KEY_PLAY_PAUSE:
        Serial.println("Demi_Tour");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_VOL_MINUS:
        Serial.println("|<< Gauche");

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
        
        delay (200);

        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);

      case Key21::KEY_VOL_PLUS:
        Serial.println("Arret ><");
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);

        break;

      case Key21::KEY_EQ:
        Serial.println("Droite >>|");

        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);
        
        delay (150);

        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
        break;

      case Key21::KEY_100_PLUS:
        Serial.println("Recule <<");
        
        //Mise en route du moteur  
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, HIGH);

        delay (150);

        //Arrêt du moteur
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);
        break;

      case Key21::KEY_200_PLUS:
        Serial.println("C");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_0:
        Serial.println("0");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_1:
        Serial.println("1");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_2:
        Serial.println("2");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_3:
        Serial.println("3");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_4:
        Serial.println("4");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_5:
        Serial.println("5");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_6:
        Serial.println("6");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_7:
        Serial.println("7");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_8:
        Serial.println("8");
        // TODO: YOUR CONTROL
        break;

      case Key21::KEY_9:
        Serial.println("9");
        // TODO: YOUR CONTROL
        break;

      default:
        Serial.println("WARNING: undefined key:");
        break;
    }
  }
}
