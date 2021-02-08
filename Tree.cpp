#include <iostream>
#include "Tree.h"

using namespace std;

//Реализация процедур балансировки
template <typename type>
void Balanc::Big_left_V(struct leaf<type>* P)
{
	type i;
	struct leaf<type> *q, *g;
	q = P->l;
	P->l = P->r->l;
	g = P->l->l;
	P->l->l = q;              //поставил A
	P->r->l = P->r->l->r;     //поставил C
	P->l->r = g;              //поставил B
	i = P->z;
	P->z = P->l->z;           //записал c
	P->l->z = i;              //записал a
	{
		if ((P->l->l != NULL) && (P->l->r != NULL))
		{
			P->l->l->d = P->l;
			if (P->l->l->h > P->l->r->h) P->l->h = P->l->l->h + 1;
			else P->l->h = P->l->r->h + 1;
		}
		if ((P->l->l != NULL) && (P->l->r == NULL))
		{
			P->l->l->d = P->l;
			P->l->h = P->l->l->h + 1;
		}
		if ((P->l->l == NULL) && (P->l->r == NULL)) P->l->h = 1;
	}
	{
		if ((P->r->l != NULL) && (P->r->r != NULL))
		{
			P->r->l->d = P->r;
			if (P->r->l->h > P->r->r->h) P->r->h = P->r->l->h + 1;
			else P->r->h = P->r->r->h + 1;
		}
		if ((P->r->l == NULL) && (P->r->r != NULL)) P->r->h = P->r->r->h + 1;
		if ((P->r->l == NULL) && (P->r->r == NULL)) P->r->h = 1;
	}
	P->l->d = P;
	if (P->l->h > P->r->h) P->h = P->l->h + 1;
	else P->h = P->r->h + 1;
}
template <typename type>
void Balanc::Big_right_V(struct leaf<type>* P)
{
	type i;
	struct leaf<type> *q, *g;
	q = P->r;
	P->r = P->l->r;
	g = P->r->r;
	P->r->r = q;              //поставил A
	P->l->r = P->l->r->l;     //поставил C
	P->r->l = g;              //поставил B
	i = P->z;
	P->z = P->r->z;           //записал c
	P->r->z = i;              //записал a
	{
		if ((P->r->r != NULL) && (P->r->l != NULL))
		{
			P->r->r->d = P->r;
			if (P->r->r->h > P->r->l->h) P->r->h = P->r->r->h + 1;
			else P->r->h = P->r->l->h + 1;
		}
		if ((P->r->r != NULL) && (P->r->l == NULL))
		{
			P->r->r->d = P->r;
			P->r->h = P->r->r->h + 1;
		}
		if ((P->r->r == NULL) && (P->r->l == NULL)) P->r->h = 1;
	}
	{
		if ((P->l->r != NULL) && (P->l->l != NULL))
		{
			P->l->r->d = P->l;
			if (P->l->r->h > P->l->l->h) P->l->h = P->l->r->h + 1;
			else P->l->h = P->l->l->h + 1;
		}
		if ((P->l->r == NULL) && (P->l->l != NULL)) P->l->h = P->l->l->h + 1;
		if ((P->l->r == NULL) && (P->l->l == NULL)) P->l->h = 1;
	}
	P->r->d = P;
	if (P->r->h > P->l->h) P->h = P->r->h + 1;
	else P->h = P->l->h + 1;
}
template <typename type>
void Balanc::Small_left_V(struct leaf<type>* P)
{
	type i;
	struct leaf<type> *q;
	q = P->l;
	P->l = P->r;
	P->r = P->l->r;      //поставил C
	P->l->r = P->l->l;   //поставил B
	P->l->l = q;         //поставил A
	i = P->z;
	P->z = P->l->z;      //записал b
	P->l->z = i;         //записал a
	{
		if ((P->l->l != NULL) && (P->l->r != NULL))
		{
			P->l->l->d = P->l;
			if (P->l->l->h > P->l->r->h) P->l->h = P->l->l->h + 1;
			else P->l->h = P->l->r->h + 1;
		}
		if ((P->l->l == NULL) && (P->l->r != NULL)) P->l->h = P->l->r->h + 1;
		if ((P->l->l != NULL) && (P->l->r == NULL))
		{
			P->l->l->d = P->l;
			P->l->h = P->l->l->h + 1;
		}
		if ((P->l->l == NULL) && (P->l->r == NULL)) P->l->h = 1;
	}
	P->r->d = P;
	P->l->d = P;
	if (P->l->h > P->r->h) P->h = P->l->h + 1;
	else P->h = P->r->h + 1;
}
template <typename type>
void Balanc::Small_right_V(struct leaf<type>* P)
{
	type i;
	struct leaf<type> *q;
	q = P->r;
	P->r = P->l;
	P->l = P->r->l;      //поставил C
	P->r->l = P->r->r;   //поставил B
	P->r->r = q;         //поставил A
	i = P->z;
	P->z = P->r->z;      //записал b
	P->r->z = i;         //записал a
	{
		if ((P->r->r != NULL) && (P->r->l != NULL))
		{
			P->r->r->d = P->r;
			if (P->r->r->h > P->r->l->h) P->r->h = P->r->r->h + 1;
			else P->r->h = P->r->l->h + 1;
		}
		if ((P->r->r == NULL) && (P->r->l != NULL)) P->r->h = P->r->l->h + 1;
		if ((P->r->r != NULL) && (P->r->l == NULL))
		{
			P->r->r->d = P->r;
			P->r->h = P->r->r->h + 1;
		}
		if ((P->r->r == NULL) && (P->r->l == NULL)) P->r->h = 1;
	}
	P->l->d = P;
	P->r->d = P;
	if (P->r->h > P->l->h) P->h = P->r->h + 1;
	else P->h = P->l->h + 1;
}

//Реализация алгоритма выборки балансировки
template <typename type>
void Balanc::Balanc(struct leaf<type>* P)
{
	if ((P->l != NULL) && (P->r != NULL))
	{
		if (P->l->h - P->r->h == 2)
		{
			if ((P->l->r != NULL) && (P->l->l != NULL))
				if (P->l->r->h > P->l->l->h)
				{
					Big_right_V(P);
					return;
				}
				else
				{
					Small_right_V(P);
					return;
				}
			if ((P->l->r != NULL) && (P->l->l == NULL))
			{
				Big_right_V(P);
				return;
			}
			if ((P->l->r == NULL) && (P->l->l != NULL))
			{
				Small_right_V(P);
				return;
			}
		}
		if (P->r->h - P->l->h == 2)
		{
			if ((P->r->l != NULL) && (P->r->r != NULL))
				if (P->r->l->h > P->r->r->h)
				{
					Big_left_V(P);
					return;
				}
				else
				{
					Small_left_V(P);
					return;
				}
			if ((P->r->l != NULL) && (P->r->r == NULL))
			{
				Big_left_V(P);
				return;
			}
			if ((P->r->l == NULL) && (P->r->r != NULL))
			{
				Small_left_V(P);
				return;
			}
		}
	}
	if ((P->l != NULL) && (P->r == NULL))
	{
		if ((P->l->r != NULL) && (P->l->l != NULL))
			if (P->l->r->h > P->l->l->h)
			{
				Big_right_V(P);
				return;
			}
			else
			{
				Small_right_V(P);
				return;
			}
		if ((P->l->r != NULL) && (P->l->l == NULL))
		{
			Big_right_V(P);
			return;
		}
		if ((P->l->r == NULL) && (P->l->l != NULL))
		{
			Small_right_V(P);
			return;
		}
	}
	if ((P->l == NULL) && (P->r != NULL))
	{
		if ((P->r->l != NULL) && (P->r->r != NULL))
			if (P->r->l->h > P->r->r->h)
			{
				Big_left_V(P);
				return;
			}
			else
			{
				Small_left_V(P);
				return;
			}
		if ((P->r->l != NULL) && (P->r->r == NULL))
		{
			Big_left_V(P);
			return;
		}
		if ((P->r->l == NULL) && (P->r->r != NULL))
		{
			Small_left_V(P);
			return;
		}
	}
}


//Вставка структуры в дерево (с последующими: пересчетом глубины и балансировкой)
template <typename type>
void proc::insert_(struct leaf<type>* P, struct leaf<type>* q)
{
	if (q->z < P->z)
		if (P->l == NULL)
		{
			P->l = q;
			q->d = P;
		}
		else insert_(P->l, q);
	else
		if (P->r == NULL)
		{
			P->r = q;
			q->d = P;
		}
		else insert_(P->r, q);
	//Блок пересчёта глубины и балансировки
	if ((P->l != NULL) && (P->r != NULL))
		if (P->l->h > P->r->h)  P->h = P->l->h + 1;
		else  P->h = P->r->h + 1;
	else if ((P->l != NULL) && (P->r == NULL)) P->h = P->l->h + 1;
	else P->h = P->r->h + 1;
	Balanc::Balanc(P);
};

//Наличие элемента в дереве
template <typename type>
bool proc::exists_(struct leaf<type>* P, type z)
{
	bool b = false;
	if (P->z == z) b = true;
	else
	{
		if ((z < P->z) && (P->l != NULL)) b = b + exists_(P->l, z);
		if ((z >= P->z) && (P->r != NULL)) b = b + exists_(P->r, z);
	}
	return b;
}

//Поиск элемента дерева на замену удоляемого
template <typename type>
type proc::sear_(struct leaf<type>* P)
{
	type x;
	if (P->l != NULL) x = sear_(P->l);
	else
	{
		x = P->z;
		if (P->r != NULL)
		{
			P->d->l = P->r;
			P->r->d = P->d;
		}
		else P->d->l = NULL;
		delete P;
		P = NULL;
	}
	//Блок пересчёта глубины и балансировки
	if (P != NULL) {
		if ((P->l != NULL) && (P->r != NULL))
			if (P->l->h > P->r->h)  P->h = P->l->h + 1;
			else  P->h = P->r->h + 1;
		else if ((P->l != NULL) && (P->r == NULL)) P->h = P->l->h + 1;
		else if ((P->l == NULL) && (P->r != NULL)) P->h = P->r->h + 1;
		else P->h = 1;
		Balanc::Balanc(P);
	}
	return x;
}

//Удаление элемента из дерева (с последующими: пересчетом глубины и балансировкой)
template <typename type>
void proc::remove_(struct leaf<type>* P, type z)
{
	if (P->z == z)
	{
		if ((P->l == NULL) && (P->r == NULL))
		{
			if (P->d->z > z) {
				P->d->l = NULL;
				delete P;
				P = NULL;
			}
			else {
				P->d->r = NULL;
				delete P;
				P = NULL;
			}
		}
		else
		{
			type x;
			if ((P->r != NULL) && (P->r->l != NULL)) x = sear_(P->r);
			else if ((P->r != NULL) && (P->r->l == NULL))
			{
				x = P->r->z;
				struct leaf<type>* y = P->r;
				P->r = P->r->r;
				if (P->r != NULL) P->r->d = P;
				delete y;
			}
			else if (P->l != NULL)
			{
				x = P->l->z;
				struct leaf<type>* y = P->l;
				P->l = NULL;
				delete y;
			}
			P->z = x;
		}
	}
	else if ((P->r != NULL) && (P->z < z)) remove_(P->r, z);
	else if (P->l != NULL) remove_(P->l, z);
	//Блок пересчёта глубины и балансировки
	if (P != NULL) {
		if ((P->l != NULL) && (P->r != NULL))
			if (P->l->h > P->r->h)  P->h = P->l->h + 1;
			else  P->h = P->r->h + 1;
		else if ((P->l != NULL) && (P->r == NULL)) P->h = P->l->h + 1;
		else if ((P->l == NULL) && (P->r != NULL)) P->h = P->r->h + 1;
		else P->h = 1;
		Balanc::Balanc(P);
	}
}

//Вывод дерева на экран
template <typename type>
void proc::print_(struct leaf<type>* P)
{
	cout << "(z= " << P->z << " Lz= ";
	if (P->l != NULL) cout << P->l->z << "; Rz= ";
	else cout << "-; Rz= ";
	if (P->r != NULL) cout << P->r->z << "; Dz= ";
	else cout << "-; Dz= ";
	if (P->d != NULL) cout << P->d->z << "; H= ";
	else cout << "-; H= ";
	cout << P->h << ")" << endl;
	if (P->l != NULL) print_(P->l);
	if (P->r != NULL) print_(P->r);
}


//Запуск удаления дерева
template <typename type>
void SimpleTree<type>::del(struct leaf<type>* P) {
	if (P->l != NULL) del(P->l);
	if (P->r != NULL) del(P->r);
	delete P;
}

//Конструкторы и деструктор
template <typename type>
SimpleTree<type>::SimpleTree() {
	P = NULL;
}

template <typename type>
SimpleTree<type>::SimpleTree(type z) {
	P = new struct leaf<type>;
	P->z = z;
	P->l = NULL;
	P->r = NULL;
	P->d = NULL;
}
template <typename type>
SimpleTree<type>::~SimpleTree() {
	if (P != NULL) del(P);
};

//Вставка элемента в дерево (с последующими: пересчетом глубины и балансировкой)
template <typename type>
void SimpleTree<type>::insert(type z) {
	struct leaf<type>* q = new struct leaf<type>;
	q->z = z;
	q->h = 1;
	q->l = NULL;
	q->r = NULL;
	q->d = NULL;
	if (P != NULL) proc::insert_(P, q);
	else P = q;
}

//Наличие элемента дереве
template <typename type>
bool SimpleTree<type>::exists(type z) {
	if (P == NULL) return false;
	else return proc::exists_(P, z);
}

//Удаление элемента из дерева (с последующими: пересчетом глубины и балансировкой)
template <typename type>
void SimpleTree<type>::remove(type z) {
	if (P == NULL) return;
	if ((P->z == z) && (P->l == NULL) && (P->r == NULL)) {
		delete P;
		P = NULL;
	}
	else proc::remove_(P, z);
}

//Вывод дерева на экран
template <typename type>
void  SimpleTree<type>::print() {
	if (P == NULL)
		cout << "Tree empty" << endl;
	else proc::print_(P);
}

template SimpleTree<int>;
template SimpleTree<double>;
template SimpleTree<string>;