#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdint>
#include <bitset>
#include <algorithm>

uint32_t ipToUint32(const std::string& ip) {
    std::istringstream iss(ip);
    std::string octetStr;
    uint32_t result = 0;
    int shift = 24;
    
    while (std::getline(iss, octetStr, '.')) {
        uint32_t octet = static_cast<uint32_t>(std::stoi(octetStr));
        result |= (octet << shift);
        shift -= 8;
    }
    return result;
}

std::string uint32ToBinaryString(uint32_t num) {
    std::bitset<32> bits(num);
    std::string full = bits.to_string();
    
    std::string result;
    for (int i = 0; i < 32; ++i) {
        result += full[i];
        if ((i + 1) % 8 == 0 && i != 31) {
            result += '.';
        }
    }
    return result;
}

void printIPInfo(const std::string& label, const std::string& ipStr, uint32_t value) {
    std::cout << "Число " << label << " ( " << ipStr << " )\n";
    std::cout << "  Десятичное значение: " << value << "\n";
    std::cout << "  Двоичное представление: " << uint32ToBinaryString(value) << "\n\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "Лабораторная работа №1 \n";
    std::cout << "Преобразование IP-адресов в двоичную систему и поразрядное умножение\n\n";
    
    std::string ipA, ipB, ipC;
    
    std::cout << "Введите IPv4-адрес A (например, 192.168.1.1): ";
    std::getline(std::cin, ipA);
    std::cout << "Введите IPv4-адрес B (например, 172.16.31.1): ";
    std::getline(std::cin, ipB);
    std::cout << "Введите маску C (например, 255.255.255.0): ";
    std::getline(std::cin, ipC);
    
    uint32_t numA = ipToUint32(ipA);
    uint32_t numB = ipToUint32(ipB);
    uint32_t numC = ipToUint32(ipC);
    
    std::cout << "Результаты преобразования в двоичную систему:\n";
    
    printIPInfo("A", ipA, numA);
    printIPInfo("B", ipB, numB);
    printIPInfo("C", ipC, numC);
    
    uint32_t andA_C = numA & numC;
    uint32_t andB_C = numB & numC;
    
    std::cout << "Поразрядное умножение (A & C) и (B & C):\n";
    
    std::cout << "A & C = " << andA_C << "\n";
    std::cout << "Двоичный вид: " << uint32ToBinaryString(andA_C) << "\n\n";
    
    std::cout << "B & C = " << andB_C << "\n";
    std::cout << "Двоичный вид: " << uint32ToBinaryString(andB_C) << "\n\n";
    
    bool areEqual = (andA_C == andB_C);
    
    std::cout << "Сравнение результатов поразрядного умножения:\n";
    std::cout << "(A & C) == (B & C) ?\n";
    std::cout << "Результат: " << (areEqual ? "True" : "False") << "\n\n";
    
    if (areEqual) {
        std::cout << "=> Адреса A и B принадлежат ОДНОЙ подсети (сеть " 
                  << (andA_C >> 24) << "."
                  << ((andA_C >> 16) & 0xFF) << "."
                  << ((andA_C >> 8) & 0xFF) << "."
                  << (andA_C & 0xFF) << ")\n";
    } else {
        std::cout << "=> Адреса A и B принадлежат РАЗНЫМ подсетям.\n";
    }
    
    return 0;
}