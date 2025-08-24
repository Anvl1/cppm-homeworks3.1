#include <iostream>
#include <Windows.h>

class Calculator 
{
private:
    double num1;
    double num2;

public:
    Calculator() : num1(0), num2(0) {}
    
    double add() 
    {
        return num1 + num2;
    }
    
    double multiply()
    {
        return num1 * num2;
    }
    
    double subtract_1_2()
    {
        return num1 - num2;
    }
    
    double subtract_2_1()
    {
        return num2 - num1;
    }
    
    double divide_1_2()
    {
        if (num2 != 0)
        {
            return num1 / num2;
        }
        else
        {
            std::cerr << "Ошибка: Деление на ноль!" << std::endl;
            return 0;
        }
    }
    
    double divide_2_1()
    {
        if (num1 != 0)
        {
            return num2 / num1;
        }
        else
        {
            std::cerr << "Ошибка: Деление на ноль!" << std::endl;
            return 0;
        }
    }
    
    bool set_num1(double value)
    {
        if (value != 0)
        {
            this->num1 = value;
            return true;
        }
        return false;
    }

    bool set_num2(double value)
    {
        if (value != 0)
        {
            this->num2 = value;
            return true;
        }
        return false;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    Calculator calc;
    double inputNum1, inputNum2;

    while (true)
    {
        std::cout << "Введите num1: ";
        std::cin >> inputNum1;

        if (!calc.set_num1(inputNum1)) 
        {
            std::cout << "Неверный ввод! Значение не должно быть равно 0." << std::endl;
            continue;
        }
        
        std::cout << "Введите num2: ";
        std::cin >> inputNum2;

        if (!calc.set_num2(inputNum2))
        {
            std::cout << "Неверный ввод! Значение не должно быть равно 0." << std::endl;
            continue;
        }
        
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;

        double divisionResult1 = calc.divide_1_2();
        double divisionResult2 = calc.divide_2_1();
        
        std::cout << "num1 / num2 = " << divisionResult1 << std::endl;
        std::cout << "num2 / num1 = " << divisionResult2 << std::endl;
        
        std::cout << std::endl;
    }

    return 0;
}