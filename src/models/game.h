#ifndef GAME_H
#define GAME_H

#include <models/timer.h>
#include <QueueArray.h>

class Game {
  public:
    Game();
    ~Game();
    void checkAnswer(int answer);
    void startGame();
    void endGame();
    void addValue();
    int currentValue;
    QueueArray<int>* answers;
    int score;
    bool isGameRunning;
    Timer* timer;
  private:
};

#endif