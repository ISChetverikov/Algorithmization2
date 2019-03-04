#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <windows.h>

using namespace std::chrono_literals;

/*
timer value
is light on/off + mutex
mutex for cnsole

console yellow light
future exit
cockroach checked lamp
Why we use mutexes with a conditional variables?
*/

const int END_TIME = 20;

const COORD timer_coord = { 0,0 };
const COORD lamp_coord = { 0,1 };
const COORD cockroach_coord = { 0,2 };
const COORD end_coord = { 0, 4 };

int t(0);
std::mutex timer_has_changed_mutex;
std::condition_variable timer_has_changed;

std::mutex lamp_has_checked_mutex;
std::condition_variable lamp_has_checked;

bool is_light_on = false;

std::mutex console_mutex;
HANDLE hConsoleWindow;

void timer() {

    while (true)
    {
        ++t;
        std::this_thread::sleep_for(1s);

        std::unique_lock<std::mutex> console_lock(console_mutex);
        SetConsoleCursorPosition(hConsoleWindow, timer_coord);
        std::cout << "timer: " << t << "       " << std::endl;
        console_lock.unlock();

        std::lock_guard<std::mutex> guard(timer_has_changed_mutex);
        timer_has_changed.notify_all();

        if (t > END_TIME)
            return;
    }
}

void lamp() {
    while (true) {
        std::unique_lock<std::mutex> lock(timer_has_changed_mutex);
        timer_has_changed.wait(lock);

        int x = t;
        double val = cos(x) - x * x * x * sin(x);

        if (val > 0)
            is_light_on = true;
        else
            is_light_on = false;

        std::lock_guard<std::mutex> guard(lamp_has_checked_mutex);
        lamp_has_checked.notify_one();

        std::unique_lock<std::mutex> console_lock(console_mutex);
        SetConsoleCursorPosition(hConsoleWindow, lamp_coord);
        if (val > 0)
            std::cout << "Light on! \n";
        else
            std::cout << "Light off!\n";
        console_lock.unlock();

        if (t > END_TIME)
            return;
    }
}

void cockroach() {
    int steps = 0;

    while (true) {

        std::unique_lock<std::mutex> lamp_lock(lamp_has_checked_mutex);
        lamp_has_checked.wait(lamp_lock);

        if (is_light_on)
            steps += 5;

        std::unique_lock<std::mutex> console_lock(console_mutex);
        SetConsoleCursorPosition(hConsoleWindow, cockroach_coord);
        std::cout << "Steps: " << steps << "        " << std::endl;
        console_lock.unlock();

        if (t > END_TIME)
            return;
    }
}

int main()
{
    hConsoleWindow = GetStdHandle(STD_OUTPUT_HANDLE);

    std::thread timer_thread(timer);
    std::thread lamp_thread(lamp);
    std::thread cockroach_thread(cockroach);

    std::this_thread::sleep_for(5s);
    
    timer_thread.join();
    lamp_thread.join();
    cockroach_thread.join();

    SetConsoleCursorPosition(hConsoleWindow, end_coord);
    std::cout << "The end!" << std::endl;

}