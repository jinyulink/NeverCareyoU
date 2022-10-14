#define INF 0x3FFFFFFF
typedef pair<int,int>PII;
const int MAXN = 100010;
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].push_back(make_pair(v,d));
}
void init(int n){
    for(int i=0;i<n;i++)
        G[i].clear();
}
int vis[MAXN];
int dis[MAXN]; 
void dijkstra(int s,int n){
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push(make_pair(dis[s],s));
    while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(!vis[y]&&dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                q.push(make_pair(dis[y],y));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(ll i=0,a,b,w;i<m;i++)
        cin>>a>>b>>w;add(a,b,w);
    dijkstra(1,n);
    for(ll i=1;i<=n;i++)    cout<<dis[i]<<" ";
    return 0;
}