#include <iostream>
using namespace std;

void PrintBoard(int** board, int rows, int columns);
bool IsUnderAttack(int** board, int row, int column, int n);
bool NQueens(int** board, int level, int n);

int main()
{
	int queens;
	cout << "Number of queens: ";
	cin >> queens; cin.ignore();

	if (queens < 1)
	{
		cout << "Invalid value" << endl;
		return 0;
	}

	// Build the board
	int **board = new int*[queens];
	for (int i = 0; i < queens; ++i)
	{
		board[i] = new int[queens];
	}
	
	// Initialize board
	for (int i = 0; i < queens; ++i)
	{
		for (int j = 0; j < queens; ++j)
		{
			board[i][j] = 0;
		}
	}

	if (NQueens(board, 0, queens))
	{
		PrintBoard(board, queens, queens);
	}
	else
	{
		cout << "No possible solutions were found..." << endl;
	}


	// Delete the board
	for (int i = 0; i < queens; ++i)
	{
		delete [] board[i];
	}
	delete[] board;

	return 0;
}

void PrintBoard(int** board, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cout << board[i][j];
		}

		cout << endl;
	}

	cout << endl;
}

bool IsUnderAttack(int** board, int row, int column, int n)
{
	// Check row
	for (int i = 0; i < n; ++i)
	{
		if (board[row][i] == 1) return true;
		if (board[i][column] == 1) return true;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((i + j) == (row + column) ||
				(i - j) == (row - column))
			{
				if ((i != row || j != column) && board[i][j] == 1)
					return true;
			}
		}
	}

	return false;
}

bool NQueens(int** board, int level, int n)
{
	// End the backtrack
	if (level == n) return true;

	for (int i = 0; i < n; ++i)
	{
		// Check for attack - skip if true
		if (IsUnderAttack(board, level, i, n)) continue;

		// Place the current queen at cell (level, i)
		board[level][i] = 1;

		// Recurse and return true if true
		if (NQueens(board, level + 1, n))
			return true;

		// Else reset cell(level, i) to 0
		board[level][i] = 0;
	}

	return false;
}