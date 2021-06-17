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
        CandyBar(int total=100, std::string message="", int width=0,
                bool left_justified=true);
        void update(int current);
        void set_total(int total);
        void set_message(std::string message);
        void set_left_justified(bool left_justified=true);

    private:
        void get_terminal_width(int& width);
        int total_value, bar_width, screen_width;
        std::string text;
        bool lft_jst;
};
