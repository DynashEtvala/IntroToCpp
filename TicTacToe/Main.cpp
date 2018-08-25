#include<iostream>

int space[2];
int turn = 0;

bool quit = false;
bool play = false;

char input = 0;
char board[3][3];
char playerTurn = 'X';

void ResetBoard();
void DisplayBoard();
bool CheckBoard(int space[2]);

int main()
{
	while (!quit)
	{
		//main menu
		std::cout << "Welcome to Tic Tac Toe!" << std::endl;
		std::cout << std::endl;
		std::cout << "[P]lay or [Q]uit?" << std::endl;
		std::cout << std::endl;
		//user selection
		std::cin >> input; 
		std::cout << std::endl;
		//process selection
		switch (input)
		{
		case 'p':
		case 'P':
			//clear board
			ResetBoard();
			system("CLS");
			play = true;
			break;
		case 'q':
		case 'Q':
			//exit game
			quit = true;
			break;
		default:
			std::cout << "Input invalid" << std::endl;
			break;
		}
		//game
		while (play)
		{
			bool oktogo = false;

			while (!oktogo)
			{
				//show whos turn it is and board
				std::cout << "It's " << playerTurn << "'s turn!" << std::endl;
				DisplayBoard();

				//get player row and collumn
				std::cout << "Select a row:" << std::endl;
				std::cin >> space[0];
				space[0]--;
				std::cout << "Select a collumn:" << std::endl;
				std::cin >> space[1];
				space[1]--;
				//check if valid
				if (space[0] >= 0 && space[0] < 3 && space[1] >= 0 && space[1] < 3)
				{
					//exit loop
					oktogo = true;
				}
				else
				{
					//tell player move is invalid then let loop
					std::cout << "Input invalid: Values must be between 1 and 3." << std::endl;
					std::cout << "Press ENTER to continue." << std::endl;
					//I don't know why but it needs two .get()s
					std::cin.get();
					std::cin.get();
				}
				system("CLS");
			}
			
			//check if space is empty
			if (board[space[0]][space[1]] == ' ')
			{
				board[space[0]][space[1]] = playerTurn;
				//Check for a win
				if (CheckBoard(space))
				{
					//win
					std::cout << "Player " << playerTurn << " wins!" << std::endl;
					DisplayBoard();
					play = false;
				}
				else
				{
					turn++;
					//tie
					if (turn == 9)
					{
						std::cout << "It's a tie!" << std::endl;
						DisplayBoard();
						play = false;
					}
					//set player for next turn
					else if (playerTurn == 'X')
					{
						playerTurn = 'O';
					}
					else
					{
						playerTurn = 'X';
					}
				}
			}
			else
			{
				//tell player move is invalid then let loop
				std::cout << "Move invalid: Space is already taken." << std::endl;
				std::cout << "Press ENTER to continue." << std::endl;
				//I don't know why but it needs two .get()s
				std::cin.get();
				std::cin.get();
			}
			system("CLS");
		}
	}
	return 0;
}

//makes all board spacs empty
void ResetBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//display the board in it's current state
void DisplayBoard()
{
	std::cout << "  1 2 3" << std::endl;
	std::cout << " +-----+" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1;
		for (int j = 0; j < 3; j++)
		{
			std::cout << '|' << board[i][j];
		}
		std::cout << '|' << std::endl;
		std::cout << " +-----+" << std::endl;
	}
}

//check the board for a winner
bool CheckBoard(int space[2])
{
	//check rows
	if (board[space[0]][0] == board[space[0]][1] && board[space[0]][0] == board[space[0]][2])
	{
		return true;
	}
	//check collumns
	if (board[0][space[1]] == board[1][space[1]] && board[0][space[1]] == board[2][space[1]])
	{
		return true;
	}
	//check top left to bottom right diagonal
	if ((space[0] == 0 && space[1] == 0) || (space[0] == 1 && space[1] == 1) || (space[0] == 2 && space[1] == 2))
	{
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		{
			return true;
		}
	}
	//check bottom left to top right diagonal
	if ((space[0] == 2 && space[1] == 0) || (space[0] == 1 && space[1] == 1) || (space[0] == 0 && space[1] == 2))
	{
		if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
		{
			return true;
		}
	}
	//no win, return false
	return false;
}