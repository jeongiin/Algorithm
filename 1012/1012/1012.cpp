#include<iostream>


using namespace std;


int N, M, K;
int dir[4][2] = { {-1,0} ,{1,0},{0,1},{0,-1} };
int maze[51][51];
int visited[51][51];

void dfs(int y, int x) {


	int nx, ny;
	
		//상하좌우 검사
		for (int i = 0; i < 4; i++) {
			ny = y + dir[i][0]; //dir에 있던 x,y좌표 값이 담기며 좌우상하 순서로 검사됨
			nx = x + dir[i][1];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && maze[ny][nx] == 1 && visited[ny][nx]==0)
			{
				visited[ny][nx]++;
				dfs(ny, nx);
			}
		}


}



int main(void) {

	int T;
	scanf_s("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf_s("%d %d %d", &M, &N, &K); // 10 8 17
		memset(maze, 0, sizeof(maze));
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < K; j++) {
			int x, y;
			scanf_s("%d %d", &x, &y);
			maze[y][x] = 1;
		}

		int ans = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (maze[j][k] == 1 && visited[j][k] == 0) {
					ans++;
					visited[j][k]++;
					dfs(j, k);
				}
			}
		}

		printf("%d", ans);

	}




	return 0;
}