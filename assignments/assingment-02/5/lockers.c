#include <stdio.h>
#include <math.h>

char lockerState(int l, int t) {
  int sqrtOfL = (int)sqrt(l);
  if (sqrtOfL * sqrtOfL == l) return 1;
  else return 0;
}

int main(int argc, char* argv[])
{
  int locker;
  while(1){
    printf("Enter locker number: ");
    scanf("%d", &locker);
    if(locker < 0){
      break;
    }else if(lockerState(locker, locker) == 0){
      printf("Closed\n");
    }else{
      printf("Open\n");
    }
  }
  return 0;
}
