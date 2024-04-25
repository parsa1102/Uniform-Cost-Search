#include <bits/stdc++.h>
using namespace std;
static auto const INF = 2147483647;


int ucs(const vector<pair<int/*adjacent node*/, int/*weight*/>>* v  , int count, int start, int destination){
    int ans = INF;
    bool visited[count];
    memset(visited, 0, sizeof(visited));
    std::priority_queue<pair<int/*dist*/, int/*node num*/>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> mpq;
    mpq.push({0, start});
    while(mpq.size() > 0){
        auto const top = mpq.top();
        mpq.pop();// we want to remove it before we lose it as the top periority element since we are about to add new nodes to the queue
        // on a side note considering the always strictly positive weight on our edges it can be proven that this never happens and this is only an extra safety precaustion
        visited[top.second] = true;
        for(auto const & i : v[top.second]){
            auto const & node = i.first;
            auto const & weight = i.second;
            if(node != destination){
                mpq.push({weight + top.first, node});
            }
            else{
                ans = min(ans, weight + top.first);
                continue;
            }
        }
    }
    return ans;
}


vector<pair<int, int>> adj[100];

int main(){
    int n, m;
    cin>>n >> m;
    int start, dest;
    cin>>start >> dest;
    for(int i = 1;i<=m;i++){
        int v,u,w;
        cin>>v>>u >>w;
        adj[v].push_back({u, w});
    }
    cout<<ucs(adj, n, start, dest) << '\n';
    return 1;
}
