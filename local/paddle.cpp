#include "paddle.h"
#include "iostream"

void Paddle::Draw(){
  Rectangle rect = Rectangle{x, y, width, height};
  DrawRectangleRounded(rect, 0.8, 0, WHITE);
};

void Paddle::Update() {
  if (IsKeyDown(KEY_UP)) {
    y -= speed;
  }

  if (IsKeyDown(KEY_DOWN)) {
    y += speed;
  }

  LimitMovement();
};

void Paddle::LimitMovement() {
  if (y <= 0) {
      y =0 ;
  }
  
  if (y + height > GetScreenHeight()) {
    y = GetScreenHeight() - height;
  }
}

float Paddle::GetX() {
  return x;
}

float Paddle::GetY() {
  return y;
}

float Paddle::GetHeight() {
  return height;
}
