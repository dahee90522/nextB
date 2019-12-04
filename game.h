#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <string>
#include<fstream>

#pragma warning(disable:4996)
using namespace std;
unsigned char f = 0xa1;
unsigned char l = 0xe1;
unsigned char mf = 0xa2;
unsigned char ml = 0xb2;
unsigned char l1 = 0xa6;//line
unsigned char l2 = 0xad;
unsigned char p1 = 0xae;//phone
unsigned char p2 = 0xac;
unsigned char p3 = 0xAF;
unsigned char p4 = 0xad;
unsigned char p5 = 0xb1;
unsigned char p6 = 0xb0;
unsigned char i1[9] = { 0xa2, 0xbe , 0xc2, 0xb8, 0xbc, 0xc3, 0xc2 };//icon
int movex = 25;
int movey = 20;
int bestscore1 = 0;
int bestscore2 = 0;
int finalbestscore = 0;
int iconnum = 1;
int colornum = 7;
//전역변수