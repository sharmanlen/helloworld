/** @file   lab3.cpp
 *  @brief  прототипы функции длЯ лабы3
 * выводит на экран на оснолве введенных данных пользователя полную информацию о книгах, которые есть в наличии(год издания, автора, издательство )
 *  информациЯ .котораЯ понадобитсЯ длЯ данной лабы3
 *  содержит прототипы длЯ файла реализации lab3.cpp
 *
 *  @author Vokueva Lena, Martusheva Leonida, Mezhdunowa Esmira.
 *  @date   11/05/2019
 *  @bug    No known bugs.
 */
#include <iostream>				// мне лень их описывать, непонятно
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;
// все данные хранящиеся в файле, больше не придумала. ===================================================================
// прошу заметить что в файле все значения стоят через Tab.
struct book{
	std::string author;			//автор
	std::string book_name;		//название книги
	std::string year;			//год
		
	char buff_year[4];			// "год"
			
};

//  =================================================================================================
void go(){
	
	bool satisfies = true;		//флаг цикла. флаг указывает на то, устраивает ли нас ввод пользователя.
	
	unsigned int numberOfArgument = 0;		// 0 - дефолтный. показывает номер параметра по которому будут икаться книги.
	
	char *letters = new char[200];			//пусть длина будет ну... пусть 200. Почему? Потому что я так хочу.
	

	do{		
		char *lettersForArgument = new char[50];	//пофиг. пусть будет 50. это нужно для проверки.
		
		//#1
		std::cout<< "Введите номер параметра по которому будут искаться книги.\n\t1 - автор\n\t2 - название\n\t3 - год\nВаш выбор: "<<std::endl;
		std::cin.getline(lettersForArgument,50);
		
		
		//Этот кусок... эмм... кусок кода извлекает только первое число из введенного набора знаков. ну... типа, мол юзер такой тупой и ввел свое соченение по русскому вместо нужной цифры.
		for(int i=0; i<strlen(lettersForArgument);i++){
			
			if(isdigit(lettersForArgument[i])){
				numberOfArgument = lettersForArgument[i] - '0';		
				if(1<=numberOfArgument&&numberOfArgument<=4)
					satisfies=false;	//вот и наш флаг		
			}
		}
		std::cout<<"Вы ввели: "<<numberOfArgument<<std::endl;
		
		
		//#2
		std::cout<< "Введите значение параметра: "<<std::endl;
		std::cin.getline(letters,200);
		std::cout<<"Вы ввели: "<<letters<<std::endl;
		
		//юзеру надо сообщить в чем он ошибся.
		if(!(1<=numberOfArgument&&numberOfArgument<=4))
			std::cout<<"Вы неверно ввели параметр"<<std::endl;
		else
			std::cout<<"Параметр подходит...\nИщем книгу..."<<std::endl;
			
	}while(satisfies); //проверяем флаг. если true, повторяем.
	
	// логическая концовка ввода и начало обработки ====================================================================
	
	std::string line;	// переменная, в которой будет хранится строка.
	book one_book;
	
	bool findbook = false;  //были ли найдены книги?
	
	//открываю файл
	std::ifstream in("knigi.txt");
	
	//проверка. открыт ли файл
	if(in.is_open()){
		
		std::cout<<"Подходящие книги:"<<std::endl;	//надо же хоть какойто базовый интерфейс предоставить
		
		// запихиваем строку из файла in до знака \n в переменную line
		while(getline(in, line, '\n')){
			
			std::stringstream line2;		// создаем из строки поток
			line2 << line;					//
			
			getline(line2,one_book.author,'.');		    	//
			getline(line2,one_book.book_name,'.');			//
			getline(line2,one_book.year, '.');				//	Мастерски разбиваем строку на значения, записанные в структуре
			//line2.getline(one_book.buff_year, 5,'.');		//
			//getline(line2,one_book.cost, '.');				//
			//line2.getline(one_book.buff_val, 4,'.');		//
			
			/*unsigned short cost;		//
			std::stringstream str;		//	перевод из string в int т.к. цена у нас это число, а не строка
			str << one_book.cost;		//
			str >> cost;*/				//
			
			
		
					
					
					bool suitable = false;	// переменная говорит подходит ли нам данная книга.
						
						switch(numberOfArgument)
						{
							case 1:
								if(one_book.author==letters){		// Если книга удовлетворяет условию, значит подходит.
								suitable = true;
							}
								break;
							case 2:
								if(one_book.book_name==letters){		// Если книга удовлетворяет условию, значит подходит. 
								suitable = true;
							}
								break;
							case 3:
								if(one_book.year==letters){		// Если книга удовлетворяет условию, значит подходит. 
									suitable = true;
								}
								break;
							/*case 4:
								if(one_book.cost==letters){		// Если книга удовлетворяет условию, значит подходит.
									suitable = true;
								}
								break;*/
						}
						
						//Если книга подходит, записываем.
						if (suitable)
						{
							std::cout<<one_book.author<<"."<<one_book.book_name<<"\t"<<one_book.year<</*"\t"<<one_book.cost<<"*/"\n";
							findbook = true;	
						}
						
		
			
		}	
		if(!findbook) std::cout<<"Мне так жаль, но увы мы не нашли подходящих книг"<<std::endl;	
	}
	else	std::cout<<"File is not connected..."<<std::endl; //ну типа, файл не соединен с программой. Ошибочка вышла.
	
	std::cout<<"Спасибо, что воспользовались нашими услугами"<<std::endl; //вежливое прощание.
}



//Главный метод, начало программы ================================================================================================================================================
int main(int argc, char** argv) {
	
	//Русскоязычный ввод и вывод

	setlocale(LC_ALL, "Russian");
	setlocale(0, "");
	cout<<"привет"<<endl;
	std::cout<<"Программа с хранилищем книг"<<std::endl;
	go(); //запускаем 
	
	system("pause");
	return 0;
}
