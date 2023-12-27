#include <raylib.h>
class Ball {
public:
  int playerScore, cpuScore;
  float x, y;
  int speed_x, speed_y;
  int radius;

  Color Green = Color{38, 185, 154, 255};
  Color Dark_Green = Color {20, 160, 133, 255};
  Color Light_Green = Color {129, 204, 184, 255};
  Color Yellow = Color{243, 213, 91, 255};
  
  void Draw();
  void Update();
  void ResetBall();
  float GetY();
  float GetX();
  float GetRadius();

};
