#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int SIZE = 20010;
const int STD = 10003;
struct Edge{
    int v, cap, rev;
    Edge(int _v, int _cap, int _rev) : v(_v), cap(_cap), rev(_rev){
    }
};
vector<vector<Edge>> vt;
void addEdge(int s, int e, int c){
    vt[s].push_back({e, c, (int)vt[e].size()});
    vt[e].push_back({s,c,(int)vt[s].size()-1});
}
int source = 20001, sink = 20002;
int map[100][100];
int cur = 0;

int N;


int ty[4] = {1,1,1,1};
int tx[4] = {1,1,-1,-1};

int mapping(int y, int x){
    return y*N + x;
}

bool isblock(int y, int x){
    return map[y][x] == 1;
}    

bool check(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < N;
}
int level[SIZE];
int work[SIZE];
bool bfs(){
    fill(level, level+SIZE, -1);
    queue<int> q;
    q.push(source);
    level[source] = 0;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto i : vt[here]){
            int next = i.v;
            int cap = i.cap;

            if(cap > 0 && level[next] == -1){
                level[next] = level[here]+1;
                q.push(next);
            }
        }
    }

    return level[sink] != -1;
}

int dfs(int here, int crtcap){
    if(here == sink)return crtcap;
    for(int &i = work[here]; i < vt[here].size(); i++){
        int there = vt[here][i].v;
        int cap = vt[here][i].cap;

        if(level[here] + 1 == level[there] && cap > 0){
            int c = dfs(there,min(crtcap, cap));
            if(c > 0){
                vt[here][i].cap -=c;
                vt[there][vt[here][i].rev].cap +=c;
                return c;
            }
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(0);
    cin >> N;
    int t; cin >> t;
    vt.resize(SIZE);
    int sy[4] = {N-1,0,1,0};
    int sx[4] = {0,1,N-1,0};
    int my[4] = {-1,0,1,0};
    int mx[4] = {0,1,0,1};
    
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 1;
    }
    bool flag = false;
    int cnt = 0;
    
    for(int i = 0; i < 4; i++){
        int startx = sx[i];
        int starty = sy[i];

        while(check(starty,startx)){
            int move_y = starty;
            int move_x = startx;
            flag = false;
            while(check(move_y,move_x)){
                if(flag == false && map[move_y][move_x] == 0){flag = true; cnt++;}
                else if(flag == true && map[move_y][move_x] == 1){flag = false;}
                if(map[move_y][move_x] == 0){
                    if(i < 2)addEdge(source, mapping(move_y,move_x), 2
                    );
                    addEdge(mapping(move_y, move_x), STD+cnt, 1);
                    }
                move_y+=ty[i];
                move_x+=tx[i];
            }
           
            starty+=my[i];
            startx+=mx[i];

        }
    }
    
    for(int i = 1; i <= cnt; i++){
        addEdge(STD+i, sink, 1);
    }
    
    for(int i = 0; i < SIZE; i++){
        if(vt[i].size() > 0){
            cout << i << " : ";
            for(int j = 0; j < vt[i].size(); j++){
                cout << vt[i][j].v << " ";
            }
            cout << '\n';
        }
    }
   int ans = 0;
   
    while(bfs()){
        fill(work, work+SIZE, 0);
        while(1){
            int f = dfs(source, 987654321);
            if(f == 0)break;
        }
    }
    for(int i = 0; i < vt[source].size(); i++){
        if(vt[source][i].cap == 2)ans++;
    }
    cout << ans;

}