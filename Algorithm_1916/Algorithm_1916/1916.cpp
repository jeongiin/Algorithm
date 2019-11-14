#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int CITYMAX = 1000 + 1;
const int BUSMAX = 1000000 + 1;
const int INF = 987654321;

int n, m;
int src, des;
vector<pair<int, int>> graph[CITYMAX];

// 다익스트라 알고리즘을 통해 구해야 하는 문제
// 자기 자신부터 더 낮은 가중치를 더해가며 찾아야 한다

vector <int> dijkstra(int start, int vertex)
{
	vector <int> distance(vertex, INF);// start를 기준으로 거리
	distance[start] = 0;

	priority_queue<pair<int, int>> pq; //Cost, Vertex
	pq.push(make_pair(0, start)); // 초기 비용과 시작점

	while (!pq.empty())
	{
		int cost = -pq.top().first; //거리의 부호를 바꿔 거리가 작은 버스부터
		//pq는 priority queue 이므로 가장 큰 수가 top에 있음 -> 부호를 바꿔줘야 오름차순 정렬됨

		int curVertex = pq.top().second; //vertex
		pq.pop();

		//최소거리 찾기
		if (distance[curVertex] < cost)
			continue;

		//이웃 모두 확인
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			int near = graph[curVertex][i].first;
			int nearDistance = cost + graph[curVertex][i].second;

			//최소 경로 발견시 업데이트
			if (distance[near] > nearDistance)
			{
				distance[near] = nearDistance;
				//거리의 부호를 바꿔 거리가 작은 버스부터
				pq.push(make_pair(-nearDistance, near));

			}
		}
	}

	return distance;


}


int main(void)
{
	
	scanf_s("%d %d", &n, &m);
	n++; //정점번호 1부터 시작
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		scanf_s("%d %d %d", &start, &end, &cost);
		graph[start].push_back(make_pair(end, cost));
	}

	scanf_s("%d %d", &src, &des);

	vector<int> result = dijkstra(src, n);

	printf("%d\n", result[des]);

	return 0;

}