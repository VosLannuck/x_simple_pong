#include "ball.h"
#include "cpuPaddle.h"
#include<iostream>
#include<raylib.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 760;
const int MON_FPS = 60;

Ball ball;
Paddle player;
CpuPaddle cpu;

void SetBall();
void SetPlayer();
void SetCpu();
void DrawMainLine();
void CheckCollision();
void DrawScore();

int main() {

  std::cout<<"Starting the Game\n";
InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

  SetTargetFPS(MON_FPS);
  SetBall();  
  SetPlayer();
  SetCpu();
  while (WindowShouldClose() == false) {
    BeginDrawing();

    // Doing the physics/ and logic 
    ball.Update();
    player.Update();
    cpu.Update(ball.GetY());
    CheckCollision();
    // Drawing section
    ClearBackground(DARKGRAY);
    DrawMainLine();
    ball.Draw();
    player.Draw();
    cpu.Draw();
    DrawScore();
    EndDrawing();
  }
  CloseWindow();
  return 0;

}

void DrawMainLine(){
  DrawLine(SCREEN_WIDTH/2, 0,
           SCREEN_WIDTH/2, SCREEN_HEIGHT, WHITE);
}

void SetBall() {
  ball.radius = 20;
  ball.x = SCREEN_WIDTH / 2;
  ball.y = SCREEN_HEIGHT / 2;
  ball.speed_x = 7;
  ball.speed_y = 7;
}

void SetPlayer() {
  player.x = 10;
  player.y = SCREEN_HEIGHT / 2;
  player.width = 20;
  player.height = 120;
  player.speed = 5;
} 

void SetCpu() {
  cpu.x = SCREEN_WIDTH - cpu.width - 30;
  cpu.y = SCREEN_HEIGHT / 2;
  cpu.width = 20;
  cpu.height = 120;
  cpu.speed = 5;
}

void CheckCollision() {
  if(CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()},
                             ball.GetRadius(),  Rectangle{player.GetX(),
                             player.GetY(), player.width,
                             player.GetHeight()})) {
    ball.speed_x *= -1;
  }

  if(CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()},
                             ball.GetRadius(),  Rectangle{cpu.GetX(),
                             cpu.GetY(), cpu.width ,cpu.GetHeight()}
                             )) {
    ball.speed_x *= -1;
  }
}

void DrawScore() {
  DrawText( TextFormat("Score"), SCREEN_WIDTH / 2.52 , 20, 80, WHITE);
  DrawText( TextFormat("Player %i", ball.playerScore), SCREEN_WIDTH / 8.3 , 20, 50, WHITE);
  DrawText( TextFormat("Cpu %i", ball.cpuScore),  6*SCREEN_WIDTH / 8.3 , 20, 50, WHITE);
}
