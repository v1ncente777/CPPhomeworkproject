#include "user.h"
#include "reader.h"
#include "dbFile.h"
#include "global.h"

using namespace std;

// 读者类
void Reader::Login()
{
    int cnt = 4;
    int flag = 0;
    int k = 0;
    int i;
    char c;
    dbFile* fp = new dbFile;
    Reader* p = rhead->get_next();
    char rpassword[2000];
    char raccount[2000];
    cout << "\n\n\n\n\n\n\n";
    printf("请输入您的账户(按0退出):");
    while (cin >> raccount)
    {
        if (strcmp(raccount, "0") == 0)
        {
            return;
        }
        if (strlen(raccount) <= 16)
        {
            break;
        }
        else
        {
            cout << "请输入长度为1到16位的账户:";
        }
    }

    cout << "请输入您的密码(按0退出):";
    for (i = 0; (c = _getch()) != '\r';)
    {
        if (c == '0')
        {
            return;
        }
        if (i <= 15 && isprint(c))
        {
            rpassword[i] = c;
            i++;
            k++;
            cout << "*";
        }
        if (k > 0 && c > 0 && c == '\b')
        {
            i--;
            k--;
            cout << "\b";
            cout << " ";
            cout << "\b";
        }
    }
    rpassword[i] = '\0';
    cout << "\n";
    while (p)
    {
        if (strcmp(p->account, raccount) == 0)
        {
            flag = 1;
            while (strcmp(p->password, rpassword) != 0)
            {
                cnt--;
                if (cnt == 1)
                {
                    fp->cls();
                    cout << "\n\n\n\n\n\n\n";
                    cout << "密码输入次数已用完！ " << "\n" << "即将退出登录页面...";
                    Sleep(3000);
                    fp->cls();
                    return;
                }
                cout << "密码错误！您还有" << cnt - 1 << "次机会\n" << endl;
                cout << "请重新输入(按0退出):";
                k = 0;
                for (i = 0; (c = _getch()) != '\r';)
                {
                    if (c == '0')
                    {
                        return;
                    }
                    if (i <= 15 && isprint(c))
                    {
                        rpassword[i] = c;
                        i++;
                        k++;
                        cout << "*";
                    }
                    if (k > 0 && c > 0 && c == '\b')
                    {
                        i--;
                        k--;
                        cout << "\b";
                        cout << " ";
                        cout << "\b";
                    }
                }
                rpassword[i] = '\0';
                cout << "\n";
            }
            cout << "读者" << raccount << "登陆成功！\n" << "即将跳转至读者页面..." << endl;
            Sleep(2000);
            fp->cls();
            fp->readerfunction(p);
            return;
        }
        p = p->get_next();
    }
    if (!flag)
    {
        cout << "不存在此账号！\n请先前往注册！\n" << endl;
        cout << "即将跳转至主页面...";
        Sleep(2000);
    }
}

void Reader::Regist()
{
    dbFile* fp = new dbFile;
    Reader* rp = new Reader;
    char raccount[2000];
    char rpassword[2000];
    char rspassword[2000];
    char name[200];
    char sex[10];
    int number;

    Reader* p = new Reader;
    cout << "\n\n\n\n\n\n\n";
    cout << "请输入账户(按0退出):";
    while (cin >> raccount)
    {
        if (strcmp(raccount, "0") == 0)
        {
            return;
        }
        if (strlen(raccount) <= 16 && !fp->exist(raccount, 0))
        {
            break;
        }
        else if (fp->exist(raccount, 1))
        {
            cout << "该账户已存在！请重新输入(按0退出):";
        }
        else
        {
            cout << "请输入长度为1到16位的账户:";
        }
    }
    strcpy_s(p->account, raccount);
    cout << "请输入密码(按0退出):";
    while (cin >> rpassword)
    {
        if (strcmp(rpassword, "0") == 0)
        {
            return;
        }
        if (strlen(rpassword) <= 16)
        {
            break;
        }
        else
        {
            cout << "请输入长度为1到16位的密码(按0退出):";
        }
    }
    strcpy_s(p->password, rpassword);
    cout << "请输入您的密保(按0退出):";
    while (cin >> rspassword)
    {
        if (strcmp(rspassword, "0") == 0)
        {
            return;
        }
        if (strlen(rspassword) <= 16)
        {
            break;
        }
        else
        {
            cout << "请输入长度为1到16位的密保(按0退出):";
        }
    }
    strcpy_s(p->spassword, rspassword);
    cout << "请输入您的姓名(按0退出):";
    cin >> name;
    if (strcmp(name, "0") == 0)
    {
        return;
    }
    p->name = name;
    cout << "请输入您的性别(按0退出):";
    while (cin >> sex)
    {
        if (strcmp(sex, "0") == 0)
        {
            return;
        }
        if (strcmp(sex, "男") == 0 || strcmp(sex, "女") == 0)
        {
            p->sex = sex;
            break;
        }
        else
        {
            cout << "请输入男或女(按0退出):";
        }
    }


    cout << "请输入您的学号(按0退出):";
    while (cin >> number)
    {
        if (number == 0)
        {
            return;
        }
        if (number >= 0)
        {
            p->number = number;
            break;
        }
        else
        {
            cout << "请输入正确格式的学号(按0退出):";
        }
    }
    _rend->set_next(p);
    _rend = p;
    _rend->set_next(NULL);

    rp->save();
    fp->cls();
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t*******************************\n");
    printf("\t\t\t\t\t**                           **\n");
    printf("\t\t\t\t\t       读者%s注册成功！！     \n", raccount);
    printf("\t\t\t\t\t**     即将跳转至主页面...   **\n");
    printf("\t\t\t\t\t**                           **\n");
    printf("\t\t\t\t\t*******************************\n");
    Sleep(1500);
}
void Reader::save()
{
    Reader* rp = rhead->get_next();
    ofstream f_reader("reader.txt", ios::out);
    while (rp)
    {
        f_reader << rp->account << " " << rp->password << " " << rp->spassword << " " << rp->number
                 << " " << rp->name << " " << rp->sex << " " << rp->bookcnt << " " << rp->books;
        for (int i = 0; i < rp->bookcnt; i++)
        {
            f_reader << " " << booklist[i];
        }
        f_reader << endl;
        rp = rp->get_next();
    }
    f_reader.close();
}

void Reader::BrowseBook()
{
    dbFile* fp = new dbFile;
    int sign = 0;
    while (1)
    {
        fp->cls();
        browsemenu();
        char choose = _getch();
        switch (choose)
        {
            case '1':
                fp->cls();
                fp->showidsort();
                break;
            case '2':
                fp->cls();
                fp->showbookamountsort();
                break;
            case '3':
                fp->cls();
                sign = 1;
                break;
            case '4':
                fp->cls();
                fp->over();
                break;
            default:
                break;
        }
        if (sign)
        {
            break;
        }
    }
}
void Reader::creat()
{
    ifstream f_reader("reader.txt", ios::in);
    char _account[20];
    char _password[20];
    char _spassword[20];
    int number;
    int bookcnt;
    int books;
    char name[20];
    char sex[20];
    char booklist[20][20];
    while (f_reader >> _account && f_reader >> _password && f_reader >> _spassword)
    {
        Reader* p = new Reader;
        strcpy_s(p->account, _account);
        strcpy_s(p->password, _password);
        strcpy_s(p->spassword, _password);
        _rend->set_next(p);
        p->set_next(NULL);
        _rend = _rend->get_next();
    }
    while (f_reader >> number && f_reader >> name && f_reader >> sex
           && f_reader >> bookcnt && f_reader >> books)
    {
        Reader* p = new Reader;
        p->number = number;
        p->sex = sex;
        p->name = name;
        p->bookcnt = bookcnt;
        p->books = books;
        _rend->set_next(p);
        p->set_next(NULL);
        _rend = _rend->get_next();
    }
    while (f_reader >> bookcnt)
    {
        Reader* p = new Reader;
        for (int i = 0; i < bookcnt; i++)
        {
            f_reader >> booklist[i];
            strcpy_s(p->booklist[i], booklist[i]);
        }
        _rend->set_next(p);
        p->set_next(NULL);
        _rend = _rend->get_next();
    }
    f_reader.close();
}
void Reader::BrowseBorrowBook(Reader* pp)
{
    int cnt = pp->bookcnt;
    long long  sign;
    if (cnt == 0)
    {
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t您还未借阅任何书籍！\n");
    }
    printf("\n\n\n\n\n\n");


    for (int i = 0; i < cnt; i++)
    {
        printf("\t第%d次借阅的书籍:", i + 1);
        printf("%s\t", pp->get_booklist(pp, i));
        cout << "借阅数量:" << pp->get_books() << endl;
    }
    printf("\n\n请输入0退出:");
    while (scanf("%lld", &sign))
    {
        if (sign == 0)
        {
            break;
        }
        else
        {
            printf("-------------无效的输入！请重新输入！");
        }
    }
}

void Reader::BorrowBook(Reader* pp)
{
    Book* bp = bhead->get_next();
    Book* _bp = new Book;
    _bp->show_book();
    char bookname[200];
    int amount;
    int flag = 1;
    int sign = 1;
    int exist = 0;

    cout << "\n\n\n\n";
    cout << "请输入要借书的名称(按0退出):";
    cin >> bookname;
    if (strcmp(bookname, "0") == 0)
    {
        return;
    }
    while (bp)
    {
        if (bp->get_bookname() == bookname)
        {
            if (bp->get_amount() == 0)
            {
                cout << "此书无余量！\n";
                sign = 0;
            }
            if (bp->get_flag() == 0)
            {
                cout << "此书不可借！\n";
                flag = 0;
            }
            if (sign == 1 && flag == 1)
            {
                cout << "请输入要借阅书籍的数量:";
                while (cin >> amount)
                {
                    if (bp->get_amount() < amount)
                    {
                        cout << "借阅数量超过此书已有库存！请重新输入:";
                    }
                    else
                    {
                        int a = pp->get_books() + amount;
                        pp->set_books(a);
                        int b = bp->get_amount() - amount;
                        bp->set_amount(b);
                        break;
                    }
                }
                pp->bookcnt++;
                strcpy_s(pp->booklist[pp->bookcnt - 1], bookname);
                pp->save();
                bp->save();
                exist = 1;
                break;
            }
        }
        bp = bp->get_next();
    }
    if (exist == 0 && sign == 1 && flag == 1)
    {
        cout << "不存在此书！！\n";
    }
    else if (exist == 1)
    {
        cout << "图书:" << bookname << "借阅成功！！\n";
    }
    cout << "页面即将跳转...";
    Sleep(1200);
}
void Reader::ReturnBook(Reader* pp)
{
    Book* bp = bhead->get_next();
    char bookname[200];
    int amount;
    int exist = 0;
    int flag = 0;
    int cnt = pp->bookcnt;
    if (cnt == 0)
    {
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t您还未借阅任何书籍！\n");
        system("pause");
        return;
    }
    printf("\n\n\n\n\n\n");
    for (int i = 0; i < cnt; i++)
    {
        cout << "-------------第" << i + 1 << "次借阅的书籍:" << pp->booklist[i] << "\t\t";
        cout << "借阅数量:" << pp->books << endl;
    }
    cout << "请输入您要退还的书籍(按0退出):";
    while (cin >> bookname)
    {
        if (strcmp(bookname, "0") == 0)
        {
            return ;
        }
        for (int i = 0; i < pp->bookcnt; i++)
        {
            if (strcmp(pp->booklist[i], bookname) == 0)
            {
                flag = i;
                exist = 1;
                break;
            }
        }
        if (!exist)
        {
            cout << "未查询到该书!\n";
            cout << "请重新输入(按0退出):";
        }
        else
        {
            break;
        }
    }
    while (bp)
    {
        if (bp->get_bookname() == bookname)
        {
            cout << "请输入您要退还书籍的数量:";
            while (cin >> amount)
            {
                if (pp->books < amount)
                {
                    cout << "您未持有此数量的书籍!\n";
                    cout << "请重新输入:";
                }
                else
                {
                    int a = pp->books - amount;
                    int b = bp->get_amount() + amount;
                    pp->set_books(a);
                    bp->set_amount(b);
                    break;
                }
            }
        }
        bp = bp->get_next();
    }
    if (pp->books == 0)
    {
        for (int i = flag; i < pp->books - 1; i++)
        {
            strcpy_s(pp->booklist[i], pp->booklist[i + 1]);
        }
        pp->bookcnt--;
    }
    pp->save();
    bp->save();
    cout << bookname << "退还成功！！\n";
    cout << "即将返回上一页面...";
    Sleep(1100);
}
void Reader::FindPassword()
{
    Reader* rp = rhead->get_next();
    char password[200];
    char account[200];
    char spassword[200];
    int flag = 0;
    int sign = 0;
    cout << "请输入您的账户(按0退出):";
    while (cin >> account)
    {
        if (strcmp(account, "0") == 0)
        {
            return;
        }
        while (rp)
        {
            if (strcmp(rp->get_account(rp), account) == 0)
            {
                flag = 1;
                break;
            }
            rp = rp->get_next();
        }
        if (flag)
        {
            break;
        }
        else
        {
            printf("此账号不存在！请重新输入(按0退出):");
            rp = rhead->get_next();
        }
    }
    if (flag)
    {
        rp = rhead->next;
        printf("请输入您设置的密保(按0退出):");
        while (cin >> spassword)
        {
            if (strcmp(spassword, "0") == 0)
            {
                return;
            }
            while (rp)
            {
                if (strcmp(rp->get_spassword(rp), spassword) == 0)
                {
                    sign = 1;
                    break;
                }
                rp = rp->get_next();
            }
            if (sign)
            {
                printf("密保输入正确！\n");
                printf("您的密码为%s\n", rp->get_password(rp));
                system("pause");
                return;
            }
            else
            {
                printf("-------------密保输入错误！请重新输入(按0退出):");
                rp = rhead->get_next();
            }
        }
    }
}
void Reader::ChangePassword()
{
    dbFile* fp = new dbFile;
    Reader* p = rhead->get_next(), * rp = new Reader;
    int flag = 0;
    int sign = 0;
    char raccount[200];
    char rpassword[200];
    char rspassword[200];
    cout << "请输入您的账户(按0退出):";
    while (cin >> raccount)
    {
        if (strcmp(raccount, "0") == 0)
        {
            return;
        }
        while (p)
        {
            if (strcmp(p->account, raccount) == 0)
            {
                flag = 1;
                break;
            }
            p = p->get_next();
        }
        if (flag)
        {
            break;
        }
        else
        {
            cout << "此账号不存在！请重新输入(按0退出):";
            p = rhead->get_next();
        }
    }
    if (flag)
    {
        p = rhead->get_next();
        cout << "请输入您设置的密保(按0退出):";
        while (cin >> rspassword)
        {
            if (strcmp(rspassword, "0") == 0)
            {
                return;
            }
            while (p)
            {
                if (strcmp(p->spassword, rspassword) == 0)
                {
                    sign = 1;
                    break;
                }
                p = p->get_next();
            }
            if (sign)
            {
                cout << "请输入修改后的密码(按0退出):";
                while (cin >> rpassword)
                {
                    if (strcmp(rpassword, "0") == 0)
                    {
                        return;
                    }
                    if (strlen(rpassword) <= 16)
                    {
                        break;
                    }
                    else
                    {
                        cout << "请输入长度为1到16位的密码(按0退出):";
                    }
                }
                strcpy_s(p->password, rpassword);
                cout << "密码修改成功！";
                fp->usesave(p);
                system("pause");
                return;
            }
            else
            {
                cout << "密保输入错误！！请重新输入(按0退出):";
                p = rhead->get_next();
            }
        }
    }
}