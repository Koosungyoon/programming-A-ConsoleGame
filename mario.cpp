#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 

void init(void);
void titleDraw(void);
int keyControl(void);
void gotoxy(int, int);
int menuDraw(void);
void Stage(char(*aryStage)[70]);
void objectXY(int x, int y);
void move(char(*aryStage)[70]);
void jump(char(*aryStage)[70]);
void drawUI(void);



int px = 2;
int py = 8;
int playing = 1;
bool GoJump = false;
int star = 0;

int main(void)
{
	char aryStage[10][70] = {
	   {"11111111111111111111111111111111111111111111111111111111111111111111"},
	   {"111111111111111100011111111111111110011111001110001111111111111111000"},
	   {"111111111100111111111111001111001111111111111111111111111111001111111"},
	   {"000000111111111111111111111111111111111111111111110000001111111111111"},
	   {"111111111001111111111111111111111111111111111111111111111110011111111"},
	   {"111111111111111001111111111001111441111111111111111111111111111110011"},
	   {"111111110011111111111100111111110011110000111111111111111111111111111"},
	   {"111111111111144111111111111111111111111110014411111111144111111441111"},
	   {"112111111111111111111111111444411111111111111111111111111111111111133"},
	   {"000000011000001100110000110000000011110000011000000000000110000011001"}
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

<<<<<<< HEAD
	printf("게임이 종료되었습니다!!!");
=======
	printf("寃뚯엫??醫낅즺 ?섏뿀?듬땲??!!!");
>>>>>>> 946e7c5604eb34189702d4428b2f3e20b4861af6

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
<<<<<<< HEAD
=======
void init(void)
{
	system("mode con cols=56 lines=20 | title SUFER MARIO");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 肄섏넄 ?몃뱾媛?몄삤湲?
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // false ?먮뒗 0 : ?④린湲?
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	//pKey = 0;
	playing = 1;
}
>>>>>>> 946e7c5604eb34189702d4428b2f3e20b4861af6

void titleDraw(void)
{
	printf("\n\n");
<<<<<<< HEAD
	printf("\t■■■  ■  ■  ■■■  ■■■  ■■■\n");
	printf("\t■    ■  ■  ■ ■  ■    ■ ■\n");
	printf("\t■■■  ■  ■  ■■■  ■■■  ■■■\n");
	printf("\t  ■  ■  ■  ■    ■    ■■\n");
	printf("\t■■■  ■■■   ■    ■■■  ■ ■\n");
	printf("\n");
	printf("\t\t▣      ▣  ▣▣▣  ▣▣▣  ▣    ▣\n");
	printf("\t\t▣▣  ▣▣  ▣  ▣  ▣  ▣  ▣  ▣  ▣\n");
	printf("\t\t▣  ▣  ▣  ▣▣▣  ▣▣▣  ▣  ▣  ▣\n");
	printf("\t\t▣      ▣  ▣  ▣  ▣▣    ▣  ▣  ▣\n");
	printf("\t\t▣      ▣  ▣  ▣  ▣  ▣  ▣    ▣\n");
=======
	printf("\t?졻뼚?? ?? ?? ?졻뼚?? ?졻뼚?? ?졻뼚??n");
	printf("\t??   ?? ?? ??   ??   ?졻뼚  ??n");
	printf("\t?졻뼚?? ?? ?? ?졻뼚?? ?졻뼚?? ?졻뼚??n");
	printf("\t  ?? ?? ?? ??   ??   ?졻뼚\n");
	printf("\t?졻뼚?? ?졻뼚??  ??   ?졻뼚?? ?? ??n");
	printf("\n");
	printf("\t\t??     ?? ?ｂ뼠?? ?ｂ뼠?? ??    ??n");
	printf("\t\t?ｂ뼠  ?ｂ뼠  ?? ?? ?? ?? ?? ??   ??n");
	printf("\t\t?? ?? ?? ?ｂ뼠?? ?ｂ뼠?? ?? ??    ??n");
	printf("\t\t??     ?? ?? ?? ?ｂ뼠    ?? ??   ??n");
	printf("\t\t??     ?? ?? ?? ?? ?? ??    ??n");
>>>>>>> 946e7c5604eb34189702d4428b2f3e20b4861af6

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


int menuDraw() {

	int x = 24;
	int y = 15;
<<<<<<< HEAD
	gotoxy(x - 2, y); // -2 한 이유는 > 를 출력해야하기 때문에  
	printf("> 게임시작");
=======
	gotoxy(x - 2, y);
	printf("> 寃뚯엫?쒖옉");
>>>>>>> 946e7c5604eb34189702d4428b2f3e20b4861af6
	gotoxy(x, y + 1);
	printf("寃뚯엫?뺣낫");
	gotoxy(x, y + 2);
	printf("  醫낅즺  ");

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

void Stage(char(*aryStage)[70])
{
<<<<<<< HEAD
	isystem("cls");
	if (px < 0)
	{
		px = 0;
	}
	if (px >= 70)
		px = 69;
	if (px > 61 && px < 70)
	{
		for (int q = py - 4; q < py + 1; q++)
		{
			for (int w = 62; w < 70; w++)
			{
				if (q == py && w == px) {
					printf("§");
				}
				else if (aryStage[q][w] == '0') {   // 0:벽 1:길 2:시작점 3:도착점 4:코인
					printf("■");
				}
				else if (aryStage[q][w] == '1') {
					printf("  ");
				}
				else if (aryStage[q][w] == '2') {
					printf("▶");
				}
				else if (aryStage[q][w] == '3') {
					printf("◀");
				}
				else if (aryStage[q][w] == '4') {
					printf("☆");
				}
			}
			printf("\n");
		}
	}
	if (px <= 61)
	{
		for (int i = py - 4; i <= py + 1; i++) {
			for (int j = px; j < px + 10; ++j) {
				if (i == py && j == px) {
					printf("§");
				}
				else if (aryStage[i][j] == '0') {   // 0:벽 1:길 2:시작점 3:도착점 4:코인
					printf("■");
				}
				else if (aryStage[i][j] == '1') {
					printf("  ");
				}
				else if (aryStage[i][j] == '2') {
					printf("▶");
				}
				else if (aryStage[i][j] == '3') {
					printf("◀");
				}
				else if (aryStage[i][j] == '4') {
					printf("☆");
				}
=======
	system("cls");
	for (int i = py - 4; i <= py + 2; i++) {
		for (int j = px - 2; j < px + 8; ++j) {
			if (i == py && j == px) {
				printf("짠");
			}
			else if (aryStage[i][j] == '0') {
				printf("??);
			}
			else if (aryStage[i][j] == '1') {
				printf("  ");
			}
			else if (aryStage[i][j] == '2') {
				printf("??);
			}
			else if (aryStage[i][j] == '3') {
				printf("??);
			}
			else if (aryStage[i][j] == '4') {
				printf("??);
>>>>>>> 946e7c5604eb34189702d4428b2f3e20b4861af6
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



void move(char(*aryStage)[70])

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

			GoJump = true;
			jump(aryStage);
			break;
		}
	}

	playing = 1;

}
<<<<<<< HEAD
void jump(char(*aryStage)[70])
{
	bool isJumping = true;
	bool isBottom = true;
	const int gravity = 1;
	int marioY = py;  //전역변수 py대입
	//int marioX = px;  //전역변수 px대입
	//char mapObject =tempMap[px][py];

	while (isBottom)
	{
		if (isJumping != false) {
			py -= gravity;
		}
		else {
			py += gravity;
		}
		if (GoJump) {
			px++;
		}
		if (py == marioY) {
			isBottom = false;
		}
		if (aryStage[px][py] == '0') {

			isJumping = false;
			py++;
		}
		else if (py <= 6) {
			isJumping = false;
		}
		Sleep(500);
		Stage(aryStage);
		printf("%d", py);//해야 할것: object의 위치를 바꾸는 것이 아니라 맵을 뒤로 움직여야됨 (앞으로가는 방향키 누르고있으면 점프 후 계속 앞으로 갈 수 있도록)
	}
	GoJump = false;
	isJumping = true;
}

void drawUI(void)

{

	gotoxy(0, 14);

	printf("########################################################");

	gotoxy(3, 16);

	printf("플레이어 위치:(%02d,%02d)", px, py);
	gotoxy(34, 16);

	printf("STAR : %d개", star);

}




/*#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>

void jump()
{
	bool isJumping = false;
	bool isBottom = true;
	const int gravity = 3;
	int marioY = py;  //전역변수 py대입

	while (true)
	{
		if (isBottom){
			isJumping = true;
			isBottom = false;
		}
		if (isJumping) {
			marioY -= gravity;
		}
		else {
			marioY += gravity;
		}
		if (marioY >= py) {
			marioY = py;
			isBottom = true;
		}
		if (marioY <= 3) {
			isJumping = false;
		}
	}

}*/
