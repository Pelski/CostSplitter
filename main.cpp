#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <list>
using namespace std;

typedef struct User {
    int id;
    string name;
    double deposit;
    double debt;
} usersStruct;

list<User> users;
double totalCost = 0.0f;
int longestName = 0;

void clearDisplay() {
    system("clear");
    cout << " ---=== COST SPLITTER ===---" << endl << endl;
}

int menuHandle() {
    clearDisplay();
    int choosen = 0;
    cout << " 1. Dodaj osobe" << endl;
    cout << " 2. Ustal kwote" << endl;
    cout << " 3. Wyswietl osoby" << endl;
    cout << " 4. Wyjdz" << endl;
    cout << "    Wartosc: ";
    cin >> choosen;
    return choosen;
}

void addUser() {
    clearDisplay();
    User userTMP;
    cout << " Imie: ";
    cin >> userTMP.name;
    cout << " Wklad: ";
    cin >> userTMP.deposit;
    users.push_back({ (int)users.size() + 1, userTMP.name, userTMP.deposit, 0.0f });
}

void setTotalCost() {
    clearDisplay();
    cout << " Kwota: ";
    cin >> totalCost;
}

void reloadData() {
    double costTMP = totalCost / (int)users.size();
    for (list<User>::iterator it = users.begin(); it != users.end(); it++) {
        it->debt = costTMP - it->deposit;
        if (it->name.length() > longestName) {
            longestName = (int)it->name.length();
        }
    }
}

double doublePrecision(double value) {
    return floor(value * 5 + 0.5) / 5;
}

void showUsers() {
    clearDisplay();
    reloadData();
    cout << " Lista osob:" << endl;
    cout << " Kwota do podzialu: " << totalCost << "zl" << endl;
    for (list<User>::iterator it = users.begin(); it != users.end(); it++) {
        cout << "  " << setw(longestName) << it->name
        << " -- wklad: " << setprecision(5) << floor(it->deposit) << "zl";
        if (it->debt == 0) {
            cout << " -- nic nie jest winien/winna" << endl;
        } else if (it->debt > 0) {
            cout << " -- winien: " << setprecision(5) << floor(doublePrecision(it->debt)) << "zl" << endl;
        } else {
            cout << " -- nadplata: " << setprecision(5) << floor(abs(doublePrecision(it->debt))) << "zl" << endl;
        }
    }
    cout << " Wpisz dowolny znak aby wrocic do menu: ";
    char tmp;
    cin >> tmp;
}

int main() {
    do {
        int menuItem = menuHandle();
        switch (menuItem) {
            case 1:
                addUser();
                break;
            case 2:
                setTotalCost();
                break;
            case 3:
                showUsers();
                break;
            default:
                clearDisplay();
                cout << " Do zobaczenia... Milego dnia!" << endl << endl;
                return 0;
        }
    } while(true);
    return 0;
}
