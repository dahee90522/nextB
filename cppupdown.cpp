#include "game.h"
int main();
void gotoxy(int x, int y);
void press_any();//아무키나 누르면 메뉴로
void press_any_out(void);//설명화면에서 넘어가기
void move(int type);
void phone();
int out();
class gamemain {
public:
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
	int out(int mainfr) {
		bestscore1 = 0, bestscore2 = 0;
		int fast = 20;
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
			int liney = line;
			int lineline[30] = {};
			for (int i = 0; i <= line; i++) {
				lineline[i] = 0;
			}
			for (int i = line+1 ; i < line + 6; i++) {
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
				if (movey > 34 || movey < 6)press_any();
				if (firstlinex-2 == movex) {
					if (lineline[movey - 5] != 1) {press_any(); }
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
				Sleep(fast);
			}
			bestscore1 = score;
			bestscore2 = bestscore1;
		}

		press_any();
	}//선 출력/게임 실행
};
class sett {
public:
	void iconchoose() {
		system("cls");
		int trix = 20, triy = 10;
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
		gotoxy(trix, triy);
		cout << "▷";
		while (1) {
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 10) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -= 2);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 80) {
					if (triy < 20) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy += 2);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 13) {
					switch (triy) {
					case 10:iconnum = 1; main();
					case 12:iconnum = 2; main();
					case 14:iconnum = 3; main();
					case 16:iconnum = 4; main();
					case 18:iconnum = 5; main();
					case 20:iconnum = 6; main();
					}
				}
			}
		}
		system("cls");
		
	}
	void colorchoose() {
		system("cls");
		int trix = 20, triy = 16;
		gotoxy(24, 12);
		cout << "1 = 파란색";
		gotoxy(24, 13);
		cout << "2 = 녹색";
		gotoxy(24, 14);
		cout << "3 = 청록색";
		gotoxy(24, 15);
		cout << "4 = 빨간색";
		gotoxy(24, 16);
		cout << "5 = 자주색";
		gotoxy(24, 17);
		cout << "6 = 노란색";
		gotoxy(24, 18);
		cout << "7 = 흰색";
		gotoxy(24, 19);
		cout << "8 = 회색\n";
		gotoxy(trix, triy);
		cout << "▷";
		while (1) {
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 12) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -=1);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 80) {
					if (triy < 19) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy +=1);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 13) {
					switch (triy) {
					case 12:colornum = 1; main();
					case 13:colornum = 2; main();
					case 14:colornum = 3; main();
					case 15:colornum = 4; main();
					case 16:colornum = 5; main();
					case 17:colornum = 6; main();
					case 18:colornum = 7; main();
					case 19:colornum = 8; main();
					}
				}
			}
		}
		system("cls");
		main();
	}
};
class gametype {
public:

	void game() {
		int trix = 20, triy = 15;
		system("cls");
		
		gotoxy(24, 15);
		cout << "1. ↑(아래에서 위로)";
		gotoxy(24, 17);
		cout << "2. ↓(위에서 아래로)";
		gotoxy(24, 19);
		cout << "0. 메인으로";
		gotoxy(trix, triy);
		cout << "▷";
		while (1) {
			gamemain g;
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 15) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -= 2);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 80) {
					if (triy < 19) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy += 2);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 13) {
					if (triy == 15) { g.out(1); }
					if (triy == 17) { g.out(2); }
					if (triy == 19) main();
				}
			}
		}
		system("cls");
	}
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
	void setting() {
		int trix = 20, triy = 15;
		system("cls");
		gotoxy(24, 15);
		cout << "1. 아이콘 고르기";
		gotoxy(24, 17);
		cout << "2. 아이콘 색 고르기";
		gotoxy(24, 19);
		cout << "3. 메뉴로 되돌아가기";
		gotoxy(trix, triy);
		cout << "▷";
		sett s;
		while (1) {
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 15) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -= 2);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 80) {
					if (triy < 19) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy += 2);
						cout << "▷";
					}
					else {
						gotoxy(trix, triy);
						cout << "▷";
					}
				}
				else if (arrow == 13) {
					if (triy == 15) { s.iconchoose(); }
					if (triy == 17) { s.colorchoose(); }
					if (triy == 19) main();
				}
			}
		}
	}
};
class file {
public:
	void confirm() {
		string name;
		system("cls");
		gotoxy(20, 15);
		cout << "점수 : " << bestscore1 << endl;
		gotoxy(20, 17);
		cout << "이름(입력 후 [ENTER]) : ";
		cin >> name;
		string out_line;
		ofstream out(name + " 인증서.txt", ios_base::out);
		phoneconfirm(name, bestscore1);
		out.close();

		//출력
		system("cls");
		string in_line;
		ifstream in(name + " 인증서.txt");
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
		confirm.open(name + " 인증서.txt");
		confirm << "\t\t인증서" << endl << endl;
		confirm << "\t\t\t\t이름 : " << name << endl << endl << endl;
		confirm << "\t위 사람은 nextB 게임을 하고" << endl;
		confirm << "\t   점수 " << bestscore1 << "점을 기록하였기에" << endl;
		confirm << "\t  이 수료장을 수여합니다." << endl << endl << endl << endl;
		confirm << "\t\t" << tm.tm_year + 1900 << "년" << tm.tm_mon + 1 << "월" << tm.tm_mday << "일" << endl;
		confirm << "\t\t\t개발자 황다희";
	}//수료증파일입출력
};
int main() {
	system("cls");
	int triy=17;
	int trix = 20;
	ifstream input("bestscore.txt");
	int n;
	input >> n;
	input.close();
	gotoxy(24, 10);
	cout << "최고 점수 : " << n << "개";
	gotoxy(24, 15);
	cout << "1. 게임 시작";
	gotoxy(24, 17);
	cout << "2. 게임 설명";
	gotoxy(24, 19);
	cout << "3. 게임 세팅";
	gotoxy(24, 21);
	cout << "4. 게임 종료";
	gotoxy(trix, triy);
	cout << "▷";
	while (1) {
		if (kbhit()) {
			int arrow = getch();
			if (arrow == 72) {
				if (triy > 15) {
					gotoxy(trix, triy);
					cout << " ";
					gotoxy(trix, triy -= 2);
					cout << "▷";
				}
				else {
					gotoxy(trix, triy);
					cout << "▷";
				}
			}
			else if (arrow == 80) {
				if (triy < 21) {
					gotoxy(trix, triy);
					cout << " ";
					gotoxy(trix, triy += 2);
					cout << "▷";
				}
				else {
					gotoxy(trix, triy);
					cout << "▷";
				}
			}
			else if (arrow == 13) {
				gametype t;
				if (triy == 15)
					t.game();
				if (triy == 17)
					t.explain();
				if (triy == 19)
					t.setting();
				if (triy == 21) {
					gotoxy(24, 24);
					exit(0);
				}
			}
		}
		
	}
	system("cls");
	return 0;
}
void press_any() {
	ifstream input("bestscore.txt");
	int n;
	input >> n;
	input.close();
	if (n <= bestscore2) {
		ofstream sco;
		sco.open("bestscore.txt"); 
		sco << bestscore2; }

	gotoxy(20, 39);
	cout << "[esc] 버튼을 누르면 인증서 발급";
	gotoxy(20, 40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "[ENTER] 누르면 메인 메뉴로..\n";

	movey = 20;
	int key;
	
	file f;
	//f.bscore(bestscore2);
	while (true) {
		if (kbhit()) {
			
			key = getch();
			if (key == 27) {  f.confirm(); }
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
	gametype g;
	g.game();
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//좌표
