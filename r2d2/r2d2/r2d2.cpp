#include <iostream>
#include <map>
#include <Windows.h>
#include <string>
using namespace std;
struct com {
	string name;
	void clear() {
		system("cls");
	}
	void set_color(string col) {
		system(("color " + col).c_str());
	}
	void start_prog(string name) {
		system(("start " + name).c_str());
	}
	void hello() {
		cout << "Пока, уебан тупой бля\n";
	}
	void help(string cm) {
		if (cm == "") {
			cout << "Слыш, короче:\n";
			cout << "1. Ты никто, поэтому слушай внимательно, иначе то би звезда.\n";
			cout << "2. Тут есть clear, он очищает консоль\n";
			cout << "3. Тут есть color, после него надо писать цифрой цвет, потому что он не хуем деланный. А деланный ли хуем ты?\n";
			cout << "4. Тут есть start, он в натуре просто открывает прогу.\n";
			cout << "5. Тут есть привет, это ты пытаешься со мной поздороваться\n";
			cout << "6. Тут есть exit, еще одна бесполезная команда. Тупо закрывает терминал нахуй. Это тупо нажатие на крестик...\n";
			cout << "7. Тут есть power, там можно off и reload (если после off текст будет, то он его напишет) и еще cancel отменяющий выключение а еще quiet чтобы без предупреждения бля\n";
			cout << "А теперь иди нахуй и чтобы глаза мои тебя не видели бля\n";
			cout << "А еще кст, ты можешь вызвать help и потом название команды чтобы узнать о ней больше\n";
		}
		else {
			cout << "бля вызов help еще не настроен для команд (иди нахуй)\n";
		}
	}
	void off(string attrib) {
		if (attrib == "reload") {
			system("shutdown /r");
		}
		else if (attrib[0] == 'o' and attrib[1] == 'f' and attrib[2] == 'f') {
			string comment = "";
			for (int i = 3; i < attrib.size(); i++) {
				comment += attrib[i];
			}
			if (comment == "") {
				system("shutdown /s");
			}
			else {
				system(("shutdown /s /c " + comment).c_str());
			}
		}
		else if (attrib == "cancel") {
			system("shutdown /a");
		}
		else if (attrib == "quiet") {
			system("shutdown /s /c " "");
		}
		else {
			cout << "нет такого в power, читать научись даун все в help написано бля\n";
		}
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	com term;
	string command, attrib, text, act;
	bool ws;
	while (1) {
		cout << "r2d2> ";
		getline(cin, text);
		act = "";
		ws = false;
		attrib = "";
		command = "";
		for (char i : text) {
			if (ws) {
				attrib += i;
			}
			else {
				if (i == ' ') {
					ws = true;
				}
				else {
					command += i;
				}
			}
		}
		if (command == "clear") {
			term.clear();
		}
		else if (command == "color") {
			term.set_color(attrib);
		}
		else if (command == "exit") {
			exit(0);
		}
		else if (command == "start") {
			term.start_prog(attrib);
		}
		else if (command == "привет") {
			term.hello();
		}
		else if (command == "help") {
			term.help(attrib);
		}
		else if (command == "power") {
			term.off(attrib);
		}
		else {
			cout << "неизвестная команда, иди нахуй\n";
		}
	}
}