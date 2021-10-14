/*
    Name: Maheswaran T Parameswaran
    Dept of EEE, S4
    Date: October 14th, 2021
*/

#include <stdio.h>

unsigned long hash(char* str)           // some hash function i yeeted off the internet
{
    unsigned int hash = 0;
    int c;
    while (c = *str++)
        hash += c;
    return hash;
}

struct dict {
    char* val;
};

// declare dictionary array
struct dict dictionary_array[10000];

void print_val(char* key)
{
    printf("%s\n", dictionary_array[hash(key)].val);
}

int main()
{
    char* str1 = "Maheswaran";
    char* str2 = "20";

    char* key1 = "Name";
    char* key2 = "Age";

    unsigned long n1 = hash(key1);
    unsigned long n2 = hash(key2);

    dictionary_array[n1].val = str1;
    dictionary_array[n2].val = str2;


    print_val("Name");
    print_val("Age");

    return 0;
}