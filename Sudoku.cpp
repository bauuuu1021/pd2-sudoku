#include <iostream>
#include "Sudoku.h"
#include <ctime>
#include <cstdlib>
const int sudokuNum = 9;

using namespace std;

int a2[9][9];
void sudoku::giveQuestion()
{
	
int a1[9][9]={{0,0,0,1,4,0,0,9,0},
		{0,4,8,2,0,0,6,1,0},
		{0,0,0,8,0,0,2,0,0},
		{3,0,7,0,0,0,9,0,0},
		{1,8,5,7,0,2,4,3,6},
		{0,0,6,0,0,0,7,0,1},
		{0,0,2,0,0,8,0,0,0},
		{0,1,4,0,0,3,8,7,0},
		{0,7,0,0,6,1,0,0,0}};

int i, j;

        for(i=0; i<9; i++)
	    {
			for(j=0; j<9; j++)
				cout<<a1[i][j]<<" ";
	        cout<<endl;
		}

}
void sudoku::readIn()
{
	int line;
	//int a2[9][9];

	for (line=1; line<10; line++)
	{
	cout<<"input line"<<line<<"(separated by a space)";
	cin>>a2[line-1][0] >>a2[line-1][1] >>a2[line-1][2] >>a2[line-1][3] >>a2[line-1][4] >>a2[line-1][5] >>a2[line-1][6] >>a2[line-1][7] >>a2[line-1][8];
	}

	/*
	for (line=1; line<10; line++)
  	{
    cout<<a2[line-1][0] <<a2[line-1][1] <<a2[line-1][2] <<a2[line-1][3] <<a2[line-1][4] <<a2[line-1][5] <<a2[line-1][6] <<a2[line-1][7] <<a2[line-1][8] <<a2[line-1][9]<<endl;
	}

	*/
	
}
void sudoku::solve()
{
}
void sudoku::changeNum(int a, int b)
{

	int i, j;

	for (i=0; i<9; i++)
	{
		for (j=0; j<9; j++)
		{
			if (a2[i][j]==a)
				a2[i][j]=b;
			else if (a2[i][j]==b)
				a2[i][j]=a;
			else
				a2[i][j]=a2[i][j];
		}
	}
}
void sudoku::changeRow(int a, int b)
{
	int b2[9][9];
	int i, j, x;

	for (i=0; i<9; i++)
	{
		for (j=0; j<9; j++)
			b2[i][j]=a2[i][j];
	}
for (j=0; j<9; j++)
{
	for (x=0; x<3; x++)
	{
		b2[x+3*b][j]=a2[3*a+x][j];
		b2[x+3*a][j]=a2[3*b+x][j];
	}
}

	 for (i=0; i<9; i++)
	 {
		for (j=0; j<9; j++)
	         a2[i][j]=b2[i][j];
     }

}
void sudoku::changeCol(int a, int b)
{
	int b3[9][9];
	int i, j, x;

	for (i=0; i<9; i++)
	{
		for (j=0; j<9; j++)
			b3[i][j]=a2[i][j];
	}

	for (i=0; i<9; i++)
	{
		for (x=0; x<3; x++)
		{
			b3[i][x+3*b]=a2[i][3*a+x];
			b3[i][x+3*a]=a2[i][3*b+x];
		}
	}
	for (i=0; i<9; i++)
	{
		for (j=0; j<9; j++)
			a2[i][j]=b3[i][j];
	}
}
void sudoku::rotate(int n)
{
	//a,b -> b,8-a
	int b[9][9];
	int i, j, x;

for (x=0; x<n; x++)
{
	for (i=0; i<9; i++)
	{
		for (j=0; j<9; j++)
			b[j][8-i]=a2[i][j];
	}

	for (i=0; i<9; i++)
	{
		for (j=0; j<9; j++)
			a2[i][j]=b[i][j];
	}
}
}

void sudoku::flip(int n)
{
	int i, j;
	int swp;

	switch (n)
	{

	case 0:
	for (i=4; i<9; i++)
	{
		for (j=0; j<9; j++)
		{
			swp=a2[i][j];
			a2[i][j]=a2[8-i][j];
			a2[8-i][j]=swp;
		}
	}
	break;

	case 1:
	for (i=0; i<9; i++)
	{
		for (j=0; j<4; j++)
		{
			swp=a2[i][j];
			a2[i][j]=a2[i][8-j];
			a2[i][8-j]=swp;
		}
	}
	break;
	}
}
void sudoku::transform()
{
	readIn();
	change();
	printOut(false);
}

void sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%sudokuNum+1, rand()%sudokuNum+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
void sudoku::printOut(bool isAns)
{
	int i, j;

	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
			cout<<sudoku::a2[i][j]<<" ";
			cout<<endl;
	}
}
