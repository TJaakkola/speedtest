/**
 * Speedtest
 *
 */
#include <Arduino.h>
#include <models/game.h>
#include <globals/definitions.h>
#include <globals/instances.h>
#include <actions.h>

void setup() {
  // initialize pins for shift registers
  Serial.begin(115200);
 
  pinMode(STARTGAMEBUTTONPIN, INPUT_PULLUP);
  pinMode(YELLOWBUTTONPIN, INPUT_PULLUP);
  pinMode(GREENBUTTONPIN, INPUT_PULLUP);
  pinMode(REDBUTTONPIN, INPUT_PULLUP);
  pinMode(BLUEBUTTONPIN, INPUT_PULLUP);
  pinMode(LIGHTLATCHPIN, OUTPUT);
  pinMode(LIGHTDATAPIN, OUTPUT);
  pinMode(LIGHTCLOCKPIN, OUTPUT);

  lightsOff();
  blink(WHITELIGHTBIT - 1);
}

void loop() {
  if(startGameButton->isEventTriggered()) { startGameAction(); }
  if(blueButton->isEventTriggered()) { blueButtonAction(); }
  if(redButton->isEventTriggered()) { redButtonAction(); }
  if(yellowButton->isEventTriggered()) { yellowButtonAction(); }
  if(greenButton->isEventTriggered()) { greenButtonAction(); }
  if(game->isGameRunning) {
    if(game->timer->isBlinkOnEventTriggered()) {
      game->addValue(); 
      blink(game->currentValue);  
    } else if(game->timer->isBlinkOffEventTriggered()) {
      blinkOff(game->currentValue);
    }
  } 
}