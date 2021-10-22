/*cpp program for count sort
Author: Anil Kumar
Date modified:21-10-2021
*/

#include <iostream>
using namespace std;

int findMax(int A[], int n)
{
    int max = A[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
void CountSort(int A[], int n)
{
    int i, j, max;

    max = findMax(A, n);
    int C[max+1];

    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++;
    }

    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}
int main()
{
    int n, i;

    cout << "number of element to short:";
    cin >> n;
    int A[n];
    cout << endl
         << "enter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << endl
         << "shorted elements:";

    CountSort(A, n);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
