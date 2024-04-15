#include <iostream>
#include <cstdlib>
#include <string>
//#include <iomanip>
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
void PrintReceipt();
void ChangePrice();
void AddElementToReceipt(int& receiptSize, int id, int count);
void RemFrStorage();
void AddToStorage();
void ChangeStorage();
void AddElToEnd();
void DelElByIn();

//тестовые функции
template <typename ArrType>
void PrintArr(ArrType arr[], int size);
// Размеры
int size = 10;
int receiptSize = 1;
double itogSum = 0;
// Глобальные массивы склада
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];
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

    
   Start();
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
    double price[size_pwgood]{2999.99, 3799.55, 2899.44, 3099.99, 2756.86,
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
            ChangePrice();
        }
        else if (choose == 4)
        {
            RemFrStorage();
        }
        else if (choose == 5)
        {
            AddToStorage();
        }
        else if (choose == 6)
        {
            ChangeStorage();
        }
        else if (choose == 0)
        {
            break;
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
    double totalSum;
    int chooseID, chooseCount, confirm;
    int confirm2;
    bool isFirst = true;
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
            if (countArr[chooseID - 1] > 0)
            {
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
            }
            else
            {
                std::cerr << "Этого товара нет на складе\n";
                continue;
            }
            std::cout << "Вы выбрали: " << nameArr[chooseID - 1] << "\n";
            std::cout << "В кол-ве: " << chooseCount << " шт\n";
            std::cout << "Подтвердите выбор: \n1 - подтвердить \n2 - отмена\n";
            std::cin >> confirm;
            if (confirm == 1)
            {
                if (isFirst)
                {
                    isFirst = false;
                    nameReceiptArr[receiptSize - 1] = nameArr[chooseID - 1];
                    countReceiptArr[receiptSize - 1] = chooseCount;
                    priceReceiptArr[receiptSize - 1] = priceArr[chooseID - 1];// * chooseCount;
                    countArr[chooseID - 1] -= chooseCount;

                }
                else if (!isFirst)
                {
                    AddElementToReceipt(receiptSize, chooseID, chooseCount);
                } 
            }
            else if (confirm == 2)
            {
                continue;
            }
            
            std::cout << "Купить ещё один товар?\n";
            std::cout << "1 - Да \n2 - Нет\n";
            std::cin >> confirm2;
            if (confirm2 == 2)
            {
                std::cout << "sddf\n";
                break;
            }
        } while (true);
        std::cout << "ssadsdddf\n";
        PrintReceipt();
        int newstart = 0;
        std::cout << "Продолжить продажу? \n1 - Да\n2 - Вернуться в меню\n";
        std::cin >> newstart;
        if (newstart == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
}
void AddElementToReceipt(int& receiptSize, int id, int count)
{
    /*
    int* arr2 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    DelDynArr(arr);
    size++;
    DynArr(arr, size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr2[i];
    }
    arr[size - 1] = element;
    DelDynArr(arr2);
    */
    std::string* nameReceiptArrTemp = new std::string[receiptSize];
    int* countReceiptArrTemp = new int[receiptSize];
    double* priceReceiptArrTemp = new double[receiptSize];
    for (int i = 0; i < receiptSize; i++)
    {
        nameReceiptArrTemp[i] = nameReceiptArr[i];
        countReceiptArrTemp[i] = countReceiptArr[i];
        priceReceiptArrTemp[i] = priceReceiptArr[i];
    }
    delete[]nameReceiptArr;
    delete[]countReceiptArr;
    delete[]priceReceiptArr;

    receiptSize++;

    nameReceiptArr = new std::string[receiptSize];
    countReceiptArr = new int[receiptSize];
    priceReceiptArr = new double[receiptSize];

    for (int i = 0; i < receiptSize - 1; i++)
    {
        nameReceiptArr[i] = nameReceiptArrTemp[i];
        countReceiptArr[i] = countReceiptArrTemp[i];
        priceReceiptArr[i] = priceReceiptArrTemp[i];
    }
    nameReceiptArr[receiptSize - 1] = nameArr[id - 1];
    countReceiptArr[receiptSize - 1] = count;
    priceReceiptArr[receiptSize - 1] = priceArr[id - 1];// *count;
    countArr[id - 1] -=  count;
    delete[]nameReceiptArrTemp;
    delete[]countReceiptArrTemp;
    delete[]priceReceiptArrTemp;
}
void PrintReceipt()
{
    
    std::cout << "Название\t\t\tЦена\t\tКол-во\n\n";
    for (int i = 0; i < receiptSize; i++)
    {
        std::cout << nameReceiptArr[i] << "\t" << priceReceiptArr[i] << "\t\t" << countReceiptArr[i] << "\n";
        itogSum = itogSum + priceReceiptArr[i] * countReceiptArr[i];
    }
    std::cout << "\nИтоговая сума: " << itogSum << "\n";
    std::cout << "\n\n";
    //admin
}
void ChangePrice()
{
    int id;
    double newPrice;
    do
    {
        std::cout << "Введите id товара: \n";
        std::cin >> id;
    } while (id < 1 || id > idArr[size - 1]);
    std::cout << "Текущая цена продукта " << nameArr[id-1] << ": " << priceArr[id - 1] << "\n";
    do
    {
        std::cout << "Введите новую цену товара: \n";
        std::cin >> newPrice;
    } while (newPrice < 0.01 || newPrice > 10000000.99);
    priceArr[id - 1] = newPrice;
    std::cout << "Изменение цены прошло успешно\n";
}
void RemFrStorage()
{
    int id;
    int goodCount;
    do
    {
        std::cout << "Введите id товара: \n";
        std::cin >> id;
    } while (id < 1 || id > idArr[size - 1]);
    std::cout << "Текущее кол-во товара " << nameArr[id - 1] << ": " << countArr[id - 1] << "\n";
    do
    {
        std::cout << "Сколько товаров списать со склада: \n";
        std::cin >> goodCount;
    } while (goodCount > countArr[id - 1] || goodCount <= 0);
    countArr[id - 1] -= goodCount;
    std::cout << "Списание товара прошло успешно\n";
}
void AddToStorage()
{
    int id;
    int goodCount;
    do
    {
        std::cout << "Введите id товара: \n";
        std::cin >> id;
    } while (id < 1 || id > idArr[size - 1]);
    std::cout << "Текущее кол-во товара " << nameArr[id - 1] << ": " << countArr[id - 1] << "\n";
    do
    {
        std::cout << "Сколько товаров добавить на склад: \n";
        std::cin >> goodCount;
    } while (goodCount <= 0);
    countArr[id - 1] += goodCount;
    std::cout << "Добавление товара прошло успешно\n";
}
void ChangeStorage()
{
    int choose;
    do
    {
        std::cout << "Изменение склада. \n1 - добавить новый товар\n2 - удалить товар\n3 - выйти\n";
        std::cin >> choose;
    } while (choose < 1 || choose > 3);
    if (choose == 1)
    {
        AddElToEnd();
    }
    else if (choose == 2)
    {
        DelElByIn();
    }
    else if (choose == 3)
    {
        std::cout << "Выход\n";
    }
}
void AddElToEnd()
{
    int* idArrTemp = new int[size];
    std::string* nameArrTemp = new std::string[size];
    int* countArrTemp = new int[size];
    double* priceArrTemp = new double[size];
    for (int i = 0; i < size; i++)
    {
        nameArrTemp[i] = nameArr[i];
        countArrTemp[i] = countArr[i];
        priceArrTemp[i] = priceArr[i];
        idArrTemp[i] = idArr[i];
    }
    delete[]nameArr;
    delete[]countArr;
    delete[]priceArr;
    delete[]idArr;

    size++;

    nameArr = new std::string[size];
    countArr = new int[size];
    priceArr = new double[size];
    idArr = new int[size];

    for (int i = 0; i < size - 1; i++)
    {
        nameArr[i] = nameArrTemp[i];
        countArr[i] = countArrTemp[i];
        priceArr[i] = priceArrTemp[i];
        idArr[i] = idArrTemp[i];
    }
    

    idArr[size - 1] = size - 1;
    std::cout << "Введите имя нового товара:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nameArr[size - 1]);
    std::cout << "Введите кол-во нового товара:\n";
    std::cin >> countArr[size - 1];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите цену нового товара:\n";
    std::cin >> priceArr[size - 1];
    std::cout << "Товар успешно добавлен\n\n";
    delete[]nameArrTemp;
    delete[]countArrTemp;
    delete[]priceArrTemp;
    delete[]idArrTemp;
}
void DelElByIn()
{
    int* idArrTemp = new int[size];
    std::string* nameArrTemp = new std::string[size];
    int* countArrTemp = new int[size];
    double* priceArrTemp = new double[size];
    for (int i = 0; i < size; i++)
    {
        nameArrTemp[i] = nameArr[i];
        countArrTemp[i] = countArr[i];
        priceArrTemp[i] = priceArr[i];
        idArrTemp[i] = idArr[i];
    }
    delete[]nameArr;
    delete[]countArr;
    delete[]priceArr;
    delete[]idArr;

    nameArr = new std::string[size];
    countArr = new int[size];
    priceArr = new double[size];
    idArr = new int[size];
    int element;
    do
    {
        std::cout << "Введите id товара, который хотите удалить\n";
        std::cin >> element;
    } while (element < 0 || element > size);
    size--;
    for (int i = 0, j = 0; i < size; i++, j++)
    {
        if (i != element - 1)
        {
            nameArr[i] = nameArrTemp[j];
            countArr[i] = countArrTemp[j];
            priceArr[i] = priceArrTemp[j];
            idArr[i] = idArrTemp[i];
        }
        else
        {
            j++;
            nameArr[i] = nameArrTemp[j];
            countArr[i] = countArrTemp[j];
            priceArr[i] = priceArrTemp[j];
            idArr[i] = idArrTemp[i];
        }
    }
    std::cout << "\nУдаление прошло успешно\n\n";
    delete[]nameArrTemp;
    delete[]countArrTemp;
    delete[]priceArrTemp;
    delete[]idArrTemp;
}
