#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<unistd.h>
#define V 20

typedef struct edge{
    int u;
    int v;
    int wt;
} edge;

void getPath(int); //Print Path after dijkstras
void dijkstra(int); // Dijkstras Algorith

edge e[V][V];
int v,s;
int selected[V],dist[V],parent[V];

int dequeue(){
    int min=INT_MAX,min_i;
    for(int i=0;i<v;i++)
    {
        if(dist[i]<min && selected[i]==0){
            min=dist[i];
            min_i=i;
        }
    }
    selected[min_i]=1;
    return min_i;
}

int main(){
    // printf("Enter number of vertices: ");
    // scanf("%d",&v);
    v=5;
    FILE *input=fopen("input5.txt","r");
    if(v>V){
        printf("Too many number of vertices!\n");
        return 1;
    }
    // printf("Enter edge weights: ");
    // for(int i=0;i<v;i++)
    // {
    //     for(int j=0;j<v;j++)
    //     {
    //         e[i][j].u=i;
    //         e[i][j].v=j;
    //         fscanf(input,"%d",&(e[i][j].wt));
    //     }    
    // }
    while(!feof(input)){
        int i,j;
        fscanf(input, "%d", &i);
        fscanf(input, "%d", &j);
        fscanf(input, "%d", &(e[i][j].wt));
        e[i][j].u=i;
        e[i][j].v=j;
    }
    for(int i=0;i<v;i++)
    {   
        selected[i]=0;
        dist[i]=INT_MAX;
        parent[i]=-1;
    }
    int source;
    // printf("Enter source vertex: ");
    // scanf("%d",&s);
    s=0; //Source Vertex
    source=s;
    sleep(1);
    printf("\nStarting Dijkstra's Algorithm\n");
    sleep(1);
    dijkstra(source);
    printf("\nProgram Terminated Without Any Error\n\n");
    sleep(2);
    return 0;
}
void dijkstra(int source){
    selected[s]=1;
    dist[s]=0;
    printf("\nSteps of relaxing: \n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++){
            if(dist[s]+e[s][j].wt<dist[j] && selected[j]==0 && e[s][j].wt!=999 && e[s][j].wt!=0 && j!=s){
                dist[j]=dist[s]+e[s][j].wt;
                parent[j]=s;
                printf("Relax Edge %c to %c\n",('A'+s),('A'+j));
                sleep(1);
            }
        }
        s=dequeue();
    }
    printf("\nGenerating Path Details:\n");
    sleep(2);
    for(int i=0;i<v;i++)
    {
        if(i==source)
            continue;
        printf("Path from %c to %c: ",('A'+source),('A'+i));
        getPath(i);
        printf("\nWeight: %d\n",dist[i]);
        sleep(1);
    }
}
void getPath(int d){
    if(parent[d]==-1)
    {
        printf("%c ",('A'+d));
        return;
    }
    getPath(parent[d]);
    printf("->");
    printf(" %c ",('A'+d));
}