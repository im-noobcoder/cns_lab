#include <bits/stdc++.h>
using namespace std;

//this program does not calculate primitive root
//we have to provide premitive root externally

long long int modexp(int a, int b, int m)
{
    return (b == 1)? a%m : ((long long int) pow(a, b)) % m;
}


int main()
{
    int p, xa, xb, ya, yb, ka, kb, alpha;
    cout << "enter a large prime number : ";
    cin >> p;
    cout<<"Enter a premitive root of "<<p<<" : ";
    cin>>alpha;
    cout << "enter xa(private key for A) less than " << p << " : ";
    cin >> xa;
    cout << "enter xb(private key for B) less than " << p << " : ";
    cin >> xb;
    ya = modexp(alpha, xa, p);
    yb = modexp(alpha, xb, p);
    cout<<"public key of A is "<<ya<<endl;
    cout<<"public key of B is "<<yb<<endl;
    ka = modexp(yb, xa, p);
    kb = modexp(ya, xb, p);
    (ka == kb)? cout<<"key exchanged are same\n" : cout<<"key exchanged are not same\n";
    cout<<"key for A is "<<ka<<"\nkey for B is "<<kb<<endl;
}