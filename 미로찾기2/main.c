#include <stdio.h>
#include <stdlib.h>

int x = 0, y = 0;
int xx = 8, yy = 8;
int di = 1;
int dd = 0;  //그냥 0으로 초기화
// 1 진행방향이 북쪽
// 2 진행방향이 서쪽
// 3 진행방향이 동쪽
// 4 진행방향이 서쪽

int main(void)
{

	char m[9][9] =
	{ {'S', 'x', 'x', 'o', 'x', 'x', 'x', 'o', 'x'},
	{'o', 'o', 'o', 'o', 'x', 'o', 'o', 'o', 'x'},
	{'x', 'o', 'x', 'o', 'o', 'o', 'x', 'o', 'x'},
	{'o', 'o', 'o', 'o', 'x', 'o', 'o', 'o', 'o'},
	{'x', 'x', 'x', 'x', 'o', 'o', 'x', 'x', 'x'},
	{'o', 'o', 'o', 'o', 'o', 'x', 'x', 'o', 'o'},
	{'o', 'x', 'o', 'x', 'o', 'o', 'x', 'o', 'x'},
	{'o', 'o', 'o', 'x', 'x', 'o', 'o', 'o', 'x'},
	{'o', 'x', 'o', 'x', 'x', 'x', 'x', 'o', 'F'} };


	for (int i = 8; i >= 0; i--)
	{
		printf("%c %c %c %c %c %c %c %c %c\n", m[i][0], m[i][1], m[i][2], m[i][3], m[i][4], m[i][5], m[i][6], m[i][7], m[i][8]);
	}

	int dr;
	printf("미로찾기 프로그램을 시작합니다. \n");
	printf("이동위치를 입력하세요 상대 또는 절대적으로 내 위치에서 이동합니다. \n");
	printf("절대위치 방향으로 진행시 0 \n");
	printf("상대위치 방향으로 진행시 1 (예 : 0) \n");
	scanf("%d", &dd);  // 입력받는 값 dd

	while (1)   //반복문
	{
		printf("이동위치를 입력하세요 ( 직진: 1  왼쪽: 2  오른쪽: 3  후진: 4  종료: 5 ) ==>  \n");
		scanf("%d", &dr);
		system("cls");  //미로를 계속 띄어 놓을 순 없을까?
		printf("키입력전 현재의 위치는 { %d, %d } 이고 현위치의 값은 %c \n", x, y, m[x][y]);
		//보기 좋게 위치를 { }로 묶었다

		if (dr == 5) break;   //바로 종료입니다

		/************************************/
		if (dd)   //입력 받는 값
		{
			switch (di) // 조건 di의 값 (상대위치)
			{
			case 1: // di가 1이면
				printf("이전 직진중입니다 \n");
				switch (dr) // 조건 dr의 값
				{
				case 1:
					printf("진행방향에서 전진 \n");
					break;
				case 2:
					printf("진행방향에서 좌회전 \n");
					break;
				case 3:
					printf("진행방향에서 우회전 \n");
					break;
				case 4:
					printf("진행방향에서 후진 \n");
					break;
				default:  //그외에는
					break;
				}
				break;

			case 2: 
				printf("이전 좌회전 중입니다 \n");
				switch (dr)
				{
				case 1:
					printf("진행방향에서 전진 \n");
					dr = 2;
					break;
				case 2:
					printf("진행방향에서 좌회전 \n");
					dr = 4;
					break;
				case 3:
					printf("진행방향에서 우회전 \n");
					dr = 1;
					break;
				case 4:
					printf("진행방향에서 후진 \n");
					dr = 3;
					break;
				default:
					break;
				}
				break;
			case 3:
				printf("이전 우회전 중입니다 \n");
				switch (dr)
				{
				case 1:
					printf("진행방향에서 전진 \n");
					dr = 3;
					break;
				case 2:
					printf("진행방향에서 좌회전 \n");
					dr = 1;
					break;
				case 3:
					printf("진행방향에서 우회전 \n");
					dr = 4;
					break;
				case 4:
					printf("진행방향에서 후진 \n");
					dr = 2;
					break;
				default:
					break;
				}
				break;
			case 4:
				printf("이전 뒤로 이동중입니다 \n");
				switch (dr)
				{
				case 1:
					printf("진행방향에서 전진 \n");
					dr = 4;
					break;
				case 2:
					printf("진행방향에서 좌회전 \n");
					dr = 3;
					break;
				case 3:
					printf("진행방향에서 우회전 \n");
					dr = 2;
					break;
				case 4:
					printf("진행방향에서 후진 \n");
					dr = 1;
					break;
				default:
					break;
				}
				break;
			default:
				printf("1~ 4 번위에서 눌러주세요 \n");
				break;
			}
			di = dr;
		}


		switch (dr)  //절대적 위치...
		{
			char mm;
		case 1:

			if (y == yy) {
				printf("최상단입니다 올라갈곳이 없습니다\n"); break;
			}
			printf("고정 위쪽 \n");
			mm = m[y + 1][x];
			switch (mm)
			{
			case 'o':
				y++;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				y++;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				return 0;
			default:
				break;
			}
			break;
		case 2:
			printf("고정 왼쪽 \n");
			if (x == 0) { printf("현재 위치가 가장 왼쪽에 있습니다. \n");  break; }
			mm = m[y][x - 1];

			switch (mm)
			{
			case 'o':
				x--;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				x--;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				return 0;
			default:
				break;
			}
			break;
		case 3:
			printf("고정 오른쪽 \n");
			if (x == xx) { printf("현재 위치가 가장 오른쪽에 있습니다. \n");  break; }

			mm = m[y][x + 1];
			switch (mm)
			{
			case 'o':
				x++;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				x++;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				return 0;
			default:
				break;
			}
			break;


		case 4:
			printf("고정 후진 \n");
			if (y == 0) { printf("현재 위치가 가장 바닥에 있습니다. \n");  break; }

			mm = m[y - 1][x];
			switch (mm)
			{
			case 'o':
				y--;
				break;
			case 'x':
				printf("************ 막혀서 움직일수 없습니다. ************\n");
				break;
			case 'S':
				y--;
				printf("출발점에 위치 하였습니다 \n");
				break;
			case 'F':
				printf("결승점에 꼴인 하였습니다 \n");
				return 0;
			default:
				break;
			}
		default:
			break;
		}
		printf("키입력후 현재의 위치는 { %d, %d } 이고 현위치의 값은 %c \n", x, y, m[x][y]);
		//보기 좋게 위치를 { }로 묶었다
}
	return 0;
}