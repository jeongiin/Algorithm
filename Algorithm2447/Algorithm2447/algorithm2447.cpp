#include<stdio.h>
#include<string.h>

// ��Ģ : 3^n �� ���ڰ� �ԷµǸ� 3^n*3^n ������ matrix�� ���������
//		  �� �� matrix�� ����� �Ϸ��� ��Ģ�� ������.

char mat[2188][2188] = { ' ', }; //3�� 7�� 2187

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