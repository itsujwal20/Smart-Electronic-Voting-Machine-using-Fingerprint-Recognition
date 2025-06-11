//Connect LCD To battery and make commmon ground by taking oin from arduino
// Fingerprint//Fpin-Vcc nd gnd//pin3of_FP-2ofaurdino//pin4ofFP-3odarduino
//SDA-A4//SCL-A5
//Buzzer-10
//RESULT and VOTING BUTTONS make as follows

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(2, 3);
const int buttonPin1 = 4;  
const int buttonPin2 = 5; 
const int buttonPin3 = 6;
const int buttonPinShowVotes = 8;
const int buzzer = 10;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonStateShowVotes = 0;

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

int id = 0, previous_voter_id = 0, vote_taken = 0;
int party_1_count = 0, party_2_count = 0, party_3_count = 0;
String winner_name = "";

void setup()  
{
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPinShowVotes, INPUT_PULLUP);
  
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  while (!Serial);
  delay(100);

  Serial.println("\n\nAdafruit finger detect test");

  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
  
  displayMessage("Smart Electronic", "Voting Machine");
  delay(3000);
}

void loop() {
  vote_taken = 0;
  displayMessage("Please place your", "finger");
  delay(100);

  id = getFingerprintIDez();
  
  if (id > 0) {
    displayMessage("Your Voter ID", String(id));
    delay(2000);

    if (id == 4) {
      determineWinner();
      displayMessage("Winner party", winner_name);
      while(1);
    }

    if (previous_voter_id != id) {
      handleVoting();
    } else {
      showDuplicateVoteWarning();
    }
  }

  buttonStateShowVotes = digitalRead(buttonPinShowVotes);
  if (buttonStateShowVotes == LOW) {
    showVoteCounts();
  }

  while (finger.getImage() != FINGERPRINT_NOFINGER) {
    delay(50);
  }
}

void determineWinner() {
  if ((party_1_count > party_2_count) && (party_1_count > party_3_count)) {
    winner_name = "BJP";
  } else if ((party_2_count > party_1_count) && (party_2_count > party_3_count)) {
    winner_name = "NCP";
  } else {
    winner_name = "Congress";
  }
}

void handleVoting() {
  do {
    displayMessage("Give Your vote", "Press Button");
    delay(500);

    previous_voter_id = id;
    buttonState1 = digitalRead(buttonPin1);
    delay(10);
    buttonState2 = digitalRead(buttonPin2);
    delay(10);
    buttonState3 = digitalRead(buttonPin3);
    delay(10);

    if (buttonState1 == LOW) {
      party_1_count++;
      vote_taken = 1;
    } else if (buttonState2 == LOW) {
      party_2_count++;
      vote_taken = 1;
    } else if (buttonState3 == LOW) {
      party_3_count++;
      vote_taken = 1;
    } else {
      vote_taken = 0;
    }

    if (vote_taken == 1) {
      displayMessage("Thanks for your", "vote");
      delay(200);  
      buzz();
    }
  } while (vote_taken == 0);
}

void showDuplicateVoteWarning() {
  displayMessage("Duplicate Vote", "buzzer on");
  buzz();
  buzz();
  buzz();
}

void buzz() {
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
}

void showVoteCounts() {
  displayMessage("BJP: " + String(party_1_count), "");
  delay(2000);
  displayMessage("NCP: " + String(party_2_count), "");
  delay(2000);
  displayMessage("Congress: " + String(party_3_count), "");
  delay(2000);
}

void displayMessage(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  Serial.println(line1);
  if (line2 != "") {
    Serial.println(line2);
  }
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return p;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return p;
  
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) return p;

  return finger.fingerID;
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) return -1;

  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  int minConfidence = 40;  // Adjust this value as needed

  if (finger.confidence < minConfidence) {
    Serial.println("Confidence level too low, try again.");
    return -1;
  }

  return finger.fingerID;
}
