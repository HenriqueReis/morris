#include <stdio.h>
#include "ninemens.h"

int main() {
 
struct Player {
   int board;
   int offboard;
};

  struct Player player[2];
  int looser = -1, actualplayer = 0, positionget = 0, positionset = 0;
  int putoff, next;
  for (int i = 0; i < 2; i++) {
     player[i].board = 0;
     player[i].offboard = 9;
  }

  do {

     if (player[actualplayer].offboard > 0) {
	 
	     do {
		     printf("Player %d, digite o número da posição onde quer colcar sua peça ", actualplayer+1);
		     scanf("%d", &positionset);
	     } while (!( canputpiece(player[actualplayer].board, player[!(actualplayer)].board, positionset)));
	     
	     player[actualplayer].board = setbit(player[actualplayer].board, positionset, ON);
	     player[actualplayer].offboard--;
     }
     else {
	     if (numberofpieces(player[actualplayer].board) >= 3) {
		     do {
			     printf("Player %d, digite o número da posição de onde quer mover a peça \n", actualplayer+1);
			     scanf("%d", &positionget);
			     printf("Player %d, digite o número da posição para onde quer mover a peça \n", actualplayer+1);
			     scanf("%d", &positionset);
			     next = setbit(player[actualplayer].board, positionget, OFF);
			     next = setbit(next, positionset, ON);
		     } while (!((validmove(player[actualplayer].board, next) && checkoverride(next, player[!(actualplayer)].board))));
		     player[actualplayer].board = next;
	     }

	     else {
		     looser = actualplayer;}
     }

     if (checktriplets(player[actualplayer].board, positionset)) {
	     do {
		     printf("Fechou uma trinca! escolha a posição de uma peça do oponente para retirar! \n");
		     scanf("%d", &putoff);
	     } while (!(getbit(player[!(actualplayer)].board, putoff))) ;
	     player[!(actualplayer)].board = setbit(player[!(actualplayer)].board, putoff, OFF);
     }

     actualplayer = !(actualplayer);    
 
  } while (looser == -1) ;
    clear();
    printf("PLAYER %d VENCEU!!!!", !(looser)+1);

  return 0;  
	
}
