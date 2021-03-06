#include <stdio.h>
#include <math.h>

/*
 * createBoardScreen function with void return type and three parameters
 * This function prints the board array's contents, sectioned off to
 * resemble a Connect Four board. It is only called when the number of rows
 * and columns is less than 40, so as to properly display boards of smaller
 * sizes. It also prints column numbers underneath each column.
 */
void createBoardScreen(char** board, int rows, int cols) {
  int i;
  int j;
  int k;
  for (i = 0; i < cols; i++) {
    printf("____");
  }
  printf("_\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
    for (k = 0; k < cols; k++) {
      printf("----");
    }
    printf("-\n");
  }
  for (k = 0; k < cols; k++) {
    if (k < 9) {
      printf("  %d ", (k+1));
    }
    else {
      printf("  %d", (k+1));
    }
  }
  printf(" \n");
}

/*
 * printSegmentedBoard function with void return type and four parameters
 * This function prints the board array's contents, sectioned off to resemble
 * a Connect Four game. Depending on which segment is passed to this function,
 * it will print the corresponding fourth of the board. It calculates half
 * of the column and row count, using that value to prevent accessing the array
 * out of bounds.
 */
void printSegmentedBoard(char** board, int rows, int cols, int segment) {
  int x;
  int y;
  int z;
  float tempRows = rows;
  float tempCols = cols;
  if (segment == 1) {
    tempCols = floor(tempCols / 2.0);
    tempRows = floor(tempRows / 2.0);
    for (x = 0; x < tempCols; x++) {
      printf("____");
    }
    printf("_\n");
    for (x = 0; x < tempRows; x++) {
      for (y = 0; y < tempCols; y++) {
        printf("| %c ", board[x][y]);
      }
      printf("|\n");
      for (z = 0; z < tempCols; z++) {
        printf("----");
      }
      printf("-\n");
    }
    for (z = 0; z < tempCols; z++) {
      if (z < 9) {
        printf("  %d ", (z+1));
      }
      else {
        printf("  %d", (z+1));
      }
    }
    printf(" \n");
  }
  else if (segment == 2) {
    tempCols = floor(tempCols / 2.0);
    tempRows = floor(tempRows / 2.0);
    for (x = tempCols; x < cols; x++) {
      printf("____");
    }
    printf("_\n");
    for (x = 0; x < tempRows; x++) {
      for (y = tempCols; y < cols; y++) {
        printf("| %c ", board[x][y]);
      }
      printf("|\n");
      for (z = tempCols; z < cols; z++) {
        printf("----");
      }
      printf("-\n");
    }
    for (z = tempCols; z < cols; z++) {
      if (z < 9) {
        printf("  %d ", (z+1));
      }
      else {
        printf("  %d", (z+1));
      }
    }
    printf(" \n");
  }
  else if (segment == 3) {
    tempCols = floor(tempCols / 2.0);
    tempRows = floor(tempRows / 2.0);
    for (x = 0; x < tempCols; x++) {
      printf("____");
    }
    printf("_\n");
    for (x = tempRows; x < rows; x++) {
      for (y = 0; y < tempCols; y++) {
        printf("| %c ", board[x][y]);
      }
      printf("|\n");
      for (z = 0; z < tempCols; z++) {
        printf("----");
      }
      printf("-\n");
    }
    for (z = 0; z < tempCols; z++) {
      if (z < 9) {
        printf("  %d ", (z+1));
      }
      else {
        printf("  %d", (z+1));
      }
    }
    printf(" \n");
  }
  else if (segment == 4) {
    tempCols = floor(tempCols / 2.0);
    tempRows = floor(tempRows / 2.0);
    for (x = tempCols; x < cols; x++) {
      printf("____");
    }
    printf("_\n");
    for (x = tempRows; x < rows; x++) {
      for (y = tempCols; y < cols; y++) {
        printf("| %c ", board[x][y]);
      }
      printf("|\n");
      for (z = tempCols; z < cols; z++) {
        printf("----");
      }
      printf("-\n");
    }
    for (z = tempCols; z < cols; z++) {
      if (z < 9) {
        printf("  %d ", (z+1));
      }
      else {
        printf("  %d", (z+1));
      }
    }
    printf(" \n");
  }
}

/*
 * printSectionedScreen function with void return type and five parameters
 * This function prints the board's array contents, with surrounded characters
 * to emulate a Connect Four board. It runs through multiple for loops to
 * determine how far it can go in every direction from the most recent move made
 * without accessing the array out of bounds, then prints a board consisting of
 * a subset of the larger board, with a maximum of 20 spaces in every direction
 * from the last move made. This function is called for boards with dimensions
 * larger than 100 in either direction.
 */
void printSectionedScreen(char** board, int rows, int cols, int nearRow, int nearCol) {
  int q;
  int flag = 0;
  int maxCol = nearCol;
  int minCol = nearCol;
  int maxRow = nearRow;
  int minRow = nearRow;
  for (q = nearCol; q < cols; q++) {
    flag++;
    if (flag < 20) {
      maxCol = q;
    }
    else {
      break;
    }
  }
  flag = 0;
  for (q = nearCol; q >= 0; q--) {
    flag++;
    if (flag < 20) {
      minCol = q;
    }
    else {
      break;
    }
  }
  flag = 0;
  for (q = nearRow; q < rows; q++) {
    flag++;
    if (flag < 20) {
      maxRow = q;
    }
    else {
      break;
    }
  }
  flag = 0;
  for (q = nearRow; q >= 0; q--) {
    flag++;
    if (flag < 20) {
      minRow = q;
    }
    else {
      break;
    }
  }
  int i;
  int j;
  int k;
  for (i = minCol; i <= maxCol; i++) {
    printf("____");
  }
  printf("_\n");
  for (i = minRow; i <= maxRow; i++) {
    for (j = minCol; j <= maxCol; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
    for (k = minCol; k <= maxCol; k++) {
      printf("----");
    }
    printf("-\n");
  }
  for (k = minCol; k <= maxCol; k++) {
    if (k < 9) {
      printf("  %d ", (k+1));
    }
    else if (k < 99) {
      printf("  %d", (k+1));
    }
    else {
      break;
    }
  }
  printf(" \n");
}
