#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 11


int main() {
  // Create a 2D array
  char array[11][25] = {
    "1111111111111111111111111",
    "1000000000000000000000001",
    "1000000000000000000000001",
    "1000000000000000000000001",
    "1000000000000000000000001",
    "1000000000000000000000001",
    "1000000E00000000000000001",
    "1000000000000000000000001",
    "1000000000000000000000001",
    "1000000000000000000000001",
    "1111111111111111111111111"
  };

  // Add curly braces to the first and last lines of the array
  array[0][0] = '{';
  array[11 - 1][25 - 1] = '}';

  // Print the array
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 25; j++) {
      printf("%c", array[i][j]);
    }
    printf("\n");
  }

  return 0;
}
