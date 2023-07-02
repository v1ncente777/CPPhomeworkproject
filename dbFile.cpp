#include "user.h"
#include "dbFile.h"
#include "global.h"
using namespace std;

// 数据操作类
void dbFile::cls()
{
    system("cls");
}
void dbFile::over()
{
    dbFile* dbp = new dbFile;
    dbp->cls();
    system("color 6");
    int time = 6;
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t感谢您的使用！！\n\n\n\n\n");
    printf(" 程序即将关闭...");
    while (--time >= 1)
    {
        printf("\r%d", time);
        printf("\b");
        Sleep(1000);
    }
    dbp->cls();
    exit(0);
}

void dbFile::login()
{
    Reader* rp = new Reader;
    manager* mp = new manager;
    int sign = 0;
    while (1)
    {
        cls();
        Loginmenu();
        char choose = _getch();
        switch (choose)
        {
            case '1':
                cls();
                useLogin(mp);
                break;
            case '2':
                cls();
                useLogin(rp);
                break;
            case '3':
                cls();
                sign = 1;
                break;
            case '4':
                cls();
                over();
                break;
            default:
                cout << "输入无效！！";
                break;
        }
        if (sign)
        {
            break;
        }
    }
}
void dbFile::useLogin(User* base)
{
    base->Login();
}
void dbFile::regist()
{
    Reader* rp = new Reader;
    manager* mp = new manager;
    int sign = 0;
    while (1)
    {
        cls();
        Registmenu();
        char choose = _getch();
        switch (choose)
        {
            case '1':
                cls();
                useRegist(mp);
                break;
            case '2':
                cls();
                useRegist(rp);
                break;
            case '3':
                cls();
                sign = 1;
                break;
            case '4':
                cls();
                over();
                break;
            default:
                cout << "无效输入！！";
                break;
        }
        if (sign)
        {
            break;
        }
    }
}
void dbFile::usesave(User* base)
{
    base->save();
}
void dbFile::usechangepassword(User* base)
{
    base->ChangePassword();
}

void dbFile::useRegist(User* base)
{
    base->Regist();
}

void dbFile::usebrowsebook(User* base)
{
    base->BrowseBook();
}

void dbFile::usefindpassword(User* base)
{
    base->FindPassword();
}
void dbFile::findpassword()
{
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t********************************\n");
    printf("\t\t\t\t\t**                            **\n");
    printf("\t\t\t\t\t**      1.管理员找回密码      **\n");
    printf("\t\t\t\t\t**                            **\n");
    printf("\t\t\t\t\t**      2.用户找回密码        **\n");
    printf("\t\t\t\t\t**                            **\n");
    printf("\t\t\t\t\t**      3.返回                **\n");
    printf("\t\t\t\t\t**                            **\n");
    printf("\t\t\t\t\t********************************\n");
    printf("请按键选择:");
    int choose;
    int sign = 0;
    Reader* rp = new Reader;
    manager* mp = new manager;
    scanf("%d", &choose);
    while (1)
    {
        cls();

        switch (choose)
        {
            case 1:
                cls();
                usefindpassword(mp);
                sign = 1;
                break;
            case 2:
                cls();
                usefindpassword(mp);
                sign = 1;
                break;
            case 3:
                sign = 1;
                break;
            default:
                printf("输入无效！");
                break;
        }
        if (sign)
        {
            break;
        }
    }
}
int dbFile::exist(char* account, int flag)
{
    if (flag == 0)
    {
        Reader* p = rhead->get_next();
        while (p != NULL)
        {
            if (strcmp(account, p->get_account(p)) == 0)
            {
                return 1;
            }
            p = p->get_next();
        }
    }
    else if (flag == 1)
    {
        manager* p = mhead->get_next();
        while (p != NULL)
        {
            if (strcmp(account, p->get_account(p) ) == 0)
            {
                return 1;
            }
            p = p->get_next();
        }
    }
    return 0;
}
void dbFile::_main()
{
    while (1)
    {
        cls();
        _mainmenu();
        char choose = _getch();
        switch (choose)
        {
            case '1':
                cls();
                login();
                break;
            case '2':
                cls();
                regist();
                break;
            case '3':
                cls();
                findpassword();
                break;
            case '4':
                cls();
                over();
                break;
            default:
                cout << "无效输入！！";
                break;
        }
    }
}

void dbFile::idsort()
{
    Book* f, *x, *y, *p;
    f = NULL;
    if (bhead->get_next() == NULL || bhead->get_next()->get_next() == NULL)
    {
        return;
    }
    while (f != bhead->get_next()->get_next())
    {
        for (p = bhead; p->get_next()->get_next() != f; p = p->get_next())
        {
            if (p->get_next()->get_id() > p->get_next()->get_next()->get_id())
            {
                x = p->get_next();
                y = p->get_next()->get_next();
                p->set_next(y);
                x->set_next(y->get_next());
                y->set_next(x);
            }
        }
        f = p->get_next();
    }
}
void dbFile::bookamountsort()
{
    Book* f, * x, * y, * p;
    f = NULL;
    if (bhead->get_next() == NULL || bhead->get_next()->get_next() == NULL)
    {
        return;
    }
    while (f != bhead->get_next()->get_next())
    {
        for (p = bhead; p->get_next()->get_next() != f; p = p->get_next())
        {
            if (p->get_next()->get_amount() > p->get_next()->get_next()->get_amount())
            {
                x = p->get_next();
                y = p->get_next()->get_next();
                p->set_next(y);
                x->set_next(y->get_next());
                y->set_next(x);
            }
        }
        f = p->get_next();
    }
}
void dbFile::showidsort()
{
    dbFile* fp = new dbFile;
    Book* bp = new Book;
    fp->idsort();
    bp->show_book();
    system("pause");
}
void dbFile::showbookamountsort()
{
    dbFile* fp = new dbFile;
    Book* bp = new Book;
    fp->bookamountsort();
    bp->show_book();
    system("pause");
}
void dbFile::managerfunction()
{
    dbFile* fp = new dbFile;
    manager* mp = new manager;
    int sign = 0;
    int choose;
    while (1)
    {
        fp->cls();
        managermenu();
        cin >> choose;
        switch (choose)
        {
            case 1:
                fp->cls();
                mp->AddBook();
                break;
            case 2:
                fp->cls();
                mp->DeleteBook();
                break;
            case 3:
                fp->cls();
                mp->ChangeBook();
                break;
            case 4:
                fp->cls();
                mp->BrowseReader();
                break;
            case 5:
                fp->cls();
                mp->BrowseBook();
                break;
            case 6:
                fp->cls();
                fp->usechangepassword(mp);
                break;
            case 7:
                fp->cls();
                sign = 1;
                break;
            case 8:
                fp->cls();
                fp->over();
                break;
            default:
                cout << "输入无效！！";
                break;
        }
        if (sign)
        {
            break;
        }
    }
}
void dbFile::readerfunction(Reader* pp)
{
    dbFile* fp = new dbFile;
    Reader* rp = new Reader;
    int sign = 0;
    while (1)
    {
        fp->cls();
        readermenu();
        char choose = _getch();
        switch (choose)
        {
            case '1':
                fp->cls();
                rp->BorrowBook(pp);
                break;
            case '2':
                fp->cls();
                rp->ReturnBook(pp);
                break;
            case '3':
                fp->cls();
                fp->usebrowsebook(rp);
                break;
            case '4':
                fp->cls();
                rp->BrowseBorrowBook(pp);
                break;
            case '5':
                fp->cls();
                fp->usechangepassword(rp);
                break;
            case '6':
                fp->cls();
                sign = 1;
                break;
            case '7':
                fp->over();
                break;
            default:
                cout << "输入无效！！";
                break;
        }
        if (sign)
        {
            break;
        }
    }
}