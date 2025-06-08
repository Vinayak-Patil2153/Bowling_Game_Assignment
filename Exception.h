#include<string>
#include <stdexcept>
using namespace std;

class GameException
{
    string mExceptionMessage;
public :
    GameException(const std::string& _exceptionMessage):mExceptionMessage(_exceptionMessage){}

    const char* what() const noexcept 
    {
        return mExceptionMessage.c_str();
    }
};