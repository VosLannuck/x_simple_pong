#include "raylib.h"

class Paddle{
protected: 
  void LimitMovement();
public:
  float x, y;
  int speed;
  float width, height;

  void Draw();

  void Update();

  float GetX();
  float GetY();
  float GetHeight();

};
