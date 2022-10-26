#include <iostream>
#include "UserProfile.h"

std::ostream &operator<<(std::ostream &os, const UserProfile &rhs)
{
    os << "User name: " << rhs.getUserName() << std::endl
       << "User level: " << rhs.getUserLevel() << std::endl
       << "Login Times: " << rhs.getLoginTimes() << std::endl
       << "Guess Times: " << rhs.getGuessTimes() << std::endl
       << "Correct Times: " << rhs.getCorrectTimes() << std::endl
       << "Correct Percent: " << rhs.getCorrectPercent() << '%' << std::endl;
    return os;
}

void comp(UserProfile &user1, UserProfile &user2)
{
    if (user1 == user2)
        std::cout << "This is one person.\n";
    else
        std::cout << "They are different persons.\n";
}

int main()
{
    UserProfile user1;
    std::cout << user1;
    UserProfile user2("hhh", UserProfile::senior, 20, 14, 5);
    std::cout << user2;
    UserProfile user3;
    comp(user1,user3);
    return 0;
}