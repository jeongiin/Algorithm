#include<iostream>
#include<queue>


using namespace std;


// (0,0) ���� (N-1,M-1) ���� �����ϴ� �̷�
// ���� ��ġ���� ���� �湮 ������ ��ġ�� �̵���
// �̵� �� �־��� ���� �ش� ��ġ���� �̵��ϴ� �� �ʿ��� �ּ�ĭ ���� �ٲ�
// ( �ٽ� �湮���� �ʱ� ���� )


int N, M;
int dir[4][2] = { {-1,0} ,{1,0},{0,1},{0,-1} };
int maze[101][101];
queue <pair<int, int>> que;

void bfs() {

	que.push(make_pair(0, 0));
	pair <int, int> current;
	int nx, ny;
	while (!que.empty()) { //���� ��ǥ�� current�� ��⵵�� ��
		current = que.front();
		que.pop();
		//�����¿� �˻�
		for (int i = 0; i < 4; i++) {
			nx = current.second + dir[i][0]; //dir�� �ִ� x,y��ǥ ���� ���� �¿���� ������ �˻��
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