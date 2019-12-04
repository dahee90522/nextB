#include "game.h"

void myicon();
void setting();
void iconchoose(); void colorchoose();
void gotoxy(int x, int y);
void gametype();
void press_any();//아무키나 누르면 메뉴로
void press_any_out(void);//설명화면에서 넘어가기
void confirm();
void phoneconfirm(string name, int bbestscore);
void move(int type);
void phone();
int out();
void explain();

int main() {
	system("cls");
	int y = 15;
	int manu;
	gotoxy(24, 10);
	//printf("최고 점수 : %d 개", bestscore);
	while (1) {
		gotoxy(24, 15);
		cout << "1. 게임 시작";
		gotoxy(24, 17);
		cout << "2. 게임 설명";
		gotoxy(24, 19);
		cout << "3. 게임 세팅";
		gotoxy(24, 21);
		cout << "4. 게임 종료";
		gotoxy(24, 25);
		cout << ">> ";
		cin >> manu;
		if (manu == 1)
			gametype();
		if (manu == 2)
			explain();
		if (manu == 3)
			setting();
		if (manu == 4) {
			gotoxy(24, 24);
			exit(0);
		}
		system("cls");
	}
	return 0;
}
void gametype() {

	system("cls");
	gotoxy(24, 15);
	cout << "1. ↑(아래에서 위로)";
	gotoxy(24, 16);
	cout << "2. ↓(위에서 아래로)";
	gotoxy(24, 19);
	cout << "0. 메인으로";
	gotoxy(24, 20);
	cout << ">> ";
	cin >> mainfr;
	while (true) {
		if (mainfr == 0) main();
		else if (mainfr == 1 || mainfr == 2) out();
		else {
			gotoxy(24, 20);
			cout << "다시 >> ";
			cin >> mainfr;
		}
	}
	system("cls");

}
void press_any() {
	gotoxy(20, 38);
	cout << "최고점수 = " << bestscore1;
	gotoxy(20, 39);
	cout << "esc버튼을 두 번 누르면 인증서 발급";
	gotoxy(20, 40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "ENTER 누르면 메인 메뉴로..\n";

	movey = 20;
	int key;
	while (true) {
		/*a = getch();
		if (a = 27) { confirm(); }
		else if (a = 13) { system("cls"); main(); break; }
		else continue;*/
		if (kbhit()) {
			key = getch();
			if (key == 27)confirm();
			else if (key == 13) main();
			else continue;
		}
	}
}
void press_any_out() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "아무 키나 누르면 게임 시작..\n";
	getch();
	system("cls");
	gametype();
}
void iconchoose() {
	system("cls");
	gotoxy(24, 8);
	cout << "현재 아이콘 번호 : " << iconnum;
	gotoxy(24, 10);
	cout << "1. " << i1[0] << i1[1];
	gotoxy(24, 12);
	cout << "2. " << i1[0] << i1[2];
	gotoxy(24, 14);
	cout << "3. " << i1[0] << i1[3];
	gotoxy(24, 16);
	cout << "4. " << i1[0] << i1[4];
	gotoxy(24, 18);
	cout << "5. " << i1[0] << i1[5];
	gotoxy(24, 20);
	cout << "6. " << i1[0] << i1[6];
	gotoxy(24, 24);
	cout << ">>";
	cin >> iconnum;
	system("cls");
}
void colorchoose() {
	system("cls");

	gotoxy(24, 16);
	cout << "1 = 파란색";
	gotoxy(24, 17);
	cout << "2 = 녹색";
	gotoxy(24, 18);
	cout << "3 = 청록색";
	gotoxy(24, 19);
	cout << "4 = 빨간색";
	gotoxy(24, 20);
	cout << "5 = 자주색";
	gotoxy(24, 21);
	cout << "6 = 노란색";
	gotoxy(24, 22);
	cout << "7 = 흰색";
	gotoxy(24, 23);
	cout << "8 = 회색\n";
	gotoxy(24, 24);
	cout << "색을 고르세요 >> ";
	cin >> colornum;
	while (colornum == 0 || colornum > 8) {//검은배경에 검은색X
		cout << "다시 고르세요 >> ";
		cin >> colornum;
	}
	system("cls");
}
void setting() {
	int set;
	system("cls");
	gotoxy(24, 15);
	cout << "1. 아이콘 고르기";
	gotoxy(24, 17);
	cout << "2. 아이콘 색 고르기";
	gotoxy(24, 19);
	cout << "3. 메뉴로 되돌아가기";
	gotoxy(24, 21);
	cout << ">> ";
	cin >> set;
	if (set == 1)
		iconchoose();
	if (set == 2)
		colorchoose();
	if (set == 3)
		main();
}
void myicon() {
	system("cls");
	//char ic;
	iconnum = 7;
	gotoxy(24, 17);
	cout << "자신이 원하는 아이콘 입력 : ";
	gotoxy(24, 20);
	cout << ">> ";
	cin >> i1[iconnum];
}
void confirm() {
	string name;
	system("cls");
	gotoxy(20, 15);
	cout << "점수 : " << bestscore1 << endl;
	gotoxy(20, 17);
	cout << "이름 : ";
	cin >> name;
	string out_line;
	ofstream out(name + ".txt", ios_base::out);
	phoneconfirm(name, bestscore1);
	out.close();

	//출력
	system("cls");
	string in_line;
	ifstream in(name + ".txt");
	cout << endl;
	while (getline(in, in_line)) {
		cout << in_line << endl;
	}
	in.close();
	cout << endl << endl;
	cout << "아무 키나 누르면 메인메뉴로..\n";
	getch();
	main();
	system("pause");
}
void phoneconfirm(string name, int bbestscore) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	ofstream confirm;
	confirm.open(name + ".txt");
	confirm << "\t\t인증서" << endl << endl;
	confirm << "\t\t\t\t이름 : " << name << endl << endl << endl;
	confirm << "\t위 사람은 nextB 게임을 하고" << endl;
	confirm << "\t   점수 " << bestscore1 << "점을 기록하였기에" << endl;
	confirm << "\t  이 수료장을 수여합니다." << endl << endl << endl << endl;
	confirm << "\t\t" << tm.tm_year + 1900 << "년" << tm.tm_mon + 1 << "월" << tm.tm_mday << "일" << endl;
	confirm << "\t\t\t개발자 황다희";

}//수료증파일입출력
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//좌표
void move(int type) {
	gotoxy(movex, movey);
	cout << "  ";
	int put;
	if (type == 1) {
		if (kbhit()) {
			put = getch();
			if (put == 32)
				movey--;
			else {
				movey++;
				Sleep(40);

			}
		}
		else {
			movey++;
			Sleep(40);

		}
	}
	else if (type == 2) {
		if (kbhit()) {
			put = getch();
			if (put == 32)
				movey++;
		}
		else {
			movey--;
			Sleep(40);

		}
	}
	gotoxy(movex, movey);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colornum);//모양을 하얀색으로 지정
	if (iconnum != 7)
		cout << i1[0] << i1[iconnum];
	else
		cout << i1[iconnum];
	Sleep(35);

}//스페이스바로 상하 조정
void phone() {
	gotoxy(20, 5);
	cout << l1 << p1;
	for (int i = 0; i < 40; i++) {
		cout << l1 << p2;
	}
	cout << l1 << p3;
	for (int j = 0; j <= 30; j++) {
		gotoxy(20, j + 6);
		cout << l1 << p4;
		for (int i = 0; i < 20; i++) {
			cout << "  ";
		}
		cout << l1 << p4;
		cout << endl;
	}
	gotoxy(20, 36);
	cout << l1 << p5;
	for (int i = 0; i < 40; i++) {
		cout << l1 << p2;
	}
	cout << l1 << p6;
	cout << endl << endl << endl << endl << endl << endl << endl;
}//기본 네모 틀 만들기
int out() {
	int fast = 20;
	int score1;
	int score2;
	int sero = 26;//세로 개수
	int line = 0;
	int color;
	int score = 0;
	srand((unsigned int)time(NULL));
	while (1) {
		int firstlinex = 60;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//틀을 하얀색으로 지정
		gotoxy(35, 3);
		cout << "점수 : " << score << " 개";
		phone();

		line = rand() % 24 + 1;//길이

		int lineline[30] = {};
		for (int i = 0; i <= line; i++) {
			lineline[i] = 0;
		}
		for (int i = line + 1; i < line + 6; i++) {
			lineline[i] = 1;
		}
		for (int i = line + 6; i < 30; i++) {
			lineline[i] = 0;
		}
		color = rand() % 15 + 1;//색 랜덤
		while (firstlinex > 22) {
			for (int c = 0; c < 2; c++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				for (int o = 0; o < 30; o++) {//줄 생성
					gotoxy(firstlinex - c, 6 + o);
					if (lineline[o] == 0) {
						cout << l1 << l2;
					}
					else {
						cout << " ";
					}
					cout << endl;
				}
			}
			move(mainfr);
			if (movey > 34 || movey < 6)
				press_any();
			if (firstlinex - 2 == movex) {
				if (lineline[movey - 5] == 0) { press_any(); }
			}

			for (int i = 0; i < 30; i++) {
				gotoxy(firstlinex, 6 + i);
				cout << " ";

			}//전 줄 없애기

			firstlinex--;
			if (firstlinex == 22) {
				for (int j = 0; j <= 1; j++) {
					for (int i = 0; i < 30; i++) {

						gotoxy(25 - j, 6 + i);
						//cout<<" ";
					}
				}score++;
				if (score % 5 == 0) {
					if (fast > 3) {
						fast -= 3;
					}
				}

			}
			Sleep(30);
		}
		bestscore1 = score;
	}
	if (mainfr == 1) {
		score1 = score;
		if (score1 > bestscore1) {
			bestscore1 = score;
		}
	}
	else if (mainfr == 2) {
		score2 = score;
		if (score2 > bestscore2) {
			bestscore2 = score;
		}
	}

	press_any();
}//선 출력/게임 실행
void explain() {
	system("cls");
	gotoxy(24, 24);
	cout << "스페이스바를 이용하여 하트를 이동시킵니다.";
	gotoxy(24, 25);
	cout << "다가오는 선중 빈 공간으로 아이콘을 넣으면 됩니다.";
	gotoxy(24, 26);
	cout << "한박자씩 늦게 움직이니 알아서 맞추시길~~";
	gotoxy(24, 27);
	cout << "즐거운 게임 되세여";
	gotoxy(24, 29);
	press_any_out();
} //설명 칸