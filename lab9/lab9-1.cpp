//66070503448 Phattharapong Duangkham
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int> > adjlist(n);
    map<int ,bool> visit;
    map<int ,bool> visit2;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        visit[a] = false;
        visit[b] = false;
        visit2[a] = false;
        visit2[b] = false;
    }

    int start;
    cin >> start;
    stack<int> s;
    queue<int> q;
//----------------DFS---------------
    visit2[start] = true;
    s.push(start);
    cout << start << " ";
    while (!s.empty()) {
        int node = s.top();
        int i=0;
        while(true) {
            if(!visit2[adjlist[node][i]]) {
                visit2[adjlist[node][i]] = true;
                node = adjlist[node][i];
                s.push(node);
                cout << node << " ";
                i=0;
            }
            else i++;
            if(i>=adjlist[node].size()) break;
        }
        s.pop();
    }
    cout << endl;
//--------------------BFS--------------------------------
    for (int i = 0; i < adjlist.size(); i++) {
        if(start == i) {
            visit[i] = true;
            q.push(i);
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                cout << node << " ";
                for (int j = 0; j < adjlist[node].size(); j++) {
                    if(visit[adjlist[node][j]] == false) {
                        q.push(adjlist[node][j]);
                        visit[adjlist[node][j]] = true;
                    }
                }
            }
        }
    }  
    cout << endl;
    return 0;
}
