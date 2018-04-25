#include <iostream>
#include "myexception.h"
#include "errors.h"

std::ofstream log ("LogFile.txt");


void First_test_func ();
void Second_test_func ();
void Third_test_func ();
void Last_test_func ();

int main()
{

    try
    {
        First_test_func ();
    }
    catch (mega_exception* exception)
    {
        log << exception;
    }

    log.close ();
    return 0;
}

void First_test_func ()
{
    try
    {
        Second_test_func ();
    }
    catch (mega_exception* exception)
    {
        if (1)
            MAKE_EXCEPTION(Bad allocation, BAD_ALLOCATION, exception)
    }
}

void Second_test_func ()
{
    try
    {
        Third_test_func ();
    }
    catch (mega_exception* exception)
    {
        if (1)
            MAKE_EXCEPTION(Logic error, LOGIC, exception)
    }
}


void Third_test_func ()
{
    try
    {
        Last_test_func ();
    }
    catch (mega_exception* exception)
    {
        std::cout << "meow";
        if (1)
            MAKE_EXCEPTION(Something strange is happening, UNCKNOWN, exception)
    }
}

void Last_test_func ()
{
    if (1)
        MAKE_EXCEPTION(Out of range, OUT_OF_RANGE, nullptr)
}
