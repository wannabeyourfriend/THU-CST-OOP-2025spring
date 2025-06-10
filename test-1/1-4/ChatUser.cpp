#include "ChatUser.h"

void ChatUser::addFriend(ChatUser *user)
{
    if(user != nullptr) {
        auto it = std::find(friends.begin(), friends.end(), user);
        if(it != friends.end()) 
        {
            std::cout << name << " and " << user->getName() << " are already friends" << std::endl;
            return;
        }
        friends.push_back(user);
        std::cout << name << " -> add friend -> " << user->getName() << std::endl;
    }
}

void ChatUser::removeFriend(ChatUser *user)
{
    if(user != nullptr)
    {
        auto it = std::find(friends.begin(), friends.end(), user);
        if (it == friends.end()) {
            std::cout << name << " and " << user->getName() << " are not yet friends" << std::endl;
            return;
        }
        if(it != friends.end())
        {
            std::cout << name << " -> remove friend -> " << user->getName() << std::endl;
            friends.erase(it);
        }
    }
    return;
}

void ChatUser::sendMessage(ChatUser *user, std::string message)
{
    if(user != nullptr) 
    {
        std::cout << name << " -> send message -> " << user->getName() << " : " << message << std::endl;
        user->receiveMessage(this, message);
    }
}

void ChatUser::receiveMessage(ChatUser *user, std::string message)
{
    if(user != nullptr) 
    {
        bool have_this_user = false;
        for(auto& pair : messageQueue ) 
        {
            if (pair.first == user)
            {
                pair.second.push_back(message);
                have_this_user = true;
                std::cout << name << " -> receive message -> " << user->getName() << " : " << message << std::endl;
                break;
            }
        }
        if(!have_this_user)
        {
            std::pair<ChatUser*, std::vector<std::string>> pair;
            pair.first = user;
            pair.second.push_back(message);
            messageQueue.push_back(pair);
            std::cout << name << " -> receive message -> " << user->getName() << " : " << message << std::endl; 
        }
    }
}

void ChatUser::showMessage()
{
    std::cout << "Chat " << name << ": " << std::endl;
    if (messageQueue.empty())
    {
        return;
    }
    for(const auto& pair : messageQueue)
    {
        std::cout << ">> From " << pair.first->getName() << ": " << std::endl;
        for(const auto& message : pair.second)
        {
            std::cout << ">> " << message << std::endl;
        }
    }
}
void ChatUser::showFriends()
{
    std::cout << name << "'s friend:";
    for(const auto& user_ptr : friends)
    {
        std::cout << " " <<
        user_ptr->getName();
    }
    std::cout << std::endl;
    return;
}