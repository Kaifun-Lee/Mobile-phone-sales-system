#ifndef _PHONE_H_
#define _PHONE_H_

#include <iostream>
#include <vector>
#include <map>
using namespace std;


// 手机
class Phone
{
private:
    vector<string> numbers, companys;
    vector<int> prices, quantitys;
    vector<string> date_of_productions;
public:
    void init_phoneList();
    bool findspe(string spe);
    void printfPhoneList();
    int checkBand(string band);
    int getIdxQuantity(int idx);
    int getBandPrice(string band);
    void subBandQuantity(string company);
    void addPhoneToList(string number, string company, int price, int quantity, string date_of_production);
    void changePhoneList_number(string company, string number);
    void changePhoneList_company(string company, string _company);
    void changePhoneList_price(string company, int price);
    void changePhoneList_quantity(string company, int quantity);
    void changePhoneList_date_of_production(string company, string date_of_production);
    void deletePhoneList(string company);
};


// 店员
class Worker
{
protected:
    vector<string> numbers, names, positions, phone_numbers, passwds;
    map<string, int> sales;
public:
    void init_workerList();
    bool findWorker(string name);
    void addSale(string name, int sale);
    bool log_in(string name, string passwd);
};


// 店长
class Manager : public Worker
{
public:
    bool manager_log_in(string name, string passwd);
    void addWorkerToList(string number, string name, string position, string phone_number, int sale);
    bool findspe(string name);
    void changeWorkerList_number(string name, string number);
    void changeWorkerList_name(string name, string _name);
    void changeWorkerList_position(string name, string position);
    void changeWorkerList_phonr_number(string name, string phone_number);
    void changeWorkerList_sale(string name, int sale);
    void deleteWorkerList(string name);
    void changeWorkerList_passwd(string name, string passwd);
};

#endif