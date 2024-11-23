#include <iostream>
#include "Shape.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include <vector>

using namespace std;

int main() {
	vector<Shape*>v;
	cout << "그래픽 에디터입니다." << endl;
	while (true) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			cout << "선:1, 원:2, 사각형:3 >> ";
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
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
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