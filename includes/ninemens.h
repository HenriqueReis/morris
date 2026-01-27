#ifndef NMM_H
# define NMM_H

# include <stdio.h>
# define checkoverride(X,Y) !(X & Y) // check if the movement of a player doesn't override the opponent's board
# define clear() printf("\033[H\033[J") // macro to clear screen
# define iseven(X) getbit(X, 0) == 0 
# define by8(X) X % 8 == 0
# define abs(X) ((X > 0)? X : (-X))
# define INVALID 0 
# define ON 1
# define OFF 0

int setbit(int x, int position, int value);
int getbit(int x, int p); // return the bit's value in desired position
int getbits(int x, int p, int n); // return number with the bits values with position p changed to value n
int countdifferentbits(int x, int y);// return the number of differents bits of two numbers comparisson
int differentbits(int x, int y, int value);// return first different bit of two numbers comparisson defined by value
void showbin(int x);  // show the binary representation of a given number [USANDO SÓ PARA TESTES: DESNECESSÁRIA]
int numberofpieces(int playerboard); //count the number of pieces a given player has on board
int validmove(int previous, int next);
int canputpiece(int board1, int board2, int position);
int checktriplets(int board, int position);

#endif
