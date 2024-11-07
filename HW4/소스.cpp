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

    virtual void print(int pages) = 0; // ���� ���� �Լ�
    virtual void showStatus() = 0;
};

class InkJetPrinter : public Printer {
    int availableInk;

public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    void print(int pages) override {
        if (availableCount < pages || availableInk < pages) {
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            availableCount -= pages;
            availableInk -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
    }

    void showStatus() override {
        cout << model << ", " << manufacturer << ", ���� ���� " << availableCount
            << "��, ���� ��ũ " << availableInk << endl;
    }
};

class LaserPrinter : public Printer {
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    void print(int pages) override {
        if (availableCount < pages || availableToner < pages) {
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            availableCount -= pages;
            availableToner -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
    }

    void showStatus() override {
        cout << model << ", " << manufacturer << ", ���� ���� " << availableCount
            << "��, ���� ��� " << availableToner << endl;
    }
};

int main() {
    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);

    int choice, pages;
    while (true) {
        cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
        inkjet.showStatus();
        laser.showStatus();

        cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
        cin >> choice >> pages;

        if (choice == 1) {
            inkjet.print(pages);
        }
        else if (choice == 2) {
            laser.print(pages);
        }
        else {
            cout << "�߸��� �����Դϴ�." << endl;
            continue;
        }

        char cont;
        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
        cin >> cont;
        if (cont == 'n' || cont == 'N') break;
    }

    return 0;
}
