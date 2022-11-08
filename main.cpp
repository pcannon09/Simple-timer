#include "functions.hpp"
#include <conio.h/conio.h>
#include <string>
#include <string.h>

int opt = 1;
int sec = 0;
int min = 0;
int sec2 = 0;
int min2 = 0;
int minSave = min;
int secSave = sec;

bool finishedTimer = false;

std::string command1 = "";

void start(std::string app)
{
    if (app == "timer" || app == "t")
    {
        clear();
        
        print("╭–––––––––––––––––––––––––––––╮");
        print("|      HOW MANY MINUTES?      |");
        print("╰–––––––––––––––––––––––––––––╯");

        std::cin>>min;
        
        getche();

        print("╭–––––––––––––––––––––––––––––╮");
        print("|      HOW MANY SECONDS?      |");
        print("╰–––––––––––––––––––––––––––––╯");
        
        std::cin>>sec;

        clear();
        
        minSave = min;
        secSave = sec;
        
        while (true)
        {
            if (command1 == "break" || command1 == "break_")
            {
                clear();

                command1 = "";
                
                break;
            }

            else if (command1 == "reset")
            {
                clear();
                
                command1 = "";
                min = minSave;
                sec = secSave;
            }

            clear();
            print("–––––––––––––––––––––––––––––––");

            if (min < 0)
            {
                print("  TIME IS UP!");
                print("  PRESS W TO CANCEL OR PRESS S TO START AGAIN\n");

                if (_kbhit())
                {
                    switch (_getche())
                    {
                    case 'w':
                        command1 = "break";

                        break;

                    case 's':
                        command1 = "reset";

                        break;

                    default:
                        break;
                    }
                }
            }

            else
            {
                if (_kbhit())
                {
                    switch (_getche())
                    {
                    case 'p':
                        while (true)
                        {
                            if (command1 == "break")
                            {
                                command1 = "";

                                break;
                            }

                            clear();
                            print ("PAUSED");
                            print ("PRESS P TO UNPAUSE");

                            if (_kbhit())
                            {
                                switch (_getche())
                                {
                                case 'p':
                                    command1 = "break";

                                    break;
                                
                                default:
                                    break;
                                }
                            }

                            sleep(1);
                        }

                    case 'q':
                        clear();
                        print("Do you want to save progress? Y/N/CANCEL?");

                        if (_kbhit())
                        {
                            switch (_getche())
                            {
                            case 'y':
                                command1 = "break_";

                                break;

                            case 'n':
                                command1 = "break_";
                                sec = 0;
                                min = 0;

                                break;
                            
                            default:
                                break;
                            }
                        }

                        break;
                    
                    default:
                        break;
                    }
                }
            }

            echo ("  ");
            echoI (min);
            echo(":");
            printI(sec);
            print("–––––––––––––––––––––––––––––––");
            sleep(1);

            sec--;

            if (sec <= 0)
            {
                sec = 59;
                min--;
            }
        }
    }

    else if (app == "s" || app == "stopwatch")
    {
        sec2 = 0;
        min2 = 0;

        while (true)
        {
            if (command1 == "break_")
            {
                command1 = "";

                break;
            }
            
            clear();
            print("–––––––––––––––––––––––––––––––");
            echo ("  ");
            echoI (min2);
            echo(":");
            printI(sec2);
            print("–––––––––––––––––––––––––––––––");

            sleep(1);

            sec2++;

            if (sec >= 59)
            {
                sec2 = 0;
                min2++;
            }

            if (_kbhit())
            {
                switch (_getche())
                {
                case 'p':
                    while (true)
                    {
                        if (command1 == "break")
                        {
                            command1 = "";

                            break;
                        }

                        clear();
                        print ("PAUSED");
                        print ("PRESS P TO UNPAUSE");

                        if (_kbhit())
                        {
                            switch (_getche())
                            {
                            case 'p':
                                command1 = "break";

                                break;
                            
                            default:
                                break;
                            }
                        }

                        sleep(1);

                    break;
                    }

                case 'q':
                    while (true)
                    {
                        clear();
                        print("Do you want to quit? Y/N?");

                        if (command1 == "break")
                        {
                            command1 = "";

                            break;
                        }
                        
                        else if (command1 == "break_")
                        {
                            break;
                        }

                        if (_kbhit())
                        {
                            switch (_getche())
                            {
                            case 'y':
                                command1 = "break_";

                                break;
                            
                            case 'n':
                                command1 = "break";

                                break;

                            default:
                                break;
                            }
                        }
                    }

                case 'r':
                    sec2 = 0;
                    min2 = 0;

                default:
                    break;
                }
            }
        }
    }
}

void get(std::string command, std::string command2 = "")
{
    if (command == "kb")
    {
        if (_kbhit())
        {
            switch (_getche())
            {
            case 's':
                opt++;

                break;

            case 'w':
                opt--;

                break;

            case 'z':
                if (opt == 1)
                {
                    start("timer");
                }

                else if (opt == 2)
                {
                    start("s");
                }

                else if (opt == 4)
                {
                    end(0);
                }

                break;

            case '1':
                opt = 1;

                break;

            case '2':
                opt = 2;

                break;

            case '3':
                opt = 3;

                break;

            case '4':
                opt = 4;

                break;
            
            default:
                break;
            }
        }
    }

    else if (command == "images")
    {
        print("╭–––––––––––––––––––––––––––––╮");
        print("|  -= TIMER AND STOPWATCH =-  |");

        if (opt == 1)
        {
            print("|           ⋐TIMER⋑           |");
        }

        else
        {
            print("|            TIMER            |");
        }

        if (opt == 2)
        {
            print("|         ⋐STOPWATCH⋑         |");
        }

        else
        {
            print("|          STOPWATCH          |");
        }

        if (opt == 3)
        {
            print("|           ⋐EXIT⋑            |");
        }

        else
        {
            print("|            EXIT             |");
        }

        print ("╰–––––––––––––––––––––––––––––╯");
    }

    else if (command == "update")
    {
        if (opt > 3)
        {
            opt = 3;
        }

        else if (opt < 1)
        {
            opt = 1;
        }
    }

    else
    {
        error("get/command(...), No command named like that");
    }
}

int main()
{
    while (true)
    {
        clear();
        get("images");
        get("kb");
        get("update");
        getche();
    }

    return 0;
}
 