#include "header.h"

/* 화면 출력용 함수 시작 */

void disp_main() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "	전화번호부" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << " 1 : 사용자 추가" << std::endl;
	std::cout << " 2 : 사용자 정보 수정" << std::endl;
	std::cout << " 3 : 사용자 삭제" << std::endl;
	std::cout << " 4 : 사용자 검색" << std::endl;
	std::cout << " 5 : 전화번호부 전체 출력" << std::endl;;
	std::cout << " 6 : 프로그램 종료" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "메뉴입력 : ";
}

void disp_add_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "추가할 사용자 정보 입력" << std::endl;
	std::cout << "END입력 : 메인화면으로 돌아가기" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "(이름, 전화번호, 주소, 이메일) : ";
}

void disp_modify_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "수정할 사용자 이름 입력" << std::endl;
	std::cout << "END입력 : 메인화면으로 돌아가기" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "(이름) : ";
}

void disp_print_info_all() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "(Table num)|이름|전화번호|주소|이메일" << std::endl;
	std::cout << "=====================================" << std::endl;

}

void disp_search_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "검색할 이름을 입력" << std::endl;
	std::cout << "취소 : END입력" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << ">>";
}

void disp_del_info() {
	system("cls");
	std::cout << "=====================================" << std::endl;
	std::cout << "삭제할 이름을 입력" << std::endl;
	std::cout << "취소 : END입력" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << ">>";
}

/* 화면 출력용 함수 끝 */

int Phonebook::chk_email(char email[]){
		if (strstr(email, "@") == NULL) //문자가 존재하는지 검사하는 함수
		{
			std::cout << "이메일 형식이 올바르지 않습니다." << std::endl;
			Sleep(1000);
			return 0;
		}
		return 1;
}

int Phonebook::chk_num_length(std::string phone_number){
		//전화번호입력이 배열의 길이를 넘을경우
		if(phone_number.length() > MAX_NUM_LENGTH)
		{
			std::cout<< "전화번호 길이제한(11자)을 초과하였습니다." <<std::endl;
			Sleep(1000);
			return 0;
		}

		else return 1;
}		

int Phonebook::add_info(Person_Info input) {
		//사용자 정보 추가 함수

		//종료문 검사
		if (strcmp(input.name, "END") == 0 || strcmp(input.address,"END") == 0 || strcmp(input.email,"END") == 0 || input.phone_number.compare("END") == 0)
			return -1;
		//이메일 및 전화번호 자리검사
		if (chk_email(input.email) != 1 || chk_num_length(input.phone_number) != 1)
			return 0;

		else{
			list[num_of_person] = input;
			num_of_person++; //사용자 수 카운트를 증가
			return 1;
		}
		return 2;
}

int Phonebook::del_info(char name[]) {
		//사용자 삭제 함수
		//search_info를 호출해 검색 후 삭제
		if (strcmp(name, "END") == 0) 
			return -1;

		Person_Info tmp_list[MAX_SIZE]; //동일한 이름의 사용자들을 임시저장하기 위한 list
		int person_index[MAX_SIZE]; //search_info로부터 받아오는 사용자의 index값을 저장
		int num_of_tmp_list = search_info(name, tmp_list,person_index); //검색된 사용자의 정보 및 수,원본배열에서의 index를 받아오기
		print_info(tmp_list,person_index,num_of_tmp_list); //출력

		if (num_of_tmp_list == 0) return 0; //사용자가 존재하지 않을 경우

		else if (num_of_tmp_list != 1 && num_of_tmp_list != -1) //여러명일 경우
		{
			int choice=0;
			std::cout << "동일한 이름의 사용자가 존재합니다" << std::endl;
			std::cout << "삭제 할 사용자의 Table number를 입력하세요." << std::endl;
			std::cout << "-1 입력 : 취소" << std::endl;

			while (1) {
				std::cout << ">>";
				std::cin >> choice;
				if (choice == -1) return -1;
				else if (strcmp(list[choice].name, name) != 0)
				{	
					//선택한 번호가 목록중에서 선택되지않았을 경우,배열의 범위가 아닌 다른 문자가 입력되었을 경우
					std::cout << "목록 중에서 선택하세요!!" << std::endl;
					std::cin.clear(); //오류스트림 초기화
					std::cin.ignore(INT_MAX, '\n'); //입력버퍼비우기
				}
				else break; //이름이 제대로 입력되었을 경우 while문 종료
			}

			for (int i = choice; i < num_of_person; i++)
			{
				//뒤에있는 값을 앞에 덮어씌우기
				list[i] = list[i + 1];
			}
			num_of_person--; //사용자 수 카운트의 값을 1 감소
			return 1;
		}

		else //한 명일경우
		{
			for (int i = 0; i < num_of_person; i++)
			{
				if (strcmp(list[i].name, name) == 0)
				{
					//검색된 위치에서부터 뒤의 나머지 배열들 정렬
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
		//사용자 정보 수정 함수
		//search_info를 호출해 검색 후 수정

		if(strcmp(name,"END") == 0) 
			return -1;

		Person_Info tmp; //수정할 내용을 임시저장
		Person_Info tmp_list[MAX_SIZE]; //사용자 정보 임시저장 리스트
		
		//search_info에 의해 검색 된 사용자들의 list배열에서의 위치정보를 순서대로 저장
		//만약 한 명일 경우 항상 person_index[0]에 저장된다.
		int person_index[MAX_SIZE]; 
		int num_of_tmp_list=search_info(name, tmp_list,person_index); //검색된 사용자의 정보 및 수,원본배열에서의 index를 받아오기
		
		if (num_of_tmp_list == 0 || num_of_tmp_list == -1) return 0;

		print_info(tmp_list,person_index,num_of_tmp_list); //출력
		
		if (num_of_tmp_list == 1) //단일 사용자에 대해 정보 수정
		{	
			//해당위치에 재입력
			//수정할 내용 입력받기
			while (1) {
				std::cout << "(이름, 전화번호, 주소, 이메일) : ";
				std::cin >> tmp.name >> tmp.phone_number >> tmp.address >> tmp.email;
				if (chk_email(tmp.email) == 1 && chk_num_length(tmp.phone_number) == 1) break;
			}
			list[person_index[0]] = tmp;
			return 1;
		}

		else //동일한 이름이 여려명 존재할 경우 선택 할 수 있게 함
		{
			int choice=0;
			std::cout << "동일한 이름이 " << num_of_tmp_list << "명 존재합니다."<<std::endl;
			std::cout << "수정할 사용자의 Table num을 선택하세요." << std::endl;
			std::cout << "-1 입력 : 취소" << std::endl;

			while (1) {
				std::cout << ">>";
				std::cin >> choice;
				if (choice == -1) return -1;
				else if (strcmp(list[choice].name, name) != 0)
				{
					//선택한 번호가 목록중에서 선택되지않았을 경우,배열의 범위가 아닌 다른 문자가 입력되었을 경우
					std::cout << "목록 중에서 선택하세요!!" << std::endl;
					std::cin.clear(); //오류스트림 초기화
					std::cin.ignore(INT_MAX, '\n'); //입력버퍼비우기
				}
				else break;
			}

			//해당위치에 재입력
			//수정할 내용 입력받기
			while (1) {
				std::cout << "(이름, 전화번호, 주소, 이메일) : ";
				std::cin >> tmp.name >> tmp.phone_number >> tmp.address >> tmp.email;
				if (chk_email(tmp.email) == 1 && chk_num_length(tmp.phone_number) == 1) break;
			}
			list[person_index[choice]] = tmp;
			return 1;
		}
}



void Phonebook::print_info() //전체 사용자 출력
	{
		if (num_of_person == 0)
		{ 
			std::cout << "저장된 사용자가 없습니다." << std::endl;
			std::cout << "아무키나 입력 : 이전으로 돌아가기" << std::endl;
			system("pause");
			return;
		}

		//2개씩 비교-strcmp 사전식 비교 사용
		//이름으로 정렬 후 출력(동일 철자시 철자가 짧은것을 먼저 오게 함 yoo>yoon
		Person_Info tmp;

		for (int i = 0; i < num_of_person; i++)
		{
			for (int j = i + 1; j < num_of_person; j++)

				if (strcmp(list[i].name, list[j].name) > 0) //앞에 문자열이 더 크거나 길면 바꾸기
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
		std::cout << "아무키나 입력 : 이전으로 돌아가기" << std::endl;
		system("pause");
}

void Phonebook::print_info(Person_Info Src_list[],int Src_index[],int num_of_person) //검색 된 사용자들을 출력
	{
		if(num_of_person == 0 || num_of_person == -1) return;
		std::cout << "=====================================" << std::endl;
		std::cout << "(Table num)|이름|전화번호|주소|이메일" << std::endl;
		std::cout << "=====================================" << std::endl;
		for(int i=0;i<num_of_person;i++){
			std::cout << Src_index[i] << " | ";
			std::cout << Src_list[i].name << " | ";
			std::cout << Src_list[i].phone_number << " | ";
			std::cout << Src_list[i].address << " | ";
			std::cout << Src_list[i].email << std::endl;
		}
		std::cout << "=====================================" << std::endl;
		std::cout << "아무키나 입력 : 계속" << std::endl;
		system("pause");
}

	
int Phonebook::search_info(char name[],Person_Info Dst_list[],int Dst_index[])
	{ 
		//이름으로 검색 후 사용자 출력,Dst_list에 검색된 사용자들을 전달 및 Dst_index에 해당 사용자의 Index값 전달
		
		if (strcmp(name, "END") == 0) 
			return -1;
		
		Person_Info tmp_list[MAX_SIZE]; //출력 및 값 전달을 위해 임시저장하는 list
		int num_of_tmp_list = 0; //tmp_list에 저장된 값의 수
		int Src_index[MAX_SIZE]; //원본배열의 index값을 저장하는 배열,Dst_index로 전달
		int tmp_index=0; // 원본배열 list에서 검색 후 해당 정보를 tmp_list 및 Src_index에 저장하기 위해 인덱싱하는 변수

		//검색
		for(int i = 0; i < num_of_person; i++) //동일한 이름이 존재하면 임시 리스트에 저장후 카운트 증가
		{
			//int i = 원본배열 list를 인덱싱하기위한 변수
			
			if (strcmp(list[i].name, name) == 0)
			{
				//tmp_list[Src_index[tmp_index]] == list[Src_index[tmp_index]]

				tmp_list[tmp_index] = list[i]; //해당 사용자 정보를 tmp_list에 저장
				Src_index[tmp_index]=i; //해당 사용자 index값을 Src_index에 저장

				//값 전달
				Dst_list[tmp_index] = tmp_list[tmp_index]; 
				Dst_index[tmp_index] = Src_index[tmp_index];
				tmp_index++;
				num_of_tmp_list++;
			}
		}

		if (num_of_tmp_list != 0) return num_of_tmp_list; //검색 된 동일 이름수를 리턴
		else
		{
			std::cout << "존재하지 않는 사용자입니다." << std::endl;
			Sleep(1000);
			return 0;
		}
}