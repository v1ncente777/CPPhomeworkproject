#pragma once
#ifndef LIBMANAGE_USER_H
#define LIBMANAGE_USER_H
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include "global.h"

class User {
protected :
    char account[20];
    char password[20];
    char spassword[20];

public :
    virtual void Login() = 0;
    virtual void Regist() = 0;
    virtual void save() = 0;
    virtual void BrowseBook() = 0;
    virtual void ChangePassword() = 0;
    virtual void FindPassword() = 0;
};


#endif //LIBMANAGE_USER_H
