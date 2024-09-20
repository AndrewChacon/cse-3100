#include <stdio.h>

char lockerState(int l, int t) {
  int toggleCount = 0;
  
  for (int i = 1; i <= t; i++) {
    if (l % i == 0) {
      toggleCount++;
    }
  }
  
  if (toggleCount % 2 == 0) {
    return 0; 
  } else {
    return 1; 
  }
}

int main(int argc, char* argv[]) {
  int locker;
  
  while (1) {
    printf("Enter locker number: ");
    scanf("%d", &locker);
    
    if (locker < 0) {
      break;
    }
    
    if (lockerState(locker, locker) == 0) {
      printf("Closed\n");
    } else {
      printf("Open\n");
    }
  }
  
  return 0;
}
