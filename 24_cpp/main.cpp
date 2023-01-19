#include <iostream>

using namespace std;

int collatz(int n)
{
    static int count = 0;
    count++;
    if(n==1)
    {
        cout << count << endl;
        return 1;
    }
    if(n % 2 == 0)
        return collatz(n/2);
    else
        return collatz(3*n+1);
}

int main()
{
    collatz(10);
    return 0;
}


// Die Funktion terminiert
