#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h> //�ѱ۱��������� �߰�


#define MAX_SIZE 100
#define MAX_NUM_LENGTH 11

class Person_Info {
public:
	char name[MAX_SIZE]; //�̸�
	std::string phone_number; //��ȭ��ȣ
	char address[MAX_SIZE]; //�ּ�	
	char email[MAX_SIZE]; //�̸���
};


class Phonebook
{
private:
	int num_of_person; //����Ǿ��ִ� ����� ��
	Person_Info list[MAX_SIZE]; //������� ������ �����ϱ� ���� �迭
	
public:
	Phonebook() {
		num_of_person = 0; //�ʱ� ������� 0
	}

	int chk_email(char email[]); //�̸��� ���� �˻� �Լ�
	int chk_num_length(std::string phone_number); //��ȭ��ȣ ���� �˻� �Լ�
	int add_info(Person_Info input); //����� ���� �߰� �Լ�
	int modify_info(char name[]); //����� ���� ���� �Լ�
	void print_info() ; //��ü ����� ��� �Լ�
	void print_info(Person_Info Src_list[],int Src_index[],int num_of_person); //�˻� �� ����ڵ��� ���
	int search_info(char name[],Person_Info Dst_list[],int Dst_index[]); //����� �˻� �Լ�
	int del_info(char name[]); //����� ���� �Լ�
};

//ȭ�� ��¿� �Լ�
void disp_main();
void disp_add_info();
void disp_modify_info();
void disp_print_info_all();
void disp_search_info();
void disp_del_info();