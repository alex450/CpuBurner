#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>

void performCalculation() {
    while (true) {
        int num1 = std::rand() % 100;
        int num2 = std::rand() % 100;
        char ops[] = {'+', '-', '*', '/'};
        char op = ops[std::rand() % 4];
        switch (op) {
            case '+':
                num1 + num2;
                break;
            case '-':
                num1 - num2;
                break;
            case '*':
                num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    num1 / num2;
                }
                break;
        }
    }
}

int main() {
    std::srand(std::time(nullptr));
    int threadCount;
    std::cout << "type in threads u want and enter"<<"\n";
    std::cout << "请输入你想要使用的线程数量,比如8核U想满载就输入16,然后按回车就开始了"<<"\n";
    std::cout << "ctrl+c when u dont want to continue"<<"\n";
    std::cout << "想结束的时候直接关掉就行了"<<"\n";
    std::cout << "MAYDE BY Aleash"<<"\n";    
    std::cout << "作者 Aleash"<<"\n";
    std::cin >> threadCount;
    std::cout << "开始烤机了"<<"\n";
    std::vector<std::thread> threads;

    for (int i = 0; i < threadCount; ++i) {
        threads.push_back(std::thread(performCalculation));
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
