#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <vector>
#include <map>
#include "phone.h"

using namespace std;

string chose_identity()
{
	int num;
	scanf("%d", &num);
	string res = "";
	if (num == 1) res = "manager";
	else if (num == 2) res = "worker";
	else if (num == 3) res = "customer";
	else if (num == 4) res = "break";
	else res = "error";
	return res;
}

void init()
{
	printf("****************************************\n");
	printf("     Welcome to use our system~\n\n");
	printf("\nPlease chose your identity:\n");
	printf("1. Manager\t2.Worker\t3.Customer\t4.退出\n\n");
	printf("Please input your identity to log in (input:1/2/3/4): ");
}

int main()
{
	Phone sy;
	Phone* pPhone = &sy;
	Worker su;
	Worker* pWorker = &su;
	Manager ma;
	Manager* pManager = &ma;

	pPhone->init_phoneList();
	pManager->init_workerList();
	printf("\n欢迎使用，两秒钟后将自动跳转登录界面~\n");
	//_sleep(2000);

	while (true)
	{
		int flag = 0;	// 是否退出
		system("cls");
		init();
		while (true)
		{
			int flg2 = 0;	// 是否退出 manager 登录系统
			string identity = chose_identity();
			/* 店长 begin */
			int flg1 = 0;	// 是否返回 manager 选择登录系统界面
			if (identity == "manager")
			{
				// 店长也应具备登录手机管理系统的功能

				system("cls");
				printf("****************************************\n");
				printf("          Manage system\n\n");
				printf("1.手机信息系统\t2.员工管理系统\t3.取消登录\n");
				printf("请输入您需要登录的系统(1/2/3): ");
				int sys;
				while (cin >> sys)
				{
					/* 登录手机信息系统 begin */
					if (sys == 1)
					{
						int flag2 = 0;	// 是否需要重新输入密码
						int flag3 = 0;	// 是否需要继续尝试登录员工系统
						int f5 = 0;
						printf("请输入您的账号(姓名拼音): ");
						string name, passwd;
						while (cin >> name)
						{
							if (!flag2)
							{
								printf("请输入您的密码(初始密码或修改后的密码): ");
								flag2 = 1;
							}
							else
							{
								printf("请重新输入您的密码(初始密码或修改后的密码): ");
							}
							cin >> passwd;
							/* 登录成功 begin */
							if (pManager->log_in(name, passwd))	// 登录成功
							{
								printf("登录成功!!  两秒钟后即将跳转至手机信息管理功能菜单\n");
								_sleep(2000);
								system("cls");

								/* Main_Menu begin */
								printf("\t\tMain Menu\n\n");
								printf("\t1.输入手机信息\t2.修改手机信息\n\t3.删除手机信息\t4.查询手机信息\n\t5.退出\n\n");
								printf("请输入您的需求(1/2/3/4/5): ");
								string num;
								while (cin >> num)
								{
									if (num == "1")
									{
										printf("请输入您需要添加的手机的详细信息: ");
										string number, company;
										int price, quantity;
										string date_of_production;
										printf("请输入编号: ");
										cin >> number;
										printf("请输入生产厂家: ");
										cin >> company;
										printf("请输入价格: ");
										cin >> price;
										printf("请输入数量: ");
										cin >> quantity;
										printf("请输入生产日期: ");
										cin >> date_of_production;
										pPhone->addPhoneToList(number, company, price, quantity, date_of_production);
										printf("信息添加成功\n请继续输入您的需求(1/2/3/4/5): ");
									}
									else if (num == "2")
									{
										// 限制条件：只允许输入生产厂家来匹配是否可以修改
										printf("请输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
										string company;
										int f = 0;	// 是否完成修改
										while (cin >> company)
										{
											if (pPhone->findspe(company))
											{
												printf("请输入需要修改的手机的具体信息(number、company、price...): ");
												/* number、company、price、quantity、date_of_production */
												string str;
												while (cin >> str)
												{
													if (str == "number")
													{
														printf("请输入您需要修改成的编号(1001、1002、1003...): ");
														string number; cin >> number;
														pPhone->changePhoneList_number(company, number);
														f = 1;
													}
													else if (str == "company")
													{
														printf("请输入您需要修改成的生产厂家(huawei、mi、apple...): ");
														string _company; cin >> _company;
														pPhone->changePhoneList_company(company, _company);
														f = 1;
													}
													else if (str == "price")
													{
														printf("请输入您需要修改成的价格(2000、3000、8000): ");
														int price; cin >> price;
														pPhone->changePhoneList_price(company, price);
														f = 1;
													}
													else if (str == "quantity")
													{
														printf("请输入您需要修改成的库存数量(100、300、800): ");
														int quantity; cin >> quantity;
														pPhone->changePhoneList_quantity(company, quantity);
														f = 1;
													}
													else if (str == "date_of_production")
													{
														printf("请输入您需要修改成的生产日期(2001.3.4、2023.10.09、2010.1.1): ");
														string date_of_production; cin >> date_of_production;
														pPhone->changePhoneList_date_of_production(company, date_of_production);
														f = 1;
													}
													else
													{
														printf("您的输入存在错误，请您检查后重试!\n请重新输入需要修改的手机的具体信息(number、company、price...): ");
													}
													if (f)
													{
														printf("手机信息修改成功~\n请继续输入您的需求(1/2/3/4/5): ");
														break;
													}
												}
											}
											else
											{
												printf("需要修改的手机的生产厂商输入有误，请重新输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
											}
											if (f) break;
										}
									}
									else if (num == "3")
									{
										// 限制条件：只允许输入生产厂家来匹配是否可以删除
										printf("请输入您需要删除的手机的生产厂家名(huawei、mi、apple、oppo...): ");
										string company;
										int f = 0;	// 是否删除成功
										while (cin >> company)
										{
											if (pPhone->findspe(company))
											{
												pPhone->deletePhoneList(company);
												printf("对应手机信息删除成功!\n请继续输入您的需求(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("需要删除的手机的生产厂商输入有误，请重新输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
											}
											if (f) break;
										}
									}
									else if (num == "4")
									{
										// 限制条件：只允许输入生产厂家来匹配是否可以查询
										printf("请输入您需要查询的手机的生产厂家名(huawei、mi、apple、oppo...): ");
										string company;
										int f = 0;	// 是否查询成功
										while (cin >> company)
										{
											if (pPhone->findspe(company))
											{
												printf("对应手机信息查询成功!\n\n请继续输入您的需求(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("需要删除的手机的生产厂商输入有误，请重新输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
											}
											if (f) break;
										}
									}
									else if (num == "5")
									{
										f5 = 1;
										break;
									}
									else	// 输入有误
									{
										printf("您的输入不符合要求，请重新输入您的需求(1/2/3/4/5): ");
									}
								}
								if (f5)
								{
									printf("退出成功,即将返回用户登录界面~\n");
									flg2 = 1;
									_sleep(1500);
									break;
								}
								/* Main_Menu end */
							}
							/* 登录成功 end */
							/* 登录失败 begin */
							else    // 普通员工登录信息错误
							{
								printf("是否需要继续尝试登录员工系统?(y/n): ");
								string f;
								while (cin >> f)
								{
									if (f == "y") break;
									else if (f == "n")
									{
										flag3 = 1;
										break;
									}
									else
									{
										printf("输入格式错误,是否需要继续尝试登录员工系统?(y/n): ");
									}
								}
								if (flag3)
								{
									printf("取消登录成功~\n请继续输入您的需求(1/2/3): ");
									_sleep(1500);
									break;
								}
								printf("请重新输入您的账号(姓名拼音): ");
							}
							/* 登录失败 end */
						}
						if (flag || flg2) break;
					}
					/* 登录手机信息系统 end */

					/* 登录员工信息系统 end */
					else if (sys == 2)
					{
						int flag2 = 0;	// 是否需要重新输入密码
						int flag3 = 0;	// 是否需要继续尝试登录员工系统
						int f5 = 0;
						printf("请输入您的账号(姓名拼音): ");
						string name, passwd;
						while (cin >> name)
						{
							if (!flag2)
							{
								printf("请输入您的密码(初始密码或修改后的密码): ");
								flag2 = 1;
							}
							else
							{
								printf("请重新输入您的密码(初始密码或修改后的密码): ");
							}
							cin >> passwd;
							/* 登录成功 begin */
							if (pManager->manager_log_in(name, passwd))	// 登录成功
							{
								printf("登录成功!!  两秒钟后即将跳转至员工信息管理功能菜单\n");
								_sleep(2000);
								system("cls");

								/* Main_Menu begin */
								printf("\t\tWorker Manage Menu\n\n");
								printf("\t1.输入人员信息\t2.修改人员信息\n\t3.删除人员信息\t4.浏览人员信息\n\t5.退出\n\n");
								printf("请输入您的需求(1/2/3/4/5): ");
								string num;
								while (cin >> num)
								{
									/* number(string) name(string) position(string) phone_number(string) sale(map<string, int>) passwd(string) */

									if (num == "1")
									{
										printf("请输入您需要添加的人员的详细信息(初始密码为 123456): ");
										string number, name, position, phone_number;
										int sale;
										printf("请输入编号: ");
										cin >> number;
										printf("请输入姓名: ");
										cin >> name;
										printf("请输入职位: ");
										cin >> position;
										printf("请输入联系方式: ");
										cin >> phone_number;
										printf("请输入销售额: ");
										cin >> sale;
										pManager->addWorkerToList(number, name, position, phone_number, sale);
										printf("人员信息添加成功\n请继续输入您的需求(1/2/3/4/5): ");
									}
									else if (num == "2")
									{
										// 限制条件：只允许输入人员姓名来匹配是否可以修改
										printf("请输入您需要修改信息的人员的姓名(Eric、Alice、Amy...): ");
										string name;
										int f = 0;	// 是否完成修改
										while (cin >> name)
										{
											if (pManager->findspe(name))
											{
												printf("请输入需要修改的人员的具体信息(number、position、phone_number...): ");
												/* number(string) name(string) position(string) phone_number(string) sale(map<string, int>) passwd(string) */
												string str;
												while (cin >> str)
												{
													if (str == "number")
													{
														printf("请输入您需要修改成的编号(1001、1002、1003...): ");
														string number; cin >> number;
														pManager->changeWorkerList_number(name, number);
														f = 1;
													}
													else if (str == "name")
													{
														printf("请输入您需要修改成的人员姓名(Eric、Alice、Amy...): ");
														string _name; cin >> _name;
														pManager->changeWorkerList_name(name, _name);
														f = 1;
													}
													else if (str == "position")
													{
														printf("请输入您需要修改成的职位(worker、manager...): ");
														string position; cin >> position;
														pManager->changeWorkerList_position(name, position);
														f = 1;
													}
													else if (str == "phone_number")
													{
														printf("请输入您需要修改成的联系方式(1110000、1330000、1180000): ");
														string phone_number; cin >> phone_number;
														pManager->changeWorkerList_phonr_number(name, phone_number);
														f = 1;
													}
													else if (str == "sale")
													{
														printf("请输入您需要修改成的销售额(1000、4000、2000): ");
														int sale; cin >> sale;
														pManager->changeWorkerList_sale(name, sale);
														f = 1;
													}
													else if (str == "passwd")
													{
														printf("请输入您需要修改成的密码(123456、66666、524142): ");
														string passwd; cin >> passwd;
														pManager->changeWorkerList_passwd(name, passwd);
														f = 1;
													}
													else
													{
														printf("您的输入存在错误，请您检查后重试!\n请重新输入需要修改的人员的具体信息(number、company、price...): ");
													}
													if (f)
													{
														printf("人员信息修改成功~\n请继续输入您的需求(1/2/3/4/5): ");
														break;
													}
												}
											}
											else
											{
												printf("需要修改的人员信息的姓名输入有误，请重新输入您需要修改的人员信息的姓名(Eric、Alice、Amy....): ");
											}
											if (f) break;
										}
									}
									else if (num == "3")
									{
										// 限制条件：只允许输入人员姓名来匹配是否可以删除
										printf("请输入您需要删除的人员的姓名(Eric、Alice、Amy...): ");
										string name;
										int f = 0;	// 是否删除成功
										while (cin >> name)
										{
											if (pManager->findspe(name))
											{
												pManager->deleteWorkerList(name);
												printf("对应人员信息删除成功!\n请继续输入您的需求(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("需要删除的手机的生产厂商输入有误，请确认您是否需要继续删除(y/n): ");
												string f1;
												while (cin >> f1)
												{
													if (f1 == "y")
													{
														break;
													}
													else if (f1 == "n")
													{
														f = 1;
														break;
													}
													else
													{
														printf("您的输入不符合要求, 请您继续输入(y/n): ");
													}
												}
												if (f) break;
												printf("请重新输入您需要删除的人员的姓名(Eric、Alice、Amy...): ");
											}
										}
										if (f)
										{
											printf("请输入您的需求(1/2/3/4/5): ");
											break;
										}
									}
									else if (num == "4")
									{
										// 限制条件：只允许输入人员姓名来匹配是否可以查询
										printf("请输入您需要查询的人员的姓名(Eric、Alice、Amy...): ");
										string name;
										int f = 0;	// 是否查询成功
										while (cin >> name)
										{
											if (pManager->findspe(name))
											{
												printf("对应人员信息查询成功!\n\n请继续输入您的需求(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("需要删除的人员的姓名输入有误，请重新输入您需要修改的手机的生产厂家名(Eric、Alice、Amy...): ");
											}
											if (f)
											{
												break;
											}
										}
									}
									else if (num == "5")
									{
										f5 = 1;
										break;
									}
									else	// 输入有误
									{
										printf("您的输入不符合要求，请重新输入您的需求(1/2/3/4/5): ");
									}
								}
								if (f5)
								{
									printf("退出成功,即将返回用户登录界面~\n");
									flg2 = 1;
									_sleep(1500);
									break;
								}
								/* Worker Manage Menu end */
							}
							/* 登录成功 end */
							/* 登录失败 begin */
							else    // manager 登录信息错误
							{
								printf("您的登录信息不符合要求! 是否需要继续尝试登录员工系统?(y/n): ");
								string f;
								while (cin >> f)
								{
									if (f == "y") break;
									else if (f == "n")
									{
										flag3 = 1;
										break;
									}
									else
									{
										printf("输入格式错误,是否需要继续尝试登录员工系统?(y/n): ");
									}
								}
								if (flag3)
								{
									printf("取消登录成功~\n请继续输入您的需求(1/2/3): ");
									_sleep(1500);
									break;
								}
								printf("请重新输入您的账号(姓名拼音): ");
							}
							/* 登录失败 end */
						}
						if (flag || flg2) break;
					}
					/* 登录员工信息系统 end */

					/* 取消登录 begin */
					else if (sys == 3)
					{
						printf("取消登录成功，即将返回用户登陆界面~\n");
						_sleep(1500);
						break;
					}
					/* 取消登录 begin */

					else
					{
						printf("您的输入有误，请重新输入您需要登录的系统(1/2/3): ");
					}
				}
				break;
			}
			else if (identity == "worker")
			{
				/* 登录 begin */
				int flag2 = 0;	// 是否需要重新输入密码
				int flag3 = 0;	// 是否需要继续尝试登录员工系统
				int f5 = 0;
				printf("请输入您的账号(姓名拼音): ");
				string name, passwd;
				while (cin >> name)
				{
					if (!flag2)
					{
						printf("请输入您的密码(初始密码或修改后的密码): ");
						flag2 = 1;
					}
					else
					{
						printf("请重新输入您的密码(初始密码或修改后的密码): ");
					}
					cin >> passwd;
					/* 登录成功 begin */
					if (pManager->log_in(name, passwd))	// 登录成功
					{
						printf("登录成功!!  两秒钟后即将跳转至手机信息管理功能菜单\n");
						_sleep(2000);
						system("cls");

						/* Main_Menu begin */
						printf("\t\tMain Menu\n\n");
						printf("\t1.输入手机信息\t2.修改手机信息\n\t3.删除手机信息\t4.查询手机信息\n\t5.退出\n\n");
						printf("请输入您的需求(1/2/3/4/5): ");
						string num;
						while (cin >> num)
						{
							if (num == "1")
							{
								printf("请输入您需要添加的手机的详细信息: ");
								string number, company;
								int price, quantity;
								string date_of_production;
								printf("请输入编号: ");
								cin >> number;
								printf("请输入生产厂家: ");
								cin >> company;
								printf("请输入价格: ");
								cin >> price;
								printf("请输入数量: ");
								cin >> quantity;
								printf("请输入生产日期: ");
								cin >> date_of_production;
								pPhone->addPhoneToList(number, company, price, quantity, date_of_production);
								printf("信息添加成功\n请继续输入您的需求(1/2/3/4/5): ");
							}
							else if (num == "2")
							{
								// 限制条件：只允许输入生产厂家来匹配是否可以修改
								printf("请输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
								string company;
								int f = 0;	// 是否完成修改
								while (cin >> company)
								{
									if (pPhone->findspe(company))
									{
										printf("请输入需要修改的手机的具体信息(number、company、price...): ");
										/* number、company、price、quantity、date_of_production */
										string str;
										while (cin >> str)
										{
											if (str == "number")
											{
												printf("请输入您需要修改成的编号(1001、1002、1003...): ");
												string number; cin >> number;
												pPhone->changePhoneList_number(company, number);
												f = 1;
											}
											else if (str == "company")
											{
												printf("请输入您需要修改成的生产厂家(huawei、mi、apple...): ");
												string _company; cin >> _company;
												pPhone->changePhoneList_company(company, _company);
												f = 1;
											}
											else if (str == "price")
											{
												printf("请输入您需要修改成的价格(2000、3000、8000): ");
												int price; cin >> price;
												pPhone->changePhoneList_price(company, price);
												f = 1;
											}
											else if (str == "quantity")
											{
												printf("请输入您需要修改成的库存数量(100、300、800): ");
												int quantity; cin >> quantity;
												pPhone->changePhoneList_quantity(company, quantity);
												f = 1;
											}
											else if (str == "date_of_production")
											{
												printf("请输入您需要修改成的生产日期(2001.3.4、2023.10.09、2010.1.1): ");
												string date_of_production; cin >> date_of_production;
												pPhone->changePhoneList_date_of_production(company, date_of_production);
												f = 1;
											}
											else
											{
												printf("您的输入存在错误，请您检查后重试!\n请重新输入需要修改的手机的具体信息(number、company、price...): ");
											}
											if (f)
											{
												printf("手机信息修改成功~\n请继续输入您的需求(1/2/3/4/5): ");
												break;
											}
										}
									}
									else
									{
										printf("需要修改的手机的生产厂商输入有误，请重新输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
									}
									if (f) break;
								}
							}
							else if (num == "3")
							{
								// 限制条件：只允许输入生产厂家来匹配是否可以删除
								printf("请输入您需要删除的手机的生产厂家名(huawei、mi、apple、oppo...): ");
								string company;
								int f = 0;	// 是否删除成功
								while (cin >> company)
								{
									if (pPhone->findspe(company))
									{
										pPhone->deletePhoneList(company);
										printf("对应手机信息删除成功!\n请继续输入您的需求(1/2/3/4/5): ");
										f = 1;
									}
									else
									{
										printf("需要删除的手机的生产厂商输入有误，请重新输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
									}
									if (f) break;
								}
							}
							else if (num == "4")
							{
								// 限制条件：只允许输入生产厂家来匹配是否可以查询
								printf("请输入您需要查询的手机的生产厂家名(huawei、mi、apple、oppo...): ");
								string company;
								int f = 0;	// 是否查询成功
								while (cin >> company)
								{
									if (pPhone->findspe(company))
									{
										printf("对应手机信息查询成功!\n\n请继续输入您的需求(1/2/3/4/5): ");
										f = 1;
									}
									else
									{
										printf("需要删除的手机的生产厂商输入有误，请重新输入您需要修改的手机的生产厂家名(huawei、mi、apple、oppo...): ");
									}
									if (f) break;
								}
							}
							else if (num == "5")
							{
								f5 = 1;
								break;
							}
							else	// 输入有误
							{
								printf("您的输入不符合要求，请重新输入您的需求(1/2/3/4/5): ");
							}
						}
						if (f5)
						{
							printf("退出成功,即将返回用户登录界面~");
							_sleep(1500);
							break;
						}
						/* Main_Menu end */
					}
					/* 登录成功 end */
					/* 登录失败 begin */
					else    // 普通员工登录信息错误
					{
						printf("是否需要继续尝试登录员工系统?(y/n): ");
						string f;
						while (cin >> f)
						{
							if (f == "y") break;
							else if (f == "n")
							{
								flag3 = 1;
								break;
							}
							else
							{
								printf("输入格式错误,是否需要继续尝试登录员工系统?(y/n): ");
							}
						}
						if (flag3)
						{
							printf("取消登录成功,即将返回主登录界面~");
							_sleep(1500);
							break;
						}
						printf("请重新输入您的账号(姓名拼音): ");
					}
					/* 登录失败 end */
				}
				/* 登录 end */
				break;
			}
			else if (identity == "customer")	// 访客
			{
				printf("即将跳转访客登陆界面!");
				_sleep(1500);
				system("cls");
				printf("访客登录成功~\n\n");
				printf("所有品牌手机信息如下:\n");
				pPhone->printfPhoneList();

				int flag1 = 0;	// 是否退出访客 -> 进入登录界面
				while (true)
				{
					printf("\n\n\t\t功能菜单如下:\n");
					printf("\t1.查询手机信息\t2.打印手机信息\t3.购买通道\t4.退出\n");
					printf("Please input your demand(1/2/3/4): ");
					int num; cin >> num;
					if (num == 1)	// 查询
					{
						cout << "请输入您要查询的手机品牌(huawei、mi、apple、oppo...): ";
						string spe;
						while (cin >> spe)
						{
							if (pPhone->findspe(spe)) break;
							else
							{
								printf("手机品牌输入有误，请重新输入(huawei、mi、apple、oppo...):");
							}
						}
					}
					else if (num == 2)	// 打印
					{
						printf("所有品牌手机信息如下:\n");
						pPhone->printfPhoneList();
					}
					else if (num == 3)	// 购买
					{
						printf("请输入您要购买的手机品牌(huawei、mi、apple、oppo...): ");
						string band;
						while (cin >> band)
						{
							if (pPhone->findspe(band))	// 找到对应品牌
							{
								printf("该品牌手机还有库存余量，请您确认是否购买(y/n): ");
								string ans;
								while (cin >> ans)
								{
									if (ans == "y")
									{
										// 增加员工销售额
										printf("请输入您的导购员(Alice、Tom、Eric...): ");
										string name;
										while (cin >> name)
										{
											if (pWorker->findWorker(name))
											{
												// 减少对应 band 库存数量
												pPhone->subBandQuantity(band);
												int sale = pPhone->getBandPrice(band);
												pWorker->addSale(name, sale);
												break;
											}
											else
											{
												printf("您输入的导购员不存在，请重新输入(Alice、Tom、Eric...): ");
											}
										}
										printf("购买成功，感谢您的购买!	即将返回功能菜单页面\n");
										_sleep(1500);
										break;
									}
									else if (ans == "n")
									{
										printf("订单已为您取消~	  即将返回功能菜单页面\n");
										break;
									}
									else
										printf("您的输入有误，请您再次输入(y/n): ");
								}
								break;
							}
							else
							{
								printf("您输入的品牌已售罄或该品牌不存在，请您重新输入(huawei、mi、apple、oppo...): ");
							}
						}
					}
					else if (num == 4)	// 退出
					{
						printf("感谢您的使用! 两秒后将自动返回登陆界面");
						flag1 = 1;
						_sleep(2000);
						break;
					}
					else
					{
						printf("您输入的 demand 有误,请重新输入(1/2):");
					}
				}
				if (flag1) break;
			}
			else if (identity == "break")
			{
				printf("感谢您使用本系统! 两秒后将自动退出\n");
				_sleep(2000);
				flag = 1;
				break;
			}
			else if (identity == "error")
			{
				printf("你的输入有误,请重新输入(1/2/3/4): ");
			}
			if (flg2)
			{
				break;
			}
		}
		if (flag) break;	// 退出
	}

	return 0;
}
