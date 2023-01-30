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
	printf("1. Manager\t2.Worker\t3.Customer\t4.�˳�\n\n");
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
	printf("\n��ӭʹ�ã������Ӻ��Զ���ת��¼����~\n");
	//_sleep(2000);

	while (true)
	{
		int flag = 0;	// �Ƿ��˳�
		system("cls");
		init();
		while (true)
		{
			int flg2 = 0;	// �Ƿ��˳� manager ��¼ϵͳ
			string identity = chose_identity();
			/* �곤 begin */
			int flg1 = 0;	// �Ƿ񷵻� manager ѡ���¼ϵͳ����
			if (identity == "manager")
			{
				// �곤ҲӦ�߱���¼�ֻ�����ϵͳ�Ĺ���

				system("cls");
				printf("****************************************\n");
				printf("          Manage system\n\n");
				printf("1.�ֻ���Ϣϵͳ\t2.Ա������ϵͳ\t3.ȡ����¼\n");
				printf("����������Ҫ��¼��ϵͳ(1/2/3): ");
				int sys;
				while (cin >> sys)
				{
					/* ��¼�ֻ���Ϣϵͳ begin */
					if (sys == 1)
					{
						int flag2 = 0;	// �Ƿ���Ҫ������������
						int flag3 = 0;	// �Ƿ���Ҫ�������Ե�¼Ա��ϵͳ
						int f5 = 0;
						printf("�����������˺�(����ƴ��): ");
						string name, passwd;
						while (cin >> name)
						{
							if (!flag2)
							{
								printf("��������������(��ʼ������޸ĺ������): ");
								flag2 = 1;
							}
							else
							{
								printf("������������������(��ʼ������޸ĺ������): ");
							}
							cin >> passwd;
							/* ��¼�ɹ� begin */
							if (pManager->log_in(name, passwd))	// ��¼�ɹ�
							{
								printf("��¼�ɹ�!!  �����Ӻ󼴽���ת���ֻ���Ϣ�����ܲ˵�\n");
								_sleep(2000);
								system("cls");

								/* Main_Menu begin */
								printf("\t\tMain Menu\n\n");
								printf("\t1.�����ֻ���Ϣ\t2.�޸��ֻ���Ϣ\n\t3.ɾ���ֻ���Ϣ\t4.��ѯ�ֻ���Ϣ\n\t5.�˳�\n\n");
								printf("��������������(1/2/3/4/5): ");
								string num;
								while (cin >> num)
								{
									if (num == "1")
									{
										printf("����������Ҫ��ӵ��ֻ�����ϸ��Ϣ: ");
										string number, company;
										int price, quantity;
										string date_of_production;
										printf("��������: ");
										cin >> number;
										printf("��������������: ");
										cin >> company;
										printf("������۸�: ");
										cin >> price;
										printf("����������: ");
										cin >> quantity;
										printf("��������������: ");
										cin >> date_of_production;
										pPhone->addPhoneToList(number, company, price, quantity, date_of_production);
										printf("��Ϣ��ӳɹ�\n�����������������(1/2/3/4/5): ");
									}
									else if (num == "2")
									{
										// ����������ֻ������������������ƥ���Ƿ�����޸�
										printf("����������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
										string company;
										int f = 0;	// �Ƿ�����޸�
										while (cin >> company)
										{
											if (pPhone->findspe(company))
											{
												printf("��������Ҫ�޸ĵ��ֻ��ľ�����Ϣ(number��company��price...): ");
												/* number��company��price��quantity��date_of_production */
												string str;
												while (cin >> str)
												{
													if (str == "number")
													{
														printf("����������Ҫ�޸ĳɵı��(1001��1002��1003...): ");
														string number; cin >> number;
														pPhone->changePhoneList_number(company, number);
														f = 1;
													}
													else if (str == "company")
													{
														printf("����������Ҫ�޸ĳɵ���������(huawei��mi��apple...): ");
														string _company; cin >> _company;
														pPhone->changePhoneList_company(company, _company);
														f = 1;
													}
													else if (str == "price")
													{
														printf("����������Ҫ�޸ĳɵļ۸�(2000��3000��8000): ");
														int price; cin >> price;
														pPhone->changePhoneList_price(company, price);
														f = 1;
													}
													else if (str == "quantity")
													{
														printf("����������Ҫ�޸ĳɵĿ������(100��300��800): ");
														int quantity; cin >> quantity;
														pPhone->changePhoneList_quantity(company, quantity);
														f = 1;
													}
													else if (str == "date_of_production")
													{
														printf("����������Ҫ�޸ĳɵ���������(2001.3.4��2023.10.09��2010.1.1): ");
														string date_of_production; cin >> date_of_production;
														pPhone->changePhoneList_date_of_production(company, date_of_production);
														f = 1;
													}
													else
													{
														printf("����������ڴ���������������!\n������������Ҫ�޸ĵ��ֻ��ľ�����Ϣ(number��company��price...): ");
													}
													if (f)
													{
														printf("�ֻ���Ϣ�޸ĳɹ�~\n�����������������(1/2/3/4/5): ");
														break;
													}
												}
											}
											else
											{
												printf("��Ҫ�޸ĵ��ֻ���������������������������������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
											}
											if (f) break;
										}
									}
									else if (num == "3")
									{
										// ����������ֻ������������������ƥ���Ƿ����ɾ��
										printf("����������Ҫɾ�����ֻ�������������(huawei��mi��apple��oppo...): ");
										string company;
										int f = 0;	// �Ƿ�ɾ���ɹ�
										while (cin >> company)
										{
											if (pPhone->findspe(company))
											{
												pPhone->deletePhoneList(company);
												printf("��Ӧ�ֻ���Ϣɾ���ɹ�!\n�����������������(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("��Ҫɾ�����ֻ���������������������������������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
											}
											if (f) break;
										}
									}
									else if (num == "4")
									{
										// ����������ֻ������������������ƥ���Ƿ���Բ�ѯ
										printf("����������Ҫ��ѯ���ֻ�������������(huawei��mi��apple��oppo...): ");
										string company;
										int f = 0;	// �Ƿ��ѯ�ɹ�
										while (cin >> company)
										{
											if (pPhone->findspe(company))
											{
												printf("��Ӧ�ֻ���Ϣ��ѯ�ɹ�!\n\n�����������������(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("��Ҫɾ�����ֻ���������������������������������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
											}
											if (f) break;
										}
									}
									else if (num == "5")
									{
										f5 = 1;
										break;
									}
									else	// ��������
									{
										printf("�������벻����Ҫ��������������������(1/2/3/4/5): ");
									}
								}
								if (f5)
								{
									printf("�˳��ɹ�,���������û���¼����~\n");
									flg2 = 1;
									_sleep(1500);
									break;
								}
								/* Main_Menu end */
							}
							/* ��¼�ɹ� end */
							/* ��¼ʧ�� begin */
							else    // ��ͨԱ����¼��Ϣ����
							{
								printf("�Ƿ���Ҫ�������Ե�¼Ա��ϵͳ?(y/n): ");
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
										printf("�����ʽ����,�Ƿ���Ҫ�������Ե�¼Ա��ϵͳ?(y/n): ");
									}
								}
								if (flag3)
								{
									printf("ȡ����¼�ɹ�~\n�����������������(1/2/3): ");
									_sleep(1500);
									break;
								}
								printf("���������������˺�(����ƴ��): ");
							}
							/* ��¼ʧ�� end */
						}
						if (flag || flg2) break;
					}
					/* ��¼�ֻ���Ϣϵͳ end */

					/* ��¼Ա����Ϣϵͳ end */
					else if (sys == 2)
					{
						int flag2 = 0;	// �Ƿ���Ҫ������������
						int flag3 = 0;	// �Ƿ���Ҫ�������Ե�¼Ա��ϵͳ
						int f5 = 0;
						printf("�����������˺�(����ƴ��): ");
						string name, passwd;
						while (cin >> name)
						{
							if (!flag2)
							{
								printf("��������������(��ʼ������޸ĺ������): ");
								flag2 = 1;
							}
							else
							{
								printf("������������������(��ʼ������޸ĺ������): ");
							}
							cin >> passwd;
							/* ��¼�ɹ� begin */
							if (pManager->manager_log_in(name, passwd))	// ��¼�ɹ�
							{
								printf("��¼�ɹ�!!  �����Ӻ󼴽���ת��Ա����Ϣ�����ܲ˵�\n");
								_sleep(2000);
								system("cls");

								/* Main_Menu begin */
								printf("\t\tWorker Manage Menu\n\n");
								printf("\t1.������Ա��Ϣ\t2.�޸���Ա��Ϣ\n\t3.ɾ����Ա��Ϣ\t4.�����Ա��Ϣ\n\t5.�˳�\n\n");
								printf("��������������(1/2/3/4/5): ");
								string num;
								while (cin >> num)
								{
									/* number(string) name(string) position(string) phone_number(string) sale(map<string, int>) passwd(string) */

									if (num == "1")
									{
										printf("����������Ҫ��ӵ���Ա����ϸ��Ϣ(��ʼ����Ϊ 123456): ");
										string number, name, position, phone_number;
										int sale;
										printf("��������: ");
										cin >> number;
										printf("����������: ");
										cin >> name;
										printf("������ְλ: ");
										cin >> position;
										printf("��������ϵ��ʽ: ");
										cin >> phone_number;
										printf("���������۶�: ");
										cin >> sale;
										pManager->addWorkerToList(number, name, position, phone_number, sale);
										printf("��Ա��Ϣ��ӳɹ�\n�����������������(1/2/3/4/5): ");
									}
									else if (num == "2")
									{
										// ����������ֻ����������Ա������ƥ���Ƿ�����޸�
										printf("����������Ҫ�޸���Ϣ����Ա������(Eric��Alice��Amy...): ");
										string name;
										int f = 0;	// �Ƿ�����޸�
										while (cin >> name)
										{
											if (pManager->findspe(name))
											{
												printf("��������Ҫ�޸ĵ���Ա�ľ�����Ϣ(number��position��phone_number...): ");
												/* number(string) name(string) position(string) phone_number(string) sale(map<string, int>) passwd(string) */
												string str;
												while (cin >> str)
												{
													if (str == "number")
													{
														printf("����������Ҫ�޸ĳɵı��(1001��1002��1003...): ");
														string number; cin >> number;
														pManager->changeWorkerList_number(name, number);
														f = 1;
													}
													else if (str == "name")
													{
														printf("����������Ҫ�޸ĳɵ���Ա����(Eric��Alice��Amy...): ");
														string _name; cin >> _name;
														pManager->changeWorkerList_name(name, _name);
														f = 1;
													}
													else if (str == "position")
													{
														printf("����������Ҫ�޸ĳɵ�ְλ(worker��manager...): ");
														string position; cin >> position;
														pManager->changeWorkerList_position(name, position);
														f = 1;
													}
													else if (str == "phone_number")
													{
														printf("����������Ҫ�޸ĳɵ���ϵ��ʽ(1110000��1330000��1180000): ");
														string phone_number; cin >> phone_number;
														pManager->changeWorkerList_phonr_number(name, phone_number);
														f = 1;
													}
													else if (str == "sale")
													{
														printf("����������Ҫ�޸ĳɵ����۶�(1000��4000��2000): ");
														int sale; cin >> sale;
														pManager->changeWorkerList_sale(name, sale);
														f = 1;
													}
													else if (str == "passwd")
													{
														printf("����������Ҫ�޸ĳɵ�����(123456��66666��524142): ");
														string passwd; cin >> passwd;
														pManager->changeWorkerList_passwd(name, passwd);
														f = 1;
													}
													else
													{
														printf("����������ڴ���������������!\n������������Ҫ�޸ĵ���Ա�ľ�����Ϣ(number��company��price...): ");
													}
													if (f)
													{
														printf("��Ա��Ϣ�޸ĳɹ�~\n�����������������(1/2/3/4/5): ");
														break;
													}
												}
											}
											else
											{
												printf("��Ҫ�޸ĵ���Ա��Ϣ����������������������������Ҫ�޸ĵ���Ա��Ϣ������(Eric��Alice��Amy....): ");
											}
											if (f) break;
										}
									}
									else if (num == "3")
									{
										// ����������ֻ����������Ա������ƥ���Ƿ����ɾ��
										printf("����������Ҫɾ������Ա������(Eric��Alice��Amy...): ");
										string name;
										int f = 0;	// �Ƿ�ɾ���ɹ�
										while (cin >> name)
										{
											if (pManager->findspe(name))
											{
												pManager->deleteWorkerList(name);
												printf("��Ӧ��Ա��Ϣɾ���ɹ�!\n�����������������(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("��Ҫɾ�����ֻ���������������������ȷ�����Ƿ���Ҫ����ɾ��(y/n): ");
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
														printf("�������벻����Ҫ��, ������������(y/n): ");
													}
												}
												if (f) break;
												printf("��������������Ҫɾ������Ա������(Eric��Alice��Amy...): ");
											}
										}
										if (f)
										{
											printf("��������������(1/2/3/4/5): ");
											break;
										}
									}
									else if (num == "4")
									{
										// ����������ֻ����������Ա������ƥ���Ƿ���Բ�ѯ
										printf("����������Ҫ��ѯ����Ա������(Eric��Alice��Amy...): ");
										string name;
										int f = 0;	// �Ƿ��ѯ�ɹ�
										while (cin >> name)
										{
											if (pManager->findspe(name))
											{
												printf("��Ӧ��Ա��Ϣ��ѯ�ɹ�!\n\n�����������������(1/2/3/4/5): ");
												f = 1;
											}
											else
											{
												printf("��Ҫɾ������Ա����������������������������Ҫ�޸ĵ��ֻ�������������(Eric��Alice��Amy...): ");
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
									else	// ��������
									{
										printf("�������벻����Ҫ��������������������(1/2/3/4/5): ");
									}
								}
								if (f5)
								{
									printf("�˳��ɹ�,���������û���¼����~\n");
									flg2 = 1;
									_sleep(1500);
									break;
								}
								/* Worker Manage Menu end */
							}
							/* ��¼�ɹ� end */
							/* ��¼ʧ�� begin */
							else    // manager ��¼��Ϣ����
							{
								printf("���ĵ�¼��Ϣ������Ҫ��! �Ƿ���Ҫ�������Ե�¼Ա��ϵͳ?(y/n): ");
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
										printf("�����ʽ����,�Ƿ���Ҫ�������Ե�¼Ա��ϵͳ?(y/n): ");
									}
								}
								if (flag3)
								{
									printf("ȡ����¼�ɹ�~\n�����������������(1/2/3): ");
									_sleep(1500);
									break;
								}
								printf("���������������˺�(����ƴ��): ");
							}
							/* ��¼ʧ�� end */
						}
						if (flag || flg2) break;
					}
					/* ��¼Ա����Ϣϵͳ end */

					/* ȡ����¼ begin */
					else if (sys == 3)
					{
						printf("ȡ����¼�ɹ������������û���½����~\n");
						_sleep(1500);
						break;
					}
					/* ȡ����¼ begin */

					else
					{
						printf("��������������������������Ҫ��¼��ϵͳ(1/2/3): ");
					}
				}
				break;
			}
			else if (identity == "worker")
			{
				/* ��¼ begin */
				int flag2 = 0;	// �Ƿ���Ҫ������������
				int flag3 = 0;	// �Ƿ���Ҫ�������Ե�¼Ա��ϵͳ
				int f5 = 0;
				printf("�����������˺�(����ƴ��): ");
				string name, passwd;
				while (cin >> name)
				{
					if (!flag2)
					{
						printf("��������������(��ʼ������޸ĺ������): ");
						flag2 = 1;
					}
					else
					{
						printf("������������������(��ʼ������޸ĺ������): ");
					}
					cin >> passwd;
					/* ��¼�ɹ� begin */
					if (pManager->log_in(name, passwd))	// ��¼�ɹ�
					{
						printf("��¼�ɹ�!!  �����Ӻ󼴽���ת���ֻ���Ϣ�����ܲ˵�\n");
						_sleep(2000);
						system("cls");

						/* Main_Menu begin */
						printf("\t\tMain Menu\n\n");
						printf("\t1.�����ֻ���Ϣ\t2.�޸��ֻ���Ϣ\n\t3.ɾ���ֻ���Ϣ\t4.��ѯ�ֻ���Ϣ\n\t5.�˳�\n\n");
						printf("��������������(1/2/3/4/5): ");
						string num;
						while (cin >> num)
						{
							if (num == "1")
							{
								printf("����������Ҫ��ӵ��ֻ�����ϸ��Ϣ: ");
								string number, company;
								int price, quantity;
								string date_of_production;
								printf("��������: ");
								cin >> number;
								printf("��������������: ");
								cin >> company;
								printf("������۸�: ");
								cin >> price;
								printf("����������: ");
								cin >> quantity;
								printf("��������������: ");
								cin >> date_of_production;
								pPhone->addPhoneToList(number, company, price, quantity, date_of_production);
								printf("��Ϣ��ӳɹ�\n�����������������(1/2/3/4/5): ");
							}
							else if (num == "2")
							{
								// ����������ֻ������������������ƥ���Ƿ�����޸�
								printf("����������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
								string company;
								int f = 0;	// �Ƿ�����޸�
								while (cin >> company)
								{
									if (pPhone->findspe(company))
									{
										printf("��������Ҫ�޸ĵ��ֻ��ľ�����Ϣ(number��company��price...): ");
										/* number��company��price��quantity��date_of_production */
										string str;
										while (cin >> str)
										{
											if (str == "number")
											{
												printf("����������Ҫ�޸ĳɵı��(1001��1002��1003...): ");
												string number; cin >> number;
												pPhone->changePhoneList_number(company, number);
												f = 1;
											}
											else if (str == "company")
											{
												printf("����������Ҫ�޸ĳɵ���������(huawei��mi��apple...): ");
												string _company; cin >> _company;
												pPhone->changePhoneList_company(company, _company);
												f = 1;
											}
											else if (str == "price")
											{
												printf("����������Ҫ�޸ĳɵļ۸�(2000��3000��8000): ");
												int price; cin >> price;
												pPhone->changePhoneList_price(company, price);
												f = 1;
											}
											else if (str == "quantity")
											{
												printf("����������Ҫ�޸ĳɵĿ������(100��300��800): ");
												int quantity; cin >> quantity;
												pPhone->changePhoneList_quantity(company, quantity);
												f = 1;
											}
											else if (str == "date_of_production")
											{
												printf("����������Ҫ�޸ĳɵ���������(2001.3.4��2023.10.09��2010.1.1): ");
												string date_of_production; cin >> date_of_production;
												pPhone->changePhoneList_date_of_production(company, date_of_production);
												f = 1;
											}
											else
											{
												printf("����������ڴ���������������!\n������������Ҫ�޸ĵ��ֻ��ľ�����Ϣ(number��company��price...): ");
											}
											if (f)
											{
												printf("�ֻ���Ϣ�޸ĳɹ�~\n�����������������(1/2/3/4/5): ");
												break;
											}
										}
									}
									else
									{
										printf("��Ҫ�޸ĵ��ֻ���������������������������������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
									}
									if (f) break;
								}
							}
							else if (num == "3")
							{
								// ����������ֻ������������������ƥ���Ƿ����ɾ��
								printf("����������Ҫɾ�����ֻ�������������(huawei��mi��apple��oppo...): ");
								string company;
								int f = 0;	// �Ƿ�ɾ���ɹ�
								while (cin >> company)
								{
									if (pPhone->findspe(company))
									{
										pPhone->deletePhoneList(company);
										printf("��Ӧ�ֻ���Ϣɾ���ɹ�!\n�����������������(1/2/3/4/5): ");
										f = 1;
									}
									else
									{
										printf("��Ҫɾ�����ֻ���������������������������������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
									}
									if (f) break;
								}
							}
							else if (num == "4")
							{
								// ����������ֻ������������������ƥ���Ƿ���Բ�ѯ
								printf("����������Ҫ��ѯ���ֻ�������������(huawei��mi��apple��oppo...): ");
								string company;
								int f = 0;	// �Ƿ��ѯ�ɹ�
								while (cin >> company)
								{
									if (pPhone->findspe(company))
									{
										printf("��Ӧ�ֻ���Ϣ��ѯ�ɹ�!\n\n�����������������(1/2/3/4/5): ");
										f = 1;
									}
									else
									{
										printf("��Ҫɾ�����ֻ���������������������������������Ҫ�޸ĵ��ֻ�������������(huawei��mi��apple��oppo...): ");
									}
									if (f) break;
								}
							}
							else if (num == "5")
							{
								f5 = 1;
								break;
							}
							else	// ��������
							{
								printf("�������벻����Ҫ��������������������(1/2/3/4/5): ");
							}
						}
						if (f5)
						{
							printf("�˳��ɹ�,���������û���¼����~");
							_sleep(1500);
							break;
						}
						/* Main_Menu end */
					}
					/* ��¼�ɹ� end */
					/* ��¼ʧ�� begin */
					else    // ��ͨԱ����¼��Ϣ����
					{
						printf("�Ƿ���Ҫ�������Ե�¼Ա��ϵͳ?(y/n): ");
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
								printf("�����ʽ����,�Ƿ���Ҫ�������Ե�¼Ա��ϵͳ?(y/n): ");
							}
						}
						if (flag3)
						{
							printf("ȡ����¼�ɹ�,������������¼����~");
							_sleep(1500);
							break;
						}
						printf("���������������˺�(����ƴ��): ");
					}
					/* ��¼ʧ�� end */
				}
				/* ��¼ end */
				break;
			}
			else if (identity == "customer")	// �ÿ�
			{
				printf("������ת�ÿ͵�½����!");
				_sleep(1500);
				system("cls");
				printf("�ÿ͵�¼�ɹ�~\n\n");
				printf("����Ʒ���ֻ���Ϣ����:\n");
				pPhone->printfPhoneList();

				int flag1 = 0;	// �Ƿ��˳��ÿ� -> �����¼����
				while (true)
				{
					printf("\n\n\t\t���ܲ˵�����:\n");
					printf("\t1.��ѯ�ֻ���Ϣ\t2.��ӡ�ֻ���Ϣ\t3.����ͨ��\t4.�˳�\n");
					printf("Please input your demand(1/2/3/4): ");
					int num; cin >> num;
					if (num == 1)	// ��ѯ
					{
						cout << "��������Ҫ��ѯ���ֻ�Ʒ��(huawei��mi��apple��oppo...): ";
						string spe;
						while (cin >> spe)
						{
							if (pPhone->findspe(spe)) break;
							else
							{
								printf("�ֻ�Ʒ��������������������(huawei��mi��apple��oppo...):");
							}
						}
					}
					else if (num == 2)	// ��ӡ
					{
						printf("����Ʒ���ֻ���Ϣ����:\n");
						pPhone->printfPhoneList();
					}
					else if (num == 3)	// ����
					{
						printf("��������Ҫ������ֻ�Ʒ��(huawei��mi��apple��oppo...): ");
						string band;
						while (cin >> band)
						{
							if (pPhone->findspe(band))	// �ҵ���ӦƷ��
							{
								printf("��Ʒ���ֻ����п������������ȷ���Ƿ���(y/n): ");
								string ans;
								while (cin >> ans)
								{
									if (ans == "y")
									{
										// ����Ա�����۶�
										printf("���������ĵ���Ա(Alice��Tom��Eric...): ");
										string name;
										while (cin >> name)
										{
											if (pWorker->findWorker(name))
											{
												// ���ٶ�Ӧ band �������
												pPhone->subBandQuantity(band);
												int sale = pPhone->getBandPrice(band);
												pWorker->addSale(name, sale);
												break;
											}
											else
											{
												printf("������ĵ���Ա�����ڣ�����������(Alice��Tom��Eric...): ");
											}
										}
										printf("����ɹ�����л���Ĺ���!	�������ع��ܲ˵�ҳ��\n");
										_sleep(1500);
										break;
									}
									else if (ans == "n")
									{
										printf("������Ϊ��ȡ��~	  �������ع��ܲ˵�ҳ��\n");
										break;
									}
									else
										printf("�����������������ٴ�����(y/n): ");
								}
								break;
							}
							else
							{
								printf("�������Ʒ�����������Ʒ�Ʋ����ڣ�������������(huawei��mi��apple��oppo...): ");
							}
						}
					}
					else if (num == 4)	// �˳�
					{
						printf("��л����ʹ��! ������Զ����ص�½����");
						flag1 = 1;
						_sleep(2000);
						break;
					}
					else
					{
						printf("������� demand ����,����������(1/2):");
					}
				}
				if (flag1) break;
			}
			else if (identity == "break")
			{
				printf("��л��ʹ�ñ�ϵͳ! ������Զ��˳�\n");
				_sleep(2000);
				flag = 1;
				break;
			}
			else if (identity == "error")
			{
				printf("�����������,����������(1/2/3/4): ");
			}
			if (flg2)
			{
				break;
			}
		}
		if (flag) break;	// �˳�
	}

	return 0;
}
