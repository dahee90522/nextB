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
----------
## schedule
**2019-04-01~** _<br>Planning what I will do_   
**2019-05-01~** _<br>Developing with C language_   
                used my knowledge that I learned at vacation academy<br>
                make a frame and main screen<br>
**2019-06-01~** _<br>make a main game source_   
		hardest thing was emoji and line move at the same time<br>
		I'm a bit awkward when run because I didn't learn about threads in C ++.<br>
**2019-08-01~** _<br>Add setting_   
		Settings can change the shape and color of emoji<br>
		Disunite the header(stdio, global variable)<br>
**2019-11-01~** _<br>change the source into C++_   
		put function to class<br>
		add file stream<br>
**2019-12-05~** _<br>final presentation_   
