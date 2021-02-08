//Задание структуры "лист" для различных типов данных
template <typename type>
struct leaf
{
	type z;				//Элемент тапа type
	int h;				//Глубина
	struct leaf* r;		//Ссылка на структуру справа (и вниз)
	struct leaf* l;		//Ссылка на структуру слева (и вниз)
	struct leaf* d;		//Ссылка на структуру вверх
};

namespace Balanc
{
	//4 процедуры балансировки
	template <typename type>
	void Big_left_V(struct leaf<type>* P);
	template <typename type>
	void Big_right_V(struct leaf<type>* P);
	template <typename type>
	void Small_left_V(struct leaf<type>* P);
	template <typename type>
	void Small_right_V(struct leaf<type>* P);

	//Алгоритм выборки балансировки (разветвление по 4 процедурам балансировки)
	template <typename type>
	void Balanc(struct leaf<type>* P);
}

namespace proc
{
	//Вставка структуры в дерево (с последующими: пересчетом глубины и балансировкой)
	template <typename type>
	void insert_(struct leaf<type>* P, struct leaf<type>* q);

	//Наличие элемента в дереве
	template <typename type>
	bool exists_(struct leaf<type>* P, type z);

	//Поиск элемента дерева на замену удоляемого
	template <typename type>
	type sear_(struct leaf<type>* P);

	//Удаление элемента из дерева (с последующими: пересчетом глубины и балансировкой)
	template <typename type>
	void remove_(struct leaf<type>* P, type z);

	//Вывод дерева на экран
	template <typename type>
	void print_(struct leaf<type>* P);
}


//Класс дерева
template <typename type>
class SimpleTree
{
private:
	//Корень дерева
	struct leaf<type>* P;
	//Запуск удаления дерева
	void del(struct leaf<type>* P);
public:
	//Конструкторы и деструктор
	SimpleTree();
	SimpleTree(type z);
	//SimpleTree(type z);
	~SimpleTree();

	//Вставка элемента в дерево (с последующими: пересчетом глубины и балансировкой)
	void insert(type z);

	//Наличие элемента дереве
	bool exists(type z);

	//Удаление элемента из дерева (с последующими: пересчетом глубины и балансировкой)
	void remove(type z);

	//Вывод дерева на экран
	void print();
};