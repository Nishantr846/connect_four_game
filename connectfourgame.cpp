#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

enum class Player
{
    NONE,
    PLAYER1,
    PLAYER2
};
enum class State
{
    ONGOING,
    DRAW,
    PLAYER1_WON,
    PLAYER2_WON
};

class ConnectFour
{
public:
    ConnectFour()
    {
        grid = std::vector<std::vector<Player>>(ROWS, std::vector<Player>(COLS, Player::NONE));
        currentPlayer = Player::PLAYER1;
        gameState = State::ONGOING;
    }

    void playGame()
    {
        while (gameState == State::ONGOING)
        {
            printBoard();
            int column;
            do
            {
                std::cout << "Player " << static_cast<int>(currentPlayer) << ", enter your move (1-7): ";
                std::cin >> column;
            } while (column < 1 || column > 7 || !isValidMove(column - 1));

            makeMove(column - 1);
            checkForWin();
            switchPlayer();
        }

        printBoard();
        if (gameState == State::PLAYER1_WON)
            std::cout << "Player 1 wins!" << std::endl;
        else if (gameState == State::PLAYER2_WON)
            std::cout << "Player 2 wins!" << std::endl;
        else
            std::cout << "It's a draw!" << std::endl;
    }

private:
    std::vector<std::vector<Player>> grid;
    Player currentPlayer;
    State gameState;

    void printBoard()
    {
        system("clear");
        for (int row = ROWS - 1; row >= 0; --row)
        {
            for (int col = 0; col < COLS; ++col)
            {
                if (grid[row][col] == Player::NONE)
                    std::cout << ". ";
                else if (grid[row][col] == Player::PLAYER1)
                    std::cout << "X ";
                else
                    std::cout << "O ";
            }
            std::cout << std::endl;
        }
        std::cout << "1 2 3 4 5 6 7" << std::endl;
    }

    bool isValidMove(int column)
    {
        return column >= 0 && column < COLS && grid[ROWS - 1][column] == Player::NONE;
    }

    void makeMove(int column)
    {
        for (int row = 0; row < ROWS; ++row)
        {
            if (grid[row][column] == Player::NONE)
            {
                grid[row][column] = currentPlayer;
                break;
            }
        }
    }

    void switchPlayer()
    {
        if (currentPlayer == Player::PLAYER1)
            currentPlayer = Player::PLAYER2;
        else
            currentPlayer = Player::PLAYER1;
    }

    void checkForWin()
    {
    }
};

int main()
{
    ConnectFour game;
    game.playGame();
    return 0;
}
