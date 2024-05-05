#include <iostream>
#include <random>

using namespace std;

struct stack
{
	int maxSize;
	int topIndex;
	int* items;
};

struct stack* newStack(int capacity)
{
	struct stack* stck = new struct stack;

	stck->maxSize = capacity;
	stck->topIndex = -1;
	stck->items = new int[capacity];

	return stck;
};

int size(struct stack* stck) {
	return (stck->topIndex) + 1;
}
bool isFull(struct stack* stck) {
	return (size(stck) == stck->maxSize) ? true : false;
}

bool isEmpty(struct stack* stck) {
	return (stck->topIndex==-1) ? true : false;
}

void push(struct stack* stck, int x)
{
	cout << "Sprawdzam czy stos jest przepelniony.\n";
	if (isFull(stck))
	{
		cout << "Stos przepelniony\n";
		
	}
	else
	{
		cout << "Jest OK\n";
		stck->topIndex++;
		cout << "Zwiekszono indeks wierzchnego elemntu na " << stck->topIndex << endl;
		stck->items[stck->topIndex] = x;
		cout << "stck->items[" << stck->topIndex << "] = " << x << endl;
	}

}

void pop(struct stack* stck)
{
	cout << "Sprawdzam czy stos jest pusty.\n";
	if (isEmpty(stck))
	{
		cout << "Stos pusty\n";
	}
	else
	{
		cout << "Stos nie pusty\n";
		stck->topIndex--;
		cout << "Zmniejszono indeks wierzchnego elemntu na " << stck->topIndex << endl;
	}

}

int top(struct stack* stck)
{
	cout << "Sprawdzam czy stos jest pusty.\n";
	if (!isEmpty(stck))
	{
		cout << "Stos nie pusty\n";
		return stck->items[stck->topIndex];
	}
	else
	{
		cout << "Stos pusty\n";

	}
}

void menu() {
	cout << "1.Push an item\n";
	cout << "2.Pop an item\n";
	cout << "3.Get top item\n";
	cout << "4.Exit\n";
}

int main() {
	struct stack* stck = newStack(20);
	int k,t;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 20);
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < 10; i++)
	{
		push(stck, dist(gen));
		cout << "-------------------------------------------------\n";
	}
	system("cls");
	do
	{

		menu();
		cin >> k;
		switch (k)
		{
		case 1:
			cout << "Podaj element : ";
			cin >> t;
			cout << "-------------------------------------------------\n";
			push(stck, t);

			break;
		case 2:
			cout << "-------------------------------------------------\n";
			pop(stck);
			break;
		case 3:
			cout << "-------------------------------------------------\n";
			 t = top(stck);
			cout << "Top item: " << t<<endl;
			break;
		case 4:
			cout << "-------------------------------------------------\n";
			cout << "Konczenie dzialanie programu\n";
			break;
		default:
			break;
		}
		cout << "-------------------------------------------------\n";
	} while (k != 4);
	delete[] stck->items;
	delete stck;
	return 0;
}