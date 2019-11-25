#include "header.h"

/* ȭ�� ��¿� �Լ� ���� */

void disp_main() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "	��ȭ��ȣ��" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << " 1 : ����� �߰�" << std::endl;
	std::cout << " 2 : ����� ���� ����" << std::endl;
	std::cout << " 3 : ����� ����" << std::endl;
	std::cout << " 4 : ����� �˻�" << std::endl;
	std::cout << " 5 : ��ȭ��ȣ�� ��ü ���" << std::endl;;
	std::cout << " 6 : ���α׷� ����" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "�޴��Է� : ";
}

void disp_add_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "�߰��� ����� ���� �Է�" << std::endl;
	std::cout << "END�Է� : ����ȭ������ ���ư���" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "(�̸�, ��ȭ��ȣ, �ּ�, �̸���) : ";
}

void disp_modify_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "������ ����� �̸� �Է�" << std::endl;
	std::cout << "END�Է� : ����ȭ������ ���ư���" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "(�̸�) : ";
}

void disp_print_info_all() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "(Table num)|�̸�|��ȭ��ȣ|�ּ�|�̸���" << std::endl;
	std::cout << "=====================================" << std::endl;

}

void disp_search_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "�˻��� �̸��� �Է�" << std::endl;
	std::cout << "��� : END�Է�" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << ">>";
}

void disp_del_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "������ �̸��� �Է�" << std::endl;
	std::cout << "��� : END�Է�" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << ">>";
}

/* ȭ�� ��¿� �Լ� �� */

int Phonebook::chk_email(char email[]){
		if (strstr(email, "@") == NULL) //���ڰ� �����ϴ��� �˻��ϴ� �Լ�
		{
			std::cout << "�̸��� ������ �ùٸ��� �ʽ��ϴ�." << std::endl;
			Sleep(1000);
			return 0;
		}
		return 1;
}

int Phonebook::chk_num_length(std::string phone_number){
		//��ȭ��ȣ�Է��� �迭�� ���̸� �������
		if(phone_number.length() > MAX_NUM_LENGTH)
		{
			std::cout<< "��ȭ��ȣ ��������(11��)�� �ʰ��Ͽ����ϴ�." <<std::endl;
			Sleep(1000);
			return 0;
		}

		else return 1;
}		

int Phonebook::add_info(Person_Info input) {
		//����� ���� �߰� �Լ�

		//���Ṯ �˻�
		if (strcmp(input.name, "END") == 0 || strcmp(input.address,"END") == 0 || strcmp(input.email,"END") == 0 || input.phone_number.compare("END") == 0)
			return -1;
		//�̸��� �� ��ȭ��ȣ �ڸ��˻�
		if (chk_email(input.email) != 1 || chk_num_length(input.phone_number) != 1)
			return 0;

		else{
			list[num_of_person] = input;
			num_of_person++; //����� �� ī��Ʈ�� ����
			return 1;
		}
		return 2;
}

int Phonebook::del_info(char name[]) {
		//����� ���� �Լ�
		//search_info�� ȣ���� �˻� �� ����
		if (strcmp(name, "END") == 0) 
			return -1;

		Person_Info tmp_list[MAX_SIZE]; //������ �̸��� ����ڵ��� �ӽ������ϱ� ���� list
		int person_index[MAX_SIZE]; //search_info�κ��� �޾ƿ��� ������� index���� ����
		int num_of_tmp_list = search_info(name, tmp_list,person_index); //�˻��� ������� ���� �� ��,�����迭������ index�� �޾ƿ���
		print_info(tmp_list,person_index,num_of_tmp_list); //���

		if (num_of_tmp_list == 0) return 0; //����ڰ� �������� ���� ���

		else if (num_of_tmp_list != 1 && num_of_tmp_list != -1) //�������� ���
		{
			int choice=0;
			std::cout << "������ �̸��� ����ڰ� �����մϴ�" << std::endl;
			std::cout << "���� �� ������� Table number�� �Է��ϼ���." << std::endl;
			std::cout << "-1 �Է� : ���" << std::endl;

			while (1) {
				std::cout << ">>";
				std::cin >> choice;
				if (choice == -1) return -1;
				else if (strcmp(list[choice].name, name) != 0)
				{	
					//������ ��ȣ�� ����߿��� ���õ����ʾ��� ���,�迭�� ������ �ƴ� �ٸ� ���ڰ� �ԷµǾ��� ���
					std::cout << "��� �߿��� �����ϼ���!!" << std::endl;
					std::cin.clear(); //������Ʈ�� �ʱ�ȭ
					std::cin.ignore(INT_MAX, '\n'); //�Է¹��ۺ���
				}
				else break; //�̸��� ����� �ԷµǾ��� ��� while�� ����
			}

			for (int i = choice; i < num_of_person; i++)
			{
				//�ڿ��ִ� ���� �տ� ������
				list[i] = list[i + 1];
			}
			num_of_person--; //����� �� ī��Ʈ�� ���� 1 ����
			return 1;
		}

		else //�� ���ϰ��
		{
			for (int i = 0; i < num_of_person; i++)
			{
				if (strcmp(list[i].name, name) == 0)
				{
					//�˻��� ��ġ�������� ���� ������ �迭�� ����
					for (int j = i; j < num_of_person; j++)
					{
						list[j] = list[j + 1];
					}
					num_of_person--;
					return 1;
				}
			}
		}

		return 2;
}


int Phonebook::modify_info(char name[]) {
		//����� ���� ���� �Լ�
		//search_info�� ȣ���� �˻� �� ����

		if(strcmp(name,"END") == 0) 
			return -1;

		Person_Info tmp; //������ ������ �ӽ�����
		Person_Info tmp_list[MAX_SIZE]; //����� ���� �ӽ����� ����Ʈ
		
		//search_info�� ���� �˻� �� ����ڵ��� list�迭������ ��ġ������ ������� ����
		//���� �� ���� ��� �׻� person_index[0]�� ����ȴ�.
		int person_index[MAX_SIZE]; 
		int num_of_tmp_list=search_info(name, tmp_list,person_index); //�˻��� ������� ���� �� ��,�����迭������ index�� �޾ƿ���
		
		if (num_of_tmp_list == 0 || num_of_tmp_list == -1) return 0;

		print_info(tmp_list,person_index,num_of_tmp_list); //���
		
		if (num_of_tmp_list == 1) //���� ����ڿ� ���� ���� ����
		{	
			//�ش���ġ�� ���Է�
			//������ ���� �Է¹ޱ�
			while (1) {
				std::cout << "(�̸�, ��ȭ��ȣ, �ּ�, �̸���) : ";
				std::cin >> tmp.name >> tmp.phone_number >> tmp.address >> tmp.email;
				if (chk_email(tmp.email) == 1 && chk_num_length(tmp.phone_number) == 1) break;
			}
			list[person_index[0]] = tmp;
			return 1;
		}

		else //������ �̸��� ������ ������ ��� ���� �� �� �ְ� ��
		{
			int choice=0;
			std::cout << "������ �̸��� " << num_of_tmp_list << "�� �����մϴ�."<<std::endl;
			std::cout << "������ ������� Table num�� �����ϼ���." << std::endl;
			std::cout << "-1 �Է� : ���" << std::endl;

			while (1) {
				std::cout << ">>";
				std::cin >> choice;
				if (choice == -1) return -1;
				else if (strcmp(list[choice].name, name) != 0)
				{
					//������ ��ȣ�� ����߿��� ���õ����ʾ��� ���,�迭�� ������ �ƴ� �ٸ� ���ڰ� �ԷµǾ��� ���
					std::cout << "��� �߿��� �����ϼ���!!" << std::endl;
					std::cin.clear(); //������Ʈ�� �ʱ�ȭ
					std::cin.ignore(INT_MAX, '\n'); //�Է¹��ۺ���
				}
				else break;
			}

			//�ش���ġ�� ���Է�
			//������ ���� �Է¹ޱ�
			while (1) {
				std::cout << "(�̸�, ��ȭ��ȣ, �ּ�, �̸���) : ";
				std::cin >> tmp.name >> tmp.phone_number >> tmp.address >> tmp.email;
				if (chk_email(tmp.email) == 1 && chk_num_length(tmp.phone_number) == 1) break;
			}
			list[person_index[choice]] = tmp;
			return 1;
		}
}



void Phonebook::print_info() //��ü ����� ���
	{
		if (num_of_person == 0)
		{ 
			std::cout << "����� ����ڰ� �����ϴ�." << std::endl;
			std::cout << "�ƹ�Ű�� �Է� : �������� ���ư���" << std::endl;
			system("pause");
			return;
		}

		//2���� ��-strcmp ������ �� ���
		//�̸����� ���� �� ���(���� ö�ڽ� ö�ڰ� ª������ ���� ���� �� yoo>yoon
		Person_Info tmp;

		for (int i = 0; i < num_of_person; i++)
		{
			for (int j = i + 1; j < num_of_person; j++)

				if (strcmp(list[i].name, list[j].name) > 0) //�տ� ���ڿ��� �� ũ�ų� ��� �ٲٱ�
				{
					tmp = list[i];
					list[i] = list[j];
					list[j] = tmp;
				}
		}

		for (int i = 0; i < num_of_person; i++) {
				std::cout << i << " | ";
				std::cout << list[i].name << " | ";
				std::cout << list[i].phone_number << " | ";
				std::cout << list[i].address << " | ";
				std::cout << list[i].email << std::endl;
			std::cout << "=====================================" << std::endl;
		}
		std::cout << "�ƹ�Ű�� �Է� : �������� ���ư���" << std::endl;
		system("pause");
}

void Phonebook::print_info(Person_Info Src_list[],int Src_index[],int num_of_person) //�˻� �� ����ڵ��� ���
	{
		if(num_of_person == 0 || num_of_person == -1) return;
		std::cout << "=====================================" << std::endl;
		std::cout << "(Table num)|�̸�|��ȭ��ȣ|�ּ�|�̸���" << std::endl;
		std::cout << "=====================================" << std::endl;
		for(int i=0;i<num_of_person;i++){
			std::cout << Src_index[i] << " | ";
			std::cout << Src_list[i].name << " | ";
			std::cout << Src_list[i].phone_number << " | ";
			std::cout << Src_list[i].address << " | ";
			std::cout << Src_list[i].email << std::endl;
		}
		std::cout << "=====================================" << std::endl;
		std::cout << "�ƹ�Ű�� �Է� : ���" << std::endl;
		system("pause");
}

	
int Phonebook::search_info(char name[],Person_Info Dst_list[],int Dst_index[])
	{ 
		//�̸����� �˻� �� ����� ���,Dst_list�� �˻��� ����ڵ��� ���� �� Dst_index�� �ش� ������� Index�� ����
		
		if (strcmp(name, "END") == 0) 
			return -1;
		
		Person_Info tmp_list[MAX_SIZE]; //��� �� �� ������ ���� �ӽ������ϴ� list
		int num_of_tmp_list = 0; //tmp_list�� ����� ���� ��
		int Src_index[MAX_SIZE]; //�����迭�� index���� �����ϴ� �迭,Dst_index�� ����
		int tmp_index=0; // �����迭 list���� �˻� �� �ش� ������ tmp_list �� Src_index�� �����ϱ� ���� �ε����ϴ� ����

		//�˻�
		for(int i = 0; i < num_of_person; i++) //������ �̸��� �����ϸ� �ӽ� ����Ʈ�� ������ ī��Ʈ ����
		{
			//int i = �����迭 list�� �ε����ϱ����� ����
			
			if (strcmp(list[i].name, name) == 0)
			{
				//tmp_list[Src_index[tmp_index]] == list[Src_index[tmp_index]]

				tmp_list[tmp_index] = list[i]; //�ش� ����� ������ tmp_list�� ����
				Src_index[tmp_index]=i; //�ش� ����� index���� Src_index�� ����

				//�� ����
				Dst_list[tmp_index] = tmp_list[tmp_index]; 
				Dst_index[tmp_index] = Src_index[tmp_index];
				tmp_index++;
				num_of_tmp_list++;
			}
		}

		if (num_of_tmp_list != 0) return num_of_tmp_list; //�˻� �� ���� �̸����� ����
		else
		{
			std::cout << "�������� �ʴ� ������Դϴ�." << std::endl;
			Sleep(1000);
			return 0;
		}
}