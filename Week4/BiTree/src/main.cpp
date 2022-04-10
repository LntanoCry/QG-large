#include <iostream>
#include "BiTree.cpp"

using namespace std;

void ShowMenu();
int t = 0;
int value;
BiTree<int> tree;

int main()
{

	ShowMenu();
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
			cout << "�ѳɹ�����һ������." << endl;
			break;
		case 2:
			cout << "����������Ҫ�����ֵ: " << endl;
			if (cin >> value)
			{
				tree.Insert(value);
				cout << "����ɹ�";
			}
			else
			{
				cout << "����ʧ��!";
			}
			cout << endl;
			break;
		case 3:
			cout << "����������Ҫɾ����ֵ: " << endl;
			cin >> value;
			tree.DeleteNode(value);
			cout << endl;
			break;
		case 4:
			tree.PreTraver();
			break;
		case 5:
			tree.MidTraver();
			break;
		case 6:
			tree.BehTraver();
			break;
		case 7:
			tree.LevelTraver();
			break;
		case 8:
			tree.NodeCount();
			break;
		case 9:
			tree.LeafCount();
			break;
		case 10:
			cout << "����������Ҫ���ҵ�ֵ: " << endl;
			cin >> value;
			tree.Search(value);
			break;
		case 11:
			tree.Destroytree();
			break;
		case 12:
			exit(1);
			break;
		default:
			cout << "�������." << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		ShowMenu();

		cout << "������Ҫ���еĲ˵�����:" << endl;
	} while (1);

	return 0;
}

void ShowMenu()
{
	printf("\n");
	printf("\n");
	printf("\t\t******************��ӭʹ�øó���********************\n");
	printf("\t\t*----------------------�˵�------------------------*\n");
	printf("\t\t*  (1)������            **   (2)�������           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (3)ɾ��ָ��ֵ        **   (4)ǰ�����           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (5)�������          **   (6)�������           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (7)�������          **   (8)��ýڵ����       *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (9)���Ҷ�ĸ���      **   (10)�����Ƿ���ĳ��    *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (11)�����           **   (12)�˳�����          *\n");
	printf("\t\t****************************************************\n");
	printf("\t------------------------------------------------------------------\n");
}