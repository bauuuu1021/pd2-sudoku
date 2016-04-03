#include <iostream>
#include "Sudoku.h"
using namespace std;

int main ()
{
	int input;
	sudoku su;
	int a, b;

///////
while(1)
{
	cout<<"input the number of the function u want :";
	cin>>input;

	switch(input)
	{
		case 1:su.giveQuestion();
			   break;
		case 2:su.readIn();
			   break;
		case 3:su.solve();
			   break;
		case 4:cout<<"input a";
			   cin>>a;
			   cout<<"input b";
			   cin>>b;
			   su.changeNum(a, b);
			   break;
		case 5:cout<<"input a";
			   cin>>a;
			   cout<<"input b";
			   cin>>b;
			   su.changeRow(a, b);
			   break;
		case 6:cout<<"input a";
			   cin>>a;
			   cout<<"input b";
			   cin>>b;
			   su.changeCol(a, b);
			   break;
		case 7:int n;
			   cout<<"input n";
			   cin>>n;
			   su.rotate(n);
  			   break;
		case 8:
			   cout<<"input n";
			   cin>>n;
			   su.flip(n);
			   break;
		case 9:su.transform();  
			   break;
		
	}

	su.printOut(0);
}
////////
	return 0;
}	
