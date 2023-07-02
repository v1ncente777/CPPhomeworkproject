#pragma once
#ifndef LIBMANAGE_BOOK_H
#define LIBMANAGE_BOOK_H
#include "user.h"
using namespace std;

class Book
{
private:
    int id;
    int amount;
    int flag;
    string bookname;
    string author;
    string press;
    class Book* next;

public :

    void creat();
    void save();
    void show_book();
    void set_id(int _id) { id = _id; };
    void set_amount(int _amount) { amount = _amount; };
    void set_flag(int _flag) { flag = _flag; };
    void set_bookname(string _bookname) { bookname = _bookname; };
    void set_author(string _author) { author = _author; };
    void set_press(string _press) { press = _press; };
    void set_next(Book* p) { next = p; };


    int get_id() { return id; };
    int get_amount() { return amount; };
    int get_flag() { return flag; };
    string get_bookname() { return bookname; };
    string get_author() { return author; };
    string get_press() { return press; };
    Book* get_next() { return next; };

};


#endif //LIBMANAGE_BOOK_H
