#include "WordAccess.h"

ReadAccess::ReadAccess(){}
ReadAccess::ReadAccess(std::string setString):str(setString){}

char* ReadAccess::operator[](int wordIndex) const
{
    return findTheWord(wordIndex, str);
}

ReadWriteAccess::ReadWriteAccess(std::string setString){}

char* ReadWriteAccess::operator[](int wordIndex)
{
    return findTheWord(wordIndex, str);
}

namespace WordAccess
{
    bool eofSentence(char* wordIndex)
    {
        int i = 0;
        while( *(wordIndex + i) != ' ' )
        {
            if( *(wordIndex + i) == '\0')
                return true;
            i++;
        }
        return false;
    }

    bool eofWord(char letterIndex)
    {
        if(*(&(letterIndex) + 1) == '\0' || *(&(letterIndex) + 1) == ' ')
            return true;
        else 
            return false;
    }
}

char* findTheWord(int wordIndex, std::string target)
{
    int wordCount = 0;
    int letterIndex = 0;
    while( wordCount != wordIndex || WordAccess::eofSentence( &target[letterIndex] ) )
    {
        if( WordAccess::eofWord( target[letterIndex] ) )
            wordCount++;

        letterIndex++;
    }

    return &target[letterIndex];
}

