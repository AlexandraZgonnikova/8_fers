#include <iostream>
#define bool int
#define true 1
#define false 0

using namespace std;
class queen
{
public:
	queen(int, queen*);
	bool findSolution();
	bool advance();
	void print();
private:
	int row;
	const int column;
	queen* neighbor;
	bool canAttack(int, int);
};

queen::queen(int col, queen* ngh) : column(col), neighbor(ngh)
{
	row = 1;
}

bool queen::canAttack(int testRow, int testColumn)
{
	if (row == testRow)
		return true;
	int columnDifference = testColumn - column;
	if ((row + columnDifference == testRow) || (row - columnDifference == testRow))
		return true;
	return neighbor && neighbor->canAttack(testRow, testColumn);
}

bool queen::findSolution()
{
	while (neighbor && neighbor->canAttack(row, column))
		if (!advance())
			return false;
	return true;
}

bool queen::advance()
{
	if (row < 8)
	{
		row++;
		return findSolution();
	}

	if (neighbor && !neighbor->advance())
		return false;
	row = 1;
	return findSolution();
}

void queen::print()
{
	if (neighbor)
		neighbor->print();
	cout << "column " << column << " row " << row << '\n';
}

void main()
{
	queen* lastQueen = 0;
	for (int i = 1; i <= 8; i++)
	{
		lastQueen = new queen(i, lastQueen);
		if (!lastQueen->findSolution())
			cout << "no solution\n";
	}
	lastQueen->print();
}
