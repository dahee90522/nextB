#include "game.h"
int main();
void gotoxy(int x, int y);
void press_any();//�ƹ�Ű�� ������ �޴���
void press_any_out(void);//����ȭ�鿡�� �Ѿ��
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colornum);//����� �Ͼ������ ����
		if (iconnum != 7)
			cout << i1[0] << i1[iconnum];
		else
			cout << i1[iconnum];

		Sleep(35);

	}//�����̽��ٷ� ���� ����
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
	}//�⺻ �׸� Ʋ �����
	int out(int mainfr) {
		bestscore1 = 0, bestscore2 = 0;
		int fast = 20;
		int sero = 26;//���� ����
		int line = 0;
		int color;
		int score = 0;

		srand((unsigned int)time(NULL));
		while (1) {
			int firstlinex = 60;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//Ʋ�� �Ͼ������ ����
			gotoxy(35, 3);
			cout << "���� : " << score << " ��";
			phone();

			line = rand() % 24 + 1;//����
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
			color = rand() % 15 + 1;//�� ����
			while (firstlinex > 22) {
				for (int c = 0; c < 2; c++) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
					for (int o = 0; o < 30; o++) {//�� ����
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

				}//�� �� ���ֱ�

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
	}//�� ���/���� ����
};
class sett {
public:
	void iconchoose() {
		system("cls");
		int trix = 20, triy = 10;
		gotoxy(24, 8);
		cout << "���� ������ ��ȣ : " << iconnum;
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
		cout << "��";
		while (1) {
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 10) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -= 2);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
					}
				}
				else if (arrow == 80) {
					if (triy < 20) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy += 2);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
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
		cout << "1 = �Ķ���";
		gotoxy(24, 13);
		cout << "2 = ���";
		gotoxy(24, 14);
		cout << "3 = û�ϻ�";
		gotoxy(24, 15);
		cout << "4 = ������";
		gotoxy(24, 16);
		cout << "5 = ���ֻ�";
		gotoxy(24, 17);
		cout << "6 = �����";
		gotoxy(24, 18);
		cout << "7 = ���";
		gotoxy(24, 19);
		cout << "8 = ȸ��\n";
		gotoxy(trix, triy);
		cout << "��";
		while (1) {
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 12) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -=1);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
					}
				}
				else if (arrow == 80) {
					if (triy < 19) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy +=1);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
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
		cout << "1. ��(�Ʒ����� ����)";
		gotoxy(24, 17);
		cout << "2. ��(������ �Ʒ���)";
		gotoxy(24, 19);
		cout << "0. ��������";
		gotoxy(trix, triy);
		cout << "��";
		while (1) {
			gamemain g;
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 15) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -= 2);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
					}
				}
				else if (arrow == 80) {
					if (triy < 19) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy += 2);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
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
		cout << "�����̽��ٸ� �̿��Ͽ� ��Ʈ�� �̵���ŵ�ϴ�.";
		gotoxy(24, 25);
		cout << "�ٰ����� ���� �� �������� �������� ������ �˴ϴ�.";
		gotoxy(24, 26);
		cout << "�ѹ��ھ� �ʰ� �����̴� �˾Ƽ� ���߽ñ�~~";
		gotoxy(24, 27);
		cout << "��ſ� ���� �Ǽ���";
		gotoxy(24, 29);
		press_any_out();
	} //���� ĭ
	void setting() {
		int trix = 20, triy = 15;
		system("cls");
		gotoxy(24, 15);
		cout << "1. ������ ����";
		gotoxy(24, 17);
		cout << "2. ������ �� ����";
		gotoxy(24, 19);
		cout << "3. �޴��� �ǵ��ư���";
		gotoxy(trix, triy);
		cout << "��";
		sett s;
		while (1) {
			if (kbhit()) {
				int arrow = getch();
				if (arrow == 72) {
					if (triy > 15) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy -= 2);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
					}
				}
				else if (arrow == 80) {
					if (triy < 19) {
						gotoxy(trix, triy);
						cout << " ";
						gotoxy(trix, triy += 2);
						cout << "��";
					}
					else {
						gotoxy(trix, triy);
						cout << "��";
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
		cout << "���� : " << bestscore1 << endl;
		gotoxy(20, 17);
		cout << "�̸�(�Է� �� [ENTER]) : ";
		cin >> name;
		string out_line;
		ofstream out(name + " ������.txt", ios_base::out);
		phoneconfirm(name, bestscore1);
		out.close();

		//���
		system("cls");
		string in_line;
		ifstream in(name + " ������.txt");
		cout << endl;
		while (getline(in, in_line)) {
			cout << in_line << endl;
		}
		in.close();
		cout << endl << endl;
		cout << "�ƹ� Ű�� ������ ���θ޴���..\n";
		getch();
		main();
		system("pause");
	}
	void phoneconfirm(string name, int bbestscore) {
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		ofstream confirm;
		confirm.open(name + " ������.txt");
		confirm << "\t\t������" << endl << endl;
		confirm << "\t\t\t\t�̸� : " << name << endl << endl << endl;
		confirm << "\t�� ����� nextB ������ �ϰ�" << endl;
		confirm << "\t   ���� " << bestscore1 << "���� ����Ͽ��⿡" << endl;
		confirm << "\t  �� �������� �����մϴ�." << endl << endl << endl << endl;
		confirm << "\t\t" << tm.tm_year + 1900 << "��" << tm.tm_mon + 1 << "��" << tm.tm_mday << "��" << endl;
		confirm << "\t\t\t������ Ȳ����";
	}//���������������
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
	cout << "�ְ� ���� : " << n << "��";
	gotoxy(24, 15);
	cout << "1. ���� ����";
	gotoxy(24, 17);
	cout << "2. ���� ����";
	gotoxy(24, 19);
	cout << "3. ���� ����";
	gotoxy(24, 21);
	cout << "4. ���� ����";
	gotoxy(trix, triy);
	cout << "��";
	while (1) {
		if (kbhit()) {
			int arrow = getch();
			if (arrow == 72) {
				if (triy > 15) {
					gotoxy(trix, triy);
					cout << " ";
					gotoxy(trix, triy -= 2);
					cout << "��";
				}
				else {
					gotoxy(trix, triy);
					cout << "��";
				}
			}
			else if (arrow == 80) {
				if (triy < 21) {
					gotoxy(trix, triy);
					cout << " ";
					gotoxy(trix, triy += 2);
					cout << "��";
				}
				else {
					gotoxy(trix, triy);
					cout << "��";
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
	cout << "[esc] ��ư�� ������ ������ �߱�";
	gotoxy(20, 40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "[ENTER] ������ ���� �޴���..\n";

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
	cout << "�ƹ� Ű�� ������ ���� ����..\n";
	getch();
	system("cls");
	gametype g;
	g.game();
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//��ǥ
