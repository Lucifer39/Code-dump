#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 50

char *inputFile="12619003165_input.txt";
char *outputFile="12619003165_output.txt";

typedef struct edges{
    int src;
    int dest;
    int wt;
} edges;

typedef struct set{
    int parent;
    int rank;
} set;

void kruskal();
//Disjoint Set Data Structure
int Find(int);
void Union(int,int);
//Quicksort
int partition(edges *,int,int);
void quicksort(edges *,int,int);

int G[MAX][MAX];
edges edgeset[MAX*MAX];
set s[MAX];
int v,e=0,sum=0;
FILE *input,*output;

int Find(int n)
{
    if(s[n].parent==-1)
        return n;
    return Find(s[n].parent);
}

void Union(int p1,int p2){
    int p1_p=Find(p1);
    int p2_p=Find(p2);
    if(s[p1_p].rank==s[p2_p].rank){
        s[p1_p].parent=p2_p;
        s[p2_p].rank+=1;
    }
    else if(s[p1_p].rank > s[p2_p].rank){
        s[p2_p].parent=p1_p;
    }
    else{
        s[p1_p].parent=p2_p;
    }
}

void kruskal(){
    quicksort(edgeset,0,e);
    for(int i=0;i<e;i++){
        edges edge=edgeset[i];
        int src = edge.src;
        int dest = edge.dest;
        int wt = edge.wt;
        
        if(Find(src) == Find(dest)){
            continue;
        }
        else{
            printf("(%c,%c) => %d\n",(src+'A'),(dest+'A'),wt);
            Union(src,dest);
            sum+=wt;
            fprintf(output,"(%c,%c) => %d\n",(src+'A'),(dest+'A'),wt);
        }
    }
}

int main(int argc,char *argv[])
{
    if(argc>1){
        inputFile=argv[1];
        outputFile=argv[2];
    }
    
    input=fopen(inputFile,"r");
    output=fopen(outputFile,"w");
    v=0;
    edges edge;
    while(!feof(input)){
        int i,j,w;
        fscanf(input, "%d", &i);
        fscanf(input, "%d", &j);
        fscanf(input,"%d",&w);
        edge.src=i;
        edge.dest=j;
        edge.wt=w;
        
        edgeset[e]=edge;
        e++;

        if(i>v)
            v=i;
        if(j>v)
            v=j;
    }
    v=v+1;  //Total number of vertices
    if(v>MAX){
        printf("Max Vertices Allowed is %d\nHence Program cannot proceed\n",MAX);
        return 1;
    }
    printf("\n\nNumber of Edges Found: %d",e);
    printf("\n\nNumber of Vertices Found: %d",v);
    fprintf(output,"\nNumber of Edges Found: %d",e);
    fprintf(output,"\nNumber of Vertices Found: %d\n\n",v);

    //Initialize Vertex Parent to -1 and Rank to zero
    for(int i=0;i<v;i++){
        s[i].parent=-1;
        s[i].rank=0;
    }

    printf("\n\nEdges to be included: \n");
    kruskal();  //Kruskal MST

    printf("Cost of MST: %d",sum);
    printf("\n\n");
    fprintf(output,"Cost of MST: %d\n",sum);
    fclose(output);
    fclose(input);
    return 0;
}


int partition(edges *a,int low,int high){ 
	edges p=a[high];
	int i=low,j=low;
	for(;j<high;j++)
	{
		if(a[j].wt<=p.wt)
		{
			edges t=a[j];
			a[j]=a[i];
			a[i]=t;
			i++;
		}
	}
	edges t=a[i];
	a[i]=a[high];
	a[high]=t;
	return i;
}

void quicksort(edges *a,int low,int high){   //Non-Randomized
	if(low<high)
	{
		int p = partition(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
	}
}