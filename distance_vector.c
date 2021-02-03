#include<stdio.h>

struct rtable
{
    int distance[20], nextnode[20];
}table[20];
int cost[10][10], n;

void distanceVector()
{
    int i, j, k, count=0;
    //fill initial values for table
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            table[i].distance[j] = cost[i][j];
            table[i].nextnode[j] = j;
        }
    
    do
    {
        count = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                for(k=0; k<n; k++)      //calculate distance between i and j through k and check if it's lesser
                {
                    if (table[i].distance[j] > cost[i][k] + table[k].distance[j])
                        {
                            table[i].distance[j] = cost[i][k] + table[k].distance[j];
                            table[i].nextnode[j] = k;
                            count++;    //increase the count if you find such intermediate node
                        }
                }
            }   //end of for loop J
        }   //end of for loop I
    }   //end of do 
    while (count != 0);     //repeat untill no such intermediate node from i to j is found
}
 
int main()
{
    int i, j;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    printf("Enter cost matrix (no path - 999) \n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &cost[i][j]);
    distanceVector();

    for(i=0; i<n; i++)
    {
        printf("state value of router : %c\n", i+65);
        printf("dest node\tnext node\tdistance\n");
        for (j=0; j<n; j++)
        {
            if (table[i].distance[j] == 990)
                printf("%c\t\t-\t\tinfinite\n", j+65);
            else
                printf("%c\t\t%c\t\t%d\n", j+65, table[i].nextnode[j] + 65, table[i].distance[j]);
        }
    }
    return 0;   
}