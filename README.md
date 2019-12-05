## this is my C++ 1 year project

This is the <u>consol game</u> that moving the emoji by clicking the **space bar** <br>
When I started this project I developed this file using **C language**.<br>
After half year I developed again to use **C++ language**.


I created this project by referring to the game called ***Amazing Wire***.  
The reason that I choose this game is just I like that game.

> **About this game's function:**

> - You can choose imoji and imoji color
> - You can choose the type that where will the emoji go when you clicking the space bar
> - You can get the certificate when you finish the game 
>    - certificate is including your name(nickname) and your score
> - This code will record your best score ↓↓↓
```C++
ifstream input("bestscore.txt");
	int n;
	input >> n;
	input.close();
	if (n <= bestscore2) {
		ofstream sco;
		sco.open("bestscore.txt"); 
		sco << bestscore2; }
```
