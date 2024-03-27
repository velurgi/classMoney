#include <iostream>

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
                    std::cout << "Введите убавочные фунты ещё раз: " << std::endl;
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
        if (pens != 0) {
            do {
                if (decreasement <= pens) {
                    pens -= decreasement;
                    sort();
                    break;
                }
                else {
                    std::cout << "Вы не можете убавить больше, чем у вас есть. Кредитный рейтинг слишком низок." << std::endl;
                    std::cout << "Текущие шиллинги: " << pens << std::endl;
                    std::cout << "Введите убавочные фунты ещё раз: " << std::endl;
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
        system("cls");
        std::cout << "Добро пожаловать в ФШП, версии 0.8.2! \n";
        std::cout << "Текущий баланс: ";
        balance.sort();
        balance.balance();
        std::cout << std::endl;
        std::cout << "Что вы хотите сделать?" << std::endl;
        std::cout << "1. - установить баланс" << std::endl << "2. - добавить баланс" << std::endl << "3. - убавить баланс" << std::endl << "4. - перевести в пенсы" << std::endl << "5. - вывести баланс в формате XX-XX-XX" << std::endl << "6. - стать счастливым" << std::endl << "7. - выход из программы" << std::endl;
        std::cin >> answer;
        answer = dataCheckInt(answer, 1, 7);
        
        switch (answer) {
        case 1:
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
            std::cout << std::endl << "Нажмите для продолжения..." << std::endl;
            std::cin >> answer;
            break;

        case 2:
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
            balance.addSchilling(answer);

            std::cout << std::endl << "Баланс успешно обновлён. \nОн составляет ";
            balance.sort();
            balance.balance();
            std::cout << std::endl << "Нажмите для продолжения..." << std::endl;
            std::cin >> answer;
            break;
        case 3:
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
            balance.decreaseSchilling(answer);

            std::cout << std::endl << "Баланс успешно обновлён. \nОн составляет ";
            balance.sort();
            balance.balance();
            std::cout << std::endl << "Нажмите для продолжения..." << std::endl;
            std::cin >> answer;
            break;
        case 4:
            std::cout << "Вы выбрали посмотреть баланс в пенсах." << std::endl;
            std::cout << "Всего у вас " << balance.allInPens() << " пенсов." << std::endl;

            std::cout << std::endl << "Нажмите для продолжения..." << std::endl;
            std::cin >> answer;
            break;
        case 5:
            std::cout << "Вы выбрали вывести баланс в формате XX-XX-XX." << std::endl;
            balance.balance();
            std::cout << std::endl << "(Он и так каждый раз выводится)" << std::endl;

            std::cout << std::endl << "Нажмите для продолжения..." << std::endl;
            std::cin >> answer;
            break;
        case 6:
            std::cout << "Ещё в разработке." << std::endl;
            std::cout << std::endl << "Нажмите для продолжения..." << std::endl;
            std::cin >> answer;
            break;
        case 7:
            std::cout << "Спасибо, что были с нами. Всего хорошего." << std::endl;
        }


    } while (answer != 7);

    return 1;
}
