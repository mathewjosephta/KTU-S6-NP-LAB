#include <stdio.h>

int main()
{
    int in;
    int out;
    int size;
    int n;

    int store = 0;

    // Input bucket size
    printf("Enter bucket size: ");
    scanf("%d", &size);

    // Input number of packets
    printf("Enter number of inputs: ");
    scanf("%d", &n);

    // Input outgoing rate
    printf("Enter outgoing rate: ");
    scanf("%d", &out);

    // Process packets
    while(n != 0)
    {
        // Input incoming packet size
        printf("Incoming packet size: ");
        scanf("%d", &in);

        // Check bucket space
        if(in <= (size - store))
        {
            store = store + in;

            printf("Bucket buffer size %d out of %d\n",
                   store, size);
        }
        else
        {
            // Drop extra packets
            printf("Dropped %d number of packets\n",
                   in - (size - store));

            store = size;

            printf("Bucket buffer size %d out of %d\n",
                   store, size);
        }

        // Remove outgoing packets
        store = store - out;

        // Avoid negative value
        if(store < 0)
        {
            store = 0;
        }

        // Display remaining packets
        printf("After outgoing %d packets left out of %d in buffer\n",
               store, size);

        n--;
    }

    return 0;
}
