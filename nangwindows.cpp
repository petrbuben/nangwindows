#include <iostream>
#include <string>
#include <stack>

void delsta(std::stack <std::string>& sta, std::string s) {
    if (sta.empty())
        return;
    std::string pr;
    if (sta.top() != s) {
        pr = sta.top();
    }
    sta.pop();

    delsta(sta, s);

    sta.push(pr);
}

void prsta(std::stack<std::string> vtopw) {
    if (vtopw.empty())
        return;
    std::string s = vtopw.top();
    vtopw.pop();
    prsta(vtopw);
    std::cout << s <<" ";
    return;
}

void status(std::stack<std::string>& vtopw) {
    //std::cout << "Report:\non top: " << vtopw.top() << "\n";
    std::cout << "Windows Opened: ";
    prsta(vtopw);
    std::cout << std::endl;
}

class Calculator {
public:
    void open(const std::string s, std::stack<std::string>& vtopw) {
        std::cout << "Opening Calculator\n";
        vtopw.push(s);
        status(vtopw);
    }
    void close(const std::string s, std::stack<std::string>& vtopw) {
        std::cout << "Closing Calculator\n";
        delsta(vtopw, "Calculator");
        status(vtopw);
    }
};

class Browser {
public:
    void open(const std::string s, std::stack<std::string>& vtopw) {
        std::cout << "Opening Browser\n";
        vtopw.push(s);
        status(vtopw);
    }
    void close(const std::string s, std::stack<std::string>& vtopw) {
        std::cout << "Closing Browser\n";
        delsta(vtopw, "Browser");
        status(vtopw);
    }
};

class Player {
public:
    void open(const std::string s, std::stack<std::string>& vtopw) {
        std::cout << "Opening Player\n";
        vtopw.push(s);
        status(vtopw);
    }
    void close(const std::string s, std::stack<std::string>& vtopw) {
        std::cout << "Closing Player\n";
        delsta(vtopw, "Player");
        status(vtopw);
    }
};


class WindowManager
{
private:
    std::stack<std::string> vtopw;
    Calculator c;
    Browser b;
    Player p;

public:
    void open(const std::string windowName)
    {
        if (windowName == "Calculator") {
            c.open(windowName, vtopw);
        }
        else if (windowName == "Browser") {
            b.open(windowName, vtopw);
        }
        else if (windowName == "Player") {
            p.open(windowName, vtopw);
        }
    }

    void close(const std::string windowName)
    {
        if (vtopw.size() == 0) {
            return;
        }
        if (windowName == "Calculator") {
            c.close(windowName, vtopw);            
        }
        else if (windowName == "Browser") {
            b.close(windowName, vtopw);            
        }
        else if (windowName == "Player") {
            p.close(windowName, vtopw);            
        }

    }

    std::string getTopWindow()
    {
        if (vtopw.empty())
            return "No top window";
        return vtopw.top();
    }
};

#ifndef RunTests
int main()
{
    WindowManager wm;
    wm.open("Calculator");
    std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
    wm.open("Browser");
    std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
    //wm.open("Browser");
    //std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
    wm.open("Player");
    std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
    wm.close("Browser");
    std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
    //wm.close("Calculator");
    //std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
    wm.close("Calculator");
    std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
    wm.close("Player");
    std::cout << "Top window: " << wm.getTopWindow() << "\n\n";
}
#endif