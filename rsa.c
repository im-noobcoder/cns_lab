#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

unsigned long modexp(unsigned long msg, unsigned long exp, unsigned long n)
{
    unsigned long i, k=1;
    for (i=0; i<exp; i++)
        k = (k*msg)%n;
    return k;
}

int main()
{
    unsigned long p, q, n, z, e, d, m, c, i;
    int len;
    printf("Enter two number p and q such that p*q > 255 : ");
    scanf("%lu %lu", &p, &q);
    n = p*q;
    z = (p-1) * (q-1);
    // calculate e such that e is relatively prime to n
    for (i=1; i<z; i++)
    {
        if (z % i == 0)
           continue;
        else
            break;
    }
    e = i;
    printf("\nencryption key is : %lu", e);
    // calculate d 

    for (i=1; i<z; i++)
        if ((i*e-1) %z == 0)
            break;
    
    d = i;
    printf("\ndecryption key is : %lu", d);

    //take the input message
    char data[50];
    printf("\nenter the data : ");
    scanf("%s", data);
    len = strlen(data);

    // start encryption and decryption
    for(i=0; i<len; i++)
    {
        m = (unsigned long) data[i];
        c = modexp(m,e,n);
        printf("\nencrypted value is %c and it's representation is %lu", (char)m, c);
        m = modexp(c, d, n);
        printf("\ndecrypted value is %lu and it's representation is %c", m, (char)m);
    }
    return 0;
}