#include <iostream>
#include <ctime>
#include <vector>

int randFunction(int max) {
    int x = rand() % (max)+1;
    return x;
}

int dataCheckInt(int integer=0, int min=0, int max=1000000) {
    while (std::cin.fail() || integer < min || integer > max) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Ошибка, вы должны ввести число от "<< min <<" до " << max << std::endl << "Введите число ещё раз: " << std::endl;
        std::cin >> integer;
    }
    return integer;
}

class sterling {
private:
        int pound;
        int schilling;
        int pens;
public: 
    void currentPound() {
        std::cout << pound;
    }
    void setAmount(int setPound, int setSchilling, int setPens) {
        pound = setPound;
        schilling = setSchilling;
        pens = setPens;
    }
    void setPound(int setPoundBalance) {
        pound = setPoundBalance;
    }
    void setSchilling(int setSchillingBalance) {
        schilling = setSchillingBalance;
    }
    void setPens(int setPensBalance) {
        pens = setPensBalance;
    }
    void balance() {
        std::cout << pound << "-" << schilling << "-" << pens;
    }
    void sort() {
        if (pens > 11) {
            schilling += pens / 12;
            pens = pens % 12;
        }
        if (schilling > 19) {
            pound += schilling / 20;
            schilling = schilling % 20;
        }

    }
    void addPound(int addedPound) {
        pound += addedPound;
    }
    void addSchilling(int addedSchilling) {
        schilling += addedSchilling;
    }
    void addPens(int addedPens) {
        pens += addedPens;
    }
    void decreasePound(int decreasement) {
        if (pound != 0) {
            do {
                if (decreasement <= pound) {
                    pound -= decreasement;
                    break;
                }
                else {
                    std::cout << "Вы не можете убавить больше, чем у вас есть. Кредитный рейтинг слишком низок." << std::endl << "Текущие фунты: " << pound << std::endl;
                    std::cout << "Введите убавочные фунты ещё раз: " << std::endl;
                    std::cin >> decreasement;
                    decreasement = dataCheckInt(decreasement, 0, pound);
                }
            } while (decreasement > pound);
        }
        else {
            std::cout << "У вас и так нет, куда снижать" << std::endl;
        }
    }
    void decreaseSchilling(int decreasement) {
        sort();
        schilling += pound * 20;
        pound = 0;
        if (schilling != 0) {
            do {
                if (decreasement <= schilling) {
                    schilling -= decreasement;
                    sort();
                    break;
                }
                else {
                    std::cout << "Вы не можете убавить больше, чем у вас есть. Кредитный рейтинг слишком низок." << std::endl;
                    std::cout << "Текущие шиллинги: " << schilling << std::endl;
                    std::cout << "Введите убавочные шиллинги ещё раз: " << std::endl;
                    std::cin >> decreasement;
                    decreasement = dataCheckInt(decreasement, 0, schilling);
                }
            } while (decreasement > schilling);
        }
        else {
            std::cout << "У вас и так нет, куда снижать" << std::endl;
        }
        sort();
    }
    void decreasePens(int decreasement) {
        sort();
        schilling += pound * 20;
        pound = 0;
        pens += schilling * 12;
        schilling = 0;
        if (pens != 0) {
            do {
                if (decreasement <= pens) {
                    pens -= decreasement;
                    sort();
                    break;
                }
                else {
                    std::cout << "Вы не можете убавить больше, чем у вас есть. Кредитный рейтинг слишком низок." << std::endl;
                    std::cout << "Текущие пенсы: " << pens << std::endl;
                    std::cout << "Введите убавочные пенсы ещё раз: " << std::endl;
                    std::cin >> decreasement;
                }
            } while (decreasement > pens);
        }
        else {
            std::cout << "У вас и так нет, куда снижать" << std::endl;
        }
        sort();
    }
    int allInPens() {
        sort();
        int aboba = 0;
        schilling += pound * 20;
        pound = 0;
        pens += schilling * 12;
        schilling = 0;
        aboba = pens;
        sort();
        return aboba;
    }
};

int main()
{
    
    setlocale(LC_ALL, "RU");
    int answer = 1;
    sterling balance;
    balance.setAmount(0, 0, 0);
    do {
        srand(time(0));
        system("cls");
        std::cout << "Добро пожаловать в ФШП, версии 1.2! \n";
        std::cout << "Текущий баланс: ";
        balance.sort();
        balance.balance();
        std::cout << std::endl;
        std::cout << "Что вы хотите сделать?" << std::endl;
        std::cout << "1. - установить баланс" << std::endl << "2. - добавить баланс" << std::endl << "3. - убавить баланс" << std::endl << "4. - перевести в пенсы" << std::endl << "5. - вывести баланс в формате XX-XX-XX." << std::endl << "6. - операции с набором сумм." << std::endl << "7. - выход из программы" << std::endl;
        std::cin >> answer;
        answer = dataCheckInt(answer, 1, 7);
        
        switch (answer) {
        case 1: {
            std::cout << "Вы выбрали установить новый баланс." << std::endl;
            std::cout << "Введите новый баланс." << std::endl << "фунты: ";
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.setPound(answer);

            std::cout << "шиллинги: ";
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.setSchilling(answer);

            std::cout << "пенсы: ";
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.setPens(answer);

            std::cout << std::endl << "Новый баланс успешно установлен. \nОн составляет ";
            balance.sort();
            balance.balance();
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 2:{
            std::cout << "Вы выбрали добавить баланс. (вот бы так в реальном банке можно было)" << std::endl;
            std::cout << "Введите добавочный баланс" << std::endl;
            std::cout << "Добавочные фунты: " << std::endl;
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.addPound(answer);
            std::cout << "Добавочные шиллинги: " << std::endl;
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.addSchilling(answer);
            std::cout << "Добавочные пенсы: " << std::endl;
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.addPens(answer);

            std::cout << std::endl << "Баланс успешно обновлён. \nОн составляет ";
            balance.sort();
            balance.balance();
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 3:{
            std::cout << "Вы выбрали убавить баланс. (а зачем?)" << std::endl;
            std::cout << "Введите убавочный баланс" << std::endl;

            std::cout << "Убавочные фунты: " << std::endl;
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.decreasePound(answer);

            std::cout << "Убавочные шиллинги: " << std::endl;
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.decreaseSchilling(answer);

            std::cout << "Убавочные пенсы: " << std::endl;
            std::cin >> answer;
            answer = dataCheckInt(answer, 0);
            balance.decreasePens(answer);

            std::cout << std::endl << "Баланс успешно обновлён. \nОн составляет ";
            balance.sort();
            balance.balance();
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 4: {
            std::cout << "Вы выбрали посмотреть баланс в пенсах." << std::endl;
            std::cout << "Всего у вас " << balance.allInPens() << " пенсов." << std::endl;
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 5:{
            std::cout << "Вы выбрали вывести баланс в формате XX-XX-XX." << std::endl;
            balance.balance();
            std::cout << std::endl << "(Он и так каждый раз выводится)" << std::endl;
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 6: 
        {
            std::cout << "Вы выбрали поперации с набором сумм." << std::endl;
            std::cout << "Введите количество N элементов будущего набора." << std::endl;
            int N;
            std::cout << "N: ";
            std::cin >> N;
            N = dataCheckInt(N, 1);
            std::vector <sterling> arr(N);
            std::cout << "Заполнить автоматически, или вручную?" << std::endl << "1. - Автоматически" << std::endl << "2. - Вручную" << std::endl;
            std::cin >> answer;
            answer = dataCheckInt(answer, 1, 2);
            
            if (answer == 1) {
                int max = 1;
                std::cout << "Введите максимум для генерации (в пенсах): ";
                std::cin >> max;
                max = dataCheckInt(max, 1);
                for (int i = 0; i < N; i++) {
                    arr[i].setPens(randFunction(max));
                    arr[i].sort();
                }
            }
            else {
                std::cout << "Вы выбрали ввод вручную. Удачи" << std::endl;
                for (int i = 0; i < N; i++) {
                    std::cout << "Введите значение (в пенсах) для элемента массива " << i << ": ";
                    std::cin >> answer;
                    answer = dataCheckInt(answer, 0);
                    arr[i].setPens(answer);
                    arr[i].sort();
                }
            }
            do {
                system("cls");
                std::cout << "Массив успешно заполнен. Что хотите сделать?" << std::endl << "1. - вывести среднее значение, выраженное в том же виде." << std::endl << "2. - Найти пары сумм, наиболее близких и наиболее далеких по значению." << std::endl << "3. - Посмотреть его элементы." << std::endl << "4. - вернуться в начальное меню" << std::endl;
                std::cin >> answer;
                answer = dataCheckInt(answer, 1, 4);
                switch (answer) {
                case 1: {
                    std::cout << "Вы выбрали вывести среднее значение, выраженное в том же виде." << std::endl << "Для массива средним значением будет являться: ";
                    int sumPens = 0;
                    for (int i = 0; i < arr.size(); i++) {
                        sumPens += arr[i].allInPens();
                    }
                    int avgPens = sumPens / arr.size();
                    int avgPounds = 0;
                    int avgSchillings = 0;
                    if (avgPens > 11) {
                        avgSchillings += avgPens / 12;
                        avgPens = avgPens % 12;
                    }
                    if (avgSchillings > 19) {
                        avgPounds += avgSchillings / 20;
                        avgSchillings = avgSchillings % 20;
                    }
                    std::cout << avgPounds << "-" << avgSchillings << "-" << avgPens << std::endl;
                    system("pause");
                    break;
                }
                case 2: {
                    std::cout << "Вы выбрали найти пары сумм, наиболее близких и наиболее далеких по значению." << std::endl;
                    if (arr.size() == 1) {
                        std::cout << "В массиве всего 1 элемент. Выполнить не получится." << std::endl;
                        system("pause");
                        break;
                    }
                    std::cout << "Наиболее близкими по значению являются ";
                    int minPens = 10000000;
                    int maxPens = 0;
                    int difference = 10000000;
                    int tmp1;
                    int tmp2;
                    int minId;
                    int maxId;
                    for (int i = 0; i < arr.size(); i++) {
                        if (arr[i].allInPens() < minPens) {
                            minPens = arr[i].allInPens();
                            minId = i;
                        }
                        if (arr[i].allInPens() > maxPens) {
                            maxPens = arr[i].allInPens();
                            maxId = i;
                        }

                        for (int j = 0; j < arr.size(); j++) {
                            if (arr[i].allInPens() == arr[j].allInPens()){
                                tmp1 = i;
                                tmp2 = j;
                                difference = 0;
                            }
                            if (arr[i].allInPens() < arr[j].allInPens()) {
                                if ((arr[j].allInPens() - arr[i].allInPens()) < difference) {
                                    difference = arr[j].allInPens() - arr[i].allInPens();
                                    tmp1 = i;
                                    tmp2 = j;
                                }
                            }
                            else {
                                if (arr[i].allInPens() - arr[j].allInPens() < difference) {
                                    difference = arr[i].allInPens() - arr[j].allInPens();
                                    tmp1 = i;
                                    tmp2 = j;
                                }
                            }
                        }
                    }
                    arr[tmp1].balance();
                    std::cout << " и ";
                    arr[tmp2].balance();
                    sterling tmpSum1;
                    sterling tmpSum2;
                    tmpSum1.setAmount(0,0,0);
                    tmpSum2.setAmount(0, 0, 0);
                    tmpSum1.addPens(arr[tmp1].allInPens());
                    tmpSum1.addPens(arr[tmp2].allInPens());
                    tmpSum1.sort();
                    std::cout << " с разностью в " << difference << " пенсов и суммой в ";
                    tmpSum1.balance();
                    std::cout << "."<< std::endl;
                    std::cout << "Наиболее отдалёнными являются ";
                    arr[minId].balance();
                    std::cout << " и ";
                    arr[maxId].balance();
                    std::cout << " с суммой в ";
                    tmpSum2.addPens(arr[minId].allInPens());
                    tmpSum2.addPens(arr[maxId].allInPens());
                    tmpSum2.sort();
                    tmpSum2.balance();
                    std::cout << "."<< std::endl;
                    system("pause");
                    break;
                }
               case 3: {
                    std::cout << "Вы выбрали посмотреть его элементы." << std::endl;
                    for (int i = 0; i < arr.size(); i++) {
                        arr[i].sort();
                        arr[i].balance();
                        std::cout << std::endl;
                    }
                    std::cout << "Это все элементы массива." << std::endl;
                    system("pause");
                    break;
                }
                }
                arr.clear();
            } while (answer != 4);
            system("pause");
            break;
        }
        case 7:
        {
            std::cout << "Спасибо, что были с нами. Всего хорошего." << std::endl;
        }
        }
    } while (answer != 7);
    return 1;
}
