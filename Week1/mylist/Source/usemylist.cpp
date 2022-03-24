#include <iostream>
#include<windows.h> /* 为了使用Sleep()函数 */
#include "mylist.h"

void showMenu();  
void func2(); /* 对应不同case内部的函数 */
void func3();
void func5();
void func6();
mylist<int> list;

int main()
{
	int t = 0;
	showMenu();
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
			cout << "输入你想要创建的数据类型: (尚未实现,默认创造int类型) " << endl;
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
				cout << "该链表成环";
			}
			else
			{
				cout << "该链表不成环";
			}
			break;
		case 9:
			cout << endl;
			cout << "由于时间和能力有限,许多想法和功能还未实现" << endl;
			cout << "比如,奇偶调换,排序,求平均值,还有一些重载的运算符等等" << endl;
			cout << "将会持续改进更新.";
			break;
		case 0:
			system("cls");
			showMenu();
			break;
		default:
			cout << "输入错误." << endl;
		}
		
		cout << "请输入要进行的菜单操作:" << endl;
	} while (1);

}

void showMenu()
{

	system("cls");
	cout << "\t作者:LntanoCry" << endl;
	cout << "\t**************************欢迎使用**************************" << endl;
	cout << " \t **************************菜单**************************" << endl;
	cout << "\t\t有以下功能: " << endl;
	cout << "\t\t-----1-----创建一个只含头结点的双链表" << endl;
	cout << "\t\t-----2-----执行插入操作" << endl;
	cout << "\t\t-----3-----执行删除操作" << endl;
	cout << "\t\t-----4-----打印双向链表" << endl;
	cout << "\t\t-----5-----获得指定值" << endl;
	cout << "\t\t-----6-----获得指定索引(下标)" << endl;
	cout << "\t\t-----7-----反转双向链表" << endl;
	cout << "\t\t-----8-----判断是否成环" << endl;
	cout << "\t\t-----9-----待实现功能" << endl;
	cout << "\t\t-----0-----清屏" << endl;

}

void func2()
{
	int a;
	int value;
	cout << "-----1-----从非空链表的前端插入" << endl;
	cout << "-----2-----从链表的后端插入 " << endl;
	cout << "-----3-----从链表的自选位置插入" << endl;
	cout << "请输入你想要执行的插入操作:" << endl;
	cin >> a;
	cout << "输入你想插入的值: " << endl;
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
		cout << "输入你想插入的索引位置:" << endl;
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
	cout << "-----1-----删除头结点后的第一个节点" << endl;
	cout << "-----2-----删除最后一个节点" << endl;
	cout << "-----3-----删除自选位置节点" << endl;
	cout << "输入你想执行的操作:" << endl;
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
		cout << "请输入你想删除的节点: " << endl;
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
	cout << "-----1-----返回最后一个值" << endl;
	cout << "-----2-----根据索引返回值" << endl;
	cout << "请输入你想要执行的操作: " << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "最后一个值是 :" << list.back() << endl;
		break;
	case 2:
		cout << "输入索引: ";
		cin >> index;
		cout << "该索引对应的值为: " << list.get_val(index) << endl;
		break;
	default:
		return;
	}
}

void func6()
{
	int j, k;
	cout << "-----1-----获得双向链表的中点" << endl;
	cout << "-----2-----索引给出数据的下标" << endl;
	cout << "输入你想要选择的操作:" << endl;
	cin >> j;
	switch (j)
	{
	case 1:
		k = list.findindex_mid();
		cout << "双向链表的中点为:" << k << endl;
		break;
	case 2:
		cout << "还没实现哈哈,但是简单." << endl;
		break;
	default:
		return;
	}
}