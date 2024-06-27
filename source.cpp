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
    std::cout << "����������Ҫʹ�õ��߳�����,����8��U�����ؾ�����16,Ȼ�󰴻س��Ϳ�ʼ��"<<"\n";
    std::cout << "ctrl+c when u dont want to continue"<<"\n";
    std::cout << "�������ʱ��ֱ�ӹص�������"<<"\n";
    std::cout << "MAYDE BY Aleash"<<"\n";    
    std::cout << "���� Aleash"<<"\n";
    std::cin >> threadCount;
    std::cout << "��ʼ������"<<"\n";
    std::vector<std::thread> threads;

    for (int i = 0; i < threadCount; ++i) {
        threads.push_back(std::thread(performCalculation));
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
