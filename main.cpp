#include <iostream>
#include <string>
#include "Tree.h"


using namespace std;

int main()
{
	SimpleTree<int>* c = new SimpleTree<int>();
	for (int i = 1; i < 6; i++)
		c->insert(i*i);
	
	printf("List after creation:\n");
	c->print();
	if (c->exists(16))
		cout << "Search for value 16: found" << endl;
	if (!c->exists(111))
		cout << "Search for value 111: not found" << endl;
	c->remove(16);
	cout << "List after deletion of the element:" << endl;
	c->print();
	cout << endl;
	delete c;
	
	SimpleTree<double>* d = new SimpleTree<double>();
	for (int i = 1; i < 6; i++)
		d->insert((i + 0.5)*i);
	printf("List after creation:\n");
	d->print();
	if (d->exists(10.5))
		cout << "Search for value 10.5: found" << endl;
	if (!d->exists(66))
		cout << "Search for value 66: not found" << endl;
	d->remove(10.5);
	cout << "List after deletion of the element:" << endl;
	d->print();
	cout << endl;
	delete d;

	SimpleTree<string>* e = new SimpleTree<string>();
	e->insert("a");
	e->insert("ab");
	e->insert("abc");
	e->insert("abcde");
	e->insert("abcdef");
	printf("List after creation:\n");
	e->print();
	if (e->exists("abc"))
		cout << "Search for value abc: found" << endl;
	if (!e->exists("abcd"))
		cout << "Search for value abcd: not found" << endl;
	e->remove("abc");
	cout << "List after deletion of the element:" << endl;
	e->print();
	cout << endl;
	delete e;

	return 0;
}