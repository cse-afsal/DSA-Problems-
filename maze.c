#include <stdio.h>
#define R 4
#define C 4

int row[] = {-1,1,0,0};
int col[] = {0,0,-1,1};


void shortestdistance(int mat[R][C])
{
    int dist[R][C];
    int qx[100],qy[100];
    int front = 0,rear = 0;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j] == 0)
            {
                dist[i][j] = 0;

                qx[rear] = i;
                qy[rear] = j;
                rear++;
            }
            else
            {
                dist[i][j] = -1;
            }
        }
    }
    while(front<rear)
    {
        int x = qx[front];
        int y = qy[front];
        front++;

        for(int k=0;k<4;k++)
        {
            int nx = x + row[k];
            int ny = y + col[k];

            if(nx>=0 && nx<R && ny>=0 && ny<C && mat[nx][ny] != -1 && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;

                qx[rear]=nx;
                qy[rear]=ny;
                rear++;
            }
 
        }
    }
    printf("Shortest distance matrix : \n");
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            printf("%3d",dist[i][j]);
        }
     printf("\n ");
    }

}

int main()
{
    int mat[R][C] = {
        {1,1,1,1},
        {1,-1,1,1},
        {1,0,1,1},
        {1,1,1,0}
    };

    shortestdistance(mat);
    return 0;
}
