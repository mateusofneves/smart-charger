#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SOLAR_PIN 34
#define DEMANDA_PIN 35

#define BOTAO 18

#define LED_AMARELO 25   // Bateria
#define LED_AZUL 26      // Rede
#define LED_VERDE 27     // Solar

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int bateriaMax = 20; // kW
const int redeMax = 30;    // kW

bool telaResumo = true;
bool ultimoEstadoBotao = HIGH;

void setup() {

  Serial.begin(115200);

  pinMode(BOTAO, INPUT_PULLUP);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("GoodWe Smart");
  lcd.setCursor(0, 1);
  lcd.print("Charging Hub");

  delay(2000);
  lcd.clear();
}

void loop() {

  bool estadoBotao = digitalRead(BOTAO);

  if (ultimoEstadoBotao == HIGH && estadoBotao == LOW) {
    telaResumo = !telaResumo;
    delay(200);
  }

  ultimoEstadoBotao = estadoBotao;

  // Leitura dos potenciometros
  int solarADC = analogRead(SOLAR_PIN);
  int demandaADC = analogRead(DEMANDA_PIN);

  int solar = map(solarADC, 0, 4095, 0, 30);
  int demanda = map(demandaADC, 0, 4095, 0, 60);

  int restante = demanda;

  // Prioridade 1 - Solar
  int usoSolar = min(restante, solar);
  restante -= usoSolar;

  // Prioridade 2 - Bateria
  int usoBateria = min(restante, bateriaMax);
  restante -= usoBateria;

  // Prioridade 3 - Rede
  int usoRede = min(restante, redeMax);
  restante -= usoRede;

  // LEDs
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_AZUL, LOW);

  if (usoSolar >= demanda) {
    digitalWrite(LED_VERDE, HIGH);
  }

  if (usoBateria > 0) {
    digitalWrite(LED_AMARELO, HIGH);
  }

  if (usoRede > 0) {
    digitalWrite(LED_AZUL, HIGH);
  }

  // Atualiza LCD
  lcd.clear();

  if (telaResumo) {

    lcd.setCursor(0, 0);
    lcd.print("Solar:");
    lcd.print(solar);
    lcd.print("kW");

    lcd.setCursor(0, 1);
    lcd.print("Dem:");
    lcd.print(demanda);
    lcd.print("kW");

  } else {

    lcd.setCursor(0, 0);

    if (usoSolar >= demanda) {
      lcd.print("Fonte: Solar");
    }
    else if (usoRede > 0) {
      lcd.print("Sol+Bat+Rede");
    }
    else {
      lcd.print("Sol+Bateria");
    }

    lcd.setCursor(0, 1);

    if (restante > 0) {
      lcd.print("Sobrecarga!");
    } else {
      lcd.print("Operacao OK");
    }
  }

  // Serial Monitor
  Serial.println("\n===== ENERGY BRAIN =====");

  Serial.print("Solar Disponivel: ");
  Serial.print(solar);
  Serial.println(" kW");

  Serial.print("Demanda Total: ");
  Serial.print(demanda);
  Serial.println(" kW");

  Serial.print("Uso Solar: ");
  Serial.print(usoSolar);
  Serial.println(" kW");

  Serial.print("Uso Bateria: ");
  Serial.print(usoBateria);
  Serial.println(" kW");

  Serial.print("Uso Rede: ");
  Serial.print(usoRede);
  Serial.println(" kW");

  if (restante > 0) {
    Serial.println("STATUS: LIMITE DE POTENCIA");
  } else {
    Serial.println("STATUS: OPERACAO NORMAL");
  }

  delay(1000);
}
