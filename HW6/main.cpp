#include <iostream>
#include "Shape.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include <vector>

using namespace std;

int main() {
	vector<Shape*>v;
	cout << "�׷��� �������Դϴ�." << endl;
	while (true) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			cout << "��:1, ��:2, �簢��:3 >> ";
			int type;
			cin >> type;
			if (type == 1)
				v.push_back(new Line());
			else if (type == 2)
				v.push_back(new Circle());
			else if (type == 3)
				v.push_back(new Rect());
		}
		else if (choice == 2) {
			cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
			int index;
			cin >> index;
			
			vector<Shape*>::iterator it = v.begin();
			it += index;
			it = v.erase(it);
		}
		else if (choice == 3) {
			for (int i = 0; i < v.size(); i++) {
				cout << i << ":";
				v[i]->paint();
			}
		}
		else if (choice == 4) {
			for (int i = 0; i < v.size(); i++) {
				delete v[i];
			}
			v.clear();
			break;
		}
	}
}