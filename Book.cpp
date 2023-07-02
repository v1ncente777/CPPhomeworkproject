#include "Book.h"
#include "global.h"
// 图书类
void Book::creat()

{
    ifstream f_book("book.txt", ios::in);
    int id;
    int amount;
    int flag;
    string bookname;
    string author;
    string press;
    while (f_book >> id && f_book >> flag && f_book >> amount && f_book >> bookname
           && f_book >> author && f_book >> press)
    {
        Book* p = new Book;
        p->id = id;
        p->flag = flag;
        p->amount = amount;
        p->bookname = bookname;
        p->author = author;
        p->press = press;

        bend->set_next(p);
        p->set_next(NULL);
        bend = bend->get_next();
    }
    f_book.close();
}

void Book::save()
{
    Book* bp = bhead->get_next();
    ofstream f_book("book.txt", ios::out);
    while (bp)
    {
        f_book << bp->id << " " << bp->flag << " " << bp->amount << " "
               << bp->bookname << " " << bp->author << " " << bp->press << endl;
        bp = bp->get_next();
    }
    f_book.close();
}

void Book::show_book()
{
    Book* bp = bhead->get_next();
    cout << "id号\t\t" << "是否可借\t\t" << "数量\t\t" << "书名\t\t" << "作者\t\t" << "出版社\n";
    while (bp)
    {
        cout << bp->get_id() << "\t\t" << bp->get_flag() << "\t\t\t" << bp->get_amount() << "\t\t"
             << bp->get_bookname() << "\t\t" << bp->get_author() << "\t\t" << bp->get_press() << "\n";
        bp = bp->get_next();
    }
}
