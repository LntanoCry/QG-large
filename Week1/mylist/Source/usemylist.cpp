#include <iostream>
#include<windows.h> /* Ϊ��ʹ��Sleep()���� */
#include "mylist.h"

void showMenu();  
void func2(); /* ��Ӧ��ͬcase�ڲ��ĺ��� */
void func3();
void func5();
void func6();
mylist<int> list;

int main()
{
	int t = 0;
	showMenu();
	cout << endl;
	cout << "������Ҫ���еĲ˵�����: " << endl;
	do
	{

		while (!(cin >> t))     /* ������������,��������� */
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "������Ҫ���еĲ˵�����: " << endl;
		}

		switch (t)
		{
		case 1:
			cout << "��������Ҫ��������������: (��δʵ��,Ĭ�ϴ���int����) " << endl;
			cout << endl;
			Sleep(1500);
			break;
		case 2:
			cout << endl;
			func2();
			break;
		case 3:
			cout << endl;
			func3();
			break;
		case 4:
			cout << endl;
			list.print();
			break;
		case 5:
			cout << endl;
			func5();
			break;
		case 6:
			cout << endl;
			func6();
			break;
		case 7:
			cout << endl;
			list.reverse();
			break;
		case 8:
			cout << endl;
			bool t;
			t = list.is_circled();
			if (t)
			{
				cout << "������ɻ�";
			}
			else
			{
				cout << "�������ɻ�";
			}
			break;
		case 9:
			cout << endl;
			cout << "����ʱ�����������,����뷨�͹��ܻ�δʵ��" << endl;
			cout << "����,��ż����,����,��ƽ��ֵ,����һЩ���ص�������ȵ�" << endl;
			cout << "��������Ľ�����.";
			break;
		case 0:
			system("cls");
			showMenu();
			break;
		default:
			cout << "�������." << endl;
		}
		
		cout << "������Ҫ���еĲ˵�����:" << endl;
	} while (1);

}

void showMenu()
{

	system("cls");
	cout << "\t����:LntanoCry" << endl;
	cout << "\t**************************��ӭʹ��**************************" << endl;
	cout << " \t **************************�˵�**************************" << endl;
	cout << "\t\t�����¹���: " << endl;
	cout << "\t\t-----1-----����һ��ֻ��ͷ����˫����" << endl;
	cout << "\t\t-----2-----ִ�в������" << endl;
	cout << "\t\t-----3-----ִ��ɾ������" << endl;
	cout << "\t\t-----4-----��ӡ˫������" << endl;
	cout << "\t\t-----5-----���ָ��ֵ" << endl;
	cout << "\t\t-----6-----���ָ������(�±�)" << endl;
	cout << "\t\t-----7-----��ת˫������" << endl;
	cout << "\t\t-----8-----�ж��Ƿ�ɻ�" << endl;
	cout << "\t\t-----9-----��ʵ�ֹ���" << endl;
	cout << "\t\t-----0-----����" << endl;

}

void func2()
{
	int a;
	int value;
	cout << "-----1-----�ӷǿ������ǰ�˲���" << endl;
	cout << "-----2-----������ĺ�˲��� " << endl;
	cout << "-----3-----���������ѡλ�ò���" << endl;
	cout << "����������Ҫִ�еĲ������:" << endl;
	cin >> a;
	cout << "������������ֵ: " << endl;
	cin >> value;
	switch (a)
	{
	case 1:
		list.push_front(value);
		break;
	case 2:
		list.push_back(value);
		break;
	case 3:
		cout << "����������������λ��:" << endl;
		int index;
		cin >> index;
		list.insert(index, value);
		break;
	default:
		return;
	}
	cout << endl;
}

void func3()
{
	int index, i;
	cout << "-----1-----ɾ��ͷ����ĵ�һ���ڵ�" << endl;
	cout << "-----2-----ɾ�����һ���ڵ�" << endl;
	cout << "-----3-----ɾ����ѡλ�ýڵ�" << endl;
	cout << "��������ִ�еĲ���:" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		list.pop_front();
		break;
	case 2:
		list.pop_back();
		break;
	case 3:
		cout << "����������ɾ���Ľڵ�: " << endl;
		cin >> index;
		list.Delete(index);
		break;
	default:
		return;
	}
}

void func5()
{
	int index, i;
	cout << "-----1-----�������һ��ֵ" << endl;
	cout << "-----2-----������������ֵ" << endl;
	cout << "����������Ҫִ�еĲ���: " << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "���һ��ֵ�� :" << list.back() << endl;
		break;
	case 2:
		cout << "��������: ";
		cin >> index;
		cout << "��������Ӧ��ֵΪ: " << list.get_val(index) << endl;
		break;
	default:
		return;
	}
}

void func6()
{
	int j, k;
	cout << "-----1-----���˫��������е�" << endl;
	cout << "-----2-----�����������ݵ��±�" << endl;
	cout << "��������Ҫѡ��Ĳ���:" << endl;
	cin >> j;
	switch (j)
	{
	case 1:
		k = list.findindex_mid();
		cout << "˫��������е�Ϊ:" << k << endl;
		break;
	case 2:
		cout << "��ûʵ�ֹ���,���Ǽ�." << endl;
		break;
	default:
		return;
	}
}