// github_project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#pragma once
#pragma once
#include "stdafx.h"
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <string.h>

using namespace std;

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define IVORY 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define SKYBLUE 9
#define YELLOWGREEN 10
#define WHITEIVORY 11
#define PINK 12
#define WHITEPURPLE 13
#define WHITEYELLOW 14
#define BOLDWHITE 15

#define BOARD_SIZE 5

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

#define PADNUM_0 49
#define PADNUM_1 50
#define PADNUM_2 51
#define PADNUM_3 52
#define PADNUM_4 53
#define PADNUM_5 54
#define PADNUM_6 55
#define PADNUM_7 56
#define PADNUM_8 57
#define PADNUM_9 58

void setColor(int background, int foreground)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (background << 4) | foreground);
}

#define MAX 3

int main()
{
	random_device rn;
	mt19937_64 rnd(rn());
	uniform_int_distribution<int> range(0, MAX - 1);

	int board[3][3] = { 0, };
	int num = 0, input, curser_x = 1, curser_y = 1, turn = 0;

	while (1) {
		system("cls");

		printf("===========삼목 게임===============\n");
		printf("┌─┬─┬─┐\n");
		for (int y = 0; y < MAX; y++) {
			printf("│");
			for (int x = 0; x < MAX; x++) {
				if (x == curser_x && y == curser_y) { printf("%★│"); }
				else if (board[y][x] == 1) { printf("○│"); }
				else if (board[y][x] == 2) { printf("Ⅹ│"); }
				else printf("  │", board[y][x]);
			}

			printf("\n");
			if (y < MAX - 1) {
				printf("├─┼─┼─┤\n");
			}
			else
				printf("└─┴─┴─┘\n");
		}

		input = _getch();

		if (input == LEFT && curser_x > 0) {
			curser_x -= 1;
		}
		else if (input == RIGHT && curser_x < MAX - 1) {
			curser_x += 1;
		}
		else if (input == UP && curser_y > 0) {
			curser_y -= 1;
		}
		else if (input == DOWN && curser_y < MAX - 1) {
			curser_y += 1;
		}
		else if (input == SPACE && turn % 2 == 0 && board[curser_y][curser_x] == 0) {
			board[curser_y][curser_x] = 1;
			turn++;
		}
		else if (input == SPACE && turn % 2 == 1 && board[curser_y][curser_x] == 0) {
			board[curser_y][curser_x] = 2;
			turn++;
		}
		for (int y = 0; y < MAX - 1; y++) {
			for (int x = 0; x < MAX - 1; x++) {

			}
		}
	}


	system("pause");

	return 0;
}

