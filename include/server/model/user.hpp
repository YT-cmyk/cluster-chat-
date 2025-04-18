#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
/*
基础的用户数据模型，是业务系统中常见的 "用户实体类"，主要用于：
    1.在内存中表示用户数据
    2.作为数据库和业务逻辑间的桥梁
    3.保证数据访问的规范性和安全性
在完整的系统中，通常会配合数据库操作类（如UserDAO）和业务逻辑类（如UserService）一起使用。
*/

// User表的ORM（对象关系映射）类
class User
{
public:
    User(int id = -1, string name = "", string pwd = "", string state = "offline")
    {
        this->id = id;
        this->name = name;
        this->password = pwd;
        this->state = state;
    }

    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setPwd(string pwd) { this->password = pwd; }
    void setState(string state) { this->state = state; }

    int getId() { return this->id; }
    string getName() { return this->name; }
    string getPwd() { return this->password; }
    string getState() { return this->state; }

protected:
    int id;
    string name;
    string password;
    string state;
};

#endif