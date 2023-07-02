#include <iostream>

#include "user.h"
#include "reader.h"
#include "manager.h"
#include "Book.h"
#include "dbFile.h"


int main()
{
    mhead = new manager; mend = new manager; mhead->set_next(NULL); mend = mhead;

    rhead = new Reader; _rend = new Reader; rhead->set_next(NULL); _rend = rhead;

    bhead = new Book; bend = new Book; bhead->set_next(NULL); bend = bhead;

    Reader* rp = new Reader; rp->creat();
    manager* mp = new manager; mp->creat();
    Book* bp = new Book; bp->creat();
    dbFile* dbp = new dbFile;
    system("color B");
    dbp->_main();
    delete dbp;
    return 0;
}
