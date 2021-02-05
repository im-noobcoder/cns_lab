#include<stdio.h>
#define min(x, y) (x < y) ? x : y

int main()
{
    int bSize, input[20], outRate, drop, container, i, n, ch;
    printf("Enter the bucket size : ");
    scanf("%d", &bSize);
    printf("\nEnter the output rate : ");
    scanf("%d", &outRate);
    do
    {
        printf("\nEnter the number of packets arriving at second %d : ", i+1);
        scanf("%d", &input[i++]);
        printf("\nEnter 1 to insert packet 0 to quit : ");
        scanf("%d", &ch);
    } while (ch);
    n = i;  // total number of inputs
    printf("\nSecond | Packets received | Packets sent | Pkts in Bucket | Packet Dropped\n");

    container = 0; drop = 0;   

    for(i=0; i<n; i++)
    {
        container += input[i];
        if (container > bSize)
        {
            drop = container - bSize;   //drop the packets if it's more than container size
            container = bSize;
        }
        printf("%d", i+1);      // second 
        printf("\t\t%d", input[i]);      //packets received at ith second
        printf("\t\t%d", min(container, outRate));      // packets sent, cannot exceed output rate
        container -=  min(container, outRate);      //calculate the packets left in bucket :: subtract the packets sent from container
        printf("\t\t%d", container);    // packets left in container
        printf("\t\t%d\n", drop);     //packets dropped
    }  

    // if container is not empty at this point 
    for (; container != 0; i++)
    {
        if(container > bSize)
            container = bSize;
        printf("%d", i+1);      // second
        printf("\t\t0");     //packets received is zero
        drop = 0;   // drop is zero once there's no incoming packets
        printf("\t\t%d", min(container, outRate));      //packets sent
        container -= min(container, outRate);
        printf("\t\t%d", container);
        printf("\t\t%d\n",drop);
    }   //end of for loop I
    return 0;
}

