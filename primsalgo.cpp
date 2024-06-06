#include <iostream>
using namespace std;

int findminvertex(int *weight, bool *visited, int n)
{
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minvertex = -1 || weight[i] < weight[minvertex]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}

void prims(int **Edge, int n)
{
    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int minvertex = findminvertex(weight, visited, n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (Edge[minvertex][j] != 0 && !visited[j])
            {
                if (Edge[minvertex][j] < weight[j])
                {
                    weight[j] = Edge[minvertex][j];
                    parent[j] = minvertex;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
            cout << weight[i] << " " << i << " " << parent[i] << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **Edge = new int *[n];
    for (int i = 0; i < n; i++)
    {
        Edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            Edge[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        Edge[f][s] = weight;
        Edge[s][f] = weight;
    }
    cout << endl;
    prims(Edge, n);
    for (int i = 0; i < n; i++)
    {
        delete[] Edge[i];
    }
    delete[] Edge;
}