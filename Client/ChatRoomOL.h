#ifndef __CHAT_ROOM_OL_H__
#define __CHAT_ROOM_OL_H__

#include <time.h>
#include "common.h"

#define NAME_SIZE 10
#define PASSWORD_SIZE 20
#define MAX_FRIEND_NUM 10
#define MAX_GROUP_NUM 10
#define MAX_GROUP_MEMBERS_NUM 20
#define CONTENT_SIZE 1024

typedef DoubleLinkList MessageList;

/* 结构体 */
/* 消息结构体 */
typedef struct Message
{
    /* 发信人 */
    char from[NAME_SIZE];
    /* 收信人 */
    char to[NAME_SIZE];
    /* 消息内容 */
    char content[CONTENT_SIZE];
    /* 消息时间 */
    time_t time;
} Message;

/* 好友列表 */
typedef struct FriendList
{
    /* 好友名字 */
    char name[NAME_SIZE];
    /* 消息链表 */
    MessageList *messageList;
} FriendList;

/* 群聊列表 */
typedef struct GroupList
{
    /* 群聊名字 */
    char name[NAME_SIZE];
    /* 消息链表 */
    MessageList *messageList;
    /* 群成员 */
    char members[MAX_GROUP_MEMBERS_NUM][NAME_SIZE];
    /* 群成员数量 */
    int membersNum;
} GroupList;

/* 用户账号 */
typedef struct UserAccount
{
    /* 账号 */
    char name[NAME_SIZE];
    /* 密码 */
    char password[PASSWORD_SIZE];
    /* 在线状态 */
    int online;
    /* 好友列表 */
    FriendList *friendList;
    /* 群聊列表 */
    GroupList *groupList;
} UserAccount;


/* 聊天室初始化 */
int ChatRoomOLInit();

/* 聊天室退出 */
int ChatRoomOLExit();

/* 聊天室注册 */
int ChatRoomOLRegister(int fd);

/* 聊天室登录 */
int ChatRoomOLLogin(int fd);

/* 添加好友 */
int ChatRoomOLAddFriend(int fd, const char *name);

/* 显示好友 */
int ChatRoomOLShowFriend(int fd);

/* 删除好友 */
int ChatRoomOLDelFriend(int fd, const char *name);

/* 私聊 */
int ChatRoomOLPrivateChat(int fd, const char *name);

/* 发起群聊 */
int ChatRoomOLAddGroupChat(int fd, const char *name);

/* 群聊 */
int ChatRoomOLGroupChat(int fd, const char *name);

/* 退出群聊 */
int ChatRoomOLExitGroupChat(int fd, const char *name);


#endif // __CHAT_ROOM_OL_H__