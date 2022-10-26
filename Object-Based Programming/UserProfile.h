#ifndef USERPROFILE_H_
#define USERPROFILE_H_

#include <string>

class UserProfile
{
public:
    enum level
    {
        junior,
        intermediate,
        senior,
        expert
    };
    UserProfile(std::string name = "guest", level lev = junior, int lt = 0, int gt = 0, int ct = 0);
    std::string getLoginRecord() const;
    std::string getUserName() const;
    std::string getUserLevel() const;
    int getLoginTimes() const;
    int getGuessTimes() const;
    int getCorrectTimes() const;
    double getCorrectPercent() const;
    void setLoginRecord(const std::string &lr);
    void setUserName(const std::string &un);
    void setLoginTimes(const int &lt);
    void setGuessTimes(const int &gt);
    void setCorrectTimes(const int &cr);
    void setUserLevel(const level &l);
    bool operator==(const UserProfile &user); //提供相等测试
    bool operator!=(const UserProfile &user); //提供不等测试

private:
    static int id;
    int UserID;
    std::string loginRecord;
    std::string userName;
    int loginTimes;
    int guessTimes;
    int correctTimes;
    level userLevel;
};

int UserProfile::id = 0;

UserProfile::UserProfile(std::string name, level lev, int lt, int gt, int ct) : userName(name), userLevel(lev), loginTimes(lt), guessTimes(gt), correctTimes(ct)
{
    UserID = id++;
}

std::string UserProfile::getUserLevel() const
{
    switch (userLevel)
    {
    case 0:
        return "junior";
    case 1:
        return "intermediate";
    case 2:
        return "senior";
    case 3:
        return "expert";
    default:
        return "junior";
    }
}

void UserProfile::setUserLevel(const level &l)
{
    userLevel = l;
}

void UserProfile::setUserName(const std::string &un)
{
    userName = un;
}

void UserProfile::setLoginTimes(const int &lt)
{
    loginTimes = lt;
}

void UserProfile::setLoginRecord(const std::string &lr)
{
    loginRecord = lr;
}

void UserProfile::setGuessTimes(const int &gt)
{
    guessTimes = gt;
}

void UserProfile::setCorrectTimes(const int &ct)
{
    correctTimes = ct;
}

std::string UserProfile::getUserName() const
{
    return userName;
}

std::string UserProfile::getLoginRecord() const
{
    return loginRecord;
}

int UserProfile::getLoginTimes() const
{
    return loginTimes;
}

int UserProfile::getGuessTimes() const
{
    return guessTimes;
}

int UserProfile::getCorrectTimes() const
{
    return correctTimes;
}

double UserProfile::getCorrectPercent() const
{
    return guessTimes ? (100.0 * correctTimes / guessTimes) : 0;
}

bool UserProfile::operator==(const UserProfile &user)
{
    if (this->loginRecord == user.loginRecord && this->userName == user.userName && this->UserID == user.UserID)
        return true;
    else
        return false;
}

bool UserProfile::operator!=(const UserProfile &user)
{
    return !(*this == user);
}

#endif