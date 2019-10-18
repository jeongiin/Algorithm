#include <iostream>
using namespace std;


const int MAX = 100 + 1;

int n,m;
int map[MAX][MAX];

int DFS(int x, int y) {

	if (map[x][y] == 0)
		return map[x][y];

	int cnt = 1, nx,ny;
	map[x][y] = 0;
	int mx[] = { -1,0,1,0 };
	int my[] = { 0,1,0,-1 };

	for (int i = 0; i < 4; i++) {
		//동서남북으로 방문
		nx = x + mx[i];
		ny = y + my[i];

		if (0 <= nx && nx < n + 1 && 0 <= ny && ny < m + 1) {
			if (map[nx][ny] != 0) {
				cnt += DFS(nx, ny);

			}
		}
	}

}


int main(void)
{
	int k; 
	scanf_s("%d %d %d", &n, &m, &k);

	while(k--) {

		int x, y;
		scanf_s("%d %d", &x, &y);
		map[x][y] = 1;

	}

	int max = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (map[i][j] == 1) {
				int cnt = DFS(i, j);
				if (max < cnt)
					max = cnt;
			}
		}
	}

	printf("%d", max);


	return 0;
}