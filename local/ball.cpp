#include "ball.h"
#include "iostream"
#include "raylib.h"

void Ball::Draw() {
  DrawCircle(x, y, radius, Yellow);
}

void Ball::Update() {
  x += speed_x;
  y += speed_y;

  if(y + radius >= GetScreenHeight() || y - radius <= 0 ) {
    speed_y *= -1;
  }

  if (x + radius >= GetScreenWidth()) {
    playerScore += 1;
    ResetBall();
  }

  if(x - radius <= 0) {
    cpuScore += 1;
    ResetBall();
  }

}


void Ball::ResetBall() {
  this->x = GetScreenWidth() / 2;
  this->y = GetScreenHeight() / 2;
}

float Ball::GetY() {
  return y;
}

float Ball::GetX() {
  return x;
}

float Ball::GetRadius() {
  return radius;
}
