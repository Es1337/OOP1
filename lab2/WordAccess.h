#ifndef WordAccess
#define WordAccess
#include <string>

class ReadAccess
{
    public:
        ReadAccess();
        ReadAccess(std::string);

        char* operator[](int) const;

        std::string str;
};

class ReadWriteAccess
{
    public:
        ReadWriteAccess(std::string);

        char* operator[](int);

        std::string str;
};

namespace WordAccess
{
    bool eofSentence(char*);
    bool eofWord(char);
}

char* findTheWord(int, std::string);



#endif