#include <iostream>
using namespace std;

class Data {
private:
    int* day;
    int* month;
    int* year;


public:
    
    Data() {
        day = new int;
        month = new int;
        year = new int;
        *day = *month = *year = 0; //Конструктор
    }

    Data(int userday, int usermonth, int useryear)
    {
        this->day = new int;
        this->month = new int;
        this->year = new int;

        *day = userday;
        *month = usermonth;
        *year = useryear;

    }
    
    Data(const Data& obj)

    {

        this->day = new int;
        this->day = obj.day;

        this->month = new int;
        this->month = obj.month;

        this->year = new int;
        this->year = obj.year;  //Конструктор копіювання 



    }
 
    ~Data() {
        delete[] day;
        delete[] month;
        delete[] year;  //Деструктор

    }
    
    void ShowData() {
        string  months[13] = 
        {
    {"Error"},
    {"January"},
    {"February"},
    {"March"},
    {"April"},
    {"May"},
    {"June"},
    {"July"},
    {"August"},
    {"September"},
    {"October"},
    {"November"},
    {"December"}
        };

        cout << *day << " ";

        cout << months[*month] << " ";

        cout << *year << " y.\n";


        if (*day < 10) {
            cout << '0';
        }
        cout << *day << ".";

        if (*month < 9) {
            cout << '0';
        }
        cout << *month << ".";

        cout << *year << endl;

    }
    
    int Getday() { return *day; }
    int Getmonth() { return *month; }
    int Getyear() { return *year; } // Функції, які повертають значення дня, місяця і року


    
    void Setday() {
        int newday;
        cout << "Enter day\n";
        cin >> newday;
        if (newday >= 0 && newday <= 31) {
            *day = newday;
        }
        else cout << "Wrong data\n"; //Функція зміни дня
    }
    void Setmonth() {
        int newmonth;
        cout << "Enter month\n";
        cin >> newmonth;
        if (newmonth >= 1 && newmonth < 13) {
            *month = newmonth;
        }
        else cout << "Wrong data\n"; //Функція зміни місяця
    }
    void Setyear() {
        int newyear;
        cout << "Enter year\n";
        cin >> newyear;
        if (newyear >= 0 && newyear < 9999) {
            *year = newyear;
        }
        else cout << "Wrong data\n"; //Функція зміни року

    }
};

int main() {
    int choice;
    Data Data1;
    Data Data2(11, 12, 2020);

    cout << "Hello \n Options:\n 1 -> Set new data\n 2 -> Show the data\n 3 -> To exit\n";
    do {
        cout << "Enter the number of needed option\n";
        cin >> choice;
        switch (choice) {
        case 1:Data1.Setday();
            Data1.Setmonth();
            Data1.Setyear();
            break;

        case 2: Data1.ShowData();
        }
    } while (choice != 3);

    return 0;
}