#include <bits/stdc++.h>
using namespace std;

int turns;
void route(vector<int>& start_N, int N, int end_N)
{
	if (N == 0) {
		return;
	}

	route(start_N, start_N[N], end_N);

	cout << N << (N == end_N ? "\n" : "  ");
}

int dijkstra(vector<vector<pair<int, int> > >& Graph,
						int strt_N, int target)
{
	vector<int> widest(Graph.size(), INT_MIN);

	vector<int> parent(Graph.size(), 0);

	priority_queue<pair<int, int>, vector<pair<int, int> >,
				greater<pair<int, int> > >
		container;

	container.push(make_pair(0, strt_N));

	widest[strt_N] = INT_MAX;

	while (container.empty() == false) {
		pair<int, int> temp = container.top();

		int current_N = temp.second;

		container.pop();

		for (auto N : Graph[current_N]) {

			int P = max(widest[N.second],
							min(widest[current_N], N.first));

			if (P > widest[N.second]) {

				widest[N.second] = P;

				parent[N.second] = current_N;

				container.push(make_pair(P, N.second));
			}
		}
	}

	route(parent, target, target);

	turns = widest[target];
}

int main()
{
    
    int student;
    cout << "Enter the number of foreign students:";
    cin >> student;
    
    int AIESEC;
    cout << "Enter the number of AIESEC students:";
    cin >> AIESEC;

	vector<vector<pair<int, int> > > graph;
    
    
	int no_N;
	int no_stu;
	
	cin >> no_N >> no_stu;

	graph.assign(no_N + 1, vector<pair<int, int> >());
	
	int i = no_stu;
	while(i > 0){
	    int j,k,l;
	    cin >> j >> k >> l;
	    graph[j].push_back(make_pair(l,k));
	    i--;
	}
	int parent, destination;
	cin >> parent >> destination;
    dijkstra(graph, parent, destination);
	cout << (student / (turns - AIESEC));

	return 0;
}