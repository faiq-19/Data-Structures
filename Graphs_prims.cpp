#include <iostream>
#include <list>
#include <queue>
using namespace std;

int stack[50][2];
int next_iter = -1;

int min_arr[50];
int min_iter = -1;

void push_min(int x)
{
    min_iter++;

    min_arr[min_iter];
}

void push(int x, int y)
{
    next_iter++;

    stack[next_iter][0] = x;
    stack[next_iter][1] = y;
}

class GraphNode
{
public:
    int W;
    int V;
    GraphNode *next;

    GraphNode()
    {
        next = NULL;
        W = 0;
        V = 0;
    }
    GraphNode(int weight, int V)
    {
        this->W = weight;
        this->V = V;
        next = NULL;
    }
};

class GraphList
{
public:
    GraphNode *head;

    GraphList()
    {
        head = NULL;
    }
    void addEdge(int data, int V)
    {
        if (head == NULL)
        {
            head = new GraphNode(data, V);
            return;
        }

        GraphNode *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new GraphNode(data, V);

        return;
    }
};

class Graph
{
public:
    int Vertices;
    bool *visited;
    GraphList *l;

    Graph(int vertices)
    {
        this->Vertices = vertices;
        l = new GraphList[vertices];
        visited = new bool[Vertices];
    }
    void addEdge(int x, int y, int weight)
    {
        l[x].addEdge(weight, y);
    }
    void DFS(int v)
    {
        GraphNode *temp;

        visited[v] = true;

        cout << v << "->";

        temp = l[v].head;

        while (temp != NULL)
        {
            if (!visited[temp->V])
            {
                DFS(temp->V);
            }
            temp = temp->next;
        }
    }
    bool isCycle(int start)
    {
        queue <int> queue;
        bool *visited = new bool [Vertices];
        GraphNode *temp = l[start].head;

        for(int i = 0; i < Vertices; i++)
        {
            visited[i] = false;
        }

        visited[start] = true;
        queue.push(start);

        while(!queue.empty())
        {
            int v = queue.front();
            queue.pop();

            while(temp != NULL)
            {
                if(!visited[temp->V])
                {
                    visited[temp->V] = true;
                }
                else
                {
                    cout << "Cylcle Detected";
                    return true;
                }
            }
        }
        return false;
    }
    void BFS(int start)
    {
        queue<int> queue;
        bool *visited = new bool[Vertices];
        GraphNode *temp;

        for (int i = 0; i < Vertices; i++)
        {
            visited[i] = false;
        }

        visited[start] = true;
        queue.push(start);

        while (!queue.empty())
        {
            int v = queue.front();
            queue.pop();

            cout << v << "->";

            temp = l[v].head;

            while (temp != NULL)
            {
                if (!visited[temp->V])
                {
                    visited[temp->V] = true;
                    queue.push(temp->V);
                }
                temp = temp->next;
            }
        }
    }
    void display()
    {
        GraphNode *temp;

        for (int i = 0; i < Vertices; i++)
        {
            temp = l[i].head;

            cout << "Vertices:" << i << "->";

            while (temp != NULL)
            {
                cout << temp->V << "(" << temp->W << ")" << ", ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

void topologicalSort(Graph unsorted)
{
    
}

void kruksalAlgorithm(Graph unsorted)
{

}

void DijikstraAlgorithm(Graph unsorted)
{

}

void primsAlgorithm(Graph unsorted)
{
    int min = 0, v = 1;
    int **nodes;

    Graph sorted(unsorted.Vertices);
    GraphNode *temp;

    for (int i = 0; i < sorted.Vertices; i++)
    {
        temp = unsorted.l[i].head;

        while (temp != NULL)
        {
            push(temp->W, temp->V);
            temp = temp->next;
        }
        for (int j = 0; j <= next_iter; j++)
        {
            if (min > stack[j][0])
            {
                for (int k = 0; k <= min_iter; k++)
                {
                    if (min == min_arr[k])
                    {
                        continue;
                    }
                    else
                    {
                        min = stack[j][0];
                        v = stack[j][1];
                    }
                }
            }
        }
        next_iter = -1;

        sorted.addEdge(i, v, min);

        push_min(min);

        min = 999999;
    }

    sorted.display();
}

int main()
{
    Graph G(6);

    G.addEdge(0, 1, 10);
    G.addEdge(0, 3, 90);
    G.addEdge(1, 3, 45);
    G.addEdge(1, 2, 35);
    G.addEdge(3, 2, 40);
    G.addEdge(3, 4, 75);
    G.addEdge(4, 5, 15);
    G.addEdge(3, 5, 30);

    G.display();

    cout << endl;

    G.BFS(0);

    cout << endl;

    G.DFS(0);

    cout << endl << endl;

    primsAlgorithm(G);
}