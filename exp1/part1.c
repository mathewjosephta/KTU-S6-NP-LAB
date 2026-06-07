#include<stdio.h>

int main()
{
    int cost[10][10];
    int dist[10][10];

    int n;
    int i, j, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            dist[i][j] = cost[i][j];
        }
    }

    // Distance Vector Algorithm
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(dist[i][j] > cost[i][k] + dist[k][j])
                {
                    dist[i][j] = cost[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display shortest distances
    printf("\nShortest Distance Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", dist[i][j]);
        }

        printf("\n");
    }

    return 0;
}
