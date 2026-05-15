#include <stdio.h>

#define MAX 20

struct node
{
    unsigned dist[MAX];
    unsigned from[MAX];
};

struct node rt[MAX];

int main()
{
    int cost[MAX][MAX];

    int n;
    int i, j, k;
    int count;

    // Input number of nodes
    printf("Enter number of nodes (max %d): ", MAX);
    scanf("%d", &n);

    // Check validity
    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of nodes\n");
        return 0;
    }

    printf("Use 999 to represent infinity\n");

    // Input cost matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Cost from node %d to node %d: ",
                   i + 1, j + 1);

            scanf("%d", &cost[i][j]);

            rt[i].dist[j] = cost[i][j];
            rt[i].from[j] = j;
        }

        // Distance to itself is 0
        cost[i][i] = 0;
        rt[i].dist[i] = 0;
        rt[i].from[i] = i;
    }

    // Distance Vector Algorithm
    do
    {
        count = 0;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    // Update shortest distance
                    if (rt[i].dist[j] >
                        cost[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] =
                            cost[i][k] + rt[k].dist[j];

                        rt[i].from[j] = k;

                        count++;
                    }
                }
            }
        }

    } while (count != 0);

    // Display routing tables
    printf("\n--- Routing Tables ---\n");

    for (i = 0; i < n; i++)
    {
        printf("\nRouting table for router %d:\n", i + 1);

        printf("Destination\tNext Hop\tDistance\n");

        for (j = 0; j < n; j++)
        {
            printf("%d\t\t%d\t\t%d\n",
                   j + 1,
                   rt[i].from[j] + 1,
                   rt[i].dist[j]);
        }
    }

    return 0;
}
