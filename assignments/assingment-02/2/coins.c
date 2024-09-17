#include <stdio.h>
#define OCTANOL 4
#define BUTANOL 3
#define ETHANOL 2
#define METHANOL 1

int value(int coin){
  if(coin == OCTANOL){
    return 8;
  }else if(coin == BUTANOL ){
    return 4;
  }else if(coin == ETHANOL){
    return 2;
  }else{
    return 1;
  }
}

int count(int amount, int maxCoin){
  if (amount == 0) return 1;
  if (amount < 0 || maxCoin < METHANOL) return 0; 

  int withMaxCoin = count(amount - value(maxCoin), maxCoin);
  int withoutMaxCoin = count(amount, maxCoin - 1);

  return withMaxCoin + withoutMaxCoin;
}

int main(int argc, char* argv[]){
  int amount;
  printf("Enter amount: ");
  scanf("%d", &amount);
  printf("Number of ways to make %d cents: %d\n", amount, count(amount, OCTANOL));
}
