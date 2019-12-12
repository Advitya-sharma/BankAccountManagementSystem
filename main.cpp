#include <bits/stdc++.h>
#include <fstream>
//#include "head.h"
using namespace std;
class Account
{
private:
    int balance;
    string name;
    int age;
    int account_number;

public:
    static int nextaccountnumber;
    Account(){};
    Account(string name, int age, int balance);
    int get_acc();
    string get_name();
    int get_age();
    int get_balance();
    friend ifstream &operator>>(ifstream &in, Account &acc);
    friend ofstream &operator<<(ofstream &of, Account &acc);
    friend ostream &operator<<(ostream &os, Account &acc);
};

int Account::nextaccountnumber = 0;
Account::Account(string name, int age, int balance)
{
    nextaccountnumber++;
    this->account_number = nextaccountnumber;
    cout << "next " << nextaccountnumber << endl;
    this->name = name;
    this->age = age;
    this->balance = balance;
};
int Account::get_acc()
{
    return account_number;
}

string Account::get_name() { return name; }
int Account::get_age() { return age; }
int Account::get_balance() { return balance; }

ifstream &operator>>(ifstream &in, Account &acc)
{
    in >> acc.account_number;
    in >> acc.name;
    in >> acc.age;
    in >> acc.balance;
    return in;
}
ofstream &operator<<(ofstream &of, Account &acc)
{
    of << acc.get_acc() << endl;
    of << acc.get_name() << endl;
    of << acc.get_age() << endl;
    of << acc.get_balance() << endl;

    return of;
}
ostream &operator<<(ostream &os, Account &acc)
{
    os << "Account number: " << acc.get_acc() << endl;
    os << "Name: " << acc.get_name() << endl;
    os << "Age :" << acc.get_age() << endl;
    os << "balance: " << acc.get_balance() << endl;

    return os;
}

class Bank
{
private:
    map<int, Account> accounts;

public:
    Bank();
    void open_account(string name, int age, int balance);
};

Bank::Bank()
{

    Account account;
    ifstream in("records.txt", ios::app);
    while (in >> account)
    {

        accounts.insert(pair<int, Account>(account.get_acc(), account));
        cout << account;
        Account::nextaccountnumber = account.get_acc();
        cout << "next " << Account::nextaccountnumber << endl;
    }

    in.close();
}

void Bank::open_account(string name, int age, int balance)
{
    Account acc(name, age, balance);
    accounts.insert(pair<int, Account>(acc.get_acc(), acc));
    ofstream ou("records.txt");
    map<int, Account>::iterator itr = accounts.begin();
    for (itr; itr != accounts.end(); itr++)
    {
        ou << itr->second;
    }
    ou.close();
}

int main()
{

    int n;
    Bank b;
    string name;
    cout << "Enter 1 for making account" << endl;
    cin >> n;
    switch (n)
    {
    case 1:
    {
        int age;
        int balance;
        cout << "enter name" << endl;
        cin >> name;
        cout << "enter age" << endl;
        cin >> age;
        cout << "enter balance" << endl;
        cin >> balance;
        b.open_account(name, age, balance);
    }
    }
}
