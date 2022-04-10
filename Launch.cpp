#include <filesystem>
#include <iostream>
#include <string>

using namespace std;
class String : public string
{
public:
    String(){}
    String(string j){
        this->operator=(j);
    }
    String operator=(string J)
    {
        this->append(J);
        return *this;
    }
    bool operator==(String *J)
    {
        return (strcmp(this->c_str(),J->c_str())==0);
    }
};
string getOsName()
{
#ifdef _WIN64 || _WIN32
    return "Win";
#elif __APPLE__ || __MACH__
    return "OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "Unsupported";
#elif __unix || __unix__
    return "Unsupported";
#else
    return "Unsupported";
#endif
}
int main()
{
    String OSNAME=getOsName();
    String ActivatePath = OSNAME + "Env/bin/activate";
    if(OSNAME=="OSX"){
    string command="source "+ActivatePath+" ; python3 src/main.py";
    system(command.c_str());
    }
    else if (OSNAME =="Win"){

    }
}
