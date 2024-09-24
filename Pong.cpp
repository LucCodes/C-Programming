#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
int ballX, ballY, paddleX;
int ballDirX, ballDirY;
bool gameOver;

void Setup()
{
    gameOver = false;
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    paddleX = WIDTH / 2;
    ballDirX = -1;
    ballDirY = -1;
}

void Draw()
{
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == ballY && j == ballX)
                cout << "O";
            else if (i == HEIGHT - 1 && j >= paddleX - 3 && j <= paddleX + 3)
                cout << "=";
            else
                cout << " ";
            if (j == WIDTH - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                paddleX--;
                break;
            case 'd':
                paddleX++;
                break;
            case 'q':
                gameOver = true;
                break;
        }
    }
}

void Logic()
{
    ballX += ballDirX;
    ballY += ballDirY;

    if (ballX == 0 || ballX == WIDTH - 1)
        ballDirX = -ballDirX;
    if (ballY == 0)
        ballDirY = -ballDirY;
    if (ballY == HEIGHT - 1 && ballX >= paddleX - 3 && ballX <= paddleX + 3)
        ballDirY = -ballDirY;
    if (ballY == HEIGHT - 1 && (ballX < paddleX - 3 || ballX > paddleX + 3))
        gameOver = true;
}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10); // Delay for smoother animation
    }

    return 0;
}