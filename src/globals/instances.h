#ifndef GLOBALINSTANCES_H
#define GLOBALINSTANCES_H

#include <models/game.h>
#include <models/button.h>
#include <TM1637Display.h>

extern Game* game;
extern byte lightsByte; // Byte controlling the light -shift register
extern TM1637Display* display;

extern Button* startGameButton;
extern Button* yellowButton;
extern Button* blueButton;
extern Button* greenButton;
extern Button* redButton;


#endif