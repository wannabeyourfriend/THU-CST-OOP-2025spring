#include "ChatSession.h"

void ChatSession::addUser(ChatUser *user)
{
    if(user != nullptr) {
        users.push_back(user);
        std::cout << "Add user: " << user->getName() << std::endl; 
    }
}

void ChatSession::removeUser(ChatUser *user)
{
    if(user != nullptr) 
    {
        auto it = std::find(users.begin(), users.end(), user);
        if(it != users.end()){
            users.erase(it);// 只是在vector中将这个地址擦除了，并没有导致这个地址的不合法
            std::cout << "Remove user: " << user->getName() << std::endl;
        }
    }
}

ChatUser *ChatSession::getUserByName(std::string name)
{
    for(auto user : users) {
        if(user->getName() == name)
        {
            return user;
        }
    }
    std::cout << name << " not in chat" << std::endl;
    return nullptr;
}
