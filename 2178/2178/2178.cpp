#include<iostream>
#include<queue>


using namespace std;


// (0,0) 부터 (N-1,M-1) 까지 도달하는 미로
// 현재 위치에서 다음 방문 가능한 위치로 이동시
// 이동 전 있었던 값을 해당 위치까지 이동하는 데 필요한 최소칸 수로 바꿈
// ( 다시 방문하지 않기 위함 )


int N, M;
int dir[4][2] = { {-1,0} ,{1,0},{0,1},{0,-1} };
int maze[101][101];
queue <pair<int, int>> que;

void bfs() {

	que.push(make_pair(0, 0));
	pair <int, int> current;
	int nx, ny;
	while (!que.empty()) { //현재 좌표가 current에 담기도록 함
		current = que.front();
		que.pop();
		//상하좌우 검사
		for (int i = 0; i < 4; i++) {
			nx = current.second + dir[i][0]; //dir에 있던 x,y좌표 값이 담기며 좌우상하 순서로 검사됨
			ny = current.first + dir[i][1];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && maze[ny][nx] == 1)
			{
				que.push(make_pair(ny, nx));
				maze[ny][nx] = maze[current.first][current.second] + 1;
			}
		}


	}


}

int main(void) {


	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &maze[i][j]);
		}
	}

	bfs();
	printf("%d", maze[N - 1][M - 1]);




	return 0;
}