#include "game.h"

void myicon();
void setting();
void iconchoose(); void colorchoose();
void gotoxy(int x, int y);
void gametype();
void press_any();//�ƹ�Ű�� ������ �޴���
void press_any_out(void);//����ȭ�鿡�� �Ѿ��
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
	//printf("�ְ� ���� : %d ��", bestscore);
	while (1) {
		gotoxy(24, 15);
		cout << "1. ���� ����";
		gotoxy(24, 17);
		cout << "2. ���� ����";
		gotoxy(24, 19);
		cout << "3. ���� ����";
		gotoxy(24, 21);
		cout << "4. ���� ����";
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
	cout << "1. ��(�Ʒ����� ����)";
	gotoxy(24, 16);
	cout << "2. ��(������ �Ʒ���)";
	gotoxy(24, 19);
	cout << "0. ��������";
	gotoxy(24, 20);
	cout << ">> ";
	cin >> mainfr;
	while (true) {
		if (mainfr == 0) main();
		else if (mainfr == 1 || mainfr == 2) out();
		else {
			gotoxy(24, 20);
			cout << "�ٽ� >> ";
			cin >> mainfr;
		}
	}
	system("cls");

}
void press_any() {
	gotoxy(20, 38);
	cout << "�ְ����� = " << bestscore1;
	gotoxy(20, 39);
	cout << "esc��ư�� �� �� ������ ������ �߱�";
	gotoxy(20, 40);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "ENTER ������ ���� �޴���..\n";

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
	cout << "�ƹ� Ű�� ������ ���� ����..\n";
	getch();
	system("cls");
	gametype();
}
void iconchoose() {
	system("cls");
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
	gotoxy(24, 24);
	cout << ">>";
	cin >> iconnum;
	system("cls");
}
void colorchoose() {
	system("cls");

	gotoxy(24, 16);
	cout << "1 = �Ķ���";
	gotoxy(24, 17);
	cout << "2 = ���";
	gotoxy(24, 18);
	cout << "3 = û�ϻ�";
	gotoxy(24, 19);
	cout << "4 = ������";
	gotoxy(24, 20);
	cout << "5 = ���ֻ�";
	gotoxy(24, 21);
	cout << "6 = �����";
	gotoxy(24, 22);
	cout << "7 = ���";
	gotoxy(24, 23);
	cout << "8 = ȸ��\n";
	gotoxy(24, 24);
	cout << "���� ������ >> ";
	cin >> colornum;
	while (colornum == 0 || colornum > 8) {//������濡 ������X
		cout << "�ٽ� ������ >> ";
		cin >> colornum;
	}
	system("cls");
}
void setting() {
	int set;
	system("cls");
	gotoxy(24, 15);
	cout << "1. ������ ����";
	gotoxy(24, 17);
	cout << "2. ������ �� ����";
	gotoxy(24, 19);
	cout << "3. �޴��� �ǵ��ư���";
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
	cout << "�ڽ��� ���ϴ� ������ �Է� : ";
	gotoxy(24, 20);
	cout << ">> ";
	cin >> i1[iconnum];
}
void confirm() {
	string name;
	system("cls");
	gotoxy(20, 15);
	cout << "���� : " << bestscore1 << endl;
	gotoxy(20, 17);
	cout << "�̸� : ";
	cin >> name;
	string out_line;
	ofstream out(name + ".txt", ios_base::out);
	phoneconfirm(name, bestscore1);
	out.close();

	//���
	system("cls");
	string in_line;
	ifstream in(name + ".txt");
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
	confirm.open(name + ".txt");
	confirm << "\t\t������" << endl << endl;
	confirm << "\t\t\t\t�̸� : " << name << endl << endl << endl;
	confirm << "\t�� ����� nextB ������ �ϰ�" << endl;
	confirm << "\t   ���� " << bestscore1 << "���� ����Ͽ��⿡" << endl;
	confirm << "\t  �� �������� �����մϴ�." << endl << endl << endl << endl;
	confirm << "\t\t" << tm.tm_year + 1900 << "��" << tm.tm_mon + 1 << "��" << tm.tm_mday << "��" << endl;
	confirm << "\t\t\t������ Ȳ����";

}//���������������
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//��ǥ
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
int out() {
	int fast = 20;
	int score1;
	int score2;
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
			if (movey > 34 || movey < 6)
				press_any();
			if (firstlinex - 2 == movex) {
				if (lineline[movey - 5] == 0) { press_any(); }
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
}//�� ���/���� ����
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