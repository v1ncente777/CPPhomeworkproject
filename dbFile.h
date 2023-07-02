#pragma once
#ifndef LIBMANAGE_DBFILE_H
#define LIBMANAGE_DBFILE_H
#include "user.h"
#include "reader.h"
#include "manager.h"
#include "Book.h"
#include "menu.h"
using namespace std;

class dbFile {
public :
    void cls();
    void over();
    void login();
    void useLogin(User* base);
    void regist();
    void useRegist(User* base);
    void usebrowsebook(User* base);
    void usesave(User* base);
    void usechangepassword(User* base);
    void usefindpassword(User* base);
    void findpassword();
    int exist(char* acconut, int flag);
    void _main();
    void idsort();
    void bookamountsort();
    void showidsort();
    void showbookamountsort();
    void managerfunction();
    void readerfunction(Reader* rp);
};


#endif //LIBMANAGE_DBFILE_H
