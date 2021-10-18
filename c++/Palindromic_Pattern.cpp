/*
Palindromic Pattern
Author: Neetu Kumari
Date Modified:18-10-2021
*/

#include<iostream>

using namespace std;

int main() {
  int n;
  cin >> n; //no of rows=n

  for (int i = 1; i <= n; i++) {
    int j;
    for (j = 1; j <= n - i; j++) {
      cout << "  ";
    }
    int k = i; //k=row no
    for (; j <= n; j++) {
      cout << k-- << " ";
    }
    k = 2;
    for (; j <= n + i - 1; j++) {
      cout << k++ << " ";
    }
    cout << endl;
  }
}
