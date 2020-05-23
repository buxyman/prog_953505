#include <stdio.h>

#define M 5
#define N 5

int main()
{
    int matr[M][N], i = -1, j, val = 1, cnt = M * N;
    int lef = -1, rig = N - 1, top = 0, bot = M - 1;

    while( lef <= rig && top <= bot )
    {
        for( j = ++lef; j <= rig && val <= cnt; j++ )      matr[i + 1][j] = val++;
        for( i = ++top; i <= bot && val <= cnt; i++ )      matr[i][j - 1] = val++;
        for( j = --rig; j >= lef && val <= cnt; j-- )      matr[i - 1][j] = val++;
        for( i = --bot; i >= top && val <= cnt; i-- )      matr[i][j + 1] = val++;
    }

    for( i = 0; i < M; i++ )
    {
        for( j = 0; j < N; j++ )
            printf( "%3d", matr[i][j] );
        printf( "\n" );
    }

    return 0;
}
