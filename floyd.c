#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INF 99999
int min(int,int);
void floyds(int p[10][10],int n) {
	int i,j,k;
	for (k=1;k<=n;k++)
	  for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	    if(i==j)
	     p[i][j]=0; else
	     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b) {
	if(a<b)
	  return(a); else
	  return(b);
}
void main() {
	clock_t start,end;
	int p[10][10],w,n,e,u,v,i,j;
	printf("\n Enter the number of vertices: ");
	scanf("%d",&n);
	printf("\n Enter the number of edges: ");
	scanf("%d",&e);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++){
		    if(i==j){
	           p[i][j]=0;
            }
            else
		       p[i][j]=INF;
		}
	}
	
	printf("\n Enter the edges with corresponding weights (source : destinatin  : weight) : \n");
	for (i=1;i<=e;i++) {
		scanf("%d %d %d",&u,&v,&w);
		p[u][v]=w;
	}
	printf("\n Matrix of input data:\n");
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++){
		    if(p[i][j]==INF){
		        printf("INF\t");
		    }
		    else{
		   printf("%d \t",p[i][j]);
        }
       }
		printf("\n");
	}
	start=clock();
	floyds(p,n);
	end=clock();
	printf("\n Transitive closure:\n");
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++)
		   printf("%d \t",p[i][j]);
		printf("\n");
	}
	printf("\n The shortest paths are:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		if(i!=j)
		    printf("\n %d---->%d=%d",i,j,p[i][j]);
	}
	printf("\n Execution Time = %f",(((double)(end-start))/CLOCKS_PER_SEC));
}