
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
const int TOP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
int start = 0;
int arr[4][4];
void print();
void putkey(int direction);
void isDead();
void move(int pos,int direction);
int move_counter,move_counter2;
void sw(int pos,int direction);
void add(int pos, int direction);
int main()
{
	int key;
	putkey(DOWN);
	while (1)//主循环
	{
		move_counter2 = -1;
		key = _getch();/*用于去掉第一个字节*/
		system("CLS");
		if (key == 27) break; /*如果是ESC退出*/
		if (key>31 && key<127) /*如果不是特殊键*/
		{
			if (key == 119) { //按下W键
				putkey(TOP);

				continue;
			}
		if ( key == 115){   //按下S键
				putkey(DOWN);
				continue;
			}
		if ( key == 97){    //按下A键
				putkey(LEFT);

				continue;
			}
		if ( key == 100){   //按下D键
				putkey(RIGHT);
				
				continue;
			}
		}
		key = _getch();
		if (key == 72) putkey(TOP);
		if (key == 80) putkey(DOWN);
		if (key == 75) putkey(LEFT);
		if (key == 77) putkey(RIGHT);
	}
	return 0;
}
void putkey(int direction) {
	//合并数字
	int tmp;
	move_counter = 1;
	move_counter2 = 0;
	while (move_counter != 0) {
		if (move_counter != 0) move_counter2++;
		move_counter = 0;
		for (tmp = 0; tmp <= 15; tmp++) {
			move(tmp, direction);
		}
		
	}
	//判断当前是否死亡
	isDead();
	if (move_counter2 == 1 && start != 0) {
		print();
		return;
	}
//生成所添加的数字 
//当前出现2的几率为0.8 出现4的几率为0.2
	start = 1;
	int addnum = 0;
	if ((rand() % 10) <= 8) {addnum = 2;}else{addnum = 4;}
	int posi = 0;
	posi = rand() % 16;
	while (arr[posi / 4][posi % 4] != 0) {
		posi = rand() % 16;
	}
	arr[posi / 4][posi % 4] = addnum;
	print();
}
void print() {
	int i, j;
	char string[10];
	printf("=-=-=-=-=-=-=-=-=-=-=");
	for (i = 0; i <= 3; i++) {
		printf("\n|");
		for (j = 0; j <= 3; j++) {
			_itoa_s(arr[i][j], string, 10);
			printf("%4.4s|",string );
		}


	}
	printf("\n=-=-=-=-=-=-=-=-=-=-=");
}
void isDead() {
	int tmp, count = 0;
	for (tmp = 0; tmp <= 15; tmp++) if (arr[tmp / 4][tmp % 4] != 0) count++;
	if (count == 16) {
		print();
		printf("\n	game over!\n\nPress S to continue\n  Press ESC to exit");
		int key;
		while (1) {
			key = _getch();
			if (key == 115) {
				for (tmp = 0; tmp <= 15; tmp++) arr[tmp / 4][tmp % 4] = 0;
				start = 0;
				system("CLS");
				break;
			}
			if (key == 27) {
				exit(0);
			}

		}
	}
}
void move(int pos, int direction) {
	switch(direction) {
	case 1:
		if ((pos / 4) == 0) break;
		if ((arr[pos / 4][pos % 4] == 0 )) break;
		if (arr[pos / 4 - 1][pos % 4] == 0) {sw(pos, direction); move_counter++; break;}
		if (arr[pos / 4 - 1][pos % 4] == arr[pos / 4][pos % 4]) {add(pos, direction);move_counter++;
		}else {break;}


		break;
	case 2:
		if ((pos / 4 )== 3) break;
		if ((arr[pos / 4][pos % 4] == 0)) break;
		if (arr[pos / 4 + 1][pos % 4] == 0) { sw(pos, direction); move_counter++; break; }
		if (arr[pos / 4 + 1][pos % 4] == arr[pos / 4][pos % 4]) {
			add(pos, direction); move_counter++;
		}
		else { break; }
		break;
	case 3:
		if ((pos % 4) == 0) break;
		if ((arr[pos / 4][pos % 4] == 0)) break;
		if (arr[pos / 4][pos % 4 - 1] == 0) { sw(pos, direction); move_counter++; break; }
		if (arr[pos / 4 ][pos % 4 - 1] == arr[pos / 4][pos % 4]) {
			add(pos, direction); move_counter++;
		}
		else { break; }
		break;
	case 4:
		if ((pos % 4) == 3) break;
		if ((arr[pos / 4][pos % 4] == 0)) break;
		if (arr[pos / 4][pos % 4 + 1] == 0) { sw(pos, direction); move_counter++; break; }
		if (arr[pos / 4][pos % 4 + 1] == arr[pos / 4][pos % 4]) {
			add(pos, direction); move_counter++;
		}
		else { break; }
		break;
	}
}
void sw(int pos,int direction) {
	switch (direction) {
		case 1:
			arr[pos / 4 - 1][pos % 4] = arr[pos / 4][pos % 4];
			arr[pos / 4][pos % 4] = 0;
			break;
		case 2:
			arr[pos / 4 + 1][pos % 4] = arr[pos / 4][pos % 4];
			arr[pos / 4][pos % 4] = 0;
			break;
		case 3:
			arr[pos / 4 ][pos % 4 -1] = arr[pos / 4][pos % 4];
			arr[pos / 4][pos % 4] = 0;
			break;
		case 4:
			arr[pos / 4 ][pos % 4 + 1] = arr[pos / 4][pos % 4];
			arr[pos / 4][pos % 4] = 0;
			break;
	}
}
void add(int pos, int direction) {

	switch (direction) {
	case 1:
		arr[pos / 4 - 1][pos % 4] *= 2;

		arr[pos / 4][pos % 4] = 0;
		break;
	case 2:
		arr[pos / 4 + 1][pos % 4] *= 2;

		arr[pos / 4][pos % 4] = 0;
		break;
	case 3:
		arr[pos / 4][pos % 4 - 1] *= 2;

		arr[pos / 4][pos % 4] = 0;
		break;
	case 4:
		arr[pos / 4][pos % 4 + 1] *= 2;

		arr[pos / 4][pos % 4] = 0;
		break;
	}
	if (arr[pos / 4 - 1][pos % 4] == 2048) arr[pos / 4 - 1][pos % 4] = 0;
}