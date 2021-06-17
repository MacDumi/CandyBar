#include "candybar.h"

CandyBar::CandyBar(int total, std::string message, int width,
        bool left_justified)
{
    // Initialize the object
    total_value = total;
    text = message;
    lft_jst = left_justified;
    get_terminal_width(screen_width);
    if (width == 0)
    {
        // If no bar width was provided use the whole width
        bar_width = screen_width;
        bar_width -= (message.length() + 8);
    } else
    {
        if ((int)message.length() + 8 + width > screen_width)
        {
            bar_width = screen_width - message.length() - 8;
            std::cout << "Reducing the widht to " << bar_width << std::endl;
        } else bar_width = width;
    }
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
    if ((int)message.length() + 8 + bar_width > screen_width)
    {
        int last_text_width = text.length();
        bar_width -= (message.length() - last_text_width);
    }
    text = message;
}

void CandyBar::set_left_justified(bool left_justified)
{
    // Change the justification
    lft_jst = left_justified;
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

    std::cout << text;

    if (!lft_jst)
    {
        int n_spaces = screen_width - text.length() - 8 - bar_width;
        for (int i = 0; i < n_spaces; i++)
            std::cout << " ";
    }

    std::cout << " [";

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

