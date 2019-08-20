#ifndef DEFINITIONS_H
#define DEFINITIONS_H

  // Pins for controlling lights with shift register
  #define LIGHTCLOCKPIN 11
  #define LIGHTLATCHPIN 12
  #define LIGHTDATAPIN 13

  // Pins for buttons
  #define STARTGAMEBUTTONPIN 6
  #define YELLOWBUTTONPIN 7
  #define REDBUTTONPIN 8
  #define GREENBUTTONPIN 9
  #define BLUEBUTTONPIN 10

  // Pins indexes for controlling display
  #define DISPLAYCLKPIN 5
  #define DISPLAYDIOPIN 4

  // Bit indexes for controlling lights with byte (using shiftregister)
  #define WHITELIGHTBIT 4
  #define YELLOWLIGHTBIT 5
  #define BLUELIGHTBIT 6
  #define REDLIGHTBIT 7
  #define GREENLIGHTBIT 8

#endif
