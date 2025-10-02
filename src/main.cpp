
#include <iostream>
#include "../include/three.h"


int main() {
    try {
        Three num1;
        Three num2(1, 2);
        Three num3{'2', '1'};
        Three num4("12");
        Three num5 = num3.add(num4);
        Three num6 = num3.subtract(num4);

        // Three num2 = num3;
        // Three num3 = num3.add(num4);
        // Three num3 = num3.subtract(num4);
    
        std::cout << "Num1: ";
        num1.print(std::cout) << std::endl;
        std::cout << "Num2: ";
        num2.print(std::cout) << std::endl;
        std::cout << "Num3: ";
        num3.print(std::cout) << std::endl;
        std::cout << "Num4: ";
        num4.print(std::cout) << std::endl;
        std::cout << "Num5: ";
        num5.print(std::cout) << std::endl;
        std::cout << "Num6: ";
        num6.print(std::cout) << std::endl;

        if (num2.equals(num6)) {
            std::cout << "Num2 равно Num6" << std::endl;
        } else {
            std::cout << "Num2 не равно Num6" << std::endl;
        }

        if (num5.greaterThan(num4)) {
            std::cout << "Num5 больше Num4" << std::endl;
        } else {
            std::cout << "Num5 не больше Num4" << std::endl;
        }

        if (num6.lessThan(num3)) {
            std::cout << "Num6 меньше Num3" << std::endl;
        } else {
            std::cout << "Num6 не меньше Num3" << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}