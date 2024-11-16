#include <iostream>
#include <string>

// Максимальна кількість контактів

const int MAX_CONTACTS = 100;

using namespace std;

class Contact_Settings {
private:
    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    // Конструктор за замовчуванням
    Contact_Settings() : fullName(""), homePhone(""), workPhone(""), mobilePhone(""), additionalInfo("") {}

    // Конструктор за параметрами
    void setContact(const string& name, const string& home, const string& work, const string& mobile, const string& info) {
        fullName = name;
        homePhone = home;
        workPhone = work;
        mobilePhone = mobile;
        additionalInfo = info;
    }


    // Методи для отримання даних
    string getFullName() const { return fullName; }
    string getHomePhone() const { return homePhone; }
    string getWorkPhone() const { return workPhone; }
    string getMobilePhone() const { return mobilePhone; }
    string getAdditionalInfo() const { return additionalInfo; }

    // Функції для встановлення даних
    void setFullName(const string& fullName) { this->fullName = fullName; }
    void setHomePhone(const string& homePhone) { this->homePhone = homePhone; }
    void setWorkPhone(const string& workPhone) { this->workPhone = workPhone; }
    void setMobilePhone(const string& mobilePhone) { this->mobilePhone = mobilePhone; }
    void setAdditionalInfo(const string& additionalInfo) { this->additionalInfo = additionalInfo; }

    // Функція виведення інформації про контакт
    void display() const {
        cout << "ПІБ: " << fullName << endl;
        cout << "Домашній телефон: " << homePhone << endl;
        cout << "Робочий телефон: " << workPhone << endl;
        cout << "Мобільний телефон: " << mobilePhone <<endl;
        cout << "Додаткова інформація: " << additionalInfo <<endl;
        cout << endl;
    }
};

class PhoneBook {
private:
    Contact_Settings contacts[MAX_CONTACTS]; // Статичний масив контактів
    int contactCount; // Кількість контактів

public:
    PhoneBook() : contactCount(0) {} // Ініціалізація кількості контактів

    // Метод для додавання контакту
    int addContact(const Contact_Settings& contact) {
        if (contactCount < MAX_CONTACTS) {
            contacts[contactCount] = contact;
            contactCount++;
            return true;
        } else {
            cout << "Телефонна книга переповнена!n";
            return false;
        }
    }

    // Функція перевірки кількості контактів
    void displayContacts() const {
        if (contactCount == 0) {
            cout << "Телефонна книга порожня";
            return;
        }
        for (int i = 0; i < contactCount; ++i) {
            contacts[i].display();
            cout << "-----------------------n";
            cout << endl;
        }
    }
};


int main() {
    system("chcp 65001");

    PhoneBook phoneBook;

    // Перший контакт(через введеня користувача)
    Contact_Settings contact1;

    cout <<"-------- Введіть данні першого контакту --------" << endl;

    string name, home, work, mobile, info;

    cout <<"Введіть ПІБ: "<<"";
    getline(cin, name);

    cout <<"Введіть Домашній телефон: "<<"";
    getline(cin, home);

    cout <<"Введіть Робочий телефон: "<<"";
    getline(cin, work);

    cout <<"Введіть Мобільний телефон: "<<"";
    getline(cin, mobile);

    cout <<"Введіть Додаткову інформацію: "<<"";
    getline(cin, info);

    contact1.setFullName(name);
    contact1.setHomePhone(home);
    contact1.setWorkPhone(work);
    contact1.setMobilePhone(mobile);
    contact1.setAdditionalInfo(info);

    phoneBook.addContact(contact1);

    // Другий контакт (Введений вже в коді)
    Contact_Settings contact2;
    contact2.setFullName("Петро Петров");
    contact2.setHomePhone("234-567");
    contact2.setWorkPhone("890-123");
    contact2.setMobilePhone("456-789");
    contact2.setAdditionalInfo("Колега");

    phoneBook.addContact(contact2);

    // Виводимо всі контакти
    phoneBook.displayContacts();

}
