//������� ��������� "����" ��� ��������� ����� ������
template <typename type>
struct leaf
{
	type z;				//������� ���� type
	int h;				//�������
	struct leaf* r;		//������ �� ��������� ������ (� ����)
	struct leaf* l;		//������ �� ��������� ����� (� ����)
	struct leaf* d;		//������ �� ��������� �����
};

namespace Balanc
{
	//4 ��������� ������������
	template <typename type>
	void Big_left_V(struct leaf<type>* P);
	template <typename type>
	void Big_right_V(struct leaf<type>* P);
	template <typename type>
	void Small_left_V(struct leaf<type>* P);
	template <typename type>
	void Small_right_V(struct leaf<type>* P);

	//�������� ������� ������������ (������������ �� 4 ���������� ������������)
	template <typename type>
	void Balanc(struct leaf<type>* P);
}

namespace proc
{
	//������� ��������� � ������ (� ������������: ���������� ������� � �������������)
	template <typename type>
	void insert_(struct leaf<type>* P, struct leaf<type>* q);

	//������� �������� � ������
	template <typename type>
	bool exists_(struct leaf<type>* P, type z);

	//����� �������� ������ �� ������ ����������
	template <typename type>
	type sear_(struct leaf<type>* P);

	//�������� �������� �� ������ (� ������������: ���������� ������� � �������������)
	template <typename type>
	void remove_(struct leaf<type>* P, type z);

	//����� ������ �� �����
	template <typename type>
	void print_(struct leaf<type>* P);
}


//����� ������
template <typename type>
class SimpleTree
{
private:
	//������ ������
	struct leaf<type>* P;
	//������ �������� ������
	void del(struct leaf<type>* P);
public:
	//������������ � ����������
	SimpleTree();
	SimpleTree(type z);
	//SimpleTree(type z);
	~SimpleTree();

	//������� �������� � ������ (� ������������: ���������� ������� � �������������)
	void insert(type z);

	//������� �������� ������
	bool exists(type z);

	//�������� �������� �� ������ (� ������������: ���������� ������� � �������������)
	void remove(type z);

	//����� ������ �� �����
	void print();
};