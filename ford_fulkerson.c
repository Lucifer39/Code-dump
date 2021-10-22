#include <stdio.h>
#define A 0
#define B 1
#define C 2
#define MAX_NODES 1000
#define O 1000000000
int n;                              //num of vertices
int e;                              //num of edges
int capacity[MAX_NODES][MAX_NODES]; //stores the remaining capcity of the flow left in edges
int flow[MAX_NODES][MAX_NODES];     //stores the current flow in the edges
int color[MAX_NODES];
int pred[MAX_NODES];
int min(int x, int y)
{
    return x < y ? x : y;
}
int head, tail;
int q[MAX_NODES + 2];
void enqueue(int x)
{
    q[tail] = x;
    tail++;
    color[x] = B;
}
int dequeue()
{
    int x = q[head];
    head++;
    color[x] = C;
    return x;
}
int bfs(int start, int target)
{
    int u, v;
    for (u = 0; u < n; u++)
    {
        color[u] = A;
    }
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head != tail)
    {
        u = dequeue();
        for (v = 0; v < n; v++)
        {
            if (color[v] == A && capacity[u][v] - flow[u][v] > 0)
            {
                enqueue(v);
                pred[v] = u;
            }
        }
    }
    return color[target] == C;
}
int fordFulkerson(int source, int sink)
{
    int i, j, u;
    int max_flow = 0; //init max_flow to 0
    //init flow of each edg eto be zero
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            flow[i][j] = 0;
        }
    }
    //while a flow path exists between source and sink
    while (bfs(source, sink))
    {
        int increment = O;
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
        }
        printf("Path used \n ");
        printf("with flow : %d \n", increment);
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            flow[pred[u]][u] += increment;
            flow[u][pred[u]] -= increment;
            printf("%d <- ", u);
        }
        printf(" source \n");
        max_flow += increment;
    }
    return max_flow;
}
int main()
{
    n = 0;
    e = 0;
    int i, j;
    printf("\n Please enter the number of vertices\n");
    scanf("%d", &n);
    printf("\n Please enter the number of edges\n");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            capacity[i][j] = 0;
        }
    }
    int src, dest, cap;
    for (int i = 0; i < e; i++)
    {
        printf("\n Please enter src->dest->weight in order\n");
        scanf("%d", &src);
        scanf("%d", &dest);
        scanf("%d", &cap);
        capacity[src][dest] = cap;
    }
    int s = 0, t = 0;
    printf("\n Please enter source and sink\n");
    scanf("%d", &s);
    scanf("%d", &t);
    printf("Max Flow: %d\n",
           fordFulkerson(s, t));
}
