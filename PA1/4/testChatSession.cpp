#include <iostream>
#include "ChatUser.h"
#include "ChatSession.h"

int main() {
    ChatSession session;

    // 创建用户
    ChatUser* userA = new ChatUser("A");
    ChatUser* userB = new ChatUser("B");
    ChatUser* userC = new ChatUser("C");

    // 添加用户到聊天室
    session.addUser(userA);
    session.addUser(userB);
    session.addUser(userC);

    // 测试查找用户
    ChatUser* foundUser = session.getUserByName("A");
    if (foundUser) {
        std::cout << "Found user: " << foundUser->getName() << std::endl;
    }

    // 测试删除用户
    session.removeUser(userB);
    session.removeUser(userB); // 再次删除，测试提示信息

    // 测试用户不在聊天室的情况
    ChatUser* notInChatUser = session.getUserByName("B");

    // 清理内存
    delete userA;
    delete userB;
    delete userC;

    return 0;
}