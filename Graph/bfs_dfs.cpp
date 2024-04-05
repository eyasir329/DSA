#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited)
{
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int neighbor : adjList[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited)
{
    stack<int> stack;
    stack.push(startNode);
    visited[startNode] = true;

    while (!stack.empty())
    {
        int currentNode = stack.top();
        stack.pop();
        cout << currentNode << " ";

        for (int neighbor : adjList[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}

void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}

void printAdjList(const vector<vector<int>>& adjList) {
    int V = adjList.size();
    for (int i = 0; i < V; ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j];
            if (j != adjList[i].size() - 1)
                cout << " -> ";
        }
        cout << endl;
    }
}


int main()
{
    int vertices = 5;
    vector<vector<int>> adjList(vertices);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);

    printAdjList(adjList);

    vector<bool> visited(vertices, false);

    cout << "BFS" << endl;
    bfs(adjList, 0, visited);

    cout << "\nDFS" << endl;
    fill(visited.begin(), visited.end(), false);
    dfs(adjList, 0, visited);

    return 0;
}