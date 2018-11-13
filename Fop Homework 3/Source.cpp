#include <iostream>
#include <Windows.h>

using namespace std;

char const BLANK = ' '; //constant: symbol used for drawing the space around the tree
char const LEAF = '#'; //constant: symbol used for drawing the tree’ leaves’
char const WOOD = '|'; //constant: symbol used for drawing the tree’s trunk
char const MINSIZE = 4; //constant: symbol used for checking min tree height
char const MAXSIZE = 20; //constant: symbol used for checking max tree height
int const borderColor = 11;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{			//produceChristmasGreeting
	bool more;
	void drawAXmasTree();
	bool agreeToContinue(bool& more);
	cout << "Joshua Warburton - SE3 - December 2017" << "\n\n";
	do
	{
		drawAXmasTree();
		agreeToContinue(more);
	} while (more == true);

	system("Pause");
	return(0);
}

void drawAXmasTree()
{
	int getValidHeight();
	int treeHeight = getValidHeight();				//height of the tree  //read in a valid value for the tree height
	void drawFoliage(int treeHeight);
	void drawTrunk(int treeHeight);
	void drawBorder(int treeHeight);
	drawBorder(treeHeight);							//draw top of border
	drawFoliage(treeHeight);						//draw tree foliage
	drawTrunk(treeHeight);							//draw tree trunk
	drawBorder(treeHeight);							//draw bottom of border
}

int getValidHeight()
{
	int treeHeight;
	cout << "Enter the size of the tree (4-20): ";
	cin >> treeHeight;
	cout << "\n";

	while ((treeHeight < MINSIZE) || (treeHeight > MAXSIZE))
	{
		cout << "ERROR: Invalid height! Enter the size of the tree (4-20): ";
		cin >> treeHeight;
	}
	return treeHeight;
}

void drawFoliage(int treeHeight) //draw the foliage of the tree

{
	void drawALineOfFoliage(int treeHeight, int branchLine);
	int branchLine = 1;

	while (branchLine <= (treeHeight - 2))
	{
		drawALineOfFoliage(treeHeight, branchLine); 
		branchLine++;
	}

}

void drawTrunk(int treeHeight) //draw the trunk of the tree
{
	int spaces;
	int trunkLine = 1;

	while (trunkLine <= 2) // for each line in the trunk
	{
		SetConsoleTextAttribute(h, borderColor);
		spaces = 1;
		cout << ".";
		while (spaces <= (treeHeight - 3)) //draw the spaces on the left
		{
			cout << (BLANK);
			spaces++;
		}
		SetConsoleTextAttribute(h, 6);		//makes trunk brown
		cout << (WOOD);			//draw the trunk
		while (spaces > 1)		//draw spaces on the right
		{
			cout << BLANK;
			spaces--;
		}
		SetConsoleTextAttribute(h, borderColor);
		cout << ".";			//draw right side border
		cout << "\n";			//go to next line
		trunkLine++;
	}
}

void drawALineOfFoliage(int treeHeight, int branchLine) {
	char randomDecoration();
	int counter = treeHeight - 2;
	SetConsoleTextAttribute(h, borderColor);									//sets "." to borderColor
	cout << ".";																//draws left side border
	for (int x = 0; x < treeHeight - branchLine - 2; x++) cout << BLANK;		//Draws spaces before the #. 

	if (branchLine == 1)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);								//sets tree decoration to red
		cout << randomDecoration();
	}
	else
	{	SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		for (int x = 0; x < (branchLine * 2) - 1; x++)		//1*2-1=1 (draws 1 leaf for first row) 2*2-1=3 (draws 3 leaves for second row)
		{
			cout << LEAF;
		}
	}

	SetConsoleTextAttribute(h, borderColor);
	for (int x = 0; x < treeHeight - branchLine - 2; x++) cout << BLANK; //adds spaces to the right side to allow for the border
	cout << ".";		//draws right side border
	cout << "\n";
}

bool agreeToContinue(bool& more)
{
	SetConsoleTextAttribute(h, 7);			//makes text white
	char input;
	cout << "Would you like another tree? (Y/N): ";
	cin >> input;
	
	switch (input)
	{
	case 'y':
		more = true;
		break;
	case 'n':
		more = false;
		break;
	case 'Y':
		more = true;
		break;
	case 'N':
		more = false;
		break;
	default:
		cout << "Incorrect input, the program will now close \n";
		break;
	}
	return more;
}

char randomDecoration()
{
	char dec;

	int r = rand() % 4;

	switch (r)
	{
	case 0: dec = '*';
		break;
	case 1: dec = '&';
		break;
	case 2: dec = '@';
		break;
	case 3: dec = '0';
		break;
	}
	return dec;
}

void drawBorder(int treeHeight)
{
	SetConsoleTextAttribute(h, borderColor);				//sets top and bottom to borderColor
	for (int x = 0; x < (treeHeight - 2) * 2 + 1; x++)		//gets the correct amount of "." needed for the border at the top and bottom
	{
		cout << ".";
	}
	cout << "\n";
}