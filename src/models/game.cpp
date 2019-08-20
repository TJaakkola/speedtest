#include <Arduino.h>
#include <models/game.h>
#include <QueueArray.h>
#include <globals/definitions.h>
#include <actions.h>
#include <globals/instances.h>

Game::Game() {
  this->isGameRunning = false;
  this->timer = new Timer();
  this->answers = new QueueArray<int>();
  this->currentValue = 0;
  this->score = 0;
}

Game::~Game() {
  delete timer;
  delete answers;
}

void Game::checkAnswer(int playerAnswer) {
  
  if(!this->answers->isEmpty() && playerAnswer == this->answers->peek()) {
    this->score += 1;
    display->showNumberDec(this->score);
    this->answers->pop();
  } else {
    Serial.print("Wrong answer. ");
    if(this->answers->isEmpty()) {
      Serial.print("No answers in queue. ");
    } else {
      Serial.print("Expected ");
      Serial.print(this->answers->pop());
      Serial.print(", Got ");
      Serial.println(playerAnswer);
    }
    this->endGame();
  }
}

void Game::startGame() {
  this->isGameRunning = true;
  this->score = 0;
  this->timer->startTimer();
  blinkOff(WHITELIGHTBIT - 1);
  display->showNumberDec(this->score);
}

void Game::endGame() {
  Serial.println("GAME OVER");
  this->isGameRunning = false;
  this->timer->stopTimer(); 
  this->currentValue = 0;
  blink(WHITELIGHTBIT - 1);
  lightsOff();
}

void Game::addValue() {
  if(this->answers->count() > 10) {
    Serial.println("You're not fast enough");
    this->endGame();
  } else {
    this->currentValue = int(random(YELLOWLIGHTBIT - 1, GREENLIGHTBIT));
    this->answers->push(this->currentValue);
    display->showNumberDec(this->score);
  } 
}

