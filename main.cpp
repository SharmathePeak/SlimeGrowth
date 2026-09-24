#include <cstring>
#include <iostream>

int main() {
  int x = 10, y = 10;
  int grid[y][x];
  memset(grid, 0, sizeof(grid));
  for (int j = 0; j < y; j++) {
    for (int i = 0; i < x; i++) {
      printf("%d", grid[j][i]);
    }
    printf("\n");
  }
}
