#include<stdio.h>

int main() {
    int i,n;
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the adjacency matrix");
    for (int i =0 ; i< n ; i++){
        for(int j =0 ;j <n ; j++) {
            printf("Enter the Vertex[%d][%d]",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    bfs(a,n);





}

int bfs(int a[][], int n){
    int q[n],front =0,rear=0,v[n];
    printf("BFS Tracersal is :")
    for (int i =0;i<n;i++) {
        for (int j=0;j<n;j++ ){
            if(a[i][j] == 1){
             printf("%d",j);
             v[j]=1;
             q[front] = a[j];
             front++;
             
                         
            }
            
        }
    }



}