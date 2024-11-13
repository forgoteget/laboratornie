#include "EvryThng.h"
#include <iostream>
#include <conio.h>
#define BUF_SIZE 256
#include <locale.h>


using namespace std;

HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void outMenu() {
	cout << "�������� ��������:" << endl;
	PrintMsg(hOut, "\t1. ������� ����\n");
	PrintMsg(hOut, "\t2. ������������� ����\n");
	PrintMsg(hOut, "\t3. ���������� ����\n");
	PrintMsg(hOut, "\t4. ������� ����\n");
	PrintMsg(hOut, "\t5. ������� �������\n");
	PrintMsg(hOut, "\t6. ������� �������\n");
	PrintMsg(hOut, "\t?. �������\n");
	PrintMsg(hOut, "\t0. �����\n");
	PrintMsg(hOut, "������� ����� ��������:\t");
}

//������� ����
void createFile() {
	string err = "������ � ";
	char fileName[BUF_SIZE];
	HANDLE hFile;
	ConsolePrompt("Input name of new file (name_file.txt):\t", fileName, BUF_SIZE, true);
	hFile = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		err.append(fileName);
	}
	//����������� ��������� ����������
	CloseHandle(hFile);
	ReportError((LPCTSTR)err.c_str(), 0, true);
}


void copyFile() {
	char fileIn[BUF_SIZE];
	char fileOut[BUF_SIZE];
	ConsolePrompt("Input file name for copy:\t", fileIn, BUF_SIZE, true);
	ConsolePrompt("Input file name where copy:\t", fileOut, BUF_SIZE, true);
	bool hFile = CopyFile(fileIn, fileOut, false);
	if (hFile == 0) {
		string err = "������ � ";
		err.append(fileIn);
		err.append(" � ");
		err.append(fileOut);
		ReportError((LPCTSTR)err.c_str(), 0, true);
		
	};
};


void renameFile() {
	char fileIn[BUF_SIZE];
	char fileOut[BUF_SIZE];
	char answer[BUF_SIZE];
	ConsolePrompt("Are you sure? [y/n]:\t", answer, BUF_SIZE, true);
	if (answer[0] == 'y') {
		ConsolePrompt("Input current file name:\t", fileIn, BUF_SIZE, true);
		ConsolePrompt("Input new file name:\t", fileOut, BUF_SIZE, true);
		if (!MoveFile(fileIn, fileOut)) {
			string err = "������ � ";
			err.append(fileIn);
			ReportError((LPCTSTR)err.c_str(), 0, true);
		};
	}
	else {
		PrintMsg(hOut, "Enter");
	}
	
};

void deleteFile() {
	char fileName[BUF_SIZE];
	ConsolePrompt("Input fileName for delete:\t", fileName, BUF_SIZE, true);
	if (DeleteFile(fileName) == 0) {
		string err = "������ ��� �������� ����� ";
		err.append(fileName);
		ReportError((LPCTSTR)err.c_str(), 0, true);
	}
	
};

void createCatalog() {
	char catalogeName[BUF_SIZE];
	ConsolePrompt("Input new catalog name for create:\t", catalogeName, BUF_SIZE, true);
	if (CreateDirectory(catalogeName, NULL) == 0) {
		string err = "������ ��� �������� �������� ";
		err.append(catalogeName);
		ReportError((LPCTSTR)err.c_str(), 1, true);
	};
};

void deleteCatalog() {
	char catalogeName[BUF_SIZE];
	ConsolePrompt("Input catalog name for delete:\t", catalogeName, BUF_SIZE, true);
	if (!RemoveDirectory(catalogeName)) {
		string err = "������ ��� �������� �������� ";
		err.append(catalogeName);
		ReportError((LPCTSTR)err.c_str(), 1, true);
	};
};



int main(int argc, LPTSTR argv[]) {

	setlocale(LC_ALL, "rus");
	char state = '1';

	while (state != '0') {

		//������� ������� �� ������� �������� � ������� ����
		system("cls");
		outMenu();

		//���� ������ ��������
		cin >> state;

		//���������� ��������
		switch (state)
		{
		case '1': 
			createFile();
			_getch();
			break;
		case '2': 
			renameFile();
			_getch();
			break;
		case '3':  
			copyFile();
			_getch();
			break;
		case '4': 
			deleteFile();
			_getch();
			break;
		case '5': 
			createCatalog();
			_getch();
			break;
		case '6':
			deleteCatalog();
			_getch();
			break;
		case '?': 
			cout << "������ ��������� ������������� ������������� �������� ������� ��������� ������ � ���������\n� �� ������ ���� ��������� ������������ ���������, �������, ����������, \n��������������� ����� � ����������� �������� ��������" << endl; 
			cout << "��� ����������� ������� ����� �������" << endl;
			_getch();
			break;
		default: 
			cout << "���!\n���-�� ����� �� ���.\n������� ���������� ����� ��������" << endl;
			cout << "��� ����������� ������� ����� �������" << endl;
			_getch();
			break;
		}
		
	};

	return 0;
}




