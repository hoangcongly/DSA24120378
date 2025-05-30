#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> convertMatrixToList(const string& filename)
{
    ifstream fIn(filename);
    if(!fIn)
    {
        cerr << "Don't open file" << endl;
        return {};
    }
    int n;
    fIn >> n;
    vector<vector<int>> adjmatrix(n, vector<int>(n));
    vector<vector<int>> list(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fIn>> adjmatrix[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(adjmatrix[i][j]!=0)
            {
                list[i].push_back(j);
            }
        }
    }
    fIn.close();
    return list;
}
vector<vector<int>> convertListToMatrix(const string&filename)
{
    ifstream fIn(filename);
    if(!fIn)
    {
        cerr << "Don't open file" << endl;
        return {};
    }
    int n;
    fIn>> n;
    fIn.ignore();
    vector<vector<int>> adjmatrix(n,vector<int>(n,0));
    for(int i=0; i<n;i++)
    {
        string line;
        getline(fIn, line);
        stringstream ss(line);
        int val;
        while(ss>>val)
        {//1 2 3 4
            adjmatrix[i][val]=1;
        }
    }
    fIn.close();
    return adjmatrix;
}

bool isDirected(const vector<vector<int>>&adjMatrix)
{
    for(int i=0; i<adjMatrix.size(); i++)
    {
        for(int j=0; j<adjMatrix[i].size(); j++)
        {
            if(adjMatrix[i][j]!=adjMatrix[j][i]) return true;
        }
    }
    return false;
}

int countVertices(const vector<vector<int>>& adjMatrix)
{
    return adjMatrix.size();
}

int countEdges(const vector<vector<int>>& adjMatrix)
{
    int count=0;
    bool derected= isDirected(adjMatrix);
    for(int i=0; i<adjMatrix.size(); i++)
    {
        for(int j=0; j<adjMatrix[i].size(); j++)
        {
            if(adjMatrix[i][j]!=0)
            {
                if(derected)
                count++;
                else if(j>i)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

vector<int> getIsolatedVertices(const vector<vector<int>>&adjmatrix)
{
    vector<int> isolated;
    for(int i=0; i<adjmatrix.size(); i++)
    {
        bool isIsolated= true;
        for(int j=0; j<adjmatrix[i].size(); j++)
        {
            if(adjmatrix[i][j]!=0|| adjmatrix[j][i]!=0)
            {
                isIsolated=false;
                break;
            }
        }
        if(isIsolated)
        {
            isolated.push_back(i);
        }
    }
    return isolated;
}

bool isCompleteGraph(const vector<vector<int>>&adjMatrix)
{
    int n= adjMatrix.size();
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j&& adjMatrix[i][j]==0) return false;
        }
    }
    return true;
}

bool isBipartite(const vector<vector<int>>&adjMatrix)
{
    int n = adjMatrix.size();
    vector<int> color(n, -1);
    for (int start = 0; start < n; ++start)
    {
        if (color[start] == -1)
        {
            color[start] = 0;
            queue<int> q;
            q.push(start);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 0; v < n; ++v)
                {
                    if (adjMatrix[u][v] == 1)
                    {
                        if (color[v] == -1)
                        {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        else if (color[v] == color[u])
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
bool isCompleteBipartite(const vector<vector<int>>& adjMatrix)
{
     if (!isBipartite(adjMatrix)) return false;
    int n = adjMatrix.size();
    vector<int> color(n, -1);
    vector<int> partition1;
    vector<int> partition2;
    for (int start = 0; start < n; ++start)
    {
        if (color[start] == -1)
        {
            color[start] = 0;
            queue<int> q;
            q.push(start);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 0; v < n; ++v)
                {
                    if (adjMatrix[u][v] == 1)
                    {
                        if (color[v] == -1)
                        {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                    }
                }
            }
        }
        if (color[start] == 0) partition1.push_back(start);
        else partition2.push_back(start);
    }
    for (int u : partition1)
    {
        for (int v : partition2)
        {
            if (adjMatrix[u][v] == 0) return false;
        }
    }
    return true;
}

vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>>& adjMatrix)
{
    int n= adjMatrix.size();
    vector<vector<int>> undirected(n, vector<int>(n,0));
    for(int i=0;i<n;++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(adjMatrix[i][j]==1|| adjMatrix[j][i]==1)
            {
                undirected[i][j]=1;
                undirected[j][i]=1;
            }
        }
    }
    return undirected;
}

vector<vector<int>> getComplementGraph(const vector<vector<int>>&adjMatrix)
{
    int n= adjMatrix.size();
    vector<vector<int>> complement(n,vector<int>(n,0));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(i!=j&& adjMatrix[i][j]==0)
            {
                complement[i][j]=1;
            }
        }
    }
    return complement;
}

vector<int> findEulerCycle(const vector<vector<int>>&adjMatrix)
{
    int n = adjMatrix.size();
    if (isDirected(adjMatrix)) return {}; 
    vector<vector<int>> graph = adjMatrix;
    stack<int> currpath;
    vector<int> circuit;
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        int degree = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] > 0) degree++;
        }
        if (degree % 2 != 0) return {}; 
        if (degree > 0)
        {
            start = i;
            break;
        }
    }
    if (start == -1) return {};
    currpath.push(start);
    int cur = start;
    while (!currpath.empty())
    {
        bool findEdge = false;
        for (int next = 0; next < n; next++)
        {
            if (graph[cur][next] > 0)
            {
                graph[cur][next]--;
                graph[next][cur]--;
                currpath.push(cur);
                cur = next;
                findEdge = true;
                break;
            }
        }
        if (!findEdge)
        {
            circuit.push_back(cur);
            cur = currpath.top();
            currpath.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}

void dfs(int u, const vector<vector<int>>&adjMatrix, vector<bool>&visited,vector<vector<int>>&tree)
{
    visited[u]=true;    
    for(int v=0; v<adjMatrix.size();++v)
    {
        if(adjMatrix[u][v]==1 && !visited[v])
        {
            tree[u][v]=1;
            tree[v][u]=1;
            dfs(v,adjMatrix,visited,tree);
        }
    }
}
vector<vector<int>> dfsSpanningTree(const vector<vector<int>>&adjMatrix, int start)
{
    int n= adjMatrix.size();
    vector<vector<int>> tree(n,vector<int>(n,0));
    vector<bool> visited(n,false);
    dfs(start,adjMatrix,visited,tree);
    return tree;
}

void bfs(int start, const vector<vector<int>>& adjMatrix, vector<bool>&visited, vector<vector<int>>&tree)
{
    queue<int>q;
    visited[start]= true;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout << u << " ";
        for(int v = 0; v < adjMatrix.size(); ++v)
        {
            if(adjMatrix[u][v]==1&& !visited[v])
            {
                visited[v]=true;
                q.push(v);
                tree[u][v]= 1;
                tree[v][u]=1 ;
            }
        }
    }
}

vector<vector<int>> bfsSpanningTree(const vector<vector<int>>&adjMatrix,int start)
{
    int n=adjMatrix.size();
    vector<vector<int>>tree(n,vector<int>(n,0));
    vector<bool> visited(n,false);
    bfs(start, adjMatrix,visited,tree);
    return tree;
}

bool isConnected(int u,int v, const vector<vector<int>>&adjMatrix)
{
    if(u<0|| u>= adjMatrix.size()||v<0|| v>=adjMatrix.size())
    {
        return false;
    }
    return adjMatrix[u][v]==1;
}

vector<int> dijkstra(int start, int end, const vector<vector<int>>& adjMatrix)
{
    int n=adjMatrix.size();
    vector<int>dist(n, INT_MAX);
    vector<int>prev(n,-1);
    vector<bool>visited(n, false);
    dist[start]=0;
    for(int i=0; i<n; i++)
    {
        int u=-1;
        int distMin= INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(!visited[j]&&dist[j]<distMin)
            {
                distMin= dist[j];
                u=j;
            }
        }
        if(u==-1|| u==end) break;
        visited[u]=true;
        for(int v=0; v<n; v++)
        {
            if(adjMatrix[u][v]>0&& !visited[v])
            {
                int alt= dist[u]+ adjMatrix[u][v];
                if(alt<dist[v])
                {
                    dist[v]= alt;
                    prev[v]= u;
                }
            }
        }
    }
    vector<int> path;
    if(dist[end]==INT_MAX) return path;
    for(int v=end; v!=-1; v=prev[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    return path;
}

vector<int> bellmanFord(int start, int end, const vector<vector<int>>& adjMatrix)
{
    int n=adjMatrix.size();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n,-1);
    dist[start]=0;
    for (int k = 0; k < n - 1; ++k) 
    {
        for (int u = 0; u < n; ++u) 
        {
            for (int v = 0; v < n; ++v) 
            {
                if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX) 
                {
                    int alt = dist[u] + adjMatrix[u][v];
                    if (alt < dist[v]) 
                    {
                        dist[v] = alt;
                        prev[v] = u;
                    }
                }
            }
        }
    }
    for (int u = 0; u < n; ++u) 
    {
        for (int v = 0; v < n; ++v) {
            if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) 
            {
                return {}; 
            }
        }
    }
    vector<int> path;
    if (dist[end] == INT_MAX) return path; 
    for (int v = end; v != -1; v = prev[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}
