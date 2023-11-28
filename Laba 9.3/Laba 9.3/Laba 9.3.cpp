#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

struct Students {
    string surname;
    string initials;
    int ap;
    int oop;
    int math;
    int english;
    int history;
};

void PrintHeader() {
    cout << "================================================================================"
        << endl;
    cout << "| №  | Прізвище | Ініціали | АП | ООП | Математика | Англійська мова | Історія |"
        << endl;
    cout << "================================================================================"
        << endl;
}

void Print(const Students* s, const int N) {
    PrintHeader();

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout
            << "| " << setw(9) << right << s[i].surname
            << "| " << setw(9) << right << s[i].initials
            << "| " << setw(3) << right << s[i].ap
            << "| " << setw(4) << right << s[i].oop
            << "| " << setw(11) << right << s[i].math
            << "| " << setw(16) << right << s[i].english
            << "| " << setw(8) << right << s[i].history << "|" << endl;
        cout << "--------------------------------------------------------------------------------";
        cout << endl;
    }
    cout << endl;
}

void ListOnly5(Students* s, int& N) {
    cout << "Список студентів які склали іспити тільки на «5»:" << endl;
    for (int i = 0; i < N; i++) {
        if (s[i].ap == 5
            && s[i].oop == 5
            && s[i].math == 5
            && s[i].english == 5
            && s[i].history == 5
            ) {
            cout << s[i].surname << ", ";
        }
    }
    cout << endl;
}

void ListHave3(Students* s, int& N) {
    cout << "Список студентів, що мають «3»:" << endl;
    for (int i = 0; i < N; i++) {
        if (s[i].ap == 3
            || s[i].oop == 3
            || s[i].math == 3
            || s[i].english == 3
            || s[i].history == 3
            ) {
            cout << s[i].surname << ", ";
        }
    }
    cout << endl;
}

void ListHave2(Students* s, int& N) {
    cout << "Список студентів, що мають «2»:" << endl;
    int count = 0;
    int t = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].ap == 2) {
            count++;
        }
        if (s[i].math == 2) {
            count++;
        }
        if (s[i].oop == 2) {
            count++;
        }
        if (s[i].english == 2) {
            count++;
        }
        if (s[i].history == 2) {
            count++;
        }
        if (count == 1) {
            cout << s[i].surname << "  " << endl;
        }
        if (count >= 2) {
            t++;
        }
        count = 0;
    }
}

void AddStudent(Students*& s, int& N) {
    Students* tmp = new Students[N + 1];
    for (int i = 0; i < N; i++) {
        tmp[i] = s[i];
    }
    cout << "Введіть прізвище студента: "; cin >> tmp[N].surname;
    cout << "Введіть ініціали студента: "; cin >> tmp[N].initials;
    cout << "Введіть оцінку з АП: "; cin >> tmp[N].ap;
    cout << "Введіть оцінку з ООП: "; cin >> tmp[N].oop;
    cout << "Введіть оцінку з Математики: "; cin >> tmp[N].math;
    cout << "Введіть оцінку з Англійської мови: "; cin >> tmp[N].english;
    cout << "Введіть оцінку з Історії: "; cin >> tmp[N].history;
    cout << endl;
    N++;

    delete[] s;
    s = tmp;
}

void DeleteStudent(Students*& s, int& N) {
    int k;
    cout << "Номер студента, якого треба вилучити: "; cin >> k;
    if (k < 1 || k > N) {
        cout << "Студента з таким номером не існує!" << endl;
        return;
    }
    Students* tmp = new Students[N - 1];
    for (int i = 0; i < k - 1; i++) {
        tmp[i] = s[i];
    }
    for (int i = k - 1; i < N - 1; i++) {
        tmp[i] = s[i + 1];
    }
    N--;

    delete[] s;
    s = tmp;
}

void EditStudent(Students* s, const int N) {
    int k;
    cout << "Номер студента, дані якого треба редагувати: "; cin >> k;
    if (k < 1 || k > N) {
        cout << "Студента з таким номером не існує!" << endl;
        return;
    }
    cout << "Введіть прізвище студента: "; cin >> s[k - 1].surname;
    cout << "Введіть ініціали студента: "; cin >> s[k - 1].initials;
    cout << "Введіть оцінку з АП: "; cin >> s[k - 1].ap;
    cout << "Введіть оцінку з ООП: "; cin >> s[k - 1].oop;
    cout << "Введіть оцінку з Математики: "; cin >> s[k - 1].math;
    cout << "Введіть оцінку з Англійської мови: "; cin >> s[k - 1].english;
    cout << "Введіть оцінку з Історії: "; cin >> s[k - 1].history;
    cout << endl;
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N = 4;
    Students* s = new Students[N];

    s[0] = { "Бабаєв", "Н.Ю", 5, 5, 5, 5, 5 };
    s[1] = { "Гринчук", "Т.В", 5, 5, 4, 4, 3 };
    s[2] = { "Левків", "Р.О", 2, 4, 5, 4, 3 };
    s[3] = { "Ткачук", "А.Р", 4, 2, 2, 4, 3 };

    int menu;
    do {
        cout << endl << endl;
        cout << "Виберіть дію: " << endl;
        cout << " [1] - Вивести таблицю всіх студентів" << endl;
        cout << " [2] - Список студентів, що склали  іспит на '5'" << endl;
        cout << " [3] - Список студентів, що мають '3'" << endl;
        cout << " [4] - Список студентів, що мають '2'" << endl;
        cout << " [5] - Додати студента" << endl;
        cout << " [6] - Вилучити студента" << endl;
        cout << " [7] - Редагувати інформацію про студента" << endl;
        cout << " [0] - Вихід з програми" << endl;
        cout << " Введіть значення команди: "; cin >> menu;
        cout << endl << endl;
        switch (menu) {
        case 1:
            Print(s, N);
            break;
        case 2:
            ListOnly5(s, N);
            break;
        case 3:
            ListHave3(s, N);
            break;
        case 4:
            ListHave2(s, N);
            break;
        case 5:
            AddStudent(s, N);
            break;
        case 6:
            DeleteStudent(s, N);
            break;
        case 7:
            EditStudent(s, N);
            break;
        case 0:
            break;

        }
    } while (menu != 0);

    delete[] s;
    return 0;
}