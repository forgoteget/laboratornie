#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <fstream>
using namespace std;

class change {
private:

public:
	int vmesimist(string coun) {
		int sum = 0;
		char perenos = '\\';
		for (char c : coun) {
			if (c == perenos) { sum++; }
		}
		return sum;
	}

	bool proverka(string coun, string bits) {
		if (vmesimist(coun) >= int(bits.size())) {
			cout << "shifrovanie voxmojno" << endl;
			return true;
		}
		else {
			cout << "Ne lezet" << endl;
			return false;
		}
	}

	string clearSentens(string sen) {
		string helpstring;
		string clearSen;
		char perenos = '\\';
		int j = 1;
		for (int i = 0; i < sen.size(); i++) {
			if (sen[i] == perenos) {
				j = 1;
				while (sen[i - j] == ' ') {
					clearSen.pop_back();
					j++;
				}
			}
			clearSen.push_back(sen[i]);
		}
		return clearSen;
	}

	string clearBits(string bits) {
		string rightBits;
		int j = 0;
		while (bits[j] == '0') {
			j++;
		}
		for (int i = j; i < bits.size(); i++) {
			rightBits.push_back(bits[i]);
		}
		return rightBits;
	}

	string rashifrovka(string sen) {
		int i = 0;
		char perenos = '\\';
		string newstring;
		for (int i = 0; i < sen.size(); i++) {
			if (sen[i] == perenos && sen[i-1] == ' ') {
				if (sen[i - 2] == ' ') {
					newstring.push_back('0');
				}
				else {
					newstring.push_back('1');
				}
			}
		}
		cout << "do rashifrovki" << newstring << endl << "rashifrovka proshla" << endl;
		return newstring;
	}

	string shifrovanie(string sen, string bits) {
		string newstring;
		cout << endl << endl << "slkgnsongosnfognofj" << bits << endl << endl;
		sen = clearSentens(sen);
		bits = clearBits(bits);
		int j = 0;
		char perenos = '\\';
		for (int i = 0; i < sen.size(); i++) {
			if (sen[i] == perenos && j < bits.size()) {
				if (bits[j] == '1') {
					newstring.push_back(' ');
				}
				else {
					newstring.push_back(' ');
					newstring.push_back(' ');
				}
				j++;
			}
			newstring.push_back(sen[i]);
		}
		return newstring;
	}

	string vivodIschodnogoSimvola(string chislo) {
		string result;
		int sum = 0;
		int sl1 = chislo.size() / 8;
		int sl2 = chislo.size() % 8;
		for (int i = 0; i < sl2; i++) {
			if (chislo[i] == '1') {
				sum = sum + pow(2, sl2 - i - 1);
			}
		}
		result.push_back(char(sum));
		sum = 0;
		for (int i = 0; i < sl1; i++) {
			for (int j = 0; j < 8; j++) {
				if (chislo[i * 8 + sl2 + j] == '1') {
					sum = sum + pow(2, 7 - j);
				}
			}
			result.push_back(char(sum));
			sum = 0;
		}
		return result;
	}

	string txtToCountainer(string str) {
		string str1;
		string str2;
		fstream file;
		string perenos = "\\n";
		file.open(str);
		if (file.is_open()) {
			while (getline(file, str2)) {
				str1 = str1 + str2 + perenos;
			}
		}
		else {
			cout << "oshibka vvoda!" << endl;
		}
		cout << endl << endl << "Polycheniy Iz Faila Konteiner: " << str1;
		return str1;
	}
};

int main() {
	string countainer;
	change chan;
	string nameFile;
	string strToNumber;
	string toShifrCountainer;
	string zasfrcont;
	char ch;
	int mesto;

	//получаем контейнер для кодировки
	cout << "vvedite imya faila s konteinerom: ";
	cin >> nameFile;
	countainer = chan.txtToCountainer(nameFile);
	countainer = chan.clearSentens(countainer);
	cout << endl << endl << "Podgotovlenniy k shifrovaniu kontainer: " << endl << countainer;
	mesto = chan.vmesimist(countainer);
	cout << endl << endl << "V danniy konteiner mojno zakodirovat': " << mesto / 8 << " symvol(ov)" << endl;

	cout << endl << "vvedite english symbol dlya shifrovki: ";
	cin >> strToNumber;
	for (char c : strToNumber) {
		bitset<8> num(c);
		toShifrCountainer += num.to_string();
		cout << "Shifruimie symvoli v dvoichnom code: " << toShifrCountainer << endl;
	}
	if (!chan.proverka(countainer, toShifrCountainer)) {
		return 2;
	}

	zasfrcont = chan.shifrovanie(countainer, toShifrCountainer);
	cout << endl << endl << "zashifrovanniy counteiner: " << endl << zasfrcont;

	cout << endl << endl << "rashifrovannoe soobshenie: " << endl << chan.vivodIschodnogoSimvola(chan.rashifrovka(zasfrcont)) << endl;

	/*
	mesto = chan.vmesimist(countainer);
	cout << endl << "V danniy konteiner mojno zakodirovat': " << mesto / 8 << " symvol(ov)" << endl;

	//Шифруемые символы
	cout << endl << "vvedite english symbol dlya shifrovki: ";
	cin >> strToNumber;
	for (char c : strToNumber) {
		bitset<8> num(c);
		toShifrCountainer += num.to_string();
		cout << "Shifruimie symvoli v dvoichnom code: " << toShifrCountainer << endl;
	}
	if (!chan.proverka(countainer, toShifrCountainer)) {
		return 2;
	}

	//запускаем шифровку
	zasfrcont = chan.shifrovanie(countainer, toShifrCountainer);
	cout << endl << endl << "zashifrovanniy counteiner: " << endl << zasfrcont;

	cout << endl << endl << "rashifrovannoe soobshenie: " << endl << chan.vivodIschodnogoSimvola(chan.rashifrovka(zasfrcont)) << endl;

	*/

	return 0;
}