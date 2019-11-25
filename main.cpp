#include "header.h"

void main() {
	_wsetlocale( LC_ALL, L"korean" ); //지역화 설정을 전역적으로 적용

	Person_Info tmp; //사용자 정보 입력받아 임시저장
	Phonebook MyBook;
	char name[MAX_SIZE]; //입력,수정,삭제하기위해 이름을 저장하는 변수

	//search_info를 호출하기 위해 생성
	Person_Info tmp_list[MAX_SIZE];
	int tmp_index[MAX_SIZE];
	int num_of_tmp_list = 0;
	/*
	함수 리턴값
	-1 : 사용자실행취소
	0 : 실패
	1 : 성공
	2 : 기타오류
	*/

	while(1){
		int main_select = 0;

		disp_main();
		std::cin >> main_select;

		if (main_select == 6)
			break;

		//!(cin >> main_select)
		else if (main_select < 1 || main_select > 6)
		//입력범위 초과 또는 잘못된 문자입력
		{
			std::cout << "메뉴중에서 선택하세요!!" << std::endl;
			std::cin.clear(); //오류스트림 초기화
			std::cin.ignore(INT_MAX, '\n'); //입력버퍼비우기
			Sleep(1000);
		}

			switch (main_select)
			{
			case 1: //사용자 정보 추가
				disp_add_info();
				std::cin >> tmp.name >> tmp.phone_number >> tmp.address >> tmp.email;
				if (MyBook.add_info(tmp) == 1) {
					std::cout << "성공적으로 추가되었습니다." << std::endl;
					Sleep(1000);
				}
				break;

			case 2: //사용자 정보 수정
				disp_modify_info();
				std::cin >> name;
				if (MyBook.modify_info(name) == 1)
				{
					std::cout << "성공적으로 수정되었습니다." << std::endl;
					Sleep(1000);
				}
				else {
					std::cout << "사용자 정보 수정 실패 또는 취소" << std::endl;
					Sleep(1000);
				}
				break;

			case 3: //사용자 삭제
				disp_del_info();
				std::cin >> name;
				if (MyBook.del_info(name) == 1)
				{
					std::cout << "성공적으로 삭제되었습니다." << std::endl;
					Sleep(1000);
				}
				else{
					std::cout<< "사용자 삭제 실패 또는 취소" <<std::endl;
					Sleep(1000);
				}
				break;

			case 4: //사용자 검색				
				disp_search_info();
				std::cin >> name;
				//num_of_tmp_list,tmp_index, tmp_list는 search_info 호출시에 매번 바뀌게되므로 사용후 초기화할 필요가없다
				num_of_tmp_list=MyBook.search_info(name, tmp_list, tmp_index);
				MyBook.print_info(tmp_list,tmp_index,num_of_tmp_list);
				break;

			case 5: //전화번호부 전체 출력
				disp_print_info_all();
				MyBook.print_info();
				break;
			}
	}
}