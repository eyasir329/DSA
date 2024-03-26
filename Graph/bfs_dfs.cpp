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

int main()
{
    int vertices = 5;
    vector<vector<int>> adjList(vertices);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    vector<bool> visited(vertices, false);

    cout << "BFS" << endl;
    bfs(adjList, 0, visited);

    cout << "\nDFS" << endl;
    fill(visited.begin(), visited.end(), false);
    dfs(adjList, 0, visited);

    return 0;
}