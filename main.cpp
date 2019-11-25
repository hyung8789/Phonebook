#include "header.h"

void main() {
	_wsetlocale( LC_ALL, L"korean" ); //����ȭ ������ ���������� ����

	Person_Info tmp; //����� ���� �Է¹޾� �ӽ�����
	Phonebook MyBook;
	char name[MAX_SIZE]; //�Է�,����,�����ϱ����� �̸��� �����ϴ� ����

	//search_info�� ȣ���ϱ� ���� ����
	Person_Info tmp_list[MAX_SIZE];
	int tmp_index[MAX_SIZE];
	int num_of_tmp_list = 0;
	/*
	�Լ� ���ϰ�
	-1 : ����ڽ������
	0 : ����
	1 : ����
	2 : ��Ÿ����
	*/

	while(1){
		int main_select = 0;

		disp_main();
		std::cin >> main_select;

		if (main_select == 6)
			break;

		//!(cin >> main_select)
		else if (main_select < 1 || main_select > 6)
		//�Է¹��� �ʰ� �Ǵ� �߸��� �����Է�
		{
			std::cout << "�޴��߿��� �����ϼ���!!" << std::endl;
			std::cin.clear(); //������Ʈ�� �ʱ�ȭ
			std::cin.ignore(INT_MAX, '\n'); //�Է¹��ۺ���
			Sleep(1000);
		}

			switch (main_select)
			{
			case 1: //����� ���� �߰�
				disp_add_info();
				std::cin >> tmp.name >> tmp.phone_number >> tmp.address >> tmp.email;
				if (MyBook.add_info(tmp) == 1) {
					std::cout << "���������� �߰��Ǿ����ϴ�." << std::endl;
					Sleep(1000);
				}
				break;

			case 2: //����� ���� ����
				disp_modify_info();
				std::cin >> name;
				if (MyBook.modify_info(name) == 1)
				{
					std::cout << "���������� �����Ǿ����ϴ�." << std::endl;
					Sleep(1000);
				}
				else {
					std::cout << "����� ���� ���� ���� �Ǵ� ���" << std::endl;
					Sleep(1000);
				}
				break;

			case 3: //����� ����
				disp_del_info();
				std::cin >> name;
				if (MyBook.del_info(name) == 1)
				{
					std::cout << "���������� �����Ǿ����ϴ�." << std::endl;
					Sleep(1000);
				}
				else{
					std::cout<< "����� ���� ���� �Ǵ� ���" <<std::endl;
					Sleep(1000);
				}
				break;

			case 4: //����� �˻�				
				disp_search_info();
				std::cin >> name;
				//num_of_tmp_list,tmp_index, tmp_list�� search_info ȣ��ÿ� �Ź� �ٲ�ԵǹǷ� ����� �ʱ�ȭ�� �ʿ䰡����
				num_of_tmp_list=MyBook.search_info(name, tmp_list, tmp_index);
				MyBook.print_info(tmp_list,tmp_index,num_of_tmp_list);
				break;

			case 5: //��ȭ��ȣ�� ��ü ���
				disp_print_info_all();
				MyBook.print_info();
				break;
			}
	}
}