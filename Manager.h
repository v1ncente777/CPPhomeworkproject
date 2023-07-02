#ifndef LIBMANAGE_MANAGER_H
#define LIBMANAGE_MANAGER_H

#pragma once
#include "user.h"
using namespace std;

class manager : public User
{
private:
    class manager* next;

public :

    virtual void Login();
    virtual void Regist();
    virtual void BrowseBook();
    virtual void save();
    virtual void ChangePassword();
    virtual void FindPassword();
    void creat();
    void AddBook();
    void ChangeBook();
    void DeleteBook();
    void DeleteReaderBook(char* bookname);
    void BrowseReader();

public :
    void set_next(manager* p) { next = p; };
    manager* get_next() { return next; };
    char* get_account(manager* p) { return p->account; };
    char* get_password(manager* p) { return p->password; };
    char* get_spassword(manager* p) { return p->spassword; };
};



#endif //LIBMANAGE_MANAGER_H
