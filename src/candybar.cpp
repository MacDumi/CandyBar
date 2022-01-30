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
            std::cout << "[CandyBar] Reducing the widht to " << bar_width << std::endl;
        } else bar_width = width;
    }

    last_update = std::chrono::system_clock::now();
}

void CandyBar::set_total(int total)
{
    // Set the total value
    if (total > 0)
        total_value = total;
}

void CandyBar::disable(bool _disable)
{
    verbose = !_disable;
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
    // Get the current time
    auto now = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                                                    now - last_update).count();

    // Compute the ETA
    eta = (float)(total_value - current) * duration / 1000.0;

    // Assign the current tim to the last_update
    last_update = now;

    // Don't show the progress bar if disables
    if (!verbose)
        return;

    std::stringstream ss;
    ss << '[';
    if (current  <= 1)
    {
        ss << "--:--]";
    }
    else
    {
        if (eta > 3599)
        {
            int hours = eta / 3600;
            ss << hours << ':';
            eta = eta - hours * 3600;
        }
        if (eta > 59)
        {
            int mins = eta / 60;
            ss << mins << ':';
            eta = eta - mins * 60;
        }
        else
            ss << "0:";

        ss << std::setfill('0') << std::setw(2) << (int) eta << ']';
    }

    // Update the progress bar
    float progress = (float) current / total_value;

    std::cout << text;


    if (!lft_jst)
    {
        int n_spaces = screen_width - text.length() - 8 - bar_width - ss.gcount();
        for (int i = 0; i < n_spaces; i++)
            std::cout << " ";
    }

    std::cout << ' ' << ss.str() << '[';
    int eta_length = ss.str().length();
    int pos = (bar_width - eta_length) * progress;
    for (int i = 0; i < bar_width - eta_length; ++i) {
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

