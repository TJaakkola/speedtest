#include <Arduino.h>
#include <actions.h>
#include <models/game.h>
#include <globals/instances.h>
#include <globals/definitions.h>

// BUTTON ACTIONS
void startGameAction() {
  game->startGame();
  blinkOff(WHITELIGHTBIT - 1);
  lightsOff();
  Serial.println("start game pressed");
}

void yellowButtonAction() {
  if(game->isGameRunning) {
    game->checkAnswer(YELLOWLIGHTBIT - 1);
    Serial.print("yellow answer ");
    Serial.println(game->score);
  }
}

void redButtonAction() {
  if(game->isGameRunning) {
    game->checkAnswer(REDLIGHTBIT - 1);
    Serial.print("red answer ");
    Serial.println(game->score);
  }
}

void greenButtonAction() {
  if(game->isGameRunning) {
    game->checkAnswer(GREENLIGHTBIT - 1);
    Serial.print("green answer ");
    Serial.println(game->score);
  }
}

void blueButtonAction() {
  if(game->isGameRunning) {
    game->checkAnswer(BLUELIGHTBIT - 1);
    Serial.print("blue answer ");
    Serial.println(game->score);
  }
}

// LIGHT ACTIONS
void blink(int lightBit) {
  bitSet(lightsByte, lightBit);
  digitalWrite(LIGHTLATCHPIN, LOW);
  shiftOut(LIGHTDATAPIN, LIGHTCLOCKPIN, MSBFIRST, lightsByte);
  digitalWrite(LIGHTLATCHPIN, HIGH);
}

void lightsOff() {
  bitClear(lightsByte, YELLOWLIGHTBIT - 1);
  bitClear(lightsByte, BLUELIGHTBIT - 1);
  bitClear(lightsByte, REDLIGHTBIT - 1);
  bitClear(lightsByte, GREENLIGHTBIT - 1);
  digitalWrite(LIGHTLATCHPIN, LOW);
  shiftOut(LIGHTDATAPIN, LIGHTCLOCKPIN, MSBFIRST, lightsByte);
  digitalWrite(LIGHTLATCHPIN, HIGH);
}

void blinkOff(int lightBit) {
  bitClear(lightsByte, lightBit);
  digitalWrite(LIGHTLATCHPIN, LOW);
  shiftOut(LIGHTDATAPIN, LIGHTCLOCKPIN, MSBFIRST, lightsByte);
  digitalWrite(LIGHTLATCHPIN, HIGH);
}


