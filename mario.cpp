
#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 

void init(void);
void titleDraw(void);
int keyControl(void);
void gotoxy(int, int);
void init(void);
int menuDraw(void);
void Stage(char(*aryStage)[51]);
void object(int x, int y);
void move(char(*aryStage)[51]);


int px = 2;
int py = 8;
int playing = 1;

int main(void)
{
	char aryStage[10][51] = {
		{"11111111111111111111111111111111111111111111111131"},
		{"11111111111111110001111111111111111001111100111000"},
		{"11111111110011111111111100111100111111111111111111"},
		{"00000011111111111111111111111111111111111111111111"},
		{"11111111100111111111111111111111111111111111111111"},
		{"11111111111111100111111111100111144111111111111111"},
		{"11111111111111111111100111111110011110000111111111"},
		{"11111114411111144111111111111111111111111110014411"},
		{"21111111111111111111111111144441111111111111111111"},
		{"00000001100000110011000011000000001111000001100000"}
	};
	int menuCode;

	init();
	while (1)
	{
		titleDraw();

		menuCode = menuDraw();
		if (menuCode == 0)
		{
			Stage(aryStage);
			move(aryStage);
		}

		else if (menuCode == 1)

		{

			//infoDraw();

		}

		else if (menuCode == 2)

		{

			break;

		}

		//menuCode = 5;

		system("cls");

	}



	gotoxy(12, 16);

	printf("게임이 종료 되었습니다.!!!");

	_getch();



	return 0;

}

void gotoxy(int x, int y) {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //  
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void init(void)
{
	system("mode con cols=56 lines=20 | title SUFER MARIO");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // false 또는 0 : 숨기기 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	//pKey = 0;
	playing = 1;
}

void titleDraw(void)
{
	printf("\n\n");
	printf("\t■■■  ■  ■  ■■■  ■■■  ■■■\n");
	printf("\t■    ■  ■  ■    ■    ■■  ■\n");
	printf("\t■■■  ■  ■  ■■■  ■■■  ■■■\n");
	printf("\t  ■  ■  ■  ■    ■    ■■\n");
	printf("\t■■■  ■■■   ■    ■■■  ■  ■\n");
	printf("\n");
	printf("\t\t▣      ▣  ▣▣▣  ▣▣▣  ▣     ▣\n");
	printf("\t\t▣▣  ▣▣  ▣  ▣  ▣  ▣  ▣  ▣    ▣\n");
	printf("\t\t▣  ▣  ▣  ▣▣▣  ▣▣▣  ▣  ▣     ▣\n");
	printf("\t\t▣      ▣  ▣  ▣  ▣▣    ▣  ▣    ▣\n");
	printf("\t\t▣      ▣  ▣  ▣  ▣  ▣  ▣     ▣\n");

}

int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
}

int menuDraw() {

	int x = 24;
	int y = 15;
	gotoxy(x - 2, y);
	printf("> 게임시작");
	gotoxy(x, y + 1);
	printf("게임정보");
	gotoxy(x, y + 2);
	printf("  종료  ");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 17) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 15;
		}
		}
	}
}

void Stage(char(*aryStage)[51])
{
	system("cls");
	for (int i = py - 4; i <= py + 2; i++) {
		for (int j = px - 2; j < px + 8; ++j) {
			if (i == py && j == px) {
				printf("§");
			}
			else if (aryStage[i][j] == '0') {
				printf("■");
			}
			else if (aryStage[i][j] == '1') {
				printf("  ");
			}
			else if (aryStage[i][j] == '2') {
				printf("▷");
			}
			else if (aryStage[i][j] == '3') {
				printf("◁");
			}
			else if (aryStage[i][j] == '4') {
				printf("☆");
			}
		}
		printf("\n");
	}
}

void object(int x, int y)
{
	px += x;
	py += y;
}

void move(char(*aryStage)[51])

{
	int mKey;
	while (playing)

	{

		mKey = keyControl();

		switch (mKey)
		{
		case UP:

			object(0, -1);
			Stage(aryStage);
			break;

		case DOWN:

			object(0, 1);
			Stage(aryStage);
			break;

		case RIGHT:

			object(1, 0);
			Stage(aryStage);
			break;

		case LEFT:

			object(-1, 0);
			Stage(aryStage);
			break;

		case SUBMIT:
			playing = 0;
		}
	}

	playing = 1;

}
