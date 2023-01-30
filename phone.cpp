#include "phone.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

// Phone
void Phone::init_phoneList()
{
	FILE* infile = fopen("手机信息.txt", "r");
	if (!infile) printf("手机信息初始化文件异常!!\n");
	char number[20], company[20];
	int price, quantity;
	char date_of_production[20];
	while (fscanf(infile, "%s%s%d%d%s", number, company, &price, &quantity, date_of_production) != EOF)
	{
		string nu = number;
		string com = company;
		string dop = date_of_production;
		numbers.push_back(nu);
		companys.push_back(com);
		prices.push_back(price);
		quantitys.push_back(quantity);
		date_of_productions.push_back(dop);
	}
	fclose(infile);

	printf("初始手机信息系统录入完成~\n");
}

bool Phone::findspe(string spe)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == spe)
		{
			//cout << numbers[i] << setw(4) << companys[i] << setw(4) << prices[i] << setw(4) << quantitys[i] << setw(4) << date_of_productions[i] << setw(4) << endl;
			printf("编号: %s\t厂商: %s\t价格: %d\t数量: %d\t生产日期: %s\n", numbers[i].c_str(), companys[i].c_str(), prices[i], quantitys[i], date_of_productions[i].c_str());
			return true;
		}
	}
	return false;
}

void Phone::printfPhoneList()
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		printf("编号: %s\t厂商: %s\t价格: %d\t数量: %d\t生产日期: %s\n", numbers[i].c_str(), companys[i].c_str(), prices[i], quantitys[i], date_of_productions[i].c_str());
	}
}

int Phone::checkBand(string band)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == band) return i;
	}
	return -1;
}

int Phone::getIdxQuantity(int idx)
{
	return quantitys[idx];
}

int Phone::getBandPrice(string band)
{
	int ans = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == band)
		{
			ans = prices[i];
			break;
		}
	}
	return ans;
}

void Phone::subBandQuantity(string company)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == company)
		{
			quantitys[i] --;
			break;
		}
	}
}

void Phone::addPhoneToList(string number, string company, int price, int quantity, string date_of_production)
{
	numbers.push_back(number);
	companys.push_back(company);
	prices.push_back(price);
	quantitys.push_back(quantity);
	date_of_productions.push_back(date_of_production);
}

void Phone::changePhoneList_number(string company, string number)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == company)
		{
			numbers[i] = number;
			break;
		}
	}
	return;
}

void Phone::changePhoneList_company(string company, string _company)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == company)
		{
			companys[i] = _company;
			break;
		}
	}
	return;
}

void Phone::changePhoneList_price(string company, int price)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == company)
		{
			prices[i] = price;
			break;
		}
	}
}

void Phone::changePhoneList_quantity(string company, int quantity)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == company)
		{
			quantitys[i] = quantity;
			break;
		}
	}
}

void Phone::changePhoneList_date_of_production(string company, string date_of_production)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (companys[i] == company)
		{
			date_of_productions[i] = date_of_production;
			break;
		}
	}
}

void Phone::deletePhoneList(string company)
{
	int i = 0;
	for (; i < numbers.size(); ++i)
	{
		if (companys[i] == company)
			break;
	}
	auto it = numbers.begin();
	numbers.erase(it + i);
	it = companys.begin();
	companys.erase(it + i);
	auto it_int = prices.begin();
	prices.erase(it_int + i);
	it_int = quantitys.begin();
	quantitys.erase(it_int + i);
	it = date_of_productions.begin();
	date_of_productions.erase(it + i);
}


// Worker
void Worker::init_workerList()
{
	FILE* infile = fopen("员工信息.txt", "r");
	if (!infile) printf("员工信息初始化文件异常!!\n");
	char number[20], name[20], position[20], phone_number[20];
	int sale;
	while (fscanf(infile, "%s%s%s%s%d", number, name, position, phone_number, &sale) != EOF)
	{
		string num = number;
		string na = name;
		string posi = position;
		string pn = phone_number;
		numbers.push_back(num);
		names.push_back(na);
		positions.push_back(posi);
		phone_numbers.push_back(pn);
		sales[na] = sale;
		passwds.push_back("123456");	// 所有工作人员的初始密码均为: "123456"
	}
	fclose(infile);

	printf("初始员工信息系统录入完成~\n");
}

bool Worker::findWorker(string name)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name) return true;
	}
	return false;
}

void Worker::addSale(string name, int sale)
{
	sales[name] += sale;
}

bool Worker::log_in(string name, string passwd)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			if (passwds[i] == passwd)
				return true;
			break;
		}
	}
	return false;
}


// Manager
bool Manager::manager_log_in(string name, string passwd)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			if (passwds[i] == passwd && positions[i] == "manager")
				return true;
			break;
		}
	}
	return false;
}

void Manager::addWorkerToList(string number, string name, string position, string phone_number, int sale)
{
	numbers.push_back(number);
	names.push_back(name);
	positions.push_back(position);
	phone_numbers.push_back(phone_number);
	sales[name] = sale;
}

bool Manager::findspe(string name)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			printf("编号: %s\t姓名: %s\t职位: %s\t电话: %s\t销售额: %d\n", numbers[i].c_str(), names[i].c_str(), positions[i].c_str(), phone_numbers[i].c_str(), sales[name]);
			return true;
		}
	}
	return false;
}

void Manager::changeWorkerList_number(string name, string number)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			numbers[i] = number;
			break;
		}
	}
}

void Manager::changeWorkerList_name(string name, string _name)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			names[i] = _name;
			break;
		}
	}
}

void Manager::changeWorkerList_position(string name, string position)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			positions[i] = position;
			break;
		}
	}
}

void Manager::changeWorkerList_phonr_number(string name, string phone_number)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			phone_numbers[i] = phone_number;
			break;
		}
	}
}

void Manager::changeWorkerList_sale(string name, int sale)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			sales[name] = sale;
			break;
		}
	}
}

void Manager::deleteWorkerList(string name)
{
	int i = 0;
	for (; i < numbers.size(); ++i)
	{
		if (names[i] == name)
			break;
	}
	auto it = numbers.begin();
	numbers.erase(it + i);
	it = names.begin();
	names.erase(it + i);
	it = positions.begin();
	positions.erase(it + i);
	it = phone_numbers.begin();
	phone_numbers.erase(it + i);
	sales[name] = 0;
}

void Manager::changeWorkerList_passwd(string name, string passwd)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (names[i] == name)
		{
			passwds[i] = passwd;
			break;
		}
	}
}
