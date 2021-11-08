#include<iostream>
#include<fstream>// Файловые потоки

using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
int main()
{
	setlocale(LC_ALL, "");
	#ifdef WRITE_TO_FILE;
	//cout << "HelloWorld" << endl;
	ofstream fout("file.txt",ios::app);// Создаем и открываем поток
	fout << "HelloWorld" <<endl;
	fout.close();//потоки обезательно нужно закрывать
	system("notepad file.txt");// открывает блокнот(more- командная строка)
	#endif WRITE_TO_FILE;



	#ifdef READ_FROM_FILE;
	ifstream fin;// создаем поток
	fin.open("file.txt");
	const unsigned int SIZE = 256;
	char sz_bufer[SIZE]{};// в эту строку будем читать из файла
	//sz_ - String Zero (строка заканчивающаясся нулем)
	if (fin.is_open())// проверяем открыт ли файл
	{
			//TODO:будем читать
		while (!fin.eof())//отслеживается нонец файла
		{
			//будет производиться чтение
			//eof() - End of file
			//fin >> sz_bufer;//читает до пробела
			fin.ignore();
			fin.getline(sz_bufer, SIZE);//читает до конца файла
			cout << sz_bufer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found"<<endl;//вывод ошибки
	}

	fin.close();
	#endif READ_FROM_FILE;

	// Поменять местами ip и mac адреса в файле 201 RAW
	ifstream fin;
	fin.open("201 RAW.txt");
	const size_t sizeIP = 15;
	const size_t sizeMAC = 18;
	char ip[sizeIP]{};
	char mac[sizeMAC]{};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> ip;
			fin >> mac;
			ofstream fout("201 RRAW.txt", ios::app);
			fout << mac<<"\t\t" << ip << endl;
			fout.close();
			
		}

	}else cerr << "Error: file not found" << endl;
	



	fin.close();
	//system("notepad 201 RRAW.txt");
	
	return 0;
}