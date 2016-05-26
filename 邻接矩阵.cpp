#include<stdio.h>
#include<stdlib.h>
#define matmax 20
typedef int adjmatrix[matmax][matmax];
void creatematrix(adjmatrix GA,int n)  //已测试 
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		printf("请输入与标号为%d节点相连的节点标号:\n",i);
		do
		{
			scanf("%d",&temp);
			if(temp>=0&&temp<n)
			GA[i][temp]=1; 
		}
		while(temp!=n);
	}
	printf("邻接矩阵为:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",GA[i][j]);
		printf("\n");
	}
}
void DFS(adjmatrix GA,int v1,int n) //已测试 
{
	int path[n+1];
	int visited[n];
	int rear=-1,i,current,flag=0;
	for(i=0;i<n+1;i++)
	path[i]=0;
	for(i=0;i<n;i++)
	visited[i]=0;
	path[++rear]=v1;
	current=v1;
	printf("V%d-",v1);
	visited[v1]=1;
	do
	{
		for(i=0;i<n;i++)
		{
			if(GA[current][i]==1&&visited[i]==0)
			{
				path[++rear]=i;
				printf("V%d-",i);
				visited[i]=1;
				current=path[rear];
				flag=1;
				break;//i=n;
			}
		}
		if(flag==0&&rear!=-1)
		current=path[rear];
		rear--;
		flag=0;
	}
	while(rear!=-2);
	printf("^\n");
} 
void BFS(adjmatrix GA,int v2,int n)  //已测试 
{
	int path[n+1];
	int visited[n];
	int rear=0,front=0,i,current;
	for(i=0;i<n+1;i++)
	path[i]=0;
	for(i=0;i<n;i++)
	visited[i]=0;
	printf("V%d-",v2);
	visited[v2]=1;
	for(i=0;i<n;i++)
	if(GA[v2][i]==1&&visited[i]==0)
	{
		path[rear++]=i;
		visited[i]=1;
	}
	do
	{
		current=path[front++];
		printf("V%d-",current);
		for(i=0;i<n;i++)
			if(GA[current][i]==1&&visited[i]==0)
			{
				path[rear++]=i;
				visited[i]=1;
			}
	}
	while(rear!=front);
	printf("^\n");
}
int main()
{
	int n,i,j,v1,v2;
	adjmatrix GA;
	printf("请输入节点个数:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			GA[i][j]=0;
	creatematrix(GA,n);
	printf("请输入DFS的遍历起点:\n");
	scanf("%d",&v1);
	printf("深度优先遍历结果:\n"); 
	DFS(GA,v1,n);
	printf("请输入BFS的遍历起点:\n");
	scanf("%d",&v2);
	printf("广度优先遍历结果:\n");
	BFS(GA,v2,n);
	return 0;
}
