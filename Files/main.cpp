#include<iostream>
#include<fstream>// �������� ������

using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
int main()
{
	setlocale(LC_ALL, "");
	#ifdef WRITE_TO_FILE;
	//cout << "HelloWorld" << endl;
	ofstream fout("file.txt",ios::app);// ������� � ��������� �����
	fout << "HelloWorld" <<endl;
	fout.close();//������ ����������� ����� ���������
	system("notepad file.txt");// ��������� �������(more- ��������� ������)
	#endif WRITE_TO_FILE;



	#ifdef READ_FROM_FILE;
	ifstream fin;// ������� �����
	fin.open("file.txt");
	const unsigned int SIZE = 256;
	char sz_bufer[SIZE]{};// � ��� ������ ����� ������ �� �����
	//sz_ - String Zero (������ ���������������� �����)
	if (fin.is_open())// ��������� ������ �� ����
	{
			//TODO:����� ������
		while (!fin.eof())//������������� ����� �����
		{
			//����� ������������� ������
			//eof() - End of file
			//fin >> sz_bufer;//������ �� �������
			fin.ignore();
			fin.getline(sz_bufer, SIZE);//������ �� ����� �����
			cout << sz_bufer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found"<<endl;//����� ������
	}

	fin.close();
	#endif READ_FROM_FILE;

	// �������� ������� ip � mac ������ � ����� 201 RAW
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