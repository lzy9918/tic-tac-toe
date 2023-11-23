#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game.h"
void menu()
{
	printf("---------------------------\n");
	printf("        tic-tac-toe        \n\n");
	printf("     1.Start    0.Exit     \n");
	printf("---------------------------\n\n");
	printf("Please enter your selection:>");
}
void game()
{
	char board[ROW][COL];
	char ret = 0;
	int sign;
	do
	{
		printf("Please select the difficulty level:> 1&2\n");
		scanf("%d", &sign);
	} while (sign != 1 && sign != 2);
	InitBoard(board, ROW, COL);
	if (sign == 1)
	{
		while (1)
		{
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
			ComputerMove1(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
		}
	}
	else
	{
		while (1)
		{
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
			ComputerMove2(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
		}
	}
	if (ret == 'W')
		printf("玩家赢!\n");
	else if (ret == 'D')
		printf("电脑赢!\n");
	else if (ret == 'Q')
		printf("平局!\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\nTic-Tac-Toe start!\n\n");
			game();
			break;
		case 0:
			printf("\nGame Exited!\n\n");
			break;
		default:
			printf("\nSelection error, please make a new selection!\n\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
