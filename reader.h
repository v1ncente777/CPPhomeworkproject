#pragma once
#ifndef LIBMANAGE_READER_H
#define LIBMANAGE_READER_H

#include "user.h"
using namespace std;
class Reader : public User
{
private:
    int number;
    string name;
    string sex;
    int books; // 借书数量
    int bookcnt;// 借阅次数
    char booklist[20][20];// 储存借阅书籍
    class Reader* next;

public :
    virtual void Login();
    virtual void Regist();
    virtual void save();
    virtual void BrowseBook();
    virtual void ChangePassword();
    virtual void FindPassword();
    void creat();
    void BrowseBorrowBook(Reader* pp);
    void BorrowBook(Reader* pp);
    void ReturnBook(Reader* pp);

public :
    void set_number(int _number) { number = _number; };
    void set_name(string _name) { name = _name; };
    void set_sex(string _sex) { sex = _sex; };
    void set_next(Reader* p) { next = p; };
    void set_books(int _books) { books = _books; };
    void set_bookcnt(int _bookcnt) { bookcnt = _bookcnt; };
    int get_bookcnt() { return bookcnt; };
    int get_number() { return number; };
    int get_books() { return books; };
    Reader* get_next() { return next; }
    string get_name() { return name; };
    string get_sex() { return sex; };
    char* get_account(Reader* p) { return p->account; };
    char* get_password(Reader* p) { return p->password; };
    char* get_spassword(Reader* p) { return p->spassword; };
    char* get_booklist(Reader* p, int i) { return p->booklist[i]; };

};

#endif //LIBMANAGE_READER_H
