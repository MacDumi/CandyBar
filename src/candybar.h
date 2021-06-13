#include <iostream>
#include <string>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#endif // Windows/Linux

class CandyBar
{
    public:
        CandyBar(int total, std::string message="", int width=0);
        void update(int current);

    private:
        void get_terminal_width(int& width);
        int total_value, bar_width;
        std::string text;
};
