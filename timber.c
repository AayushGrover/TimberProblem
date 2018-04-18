#include<stdio.h>

int main()
{
    int m1,n1;
    scanf("%d %d",&m1,&n1);
    const int m = m1;
    const int n = n1;
    int arr[m+1][n+1];

    //shifting the indexing
    for(int i = 0 ; i < m+1 ; i++)
        arr[i][0] = 0;
    for(int i = 0 ; i < n+1 ; i++)
        arr[0][i] = 0;

    //taking the input
    for(int i = 1 ; i < m+1 ; i++)
        for(int j = 1 ; j < n+1 ; j++)
            scanf("%d",&arr[i][j]);

    //creating the dp array
    int v1,v2,v3,v4;
    for(int i = 1 ; i < m+1 ; i++)
    {
         for(int j = 1 ; j < n+1 ; j++)
         {
             v1 = arr[i-1][j];//value above
             v2 = arr[i][j-1];//value to the left
             v3 = arr[i-1][j-1];//value to the top left

             arr[i][j] = v1 + v2 - v3 + arr[i][j];
            // cout << "(" << v1 << "," << v2 << "," << v3 << ")" << " ";
            // cout << arr[i][j] << " ";
         }
        //  cout << endl;
    }

    int c,x1,y1,x2,y2;
    scanf("%d",&c);

    for(int i = 0 ; i < c ; i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        v1 = arr[x2][y2];//bottom right
        v2 = arr[x2][y1-1];//bottom left
        v3 = arr[x1-1][y2];//top right
        v4 = arr[x1-1][y1-1];//top left
        //shifted since data stored in bottom right corner

        printf("%d\n",v1-v2-v3+v4);
    }

}
