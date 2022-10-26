#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#include <string>

class GlobalData
{
public:
    GlobalData();
    ~GlobalData();
    static std::string getProgramName()
    {
        return program_name;
    }
    static void setProgramName(const std::string &str)
    {
        program_name=str;
    }
    static std::string getVersionStamp()
    {
        return version_stamp;
    }
    static void setVersionStamp(const std::string &str)
    {
        version_stamp=str;
    }
    static int getVersionNumber()
    {
        return version_number;
    }
    static void setVersionNumber(const int &vn)
    {
       version_number=vn;
    }
    static int getTestsRun()
    {
        return tests_run;
    }
    static void setTestsRun(const int &tr)
    {
        tests_run=tr;
    }
    static int getTestsPassed()
    {
        return tests_passed;
    }
    static void setTestsPassed(const int &tp)
    {
        tests_passed=tp;
    }
private:
    static std::string program_name;
    static std::string version_stamp;
    static int version_number;
    static int tests_run;
    static int tests_passed;
};

#endif