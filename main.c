#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int get_number(void){
int selNum=0;
do{
	printf("select a number : ");
	scanf("%d", &selNum);
	fflush(stdin);
	
	if (selNum < 1|| selNum > N_SIZE*N_SIZE || bingo_checkNum (selNum) == BINGO_NUMSTATUS_ABSENT)
	{
		printf("%i is not on the board! select other one.\n", selNum);
	}
} while (selNum < 1|| selNum > N_SIZE*N_SIZE || bingo_checkNum (selNum) == BINGO_NUMSTATUS_ABSENT);

return selNum;

}


int main(int argc, char *argv[]) {
	
	
	srand((unsigned) (time(NULL)) ) ;
	
	//opening
	printf("==========================================\n");
	printf("******************************************\n");
	printf("               BINGO GAME                 \n");
	printf("******************************************\n");
	printf("==========================================\n");
	
	//game 
	
	
	
	bingo_init();
	bingo_print();
	selNum = get_number();
	bingo_inputNum(selNum);
	bingo_print();
	
	//initialize bingo boards
	
	//while (game is not end) //줄수가 N_BINGO보다 작음   
	/*
	{
		//bingo board print
		
		//print no. of completed line
		
		//select a number
		
		//update the board status
	}
	*/

		
	
	
	
	
	//ending
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("==========================================\n");
	printf("******************************************\n");
	printf("               CONGRATULATION             \n");
	printf("                   BINGO                  \n");
	printf("               YOU WIN!!!!!!!             \n");
	printf("******************************************\n");
	printf("==========================================\n\n");
	
	
	return 0;
}
