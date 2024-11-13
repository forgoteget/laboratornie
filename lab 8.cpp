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
			for (char c : coun) {
				if (c == '!' || c == '.' || c == '?') { sum++; }
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
			string clearSen;
			for (int i = 0; i < sen.size(); i++) {
				if ((sen[i] == '.') || (sen[i] == '!') || (sen[i] == '?')) {
					clearSen.push_back(sen[i]);
					i++;
					while (sen[i] == ' ') {
						i++;
					}
					clearSen.push_back(' ');
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
			string newstring;
			while (i < sen.size()) {
				if (sen[i] == '.' || sen[i] == '?' || sen[i] == '!') {
					i++;
					if (sen[i] == ' ') {
						if (sen[i+1] == ' ') { newstring.push_back('0'); }
						else {	newstring.push_back('1'); }
					}
					if (sen[i] == '&') {
						if (sen[i + 1] == '&') { newstring.push_back('0'); }
						else { newstring.push_back('1'); }
						break;
					}
				}
				i++;
			}
			cout << "rashifrovka proshla" << endl;
			/*
			for (int i = 0; i < sen.size(); i++) {
				if (sen[i] == '.' || sen[i] == '?' || sen[i] == '!') {
					if ((i + 1) < sen.size() && sen[i+1] == ' ') {
						if ((i + 2) < sen.size() && sen[i + 2] == ' ') {
							newstring.push_back('0');
						}
						else {
							newstring.push_back('1');
						}
					}
					else {
						break;
					}
				}
			}*/
			return newstring;
		}

		string shifrovanie(string sen, string bits) {
			string newstring;
			sen = clearSentens(sen);
			bits = clearBits(bits);
			int j = 0;
			for (int i = 0; i < bits.size(); i++) {
				while (sen[j] != '.' && sen[j] != '!' && sen[j] != '?') {
					newstring.push_back(sen[j]);
					j++;
				}
				if (i == bits.size() - 1) {
					newstring.push_back(sen[j]);
					j++;
					if (bits[i] == '0') {
						newstring.push_back('&');
						newstring.push_back('&');
					}
					else {
						newstring.push_back('&');
					}
					j++;
					break;
				}
				else{
					newstring.push_back(sen[j]);
					j++;
					if (bits[i] == '0') {
						newstring.push_back(' ');
					}
				}
			}
			if (j < sen.size()) {
				for (int i = j; i < sen.size(); i++) {
					newstring.push_back(sen[i]);
				}
			}
			/*
			for (char c : bits) {
				while (sen[j] != '.' && sen[j] != '!' && sen[j] != '?') {
					newstring.push_back(sen[j]);
					j++;
				}
				newstring.push_back(sen[j]);
				j++;
				if (c == '1') {
					newstring.push_back(' ');
				}
				else {
					newstring.push_back(' ');
					newstring.push_back(' ');
				}
			}
			if (j < sen.size()) {
				for (int i = j; i < sen.size(); i++) {
					newstring.push_back(sen[i]);
				}
			}*/
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
			file.open(str);
			if (file.is_open()) {
				while (getline(file, str2)) {
					str1 = str1 + str2;
				}
			}
			else {
				cout << "oshibka vvoda!" << endl;
			}
			cout << endl << endl << "Polycheniy Iz Faila Konteiner: " << str1;
			return str1;
		}
};
// Добавить ограничитель, возможность шифровать слова и предложения

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

	mesto = chan.vmesimist(countainer);
	cout << endl << "V danniy konteiner mojno zakodirovat': " << mesto / 8 << " symvol(ov)" << endl;

	//Шифруемые символы
	cout << endl << "vvedite english symbol dlya shifrovki: ";
	cin >> strToNumber;
	for (char c : strToNumber) {
		bitset<8> num(c);
//		cout << endl << num << endl; 
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

//	bitset<8> num(ch);// 01001101
//	string zasfrcont = chan.shifrovanie(countainer, num.to_string());


	/*
	cout << "Zashifrovaniy container: " << endl
		<< zasfrcont << endl
		<< "Rashifrovka: " << chan.rashifrovka(zasfrcont) << endl
		<< "Ischodniy symbol: " << chan.vivodIschodnogoSimvola(chan.rashifrovka(zasfrcont));*/
//	cout << chan.vmesimist(countainer) << endl
//		<< chan.proverka(countainer, num.to_string()) << endl << (num.to_string()).size();
	return 0;
}