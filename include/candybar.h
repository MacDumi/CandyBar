#include <iostream>
#include <string>
#include <deque>
#include <iomanip>
#include <sstream>
#include <chrono>

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
                bool left_justified=true, bool _disable=false);
        void disable(bool _disable);
        void update(int current);
        void set_total(int total);
        void set_message(std::string message);
        void set_left_justified(bool left_justified=true);

    private:
        void get_terminal_width(int& width);
        int total_value, bar_width, screen_width;
        std::string text;
        bool verbose = true;
        bool lft_jst;
        std::deque<int> dur_buffer;
        unsigned int avg_window;
        long win_duration; // in us
        double eta; // in us
        std::chrono::time_point<std::chrono::system_clock> last_update;

};
