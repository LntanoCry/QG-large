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
	cout << "请输入要进行的菜单操作: " << endl;
	do
	{

		while (!(cin >> t))     /* 处理不正常输入,清空输入流 */
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "请输入要进行的菜单操作: " << endl;
		}

		switch (t)
		{
		case 1:
			cout << "已成功创建一个空树." << endl;
			break;
		case 2:
			cout << "请输入你想要插入的值: " << endl;
			if (cin >> value)
			{
				tree.Insert(value);
				cout << "插入成功";
			}
			else
			{
				cout << "插入失败!";
			}
			cout << endl;
			break;
		case 3:
			cout << "请输入你想要删除的值: " << endl;
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
			cout << "请输入你想要查找的值: " << endl;
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
			cout << "输入错误." << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		ShowMenu();

		cout << "请输入要进行的菜单操作:" << endl;
	} while (1);

	return 0;
}

void ShowMenu()
{
	printf("\n");
	printf("\n");
	printf("\t\t******************欢迎使用该程序********************\n");
	printf("\t\t*----------------------菜单------------------------*\n");
	printf("\t\t*  (1)创建树            **   (2)插入操作           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (3)删除指定值        **   (4)前序遍历           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (5)中序遍历          **   (6)后序遍历           *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (7)层序遍历          **   (8)获得节点个数       *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (9)获得叶的个数      **   (10)查找是否有某数    *\n");
	printf("\t\t****************************************************\n");
	printf("\t\t*  (11)清空树           **   (12)退出程序          *\n");
	printf("\t\t****************************************************\n");
	printf("\t------------------------------------------------------------------\n");
}