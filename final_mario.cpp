#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 


void titleDraw(void);
int keyControl(void);
void gotoxy(int, int);
int menuDraw(void);
void Stage(char(*aryStage)[80]);
void objectXY(int x, int y);
void move(char(*aryStage)[80]);
void jump(char(*aryStage)[80]);
void drawUI(void);
void infoDraw();



int px = 2;
int py = 8;
int playing = 1;
bool Go = false;
bool item = true;
int star = 0;
int big = 0;
int fire = 0;
bool fireState = false;

char tempStage[10][80] = {
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111105111111111111601111111111111111111111111111111111111111311111111111111"},
	   {"1111111111110011114411111111111111001111111144111111111441111110001111111111111"},
	   {"1111111111111111119911111119444111111111111111111111111111111100000111111111111"},
	   {"0000000000000000000000000000000000111000000110000011000001100000000001111111111"}
};

int main(void)
{
	char aryStage[10][80] = {
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111111111111111111111111111111111111111111111111111111111111111111111111111"},
	   {"1111111105111111111111601111111111111111111111111111111111111111311111111111111"},
	   {"1111111111110011114411111111111111001111111144111111111441111110001111111111111"},
	   {"1111111111111111119911111119444111111111111111111111111111111100000111111111111"},
	   {"0000000000000000000000000000000000111000000110000011000001100000000001111111111"}
	};

	int menuCode;
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

			infoDraw();

		}

		else if (menuCode == 2)

		{

			break;

		}

		//menuCode = 5;

		system("cls");

	}



	gotoxy(12, 16);

	printf("게임이 종료되었습니다!!!");

	_getch();



	return 0;

}

void gotoxy(int x, int y) {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void titleDraw(void)
{
	printf("\n\n");
	printf("\t■■■  ■  ■  ■■■  ■■■  ■■■\n");
	printf("\t■      ■  ■  ■  ■  ■      ■  ■\n");
	printf("\t■■■  ■  ■  ■■■  ■■■  ■■■\n");
	printf("\t    ■  ■  ■  ■      ■      ■■\n");
	printf("\t■■■  ■■■  ■      ■■■  ■  ■\n");
	printf("\n");
	printf("\t\t▣      ▣  ▣▣▣  ▣▣▣  ▣    ▣\n");
	printf("\t\t▣▣  ▣▣  ▣  ▣  ▣  ▣  ▣  ▣  ▣\n");
	printf("\t\t▣  ▣  ▣  ▣▣▣  ▣▣▣  ▣  ▣  ▣\n");
	printf("\t\t▣      ▣  ▣  ▣  ▣▣    ▣  ▣  ▣\n");
	printf("\t\t▣      ▣  ▣  ▣  ▣  ▣  ▣    ▣\n");

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
	else if (temp == ' ') { // 스페이스바(공백)이 선택 버튼  
		return SUBMIT;
	}
}

void infoDraw() {

	system("cls"); // 화면 모두 지우기  

	printf("\n\n");

	printf("                       [ 조작법 ]\n\n\n\n");

	printf("                       이동: A, D\n");

	printf("                      위로 점프: W\n");

	printf("             오른쪽 점프 및 선택: 스페이스바\n\n\n\n\n");

	printf("                개발자: consolegame 4조\n\n");

	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {

		if (keyControl() == SUBMIT) {
			break;
		}
	}
}


int menuDraw() {

	int x = 24;
	int y = 15;
	gotoxy(x - 2, y); // -2 한 이유는 > 를 출력해야하기 때문에  
	printf("> 게임시작");
	gotoxy(x, y + 1);
	printf("게임정보");
	gotoxy(x, y + 2);
	printf("  종료  ");

	while (1) { // 무한반복  
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기  
		switch (n) {
		case UP: { // 입력된 키의 값이 UP인경우 (w) 
			if (y > 15) { // y는 12~14까지만 이동  
				gotoxy(x - 2, y); // x-2 하는 이유는 ">"를 두칸 이전에 출력하기위해  
				printf(" "); // 원래 위치를 지우고  
				gotoxy(x - 2, --y); // 새로 이동한 위치로 이동하여  
				printf(">"); // 다시 그리기  
			}
			break;
		}
		case DOWN: { // 입력된 키의 값이 DOWN인경우 (s) 
			if (y < 17) { // 최대 14  
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 15; // 스페이스바(선택)되었을 경우 y-12
			// y 시작 위치가 12였으므로 y-12 를 하면 0, 1, 2 세 숫자를 받을 수 있다. 
		}
		}
	}
}

void Stage(char(*aryStage)[80])
{
	system("cls");
	
	if (px < 0) {
		px = 0;
	}

	else if (px >= 69) {
		px = 68;
	}

	else if (px > 61)
	{

		for (int q = py - 4; q < py + 2; q++)
		{
			for (int w = px; w < px + 8; w++)
			{
				if (q == py && w == px) {

					if (tempStage[q][w] == '4')
					{
						tempStage[q][w] = '1';
						star++;
					}
					else if (tempStage[q][w] == '5')
					{
						tempStage[q][w] = '1';
						big = 1;
					}
					else if (tempStage[q][w] == '6')
					{
						tempStage[q][w] = '1';
						fireState = true;
						fire = 1;
					}

					else if (tempStage[q][w] == '9')
					{	
						if (big >= 0)
						{
							tempStage[q][w] = '1';
							big--;
						}

						else if (big < 0)
						{
							/*for (int a = py-4; a < py + 2; a++)
							{
							   for (int b = px; b < px + 8; b++)
							   {
								  printf("♨");
							   }
							   Sleep(500);
							}*/
							memcpy(tempStage, aryStage, sizeof(tempStage));
							playing = 0;
						}

						if (!fireState) {
							if (fire > 0)
							{
								tempStage[q][w] = '1';
								fire--;
							}
						}
						else if (fire < 0)
						{
							memcpy(tempStage, aryStage, sizeof(tempStage));
							playing = 0;
						}
						
					}

					if (big==0) {
						printf("§");
					}
					else if (big==1) {
						printf("§\n");
						printf("    §");
					}
				}
				else if (tempStage[q][w] == '0' || tempStage[q][w] == '5' || tempStage[q][w] == '6') {   // 0:벽 1:길 2:시작점 3:도착점 4:코인
					if (item) {
						printf("■");
					}
					else {
						if (tempStage[q][w] == '0') {
							printf("■");
						}
						if (tempStage[q][w] == '5') {
							printf("♡");
						}
						else if (tempStage[q][w] == '6') {
							printf("♧");
						}

					}
				}
				else if (aryStage[q][w] == '9')
				{
					printf("※");
				}
				else if (tempStage[q][w] == '1') {
					printf("  ");
				}
				else if (tempStage[q][w] == '2') {
					printf("▶");
				}
				else if (tempStage[q][w] == '3') {
					printf("◀");
				}
				else if (tempStage[q][w] == '4') {
					printf("☆");
				}

			}
			printf("\n");
		}
	}

	else {
		for (int i = py - 4; i <= py + 2; i++) {
			for (int j = px - 2; j < px + 8; ++j) {
				if (i == py && j == px) {

					if (tempStage[i][j] == '4') {
						tempStage[i][j] = '1';
						star++;
					}

					else if (tempStage[i][j] == '5')
					{
						tempStage[i][j] = '1';
						big = 1;
					}
					else if (tempStage[i][j] == '6')
					{
						tempStage[i][j] = '1';
						fire = 1;
					}
					else if (tempStage[i][j] == '9')
					{
						if (big >=0)
						{
							tempStage[i][j] = '1';
							big--;
						}
						if (fire >= 0)
						{
							tempStage[i][j] = '1';
							fireState = false;
							fire--;
						}
						else if (big < 0)
						{
							big = 0;
							star = 0;
							fire = 0;
							px = 2;
							py = 8;
							memcpy(tempStage, aryStage, sizeof(tempStage));
							playing = 0;
						}
						else if (fire < 0)
						{
							big = 0;
							star = 0;
							fire = 0;
							px = 2;
							py = 8;
							memcpy(tempStage, aryStage, sizeof(tempStage));
							playing = 0;
						}
					}
					if (fireState) {
						if (tempStage[i][j + 1] == '9') {
							tempStage[i][j + 1] = '1';
						}
					}

					if (big == 0) {
						printf("§");
					}
					else if (big == 1) {
						printf("§\n");
						printf("    §");
					}
				}

				else if (tempStage[i][j] == '0' || tempStage[i][j] == '5' || tempStage[i][j] == '6') {   // 0:벽 1:길 2:시작점 3:도착점 4:코인
					if (item) {
						printf("■");
					}
					else {
						if (tempStage[i][j] == '0') {
							printf("■");
						}
						if (tempStage[i][j] == '5') {
							printf("♡");
						}
						else if (tempStage[i][j] == '6') {
							printf("♧");
						}
					}
				}
				else if (tempStage[i][j] == '1') {
					printf("  ");
				}
				else if (tempStage[i][j] == '2') {
					printf("▶");
				}
				else if (tempStage[i][j] == '3') {
					printf("◀");
				}
				else if (tempStage[i][j] == '4') {
					printf("☆");
				}
				else if (aryStage[i][j] == '9')
				{
					printf("※");
				}

			}
			printf("\n");
		}
	}
}

void objectXY(int x, int y)
{
	px += x;
	py += y;
}

void move(char(*aryStage)[80])

{
	int mKey;
	while (playing)

	{
		drawUI();
		mKey = keyControl();

		switch (mKey)
		{
		case UP:

			jump(aryStage);
			break;

		case DOWN:

			objectXY(0, 1);
			Stage(aryStage);
			break;

		case RIGHT:

			objectXY(1, 0);
			Stage(aryStage);
			break;

		case LEFT:

			objectXY(-1, 0);
			Stage(aryStage);
			break;

		case SUBMIT:

			Go = true;
			jump(aryStage);
			break;
		}

		if (aryStage[py + 1][px] != '0') {   //만약 발 밑이 벽돌이 아니라면 바닥으로

			while (py < 8) {
				py++;
				Stage(aryStage);
			}
		}

		if (aryStage[py + 1][px] == '1') {
			py++;
			Stage(aryStage);
			Sleep(20);
			system("cls");
			printf("플레이어 사망\n");     //좀 더 화려하게 꾸밀 것  (ex : 폭탄 bomb 하면서 터지는 그런거)
			big = 0;
			star = 0;
			fire = 0;
			px = 2;
			py = 8;
			memcpy(tempStage, aryStage, sizeof(tempStage));
			Sleep(1000);
			playing = 0;
		}

		if (tempStage[py][px] == '3')
		{
			system("cls");
			gotoxy(8, 8);
			printf("♭♭Game Clear♭♭");
			Sleep(1000);
			big = 0;
			star = 0;
			fire = 0;
			px = 2;
			py = 8;
			playing = 0;
		}

		/*if (big < 0)
		{
			memcpy(tempStage, aryStage, sizeof(tempStage));
			big = 0;
			star = 0;
			px = 2;
			py = 8;
			playing = 0;
		}
		else if (fire < 0)
		{
			memcpy(tempStage, aryStage, sizeof(tempStage));
			fire = 0;
			star = 0;
			px = 2;
			py = 8;
			playing = 0;
		}*/
	}

	playing = 1;

}

void jump(char(*aryStage)[80])
{
	bool isJumping = true;
	bool isBottom = true;
	const int gravity = 1;
	int marioY = py;  //전역변수 py대입
	//int marioX = px;  //전역변수 px대입

	while (isBottom)
	{

		if (isJumping) {
			py -= gravity;
		}

		else {
			py += gravity;
		}

		if (Go) {
			px++;
		}

		if (py == marioY) {
			isBottom = false;
		}

		if (aryStage[py][px] == '0' || aryStage[py][px] == '5' || aryStage[py][px] == '6') {
			if (item) {
				if (aryStage[py][px] == '0') {
					isJumping = false;
				}

				else {
					item = false;
					if (aryStage[py][px] == '5') {
						big = 1;
						// 벽돌사라지고 벽돌자리에 아이템  (버섯 or 총알)
					}
				}
				py++;
			}

			else {
				if (aryStage[py][px] == '0') {
					isJumping = false;
					py++;
				}

				/*else {
					tempStage[py][px] = '1';  //아이템 사라지고 스코어 올라감 (쿠 해줘 스코어)
				}*/
			}
		}
		if (fireState) {
			if (aryStage[py + 1][px] == '9') {
				tempStage[py + 1][px] = '1';
			}
		}

		if (aryStage[py + 1][px] == '0') {  //만약 발 밑이 벽돌이라면 벽돌 위
			isBottom = false;
		}

		if (py <= 6) {
			isJumping = false;
		}

		//Sleep(200);
		Sleep(20);
		Stage(aryStage);
		printf("%d", py);

	}
	Go = false;
	item = true;
}

void drawUI(void)

{

	gotoxy(0, 14);

	printf("########################################################");

	gotoxy(3, 16);
	printf("플레이어 위치:(%02d,%02d)", px, py);

	gotoxy(34, 16);
	printf("STAR : %d개", star);

	if (big == 1) {
		gotoxy(34, 17);
		printf("BIG");
	}
	if (fire == 1) {
		gotoxy(34, 18);
		printf("FIRE : %d", fire);
	}

}
