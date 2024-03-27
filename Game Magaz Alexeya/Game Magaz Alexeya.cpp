#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>
void Start();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    return 0;
}
void Start()
{
    std::string adminLogin = "admin";
    std::string adminPassword = "admin";
    std::string login, password;
    std::cout << "\n\t\t\tДобро пожаловать в Игровой Магаз Алексея!\n\n";
    std::cout << "Логин: ";
    std::getline(std::cin, login);
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Пароль: ";
    std::getline(std::cin, password);
    std::cin.ignore();
    

}
