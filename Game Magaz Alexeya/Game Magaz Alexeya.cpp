#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
//#include <Windows.h>
// Игровой Магаз Алексея
// Функции
void Start();
void CreateStore();
template <typename ArrType>
void FillArr(ArrType statArr[], ArrType dinArr[], int size);
void Shop();
void ShopStorage();
void Selling();


//тестовые функции
template <typename ArrType>
void PrintArr(ArrType arr[], int size);
// Размеры
int size = 10;
int receiptSize = 1;
// Глобальные массивы склада
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
float* priceArr = new float[size];
// Глобальные массивы чека
std::string* nameReceiptArr = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];



/*
    inline int max(int a, int b)
    {
        return a > b ? a : b;
    }
    std::cout << max(10, 15) << "\n";
    */
    /*
    std::cout << sqrt(25) << "\n";
    std::cout << tan(25) << "\n";
    std::cout << sin(25) << "\n";
    std::cout << cos(25) << "\n";
    std::cout << floor(25,6) << "\n";
    #include <cmath>
    */
    //CreateStore();
    //ShopStorage();
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    CreateStore();
    ShopStorage();
    Selling();
    //Start();
    delete[]idArr;
    delete[]nameArr;
    delete[]countArr;
    delete[]priceArr;
    delete[]nameReceiptArr;
    delete[]countReceiptArr;
    delete[]priceReceiptArr;
    return 0;
}
void Start()
{
    std::string adminLogin = "admin";
    std::string adminPassword = "admin";
    std::string login, password;
    bool exit = false;
    int choose;
    std::cout << "\n\t\t\tДобро пожаловать в Игровой Магаз Алексея\n\n";
    do
    {
        std::cout << "Логин: ";
        std::getline(std::cin, login);
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Пароль: ";
        std::getline(std::cin, password, '\n');
        if (login != adminLogin || password != adminPassword)
        {
            std::cerr << "Неверный логин или пароль\n";
            std::cout << "Попробовать ещё раз? 1 - Да, 2 - Выход из программы\n";
            std::cin >> choose;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choose == 2)
            {
                exit = true;
            }
        }
        else
        {
            exit = true;
            int schooseStorageType;
            do
            {
                std::cout << "Выберите формат склада: \n1 - Готовый склад \n2 - создать склад вручную\n";
                std::cin >> schooseStorageType;
            } while (schooseStorageType < 1 || schooseStorageType > 2);
            if (schooseStorageType == 1)
            {
                CreateStore();
                Shop();
            }
            else if (schooseStorageType == 2)
            {
                
            }
        }
    } while (!exit);
}
void CreateStore()
{
    const int size_pwgood = 10;
    int id[size_pwgood]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string name[size_pwgood]{"Devil May Cry 5 (PS4)      ", "Rezident Evil 4 (PS4)      ",
        "Cyberpunk 2077 (PS4)       ", "GTA V (PS4)                ", "Detroit: Become Human (PS4)", "Far Cry 3 (PS4)            ",
        "Red Dead Redemption 2 (PS4)", "Hogwartz Legacy (PS4)      ", "Minecraft (PS4)            ", "Terraria (PS4)             "};
    int count[size_pwgood]{9, 10, 10, 10, 8, 12, 10, 10, 11, 9};
    float price[size_pwgood]{2999.99, 3799.55, 2899.44, 3099.99, 2756.86,
        2673.49, 3300.79, 4700.39, 4990.64, 2739.99};
    FillArr(id, idArr, size);
    FillArr(name, nameArr, size);
    FillArr(count, countArr, size);
    FillArr(price, priceArr, size);
}
template <typename ArrType>
void FillArr(ArrType statArr[], ArrType dinArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dinArr[i] = statArr[i];
    }
}
template <typename ArrType>
void PrintArr(ArrType arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void Shop()
{
    int choose;

    while (true)
    {
        do
        {
            std::cout << "1) Показать склад\n";
            std::cout << "2) Начать продажу\n";
            std::cout << "3) изменить цену\n";
            std::cout << "4) Списать товар\n";
            std::cout << "5) Пополнить товар\n";
            std::cout << "6) Изменение склада\n";
            std::cout << "0) Закончить смену\n";
            std::cin >> choose;
        } while (choose < 0 || choose > 6);
        if (choose == 1)
        {
            ShopStorage();
        }
        else if (choose == 2)
        {
            Selling();
        }
        else if (choose == 3)
        {

        }
        else if (choose == 4)
        {

        }
        else if (choose == 5)
        {

        }
        else if (choose == 6)
        {

        }
        else if (choose == 0)
        {

        }
    }
}
void ShopStorage()
{
    std::cout << "id товара\tНазвание\t\t\tЦена\t\tКол-во\n\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << idArr[i] + 1 << "\t\t" << nameArr[i] << "\t" << priceArr[i] << "\t\t" << countArr[i] << "\n";
    }
    std::cout << "\n\n";
}
void Selling()
{
    int chooseID, chooseCount, confirm;
    while (true)
    {
        do
        {
            do
            {
                std::cout << "Введите ID товара, который хотите купить: \n";
                std::cin >> chooseID;
                if (chooseID < 1 || chooseID > size)
                {
                    std::cerr << "Нет такого ID\n";
                    continue;
                }
                else
                {
                    break;
                }
            } while (true);
            do
            {
                std::cout << "Вы выбрали: " << nameArr[chooseID - 1] << "\n";
                std::cout << "Кол-во товара на складе: " << countArr[chooseID - 1] << "\n";
                std::cout << "Введите кол-во товара:\n";
                std::cin >> chooseCount;
                if (chooseCount < 1 || chooseCount > countArr[chooseID - 1])
                {
                    std::cerr << "Товаров на складе не хватает\n";
                    continue;
                }
                else
                {
                    break;
                }
            } while (true);
            std::cout << "Вы выбрали: " << nameArr[chooseID - 1] << "\n";
            std::cout << "В кол-ве: " << chooseCount << " шт\n";
            std::cout << "Подтвердите выбор: \n1 - подтвердить \n2 - повторить\n";
            std::cin >> confirm;
            if (confirm == 1)
            {
                break;
            }
        } while (true);
    }
}
