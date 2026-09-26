#include "raylib.h"
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>
using namespace std;

const int x = 52, y = 52;

int grid[y][x];
int bgrid[y][x];

void check(int ri, int i, int j) {
  switch (ri) {
  case 1:
    if (j > 1 && i > 1) {
      grid[j - 1][i - 1] = 1;
    } else {
      grid[j - 1][i - 1] = 0;
    }
    break;
  case 2:
    if (j > 1) {
      grid[j - 1][i] = 1;
    } else {
      grid[j - 1][i] = 0;
    }
    break;
  case 3:
    if (j > 1 && i < x - 1) {
      grid[j - 1][i + 1] = 1;
    } else {
      grid[j - 1][i + 1] = 0;
    }
    break;
  case 4:
    if (i > 1) {
      grid[j][i - 1] = 1;
    } else {
      grid[j][i - 1] = 0;
    }
    break;
  case 5:
    if (i < x - 1) {
      grid[j][i + 1] = 1;
    } else {
      grid[j][i + 1] = 0;
    }
    break;
  case 6:
    if (j < y - 1 && i > 1) {
      grid[j + 1][i - 1] = 1;
    } else {
      grid[j + 1][i - 1] = 0;
    }
    break;
  case 7:
    if (j < y - 1) {
      grid[j + 1][i] = 1;
    } else {
      grid[j + 1][i] = 0;
    }
    break;
  case 8:
    if (j < y - 1 && i < x - 1) {
      grid[j + 1][i + 1] = 1;
    } else {
      grid[j + 1][i + 1] = 0;
    }
    break;
  }
}

/*
123
4C5
678
*/

void init() { grid[9][9] = 1; }

int main() {

  // Init
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distr(1, 8);
  memset(grid, 0, sizeof(grid));
  init();

  // Main Logic

  // Draw Logic
  for (int j = 0; j < y; j++) {
    for (int i = 0; i < x; i++) {
      int rint = distr(gen);
      // cout << grid[j][i];
    }
    // cout << endl;
  }

  InitWindow(800, 800, "Slime Growth");
  SetTargetFPS(8);

  while (!WindowShouldClose()) {
    memcpy(bgrid, grid, sizeof(grid));
    // Updation
    for (int j = 0; j < y; j++) {
      for (int i = 0; i < x; i++) {
        int rint = distr(gen);
        // cout << grid[j][i];
        if (bgrid[j][i] == 1)
          check(rint, i, j);
      }
    }

    // DrawGrid
    BeginDrawing();
    ClearBackground(BLACK);

    for (int j = 0; j < y; j++) {
      for (int i = 0; i < x; i++) {
        if (grid[j][i] == 1) {
          DrawRectangle(i * 15, j * 15, 15, 15, YELLOW);
        }
      }
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
