#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ctime>
#include <functional>
#include <string>

void Routine12() {
    std::vector<int> v(20);
    std::random_device rnd_device;
    std::mt19937 mersenne_engine{ rnd_device() }; 
    std::uniform_int_distribution<int> dist{ 1, 100 };

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };
    std::generate(begin(v), end(v), gen);

    auto is_not_multiple_of_six = [](int n) 
    { 
        return n % 6 != 0; 
    };
    auto end = std::remove_if(v.begin(), v.end(), is_not_multiple_of_six);
    v.erase(end, v.end());

    std::cout << "Function 12:" << std::endl;
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return;
}

bool is_palyndrome(const std::string s) {
    return std::equal(s.begin(), s.end(), s.rbegin());
}

void Routine7() {
    std::string str1, str2;

    std::cout << "Function 7:" << std::endl;
    std::cout << "First string:" << std::endl;
    std::cin >> str1;
    std::cout << "Second string:" << std::endl;
    std::cin >> str2;

    bool flag = true;
    if (flag &= is_palyndrome(str1))
        std::cout << "First string is a palyndorme" << std::endl;

    if (flag &= is_palyndrome(str2))
        std::cout << "Second string is a palyndorme" << std::endl;

    if (flag)
        return;
    
    std::cout << "Common substrings:" << std::endl;
    for (auto it = str1.begin(); it != str1.end(); ++it)
        for (auto it2 = it; it2 != str1.end(); ++it2)
            if (std::search(str2.begin(), str2.end(), it, it2 + 1) != str2.end())
                std::cout << "sub: " << std::string(it, it2 + 1) << std::endl;
        
    return;
}

void Routine14() {
    const int time = 2;
    const int dist_old = 15951;
    int dist_new = 0;

    std::cout << "Function 14:" << std::endl;
    std::cout << "Input new distance:" << std::endl;
    std::cin >> dist_new;

    if (dist_new <= dist_old || !is_palyndrome(std::to_string(dist_new))) {
        std::cout << "Incorrect input" << std::endl;
        return;
    }
       
    std::cout << "Average speed is " << (dist_new - dist_old) / (double)time << " km/h" << std::endl;

    return;
}

int main() {
    Routine14();
}