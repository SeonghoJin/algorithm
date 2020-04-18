/*
첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000) 둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데, a번 정점에서 b번 정점까지 양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1,000) 다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호가 주어진다.

출력
첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.
*/
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using point = pair<int, int>;
vector<vector<point>> adj(801, vector<point>());

int N, E,tx,ty;
int INF = 987654321;
vector<int> ret(801,INF);
	
void dijkstra(int start){
	
	for(int i = 1; i <=N; i++){
		ret[i]=INF;
	}
	
	priority_queue<point> pq;
	ret[start] = 0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		int weight = -pq.top().first;
		int num = pq.top().second;
		pq.pop();
		if(weight > ret[num]) continue;
		
		for(int i = 0; i < adj[num].size(); i++){
			int next = adj[num][i].second;
			int nextweight = adj[num][i].first + weight;
			
			if(nextweight < ret[next]){
				ret[next] = nextweight;
				pq.push(make_pair(-nextweight,next));
				
			}
		}
		
	}
	
	
}

int main(){
	cin.tie(0);
	ios_base :: sync_with_stdio(0);
	cin >> N >> E;
	
	for(int i = 0; i < E; i++){
		int a, b ,c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));
	}
	
	cin >> tx >> ty;
	
	dijkstra(1);
	long long ans = INF;
	long long ans1 = INF;
	
	int sx = ret[tx];
	int sy = ret[ty];
	dijkstra(tx);
	int xy = ret[ty];
	int xn = ret[N];
	dijkstra(ty);
	int yx = ret[tx];
	int yn = ret[N];
	
		ans = sx;
		ans += xy;
		ans += yn;

		ans1 = sy;
		ans1 += yx;
		ans1 += xn;
	
	ans = min(ans,ans1);
	if(ans < INF)cout << ans;
	else cout << -1 ;
	
	
}
*/
/*
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cctype>
using namespace std;
typedef pair<int, int> pii;

// https://github.com/csehydrogen/algorithm/blob/master/fast_io.cc
class FastIO {
    int fd, bufsz;
    char *buf, *cur, *end;
public:
    FastIO(int _fd = 0, int _bufsz = 1 << 20) : fd(_fd), bufsz(_bufsz) {
        buf = cur = end = new char[bufsz];
    }
    ~FastIO() {
        delete[] buf;
    }
    bool readbuf() {
        cur = buf;
        end = buf + bufsz;
        while (true) {
            size_t res = fread(cur, sizeof(char), end - cur, stdin);
            if (res == 0) break;
            cur += res;
        }
        end = cur;
        cur = buf;
        return buf != end;
    }
    int readint() {
        while (true) {
            if (cur == end) readbuf();
            if (isdigit(*cur) || *cur == '-') break;
            ++cur;
        }
        bool sign = true;
        if (*cur == '-') {
            sign = false;
            ++cur;
        }
        int ret = 0;
        while (true) {
            if (cur == end && !readbuf()) break;
            if (!isdigit(*cur)) break;
            ret = ret * 10 + (*cur - '0');
            ++cur;
        }
        return sign ? ret : -ret;
    }
};

FastIO fio;
const int INF = 715824321;
int n, e, s, t;
vector<vector<pii>> graph;

void dijkstra(int st, vector<int> &d)
{
    priority_queue<pii> pq;
    d[st] = 0; pq.push({0, st});
    while (!pq.empty()) {
        auto r = pq.top(); pq.pop();
        int here = r.second, dist = -r.first;
        if (d[here] < dist) continue;
        for (auto &iter : graph[here]) {
            int there = iter.first, newDist = dist + iter.second;
            if (newDist < d[there]) {
                d[there] = newDist;
                pq.push({-newDist, there});
            }
        }
    }
}

int main()
{
    n = fio.readint(); e = fio.readint();
    graph.resize(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        u = fio.readint(); v = fio.readint(); w = fio.readint();
        --u, --v;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    s = fio.readint(); t = fio.readint();
    --s, --t;

    vector<int> d0(n, INF), ds(n, INF), dt(n, INF);
    dijkstra(0, d0); dijkstra(s, ds); dijkstra(t, dt);

    int d1 = d0[s] + ds[t] + dt[n - 1], d2 = d0[t] + dt[s] + ds[n - 1];
    int ans = min(d1, d2);
    if (ans >= INF) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}

*/
