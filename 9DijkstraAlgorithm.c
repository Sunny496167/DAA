#include<stdio.h>
#include<stdlib.h>

void dijkstraAlgo(int n,int cost[10][10],int s,int dist[10]){
	 int i,v,min,count=1,visited[10];
	 for(i=1;i<=n;i++){
		visited[i]=0;
		dist[i]=cost[s][i];
	}
	visited[s]=1;
	dist[s]=0;
	while(count<=n){
		min=999;
		for(i=1;i<=n;i++){
			if(dist[i]<min && visited[i]==0){
				v=i;
				min=dist[i];
			}
			visited[v]=1;
			count++;
			for(i=1;i<=n;i++){
				if(dist[v]+cost[v][i]<dist[i] && visited[i]==0){
					dist[i]=dist[v]+cost[v][i];
				}
			}
		}
	}
}

int main(){
	int n,i,j,s,cost[10][10],dist[10];
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Read Cost Matrix : \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("\nEnter the source vertex : \n");
	scanf("%d",&s);
	dijkstraAlgo(n,cost,s,dist);
	printf("\nShortest path from %d is \n",s);
	for(i=1;i<=n;i++){
		if(s!=i){
			printf("%d -> %d = %d\n",s,i,dist[i]);
		}
	}
	return 0;
}