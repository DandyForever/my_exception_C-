#include <iostream>
#include <fstream>

class mega_exception
{
    private:
        const int ERR_CODE_ = 0;
        const int STRING_ = 0;
        const char* MESS_ = "";
        const char* FUNC_ = "";
        const char* FILE_ = "";
        mega_exception* CLASS_POINTER_ = nullptr;


    public:
        mega_exception (const int error, const int string, const char* function,
                        const char* file, const char* message, mega_exception* pointer):
            ERR_CODE_ (error),
            STRING_ (string),
            MESS_ (message),
            FUNC_ (function),
            FILE_ (file),
            CLASS_POINTER_ (pointer)
        {}

        ~mega_exception () {}

        friend std::ofstream& operator << (std::ofstream& fout, mega_exception* exception)
        {
            while (exception != nullptr)
            {
                fout << "ERROR! " << exception -> MESS_ << '\n';
                fout << "File: " << exception -> FILE_ << '\n';
                fout << "Function: " << exception -> FUNC_ << '\n';
                fout << "Line: " << exception -> STRING_ << '\n';
                fout << "Code: " << exception -> ERR_CODE_ << '\n';

                if (exception -> CLASS_POINTER_ != nullptr)
                    fout << "....\n";

                exception = exception -> CLASS_POINTER_;
            }

            return fout;
        }
};

#define MAKE_EXCEPTION(message, code, pointer) throw new mega_exception (code, __LINE__, __PRETTY_FUNCTION__, __FILE__, #message, pointer)
