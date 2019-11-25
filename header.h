#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h> //한글깨짐때문에 추가


#define MAX_SIZE 100
#define MAX_NUM_LENGTH 11

class Person_Info {
public:
	char name[MAX_SIZE]; //이름
	std::string phone_number; //전화번호
	char address[MAX_SIZE]; //주소	
	char email[MAX_SIZE]; //이메일
};


class Phonebook
{
private:
	int num_of_person; //저장되어있는 사람의 수
	Person_Info list[MAX_SIZE]; //사용자의 정보를 저장하기 위한 배열
	
public:
	Phonebook() {
		num_of_person = 0; //초기 사람수는 0
	}

	int chk_email(char email[]); //이메일 형식 검사 함수
	int chk_num_length(std::string phone_number); //전화번호 길이 검사 함수
	int add_info(Person_Info input); //사용자 정보 추가 함수
	int modify_info(char name[]); //사용자 정보 수정 함수
	void print_info() ; //전체 사용자 출력 함수
	void print_info(Person_Info Src_list[],int Src_index[],int num_of_person); //검색 된 사용자들을 출력
	int search_info(char name[],Person_Info Dst_list[],int Dst_index[]); //사용자 검색 함수
	int del_info(char name[]); //사용자 삭제 함수
};

//화면 출력용 함수
void disp_main();
void disp_add_info();
void disp_modify_info();
void disp_print_info_all();
void disp_search_info();
void disp_del_info();