#include "ninemens.h"
int setbit(int x, int position, int value) { // return x with position bit changed to value
    return ((x & ~(1 << position)) | (value << position));
}

int getbit(int x, int p) { // return the bit's value in desired position
    return (x >> p) & 1;
}

int getbits(int x, int p, int n) { // return number with the bits values with position p changed to value n
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int countdifferentbits(int x, int y) {// return the number of differents bits of two numbers comparisson
   int i, j = 0;
   if (x == y) return 0; // NULL 
   for (i = 0; i <= 23; i++) {
      if (getbit(x, i) != getbit(y, i))  j++;
   }
   return j;
}

int differentbits(int x, int y, int value) {// return first different bit of two numbers comparisson defined by value
   int i;
   if (x == y) return 24; // 24 is out of range, so it's an invalid postion 
   for (i = 0; i <= 23; i++) {
      if ((getbit(x, i) != getbit(y, i)) && getbit(x, i) == value ) return i;
   }
   return 24;
}

void showbin(int x) {  // show the binary representation of a given number [USANDO SÓ PARA TESTES: DESNECESSÁRIA]
   int i;
   for (i = 23; i >= 0; i--) {
      printf("%d", getbit(x, i));
   }
   printf("\n");
}

int numberofpieces(int playerboard) { //count the number of pieces a given player has on board
   int i, number  = 0;
   for (i = 0; i < 24; i++) {
      if (getbit(playerboard, i)) 
          number++; 
   }
   return number;
}

int validmove(int previous, int next) {

   int validmovments[24][4] = {{1,7}, {0,2,9}, {1,3},{2,4,11},{3,5},{4,6,13},{5,7},{0,6,15},{9,15},{1,8,10,17},{9,11},{3,10,12,19},{11,13},{5,12,14,21},{13,15},{7,8,14,23},{17,23},{9,16,18},{17,19},{11,18,20},{19,21},{13,20,22},{21,23},{15,16,22}};
   int bitprevious, bitnext, j = 0;

   if (countdifferentbits(previous, next) != 2) return INVALID;
   
   bitprevious = differentbits(previous, next, 1);
   bitnext = differentbits(previous, next, 0);
   
  // if (bitnext >= 24 || bitprevious >= 24) return INVALID; /// se o numero de bits diferentes é 2 então isso nunca será vdd
   
   if (numberofpieces(previous) == 3)
       return 1;
   else  {
   
	   do {	      

	       if (bitnext == validmovments[bitprevious][j])
		   return 1;
	   j++; 
	   
	   }  while (validmovments[bitprevious][j]);  // not 0

    }
    
   return 0;
}


int canputpiece(int board1, int board2, int position) {
    if (getbit(board1, position) || getbit(board2, position)) return 0;
       return 1;
}

int checktriplets(int board, int position) {
  int triplets[24][4] = { {1,2,6,7}, {0,2,9,17}, {0,1,3,4}, {2,4,11,19}, {2,3,5,6}, {4,6,13,21},{4,5,0,7}, {0,6,15,23},{9,10,14,15},{8,10,1,17},{8,9,11,12},{3,19,10,12},{10,11,13,14},{5,21,12,14},{12,13,8,15},{7,23,8,14},{17,18,22,23},{1,9,16,18},{16,17,19,20},{3,11,18,20},{18,19,21,22},{5,13,20,22},{20,21,16,23},{7,15,16,22}};


  return ((getbit(board, triplets[position][0]) && getbit(board, triplets[position][1])) || (getbit(board, triplets[position][2]) && getbit(board, triplets[position][3])));

}
/* FICANDO OBSOLETO
 *
int move(int x, int from, int to) { // average move

    if (from > 7 || to > 7) return INVALID; // Maximum value admitted for a position 
    if (!(getbit(x, from)) || getbit(x, to)) return INVALID; // from must be 1 and to must be 0
    if ((from - to != 1) && (from - to != -1) && (from - to != 7) && (from - to != -7)) return INVALID; // move must be at adjcent position
    return setbit((setbit(x, from, 0)), to, 1);  
}

int checktriplets(int player[], int shell, int x ) { // x = new board's display on the given shell //REFATORAR

    int unlikebit, counttriplet = 0;
    int i;

    if (player[shell] == x) return 0;

    // 760 triplet
    if (( getbits(player[shell], 7, 2) != 3 || !(getbit(player[shell], 0))) && (getbits(x, 7, 2) == 3 && getbit(x, 0))) return 1; 

     // inner shells triplets
    unlikebit = differentbits(x,player[shell],1);
    if (getbit(x, unlikebit)) counttriplet++;

    if (unlikebit == 1 || unlikebit == 3 ||  unlikebit ==  5 ||  unlikebit == 7 )   { 
        for (i = 0; i <= 2; i++) {
            if (getbit(player[i], unlikebit)) counttriplet++;
        }
        if (counttriplet == 3) return 1;
    }

    // 012 234 456 triplets
    for ( i = 2; i <= 6; i += 2) {
        if ((getbits(player[shell], i, 3) != 7) && (getbits(x, i, 3) == 7)) return 1;
    }

    return 0;
}

*/
