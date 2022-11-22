#include <stdio.h>
#include "bingoBoard.h"

#define BINGONUM_HOLE   -1


static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

int bingo_checkNum(int selNum)
{
	if (numberStatus[selNum-1] == BINGONUM_HOLE)
	return BINGO_NUMSTATUS_ABSENT;
	
	return BINGO_NUMSTATUS_PRESENT;
}

void bingo_init(void)
{
	int i, j, k;
	int randNum;
	int maxNum = N_SIZE*N_SIZE;
	
	
	for (i=0; i<N_SIZE; i++)
		numberStatus[i] = BINGO_NUMSTATUS_ABSENT;
		
		for (i=0; i<N_SIZE; i++)
		for (j=0; j<N_SIZE; j++)
		{
			randNum = rand()%maxNum;
			
			for (k=0; k<N_SIZE*N_SIZE; k++)
			{
				if (numberStatus[k] == BINGO_NUMSTATUS_ABSENT)
				{
					if (randNum ==0)
						break;
					else
						randNum --;
				}
			}
			numberStatus[k] = i*N_SIZE + j;
			bingoBoard[i][j] = k+1;
			maxNum --;
		}
}

void bingo_print(void)
{
	int i, j;
	
	printf("========================\n");
	for (i=0; i<N_SIZE; i++) {
		for(j=0; j<N_SIZE; j++) {
			if (bingoBoard[i][j]==BINGONUM_HOLE)
				printf("X\t");
			else
				printf("%i\t", bingoBoard[i][j]);
		}
		printf("\n");
	}
	printf("=========================\n\n");
}

void bingo_inputNum(int sel)
{
	bingoBoard[numberStatus[sel-1]/N_SIZE][numberStatus[sel-1]%N_SIZE] = BINGONUM_HOLE;
}

int bingo_countCompletedLined(void)
{
  int i,j;
  int cnt = 0;
  int checkBingo;


//check row 행에 대해 따짐    
	for (i=0; i<N_SIZE; i++) {
		checkBingo = 1;
		for (j=0; j<N_SIZE; j++)
			if (bingoBoard[i][j]>0) {
				checkBingo = 0;
				break;
			}

	if (checkBingo == 1) {
		cnt ++;
	}
}

//열
	for (j=0; j<N_SIZE; j++){
		checkBingo = 1;
		for(i=0; i<N_SIZE; i++){
			if (bingoBoard[i][j]>0){
				checkBingo = 0;
				break;
			}
			
		if (checkBingo ==1 )
		cnt ++;
		}
	} 

//대각선 1
	checkBingo=1;
		for (i=0; i<N_SIZE; i++)
		{
			if (bingoBoard[i][i]>0)
			{
				checkBingo =0;
				break;
			}
		}
		if (checkBingo == 1)
		cnt ++;
//대각선 2 
checkBingo=1;
		for (i=0; i<N_SIZE; i++)
		{
			if (bingoBoard[i][N_SIZE-i-1]>0)
			{
				checkBingo =0;
				break;
			}
		}
		if (checkBingo == 1)
		cnt ++;


}

return cnt;


