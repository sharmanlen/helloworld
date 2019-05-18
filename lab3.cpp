/** @file   lab3.cpp
 *  @brief  ��������� ������� ��� ����3
 * ������� �� ����� �� ������� ��������� ������ ������������ ������ ���������� � ������, ������� ���� � �������(��� �������, ������, ������������ )
 *  ���������� .������� ����������� ��� ������ ����3
 *  �������� ��������� ��� ����� ���������� lab3.cpp
 *
 *  @author Vokueva Lena, Martusheva Leonida, Mezhdunowa Esmira.
 *  @date   11/05/2019
 *  @bug    No known bugs.
 */
#include <iostream>				// ��� ���� �� ���������, ���������
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;
// ��� ������ ���������� � �����, ������ �� ���������. ===================================================================
// ����� �������� ��� � ����� ��� �������� ����� ����� Tab.
struct book{
	std::string author;			//�����
	std::string book_name;		//�������� �����
	std::string year;			//���
		
	char buff_year[4];			// "���"
			
};

//  =================================================================================================
void go(){
	
	bool satisfies = true;		//���� �����. ���� ��������� �� ��, ���������� �� ��� ���� ������������.
	
	unsigned int numberOfArgument = 0;		// 0 - ���������. ���������� ����� ��������� �� �������� ����� ������� �����.
	
	char *letters = new char[200];			//����� ����� ����� ��... ����� 200. ������? ������ ��� � ��� ����.
	

	do{		
		char *lettersForArgument = new char[50];	//�����. ����� ����� 50. ��� ����� ��� ��������.
		
		//#1
		std::cout<< "������� ����� ��������� �� �������� ����� �������� �����.\n\t1 - �����\n\t2 - ��������\n\t3 - ���\n��� �����: "<<std::endl;
		std::cin.getline(lettersForArgument,50);
		
		
		//���� �����... ���... ����� ���� ��������� ������ ������ ����� �� ���������� ������ ������. ��... ����, ��� ���� ����� ����� � ���� ���� ��������� �� �������� ������ ������ �����.
		for(int i=0; i<strlen(lettersForArgument);i++){
			
			if(isdigit(lettersForArgument[i])){
				numberOfArgument = lettersForArgument[i] - '0';		
				if(1<=numberOfArgument&&numberOfArgument<=4)
					satisfies=false;	//��� � ��� ����		
			}
		}
		std::cout<<"�� �����: "<<numberOfArgument<<std::endl;
		
		
		//#2
		std::cout<< "������� �������� ���������: "<<std::endl;
		std::cin.getline(letters,200);
		std::cout<<"�� �����: "<<letters<<std::endl;
		
		//����� ���� �������� � ��� �� ������.
		if(!(1<=numberOfArgument&&numberOfArgument<=4))
			std::cout<<"�� ������� ����� ��������"<<std::endl;
		else
			std::cout<<"�������� ��������...\n���� �����..."<<std::endl;
			
	}while(satisfies); //��������� ����. ���� true, ���������.
	
	// ���������� �������� ����� � ������ ��������� ====================================================================
	
	std::string line;	// ����������, � ������� ����� �������� ������.
	book one_book;
	
	bool findbook = false;  //���� �� ������� �����?
	
	//�������� ����
	std::ifstream in("knigi.txt");
	
	//��������. ������ �� ����
	if(in.is_open()){
		
		std::cout<<"���������� �����:"<<std::endl;	//���� �� ���� ������� ������� ��������� ������������
		
		// ���������� ������ �� ����� in �� ����� \n � ���������� line
		while(getline(in, line, '\n')){
			
			std::stringstream line2;		// ������� �� ������ �����
			line2 << line;					//
			
			getline(line2,one_book.author,'.');		    	//
			getline(line2,one_book.book_name,'.');			//
			getline(line2,one_book.year, '.');				//	��������� ��������� ������ �� ��������, ���������� � ���������
			//line2.getline(one_book.buff_year, 5,'.');		//
			//getline(line2,one_book.cost, '.');				//
			//line2.getline(one_book.buff_val, 4,'.');		//
			
			/*unsigned short cost;		//
			std::stringstream str;		//	������� �� string � int �.�. ���� � ��� ��� �����, � �� ������
			str << one_book.cost;		//
			str >> cost;*/				//
			
			
		
					
					
					bool suitable = false;	// ���������� ������� �������� �� ��� ������ �����.
						
						switch(numberOfArgument)
						{
							case 1:
								if(one_book.author==letters){		// ���� ����� ������������� �������, ������ ��������.
								suitable = true;
							}
								break;
							case 2:
								if(one_book.book_name==letters){		// ���� ����� ������������� �������, ������ ��������. 
								suitable = true;
							}
								break;
							case 3:
								if(one_book.year==letters){		// ���� ����� ������������� �������, ������ ��������. 
									suitable = true;
								}
								break;
							/*case 4:
								if(one_book.cost==letters){		// ���� ����� ������������� �������, ������ ��������.
									suitable = true;
								}
								break;*/
						}
						
						//���� ����� ��������, ����������.
						if (suitable)
						{
							std::cout<<one_book.author<<"."<<one_book.book_name<<"\t"<<one_book.year<</*"\t"<<one_book.cost<<"*/"\n";
							findbook = true;	
						}
						
		
			
		}	
		if(!findbook) std::cout<<"��� ��� ����, �� ��� �� �� ����� ���������� ����"<<std::endl;	
	}
	else	std::cout<<"File is not connected..."<<std::endl; //�� ����, ���� �� �������� � ����������. �������� �����.
	
	std::cout<<"�������, ��� ��������������� ������ ��������"<<std::endl; //�������� ��������.
}



//������� �����, ������ ��������� ================================================================================================================================================
int main(int argc, char** argv) {
	
	//������������� ���� � �����

	setlocale(LC_ALL, "Russian");
	setlocale(0, "");
	cout<<"������"<<endl;
	std::cout<<"��������� � ���������� ����"<<std::endl;
	go(); //��������� 
	
	system("pause");
	return 0;
}
