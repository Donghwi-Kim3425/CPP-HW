#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount)
        : model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {}

    virtual void print(int pages) = 0; // 순수 가상 함수
    virtual void showStatus() = 0;
};

class InkJetPrinter : public Printer {
    int availableInk;

public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    void print(int pages) override {
        if (availableCount < pages || availableInk < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            availableCount -= pages;
            availableInk -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    void showStatus() override {
        cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount
            << "장, 남은 잉크 " << availableInk << endl;
    }
};

class LaserPrinter : public Printer {
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    void print(int pages) override {
        if (availableCount < pages || availableToner < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            availableCount -= pages;
            availableToner -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    void showStatus() override {
        cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount
            << "장, 남은 토너 " << availableToner << endl;
    }
};

int main() {
    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

    int choice, pages;
    while (true) {
        cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
        inkjet.showStatus();
        laser.showStatus();

        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> choice >> pages;

        if (choice == 1) {
            inkjet.print(pages);
        }
        else if (choice == 2) {
            laser.print(pages);
        }
        else {
            cout << "잘못된 선택입니다." << endl;
            continue;
        }

        char cont;
        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> cont;
        if (cont == 'n' || cont == 'N') break;
    }

    return 0;
}
