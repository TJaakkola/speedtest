#include <Arduino.h>
#include <globals/instances.h>
#include <models/game.h>
#include <globals/definitions.h>
#include <TM1637Display.h>

Game* game = new Game();
byte lightsByte = 0;
TM1637Display* display = new TM1637Display(DISPLAYCLKPIN, DISPLAYDIOPIN);

Button* startGameButton = new Button(STARTGAMEBUTTONPIN);
Button* yellowButton = new Button(YELLOWBUTTONPIN);
Button* blueButton = new Button(BLUEBUTTONPIN);
Button* greenButton = new Button(GREENBUTTONPIN);
Button* redButton = new Button(REDBUTTONPIN);