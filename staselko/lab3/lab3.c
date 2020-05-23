#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    printf("n= ");
    scanf("%d",&n);
    printf("m= ");
    scanf("%d",&m);

    int Arr[n][m];
    int i=0, j, k = 0, p=1;
//fiilling the array
    while (i < n*m) 
     {
        k++;
        for (j=k-1;j<m-k+1;j++)
        {
            Arr[k-1][j]=p++;
            i++;
        }  

        for (j=k;j<n-k+1;j++)
        {
            Arr[j][m-k]=p++;
            i++;
        }

        for (j=m-k-1;j>=k-1;j--)
        {
            Arr[n-k][j]=p++;
            i++;
        } 

        for (j=n-k-1;j>=k;j--)
        {
            Arr[j][k-1]=p++;
            i++;
        } 

     }

    for (int q=0; q<n; q++)
    {
        for (int w=0; w<m; w++)
        {
            printf("%d \t",Arr[q][w]);
        };
        printf("\n");
    }

    return(0);
}
