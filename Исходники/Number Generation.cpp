#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

int att = 1;
std::atomic<int> time1 = 0;

std::atomic<bool> runn = true;

void master() {
	while (runn) {
		system("cls");
		std::cout << "Time: " << time1 << " Att: " << att;
		time1 += 1;
		Sleep(1000);
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string number;
	std::string text;
	int ch;
	int Bign = 0;

	while (true) {
		std::cout << "=============================\n";
		Sleep(20);
		std::cout << "[1] - Генерация номеров\n";
		Sleep(20);
		std::cout << "[2] - Тестовая генерация\n";
		Sleep(20);
		std::cout << "=============================\n";
		std::cin >> ch;
		system("cls");
		if (ch == 1) {
			std::cout << "=============================\n";
			Sleep(20);
			std::cout << "[1] - Русские номера\n";
			Sleep(20);
			std::cout << "[2] - Белоруские номера\n";
			Sleep(20);
			std::cout << "=============================\n";
			std::cin >> ch;
			if (ch == 1) {
				while (true) {
					system("cls");
					for (int i = 0; i < 10; i++) {
						number.clear();
						std::random_device rd;
						std::mt19937 gen(rd());
						std::uniform_int_distribution<> dist('a', 'z');
						std::uniform_int_distribution<> dist1(1, 9);
						std::uniform_int_distribution<> dist2(10, 99);

						number += dist(gen);

						for (int i = 0; i < 3; i++) {
							number += std::to_string(dist1(gen));
						}
						for (int i = 0; i < 2; i++) {
							number += dist(gen);
						}
						number += " ";
						number += std::to_string(dist2(gen));
						std::cout << "[ " << number << " ]\n";
					}
					Sleep(3000);
				}
			}
			else if (ch == 2) {
				while (true) {
					system("cls");
					for (int i = 0; i < 10; i++) {
						number.clear();
						std::random_device rd;
						std::mt19937 gen(rd());
						std::uniform_int_distribution<> dist('a', 'z');
						std::uniform_int_distribution<> dist1(1, 9);

						for (int i = 0; i < 4; i++) {
							number += std::to_string(dist1(gen));
						}
						for (int i = 0; i < 2; i++) {
							number += dist(gen);
						}
						number += " ";
						number += std::to_string(dist1(gen));
						std::cout << "[ " << number << " ]\n";
					}
					Sleep(3000);
				}
			}
		}
		else if (ch == 2) {
			std::cout << "=============================\n";
			Sleep(20);
			std::cout << "[1] - Русские номера\n";
			Sleep(20);
			std::cout << "[2] - Белоруские номера\n";
			Sleep(20);
			std::cout << "=============================\n";
			std::cin >> ch;
			system("cls");
			if (ch == 1) {
				std::cout << "=============================\n";
				Sleep(20);
				std::cout << "Формат номера: x123xx 10-99\n";
				Sleep(20);
				std::cout << "Пример номера: a734px 55\n";
				Sleep(20);
				std::cout << "=============================\n";
				std::cin.ignore();
				std::getline(std::cin, text);
				system("cls");
				std::thread th(master);
				while (true) {
					number.clear();
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> dist('a', 'z');
					std::uniform_int_distribution<> dist1(1, 9);
					std::uniform_int_distribution<> dist2(10, 99);

					number += dist(gen);

					for (int i = 0; i < 3; i++) {
						number += std::to_string(dist1(gen));
					}
					for (int i = 0; i < 2; i++) {
						number += dist(gen);
					}
					number += " ";
					number += std::to_string(dist2(gen));

					if (number == text) {
						runn = false;
						th.join();
						std::cout << "Time: " << time1 << " Number: " << text << " Att: " << att;
						Sleep(INFINITE);
					}
					else {
						att += 1;
					}
				}
			}
			else if (ch == 2) {
				std::cout << "=============================\n";
				Sleep(20);
				std::cout << "Формат номера: 1234xx 1-9\n";
				Sleep(20);
				std::cout << "Пример номера: 6823ag 4\n";
				Sleep(20);
				std::cout << "=============================\n";
				std::cin.ignore();
				std::getline(std::cin, text);
				system("cls");
				std::thread th(master);
				while (true) {
					number.clear();
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> dist('a', 'z');
					std::uniform_int_distribution<> dist1(1, 9);

					for (int i = 0; i < 4; i++) {
						number += std::to_string(dist1(gen));
					}
					for (int i = 0; i < 2; i++) {
						number += dist(gen);
					}
					number += " ";
					number += std::to_string(dist1(gen));

					if (number == text) {
						runn = false;
						th.join();
						system("cls");
						std::cout << "Time: " << time1 << " Number: [" << text << "] Att: " << att;
						Sleep(INFINITE);
					}
					else {
						att += 1;
					}
				}
			}
		}
	}
}