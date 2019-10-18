#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int MAX = 100+1;

int m, n, p1, p2;
int r1 = 0; //relationship
int r2 = 0;

vector<int> vec[MAX];//vector의 배열
queue <int> q;
vector<int> visited(101,0); //visited에 값을 저장하고 이용해야 하므로 vector로 처리함 (vector란 메모리가 자동으로 할당되는 배열) - 0으로 찬 공간 101개 할당


int main(void)
{
	//n:정점의 갯수 m: 간선의 갯수
	scanf_s("%d", &n);
	scanf_s("%d %d", &p1, &p2);
	scanf_s("%d", &m);

	for (int i = 0; i < m; i++) {

		int node1, node2;
		scanf_s("%d %d", &node1, &node2);

		vec[node1].push_back(node2);//양방향 연결 -> 어느 방향으로 찾아도 관계를 명시할 수 있음
		vec[node2].push_back(node1);

	}

	q.push(p1);

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		if (p == p2) { //p2까지 관계를 모두 찾았을 때
			break;
		}

		for (int i = 0;  i < vec[p].size(); i++) { //bfs사용
			if (!visited[vec[p][i]]) {
				visited[vec[p][i]] = visited[p] + 1;
				q.push(vec[p][i]);
			}
		}
	}

	if (visited[p2] != 0)
		printf("%d", visited[p2]);
	else
		printf("-1");

	return 0;
}