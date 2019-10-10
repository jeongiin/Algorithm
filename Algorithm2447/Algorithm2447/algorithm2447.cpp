#include<stdio.h>
#include<string.h>

// 규칙 : 3^n 인 숫자가 입력되면 3^n*3^n 형태의 matrix가 만들어진다
//		  이 때 matrix의 모양은 일련의 규칙을 가진다.

char mat[2188][2188] = { ' ', }; //3의 7승 2187

void printStar(int y, int x, int n){

	if (n == 1)
	{
		mat[y][x] = '*';
		return;
	}

	int quot = n / 3;

	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			if (i != 1 || j != 1)
				printStar(y + (i * quot), x + (j * quot), quot);
		}
	}

}



int main(void) {
	
	int n;
	scanf_s("%d", &n);

	printStar(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", mat[i][j]);
		printf("\n");
	}

	return 0;
}