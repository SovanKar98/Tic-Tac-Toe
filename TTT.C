#include <stdio.h>
#include <conio.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board(char[],char[]);

int main()
{
    int player = 1, i,j,z,q, choice;
    char mark;

    char p1[25],p2[25];
    clrscr();
    textcolor(YELLOW);
    printf("\t\t\t\t");
    cprintf("\n\nTic Tac Toe\n\n");

    printf("\nEnter player names :: \n\n");
    printf("________________\n");
    printf("|| Player 1 : || ");
    gets(p1);
    printf("________________\n");
    printf("|| Player 2 : || ");
    gets(p2);
    printf("________________");


     gotoxy(20,18);
     printf("\tThe game is loading .....\n\n");
     for(q=1;q<=80;q++)
     {
     textcolor(GREEN);
     cprintf("%c",(char)221);
     delay(25);
     }


    do
    {
	board(p1,p2);
	player = (player % 2) ? 1 : 2;

	if(player==1)
	{
	printf("%s, enter a number:  ", p1);
	scanf("%d", &choice);
	}
	else

	{
	printf("%s, enter a number:  ", p2);
	scanf("%d", &choice);
	}

	mark = (player == 1) ? 'X' : '0';

   /*	for(int j=1;j<10;j++)
	{
		if(choice==j && square[j]==(char)j)
		square[j]=mark;
		}          */


	if (choice == 1 && square[1] == '1')
	    square[1] = mark;

	else if (choice == 2 && square[2] == '2')
	    square[2] = mark;

	else if (choice == 3 && square[3] == '3')
	    square[3] = mark;

	else if (choice == 4 && square[4] == '4')
	    square[4] = mark;

	else if (choice == 5 && square[5] == '5')
	    square[5] = mark;

	else if (choice == 6 && square[6] == '6')
	    square[6] = mark;

	else if (choice == 7 && square[7] == '7')
	    square[7] = mark;

	else if (choice == 8 && square[8] == '8')
	    square[8] = mark;

	else if (choice == 9 && square[9] == '9')
	    square[9] = mark;

	else
	{
	    printf("Invalid move ");

	    player--;
	    getch();
	}

  /*	for(j=1;j<10;j++)
	{
	if(choice==j)
	square[j]=mark;
	}
	if(j==10)
	{
	    printf("Invalid move ");

	    player--;
	    getch();
	}  */


	i = checkwin();

	player++;
    }while (i ==  - 1);

    board(p1,p2);

    if (i == 1)
	{
	z=--player;
	if(z==1)
	{
	textcolor(LIGHTBLUE);
	cprintf("==>%s Wins ",p1);
	}
	else
	{
	textcolor(GREEN);
	cprintf("==>%s Wins ",p2);
	}
	}
    else
	printf("==>Game Draw");

    getch();

    return 0;
}


int checkwin()      // 1 winner || 0 game running || -1 no winner
{
    int k;
    for(k=1;k<=7;k=k+3)
    {
	if(square[k]==square[k+1] && square[k+1]==square[k+2])
	return 1;
	}
    for(k=1;k<=3;k++)
    {
	if(square[k]==square[k+3] && square[k+3]==square[k+6])
	return 1;
	}



/*    if (square[1] == square[2] && square[2] == square[3])
	return 1;

    else if (square[4] == square[5] && square[5] == square[6])
	return 1;

    else if (square[7] == square[8] && square[8] == square[9])
	return 1;

    else if (square[1] == square[4] && square[4] == square[7])
	return 1;

    else if (square[2] == square[5] && square[5] == square[8])
	return 1;

    else if (square[3] == square[6] && square[6] == square[9])
	return 1;
  */
     if (square[1] == square[5] && square[5] == square[9])
	return 1;

    else if (square[3] == square[5] && square[5] == square[7])
	return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
	square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
	!= '7' && square[8] != '8' && square[9] != '9')

	return 0;
    else
	return  - 1;
}



void board(char p1[25],char p2[25])
{
    system("cls");
    textcolor(YELLOW);
    printf("\t\t\t\t");
    cprintf("\n\nTic Tac Toe\n\n");

    printf("\n%s (X)  -  %s (O)\n\n\n",p1,p2);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

