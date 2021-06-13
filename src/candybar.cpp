#include "candybar.h"

CandyBar::CandyBar(int total, std::string message, int width)
{
    // Initialize the object
    total_value = total;
    text = message;
    if (width == 0)
    {
        // If no bar width was provided use the whole width
        get_terminal_width(bar_width);
        bar_width -= (message.length() + 8);
    } else
        bar_width = width;
}

void CandyBar::set_total(int total)
{
    // Set the total value
    if (total > 0)
        total_value = total;
}

void CandyBar::set_message(std::string message)
{
    // Change the message
    int last_text_width = text.length();
    text = message;
    bar_width -= (text.length() - last_text_width);
}

void CandyBar::get_terminal_width(int& width)
{
    // Get the width of the terminal window
    #if defined(_WIN32)
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        width = (int)(csbi.srWindow.Right-csbi.srWindow.Left+1);
    #elif defined(__linux__)
        struct winsize w;
        ioctl(fileno(stdout), TIOCGWINSZ, &w);
        width = (int)(w.ws_col);
    #endif
}

void CandyBar::update(int current)
{
    // Update the progress bar
    float progress = (float) current / total_value;

    if (text == "")
        std::cout << "[";
    else
        std::cout << text << " [";

    int pos = bar_width * progress;
    for (int i = 0; i < bar_width; ++i) {
        if (i < pos) std::cout << '-';
        else if (i == pos)
        {
            // Draw the "pacman"
            std::cout << "\e[1;33m";
            if (i % 3 == 2)
                std::cout << 'C';
            else
                std::cout << 'c';
            std::cout << "\e[0m";
        }
        else
        {
            // Draw the candy
            if (i % 3 == 0)
                std::cout << 'o';
            else
                std::cout << ' ';
        }
    }
    std::cout << "] " << int(progress * 100.0) << "%\r";
    std::cout.flush();

    if (progress == 1.0)
        std::cout << std::endl;
}

