#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top=-1;

void dfs(int u,int n){
    int v;
    visited[u]=1;
    for(v=0;v<n;v++){
        if(!visited[v] && graph[u][v]){
            dfs(v,n);
        }
    }
    stack[++top]=u;
}

void topological_ordering(int n){
    int u;
    int i;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(u=0;u<n;u++){
        if(!visited[u]){
            dfs(u,n);
        }
    }
    printf("Toplogical Ordering\n4");
    while(top!=-1){
        printf("%d->",stack[top--]);
    }
}

int main(){
    int i,j,n;
    printf("\nEnter the no of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adajaceny matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Topological Sorting");
    topological_ordering(n);
}