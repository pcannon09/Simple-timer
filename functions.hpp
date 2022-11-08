#pragma once

#include "functions.hpp"
#include <iostream>
#include <string>
#include <string.h>

std::string WITHLINES = "with lines";
std::string WITHOUTLINES = "without lines";
int i = 0;

void clear()
{
    system("clear");
}

void error(std::string message)
{
    std::cout<<"E: "<<message<<"\n";

    exit(1);
}

void end(int endType, int defaultType = 2)
{
    clear();
    
    if (defaultType == 2)
    {
        if (endType == 0)
        {
            std::cout<<"Exit with code 0"<<"\n";
            exit(0);
        }

        else if (endType == 1)
        {
            std::cout<<"Exit with code 1"<<"\n";
            exit(1);
        }

        else
        {
            error("end/endType, Var endType is not 0 or 1");
        }

    }

    else if (defaultType == 0)
    {
        exit(0);
    }
    
    else if (defaultType == 1)
    {
        exit(1);
    }

    else
    {
        error("end/defaultType, Var defaultType is not 0 or 1");
    }
}

void printI(int text = 0, std::string lines = WITHLINES)
{
    if (lines == WITHLINES)
    {
        std::cout<<text<<"\n";
    }

    else if (lines == WITHOUTLINES)
    {
        std::cout<<text;
    }
}

void printB(bool text = false, std::string lines = WITHLINES)
{
    if (lines == WITHLINES)
    {
        std::cout<<text<<"\n";
    }

    else if (lines == WITHOUTLINES)
    {
        std::cout<<text;
    }
}

void print(std::string text = "", std::string lines = WITHLINES)
{
    if (lines == WITHLINES)
    {
        std::cout<<text<<"\n";
    }
    
    else if (lines == WITHOUTLINES)
    {
        std::cout<<text;
    }
    
    else
    {
        error("print/lines, Expected a right name");
    }
}

void echo(std::string text = "")
{
    print(text, WITHOUTLINES);
}

void echoI(int text = 0)
{
    printI(text, WITHOUTLINES);
}

void echoB(bool text = false)
{
    printB(text, WITHOUTLINES);
}

void clearX(int times)
{
    i = 0;
    
    while (i <= times)
    {
        clear();
        i++;
    }
}
 