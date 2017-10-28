#include<iostream>
#include<string>

using namespace std;
char aray[3][3];
void fill();
void output();
void flip(char, char);
int num_check(char);
int if_fill(char);
char winner_check();

int main()
{

	int player = 1;
	char continu;
	char field;
	do
	{
		system("cls");
		fill();
		output();
		player = 1;
		for (int i = 0; i < 9; i++)
		{
			player *= -1;
			if (player == -1)
			{
				do
				{
					do
					{
						cout << "\n\nPlayer 1, it's your turn: ";
						cin >> field;
						cout << "\n";
					} while (num_check(field) != 1);
				} while (if_fill(field));
				flip(field, 'X');
			}
			else
			{
				do
				{
					do
					{
						cout << "\n\nPlayer 2, it's your turn: ";
						cin >> field;
						cout << "\n";
					} while (num_check(field) != 1);
				} while (if_fill(field));
				flip(field, 'O');
			}
			system("cls");
			output();
			if (winner_check() == 'X')
			{
				cout << "\n\nPlayer 1 is the winner!\n";
				break;
			}
			if (winner_check() == 'O')
			{
				cout << "\n\nPlayer 2 is the winner!\n";
				break;
			}
		}
		cout << "\nWanna play again?(Y/N): ";
		cin >> continu;
		cout << "\n";
		continu = toupper(continu);
	} while (continu != 'N');

}
void fill()
{
	char field = '1';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			aray[i][j] = field++;
		}
	}
}
void output()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << aray[i][j] << " ";
			if (j != 2)
				cout << "| ";
		}
		if (i != 2)
			cout << endl << "---------" << endl;
	}
}
void flip(char field, char simbol)
{
	switch (field)
	{
	case '1': aray[0][0] = simbol; break;
	case '2': aray[0][1] = simbol; break;
	case '3': aray[0][2] = simbol; break;
	case '4': aray[1][0] = simbol; break;
	case '5': aray[1][1] = simbol; break;
	case '6': aray[1][2] = simbol; break;
	case '7': aray[2][0] = simbol; break;
	case '8': aray[2][1] = simbol; break;
	case '9': aray[2][2] = simbol; break;
	}
}
int num_check(char field)
{
	int ocupied = 0;
	if (field >= '1' && field <= '9')
		ocupied = 1;
	return ocupied;
}
int if_fill(char field)
{
	int ocupied = 0;
	switch (field)
	{
	case '1': if (aray[0][0] != field) ocupied = 1; break;
	case '2': if (aray[0][1] != field) ocupied = 1; break;
	case '3': if (aray[0][2] != field) ocupied = 1; break;
	case '4': if (aray[1][0] != field) ocupied = 1; break;
	case '5': if (aray[1][1] != field) ocupied = 1; break;
	case '6': if (aray[1][2] != field) ocupied = 1; break;
	case '7': if (aray[2][0] != field) ocupied = 1; break;
	case '8': if (aray[2][1] != field) ocupied = 1; break;
	case '9': if (aray[2][2] != field) ocupied = 1; break;
	}
	return ocupied;
}
char winner_check()
{
	if (aray[0][0] == aray[0][1] && aray[0][1] == aray[0][2])
		return aray[0][0];
	if (aray[1][0] == aray[1][1] && aray[1][1] == aray[1][2])
		return aray[1][0];
	if (aray[2][0] == aray[2][1] && aray[2][1] == aray[2][2])
		return aray[2][0];
	if (aray[0][0] == aray[1][0] && aray[1][0] == aray[2][0])
		return aray[0][0];
	if (aray[0][1] == aray[1][1] && aray[1][1] == aray[2][1])
		return aray[0][1];
	if (aray[0][2] == aray[1][2] && aray[1][2] == aray[2][2])
		return aray[0][2];
	if (aray[0][0] == aray[1][1] && aray[1][1] == aray[2][2])
		return aray[0][0];
	if (aray[0][2] == aray[1][0] && aray[1][1] == aray[2][0])
		return aray[0][2];
	if (aray[2][0] == aray[1][1] && aray[0][2] == aray[2][0])
		return aray[2][0];
	return 'a';
}