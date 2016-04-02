#include <iostream>
#include <ctime>
class sudoku
{
	
	public:
		int a[9][9];
		int a2[9][9];

		void giveQuestion();            //1
		void readIn();                  //2
		void solve();                   //3
		void changeNum(int a, int b);   //4 
		void changeRow(int a, int b);   //5
		void changeCol(int a, int b);   //6
		void rotate(int n);             //7
		void flip(int n );              //8
		void transform();               //9
		void change();
		void printOut(bool isAns);
};
