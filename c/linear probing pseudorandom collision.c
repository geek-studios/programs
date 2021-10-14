#include <stdio.h>
#include <stdlib.h>

struct Node {//defines hash node
	long long key;
	int value;
};
const int Max = 23,a=3,c=5;
int Size = 0;
struct Node** arr;
struct Node* b;//dummy node

void Insert(long long key, int value){//Inserts the key value pair
	struct Node* temp = (struct Node*)calloc(1,sizeof(struct Node));
	temp->key = key;
	temp->value = value;
	int address = (a*key + c) % Max;//pseudo random hash implementation
	while (arr[address] != NULL && arr[address]->key != key	&& arr[address]->key != -1) {// Finds the next free space
		address++;
		address %= Max;
	}
	if (arr[address] == NULL || arr[address]->key == -1)Size++;
	arr[address] = temp;printf("index of key %lld = %d\n",key,address);
	printf("---------------------\n");
}

int FindKey(long long key){//Finds the key
	int address = (a*key + c) % Max;
	int Count = 0;
	while (arr[address] != NULL) {
		int Count = 0;
		if (Count++ > Max)break;
		if (arr[address]->key == key)return arr[address]->value;
		address++;
		address %= Max;
	}
	return -1;
}

int Delete(long long key){// Function to delete a key value pair
	int address = (a*key + c) % Max;
	while (arr[address] != NULL) {
		if (arr[address]->key == key) {
			arr[address] = b;
			Size--;
			return 1;
		}
		address++;
		address %= Max;
	}
	return 0;
}

int main(void)
{
	arr = (struct Node**)calloc(1,Max * sizeof(struct Node*));
	b = (struct Node*)calloc(1,sizeof(struct Node));
	b->key = -1;
	b->value = -1;
	Insert(1, 6);
	Insert(24, 50);
	Insert(47, 12);
	Insert(70, 54);
	Insert(21, 60);
	Insert(33, 4);
	Insert(54, 14);
	Insert(7, 58);
	printf("1-------------\n");
	printf("Inserting element in Hashtable\n");
    printf("Enter key and value : ");
    int value;
    long long key;
    scanf("%lld %d", &key, &value);
    Insert(key, value);
    printf("2-------------\n");
	if (FindKey(1) != -1)printf("Value of Key 1 = %d\n", FindKey(1));
	else printf("NOT FOUND\n");
	printf("3-------------\n");
	if (FindKey(23) != -1)printf("Value of Key 23 = %d\n", FindKey(23));
	else printf("NOT FOUND\n");
	printf("4-------------\n");
	if (FindKey(6) != -1)printf("Value of Key 6 = %d\n", FindKey(6));
	else printf("NOT FOUND\n");
	printf("5-------------\n");
	if (Delete (54))printf("Node value of key 54 is deleted successfully\n");
	else printf("NOT FOUND\n");
	printf("6-------------\n");
	if (FindKey(54) != -1)printf("Value of Key 54 = %d\n", FindKey(54));
	else printf("NOT FOUND\n");
	Insert(13, 89);
	Insert(20, 55);
	printf("7-------------\n");
	if (FindKey(14) != -1)printf("Value of Key 14 = %d\n", FindKey(14));
	else printf("NOT FOUND\n");
	printf("8-------------\n");
	if (Delete (13))printf("Node value of key 13 is deleted successfully\n");
	else printf("NOT FOUND\n");
	printf("9-------------\n");
	if (FindKey(-1) != -1)printf("Value of Key -1 = %d\n", FindKey(-1));
	else printf("NOT FOUND\n");
	printf("10-------------\n");
	if (FindKey(key) != -1)printf("Value of Key %lld = %d\n", key,FindKey(key));
	else printf("NOT FOUND\n");
	printf("11-------------\n");
	if (Delete (key))printf("Node value of key %lld is deleted successfully\n",key);
	else printf("NOT FOUND\n");

    return 0;
}
