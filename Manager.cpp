#include "Manager.h"
#include "dbFile.h"
#include "global.h"

// 管理员类
void manager::Login()
{
    int cnt = 4;
    int flag = 0;
    int k = 0;
    int i;
    char c;
    dbFile* fp = new dbFile;
    manager* p = mhead->get_next();
    char mpassword[2000];
    char maccount[2000];
    cout << "\n\n\n\n\n\n\n";
    printf("请输入您的账户(按0退出):");
    while (cin >> maccount)
    {
        if (strcmp(maccount, "0") == 0)
        {
            return;
        }
        if (strlen(maccount) <= 16)
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
            mpassword[i] = c;
            i++;
            k++;
            printf("*");
        }
        if (k > 0 && c > 0 && c == '\b')
        {
            i--;
            k--;
            printf("\b");
            printf(" ");
            printf("\b");
        }
    }
    mpassword[i] = '\0';
    printf("\n");
    while (p)
    {
        if (strcmp(p->account, maccount) == 0)
        {
            flag = 1;
            while (strcmp(p->password, mpassword) != 0)
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
                cout << "密码错误！您还有"<< cnt - 1 << "次机会\n"<< endl;
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
                        mpassword[i] = c;
                        i++;
                        k++;
                        printf("*");
                    }
                    if (k > 0 && c > 0 && c == '\b')
                    {
                        i--;
                        k--;
                        printf("\b");
                        printf(" ");
                        printf("\b");
                    }
                }
                mpassword[i] = '\0';
                printf("\n");
            }
            cout << "管理员"<< maccount << "登陆成功！\n" << "即将跳转至管理员页面..." << endl;
            Sleep(2000);
            fp->cls();
            fp->managerfunction();
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
void manager::Regist()
{
    dbFile* fp = new dbFile;
    manager* mp = new manager;
    char maccount[2000];
    char mpassword[2000];
    char mspassword[2000];
    char managercode[2000];
    cout << "\n\n\n\n\n\n\n";
    cout << "请输入管理员验证码:";
    cin >> managercode;
    int cnt = 2;
    while (--cnt >= 0)
    {
        if (strcmp(managercode, code) == 0)
        {
            cout << "管理员验证成功！！\n" << "即将跳转至注册页面...";
            Sleep(1000);
            fp->cls();
            break;
        }
        else
        {
            cout << "管理员验证失败！！\n" << "您还有" << cnt + 1 << "次机会\n";
            cout << "请重新输入:";
            cin >> managercode;
        }
        if (cnt == 0)
        {
            cout << "输入次数已用完\n" << "即将退出管理员注册系统...";
            Sleep(1000);
            fp->cls();
            return;
        }
    }
    manager* p = new manager;
    cout << "\n\n\n\n\n\n\n";
    cout << "请输入账户(按0退出):";
    while (cin >> maccount)
    {
        if (strcmp(maccount, "0") == 0)
        {
            return;
        }
        if (strlen(maccount) <= 16 && !fp->exist(maccount, 1))
        {
            break;
        }
        else if (fp->exist(maccount, 1))
        {
            cout << "该账户已存在！请重新输入(按0退出):";
        }
        else
        {
            cout << "请输入长度为1到16位的账户:";
        }
    }
    strcpy_s(p->account, maccount);
    cout << "请输入密码(按0退出):";
    while (cin >> mpassword)
    {
        if (strcmp(mpassword, "0") == 0)
        {
            return;
        }
        if (strlen(mpassword) <= 16)
        {
            break;
        }
        else
        {
            cout << "请输入长度为1到16位的密码(按0退出):";
        }
    }
    strcpy_s(p->password, mpassword);
    cout << "请输入您的密保(按0退出):";
    while (cin >> mspassword)
    {
        if (strcmp(mspassword, "0") == 0)
        {
            return;
        }
        if (strlen(mspassword) <= 16)
        {
            break;
        }
        else
        {
            cout << "请输入长度为1到16位的密保(按0退出):";
        }
    }
    strcpy_s(p->spassword, mspassword);
    mend->set_next(p);
    mend = p;
    mend->set_next(NULL);

    mp->save();
    fp->cls();
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t*******************************\n");
    printf("\t\t\t\t\t**                           **\n");
    printf("\t\t\t\t\t       管理员%s注册成功！！     \n", maccount);
    printf("\t\t\t\t\t**     即将跳转至主页面...   **\n");
    printf("\t\t\t\t\t**                           **\n");
    printf("\t\t\t\t\t*******************************\n");
    Sleep(1500);
}
void manager::BrowseBook()
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
void manager::save()
{
    manager* mp = mhead->get_next();
    ofstream f_manager("manager.txt", ios::out);
    while (mp)
    {
        f_manager << mp->account << " " << mp->password << " " << mp->spassword << endl;
        mp = mp->get_next();
    }
    f_manager.close();
}
void manager::creat()
{
    char account[20];
    char password[20];
    char spassword[20];

    ifstream f_manager("manager.txt", ios::in);
    while (f_manager >> account && f_manager >> password && f_manager >> spassword)
    {

        manager* p = new manager;
        strcpy_s(p->account, account);
        strcpy_s(p->password, password);
        strcpy_s(p->spassword, password);
        mend->set_next(p);
        p->set_next(NULL);
        mend = mend->get_next();
    }
    f_manager.close();
}
void manager::AddBook()
{
    dbFile* fp = new dbFile;
    Book* p = bhead->get_next();
    int a;
    int id = 0;
    int amount;
    char bookname[2000];
    do
    {
        fp->cls();
        cout << "\n\n\n\n\n";
        cout << "请输入要添加书名id(按0退出):";
        while (cin >> id)
        {
            if (id == 0)
            {
                return;
            }
            if (id < 0)
            {
                cout << "请输入正确格式的id号(按0退出):";
            }
            else
            {
                break;
            }
        }
        int flag = 0;
        while (p)
        {
            if (p->get_id() == id)
            {
                flag = 1;
                break;
            }
            p = p->get_next();
        }
        if (flag)
        {
            cout << "已查出此书，请输入再次增加图书的数量:";
            while (cin >> amount)
            {
                if (amount <= 199 && amount > 0)
                {
                    int temp = p->get_amount() + amount;
                    p->set_amount(temp);
                    cout << "图书" << p->get_bookname() << "添加成功！";

                    break;
                }
                else
                {
                    cout << "请输入数量为0-199以内的图书:";
                }
            }
        }
        else
        {
            p = new Book;
            p->set_id(id);
            cout << "请输入增加图书的数量:";
            while (cin >> amount)
            {
                if (amount <= 199 && amount > 0)
                {
                    p->set_amount(amount);
                    break;
                }
                else
                {
                    cout << "请输入数量为0-199范围以内的图书:";
                }
            }

            cout << "请输入是否可借:";
            int sign = 0;
            while (cin >> sign)
            {
                if (sign == 1 || sign == 0)
                {
                    p->set_flag(sign);
                    break;
                }
                else if (sign < 0 || sign > 1)
                {
                    cout << "请输入正确格式的可借标志(1为可借，0为不可借):";
                }
            }
            char bookname[200];
            cout << "请输入书名:";
            cin >> bookname;
            p->set_bookname(bookname);

            char author[200];
            cout << "请输作者:";
            cin >> author;
            p->set_author(author);

            char press[200];
            cout << "请输入出版社:";
            cin >> press;
            p->set_press(press);

            bend->set_next(p);
            bend = p;
            bend->set_next(NULL);
        }
        p->save();
        fp->cls();
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t********************************\n");
        printf("\t\t\t\t\t**                            **\n");
        printf("\t\t\t\t\t      图书%d添加成功!       \n", bend->get_id());
        printf("\t\t\t\t\t**                            **\n");
        printf("\t\t\t\t\t********************************\n");
        Sleep(1000);
        fp->cls();
        cout << "\n\n\n\n\n";
        cout << "是否继续添加？\n" << "继续请按1，返回请按0:";
        cin >> a;
    } while (a == 1);
    printf("页面即将跳转...");
    Sleep(1000);
}
void manager::ChangeBook()
{
    dbFile* fp = new dbFile;
    Book* p = bhead->get_next();
    int id;
    int amount;
    int flag = 0;
    char bookname[200];
    char author[200];
    char press[200];
    int exist = 0;
    int sign = 0;

    Book* bp = bhead->get_next();
    bp->show_book();

    cout << "请输入要修改书名的id号(按0退出):";
    while (cin >> id)
    {
        if (id == 0)
        {
            return;
        }
        while (p)
        {
            if (p->get_id() == id)
            {
                exist = 1;
                break;
            }
            p = p->get_next();
        }
        if (!exist)
        {
            p = bhead->get_next();
            cout << "为查询到该id号！请重新输入(按0退出):";
        }
        else
        {
            break;
        }
    }
    if (!exist)
    {
        return;
    }
    else
    {
        int sign = 0;
        int choose;
        fp->cls();
        changebookmenu();
        while (1)
        {
            cout << "请输入您要进行的操作:";
            cin >> choose;
            switch (choose)
            {
                case 1:
                    cout << "请输入修改后的id号:";
                    cin >> id;
                    p->set_id(id);
                    cout << "修改成功！！\n";
                    break;
                case 2:
                    cout << "请输入要修改后的图书名称:";
                    cin >> bookname;
                    p->set_bookname(bookname);
                    cout << "修改成功！！\n";
                    break;
                case 3:
                    cout << "请输入要修改后的作者:";
                    cin >> author;
                    p->set_author(author);
                    cout << "修改成功！！\n";
                    break;
                case 4:
                    cout << "请输入修改后的出版社:";
                    cin >> press;
                    p->set_press(press);
                    cout << "修改成功！！\n";
                    break;
                case 5 :
                    cout << "请输入修改后的图书数量:";
                    while (cin >> amount)
                    {
                        if (amount <= 199 && amount > 0)
                        {
                            p->set_amount(amount);
                            break;
                        }
                        else
                        {
                            cout << "请输入0-199以内的图书数量:";
                        }
                    }
                    cout << "修改成功！！\n";
                    break;
                case 6 :
                    if (p->get_flag() == 1)
                    {
                        cout << "是否将此书修改为不可借？(1确认，2返回):";

                        while (cin >> flag)
                        {
                            if (flag == 2)
                            {
                                break;
                            }
                            if (flag == 1)
                            {
                                p->set_flag(1);
                                p->save();
                                cout << "修改成功！！\n";
                                break;
                            }
                            else
                            {
                                cout << "请输入正确格式的借书标志!(1确认，2返回):";
                            }
                        }

                    }
                    else if (p->get_flag() == 0)
                    {
                        cout << "是否将此书修改为可借？(1确认，2返回):";
                        while (cin >> flag)
                        {
                            if (flag == 2)
                            {
                                break;
                            }
                            if (flag == 1)
                            {
                                p->set_flag(0);
                                p->save();
                                cout << "修改成功！！\n";
                                break;
                            }
                            else
                            {
                                cout << "请输入正确格式的借书标志!(1确认，2返回):";
                            }
                        }
                    }
                    break;
                case 7:
                    sign = 1;
                    break;
                default :
                    cout << "输入无效！！";
                    cin.clear();
                    break;
            }
            if (sign)
            {
                break;
            }
        }
    }
}
void manager::DeleteBook()
{
    Book* bp = bhead->get_next();
    char bookname[20];
    int flag = 0;
    bp->show_book();
    cout << "请输入您要删除图书的名称(按0退出):";
    while (cin >> bookname)
    {
        if (strcmp(bookname, "0") == 0)
        {
            return;
        }
        while (bp)
        {
            if (bp->get_bookname() == bookname)
            {
                flag = 1;
                break;
            }
            bp = bp->get_next();
        }
        if (flag == 0)
        {
            cout << "未查询到此书!\n" << "请重新输入(按0退出):";
            bp = bhead->get_next();
        }
        else
        {
            break;
        }
    }
    DeleteReaderBook(bookname);
    bp = bhead->get_next();
    Book* pp = bhead;
    while (bp)
    {// bp->next 可能是链表的最后一个
        if (bp->get_bookname() == bookname)
        {
            if (bp->get_next() == NULL)
            {
                bhead->set_next(NULL);
            }
            else
            {
                pp->set_next(bp->get_next());
            }
        }
        pp = pp->get_next();
        bp = bp->get_next();
    }

    cout << "\n\n\n\n\n\n";
    cout << "图书" << bookname << "删除成功!!\n";
    cout << "页面即将跳转..";
    Sleep(1500);
    Book* p = new Book;
    p->save();
}
void manager::DeleteReaderBook(char* bookname)
{
    Reader* rp = rhead->get_next();
    Reader* pp = new Reader;
    int flag = 0;

    while (rp)
    {
        flag = 1;
        for (int i = 0; i < rp->get_bookcnt(); i++)
        {
            if (strcmp(rp->get_booklist(rp, i), bookname) == 0)
            {
                flag = i;
                break;
            }
        }
        if (flag != 1)
        {
            for (int j = flag; j < rp->get_bookcnt() - 1; j++)
            {
                strcpy(rp->get_booklist(rp, j), rp->get_booklist(rp, j + 1));
            }
            int temp = rp->get_bookcnt();
            temp--;
            rp->set_bookcnt(temp);
        }
        rp = rp->get_next();
    }
    pp->save();
}
void manager::BrowseReader()
{

    cout << "账户\t\t" << "密码\t\t" << "密保\t\t" << "性别\t\t" << "姓名\t\t"
         << "学号\t\t" << "借书次数\n";
    Reader* rp = rhead->get_next();
    while (rp)
    {

        cout << rp->get_account(rp) << "\t\t" << rp->get_password(rp) << "\t\t" << rp->get_spassword(rp) << "\t\t"
             << rp->get_sex() << "\t\t" << rp->get_name() << "\t\t" << rp->get_number() << "\t\t" << rp->get_bookcnt() << endl;
        rp = rp->get_next();
    }
    system("pause");
}
void manager::FindPassword()
{
    manager* mp = mhead->get_next();
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
        while (mp)
        {
            if (strcmp(mp->get_account(mp), account) == 0)
            {
                flag = 1;
                break;
            }
            mp = mp->get_next();
        }
        if (flag)
        {
            break;
        }
        else
        {
            printf("此账号不存在！请重新输入(按0退出):");
            mp = mhead->get_next();
        }
    }
    if (flag)
    {
        mp = mhead->get_next();
        printf("请输入您设置的密保(按0退出):");
        while (cin >> spassword)
        {
            if (strcmp(spassword, "0") == 0)
            {
                return;
            }
            while (mp)
            {
                if (strcmp(mp->get_spassword(mp), spassword) == 0)
                {
                    sign = 1;
                    break;
                }
                mp = mp->get_next();
            }
            if (sign)
            {
                printf("密保输入正确！\n");
                printf("您的密码为%s\n", mp->get_password(mp));
                system("pause");
                return;
            }
            else
            {
                printf("-------------密保输入错误！请重新输入(按0退出):");
                mp = mhead->get_next();
            }
        }
    }
}
void manager::ChangePassword()
{
    dbFile* fp = new dbFile;
    manager* p = mhead->get_next(), *mp = new manager;
    int flag = 0;
    int sign = 0;
    char maccount[200];
    char mpassword[200];
    char mspassword[200];
    cout << "请输入您的账户(按0退出):";
    while (cin >> maccount)
    {
        if (strcmp(maccount, "0") == 0)
        {
            return;
        }
        while (p)
        {
            if (strcmp(p->account, maccount) == 0)
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
            p = mhead->get_next();
        }
    }
    if (flag)
    {
        p = mhead->get_next();
        cout << "请输入您设置的密保(按0退出):";
        while (cin >> mspassword)
        {
            if (strcmp(mspassword, "0") == 0)
            {
                return;
            }
            while (p)
            {
                if (strcmp(p->spassword, mspassword) == 0)
                {
                    sign = 1;
                    break;
                }
                p = p->get_next();
            }
            if (sign)
            {
                cout << "请输入修改后的密码(按0退出):";
                while (cin >> mpassword)
                {
                    if (strcmp(mpassword, "0") == 0)
                    {
                        return;
                    }
                    if (strlen(mpassword) <= 16)
                    {
                        break;
                    }
                    else
                    {
                        cout << "请输入长度为1到16位的密码(按0退出):";
                    }
                }
                strcpy_s(p->password, mpassword);
                cout << "密码修改成功！";
                fp->usesave(p);
                system("pause");
                return;
            }
            else
            {
                cout << "密保输入错误！！请重新输入(按0退出):";
                p = mhead->get_next();
            }
        }
    }
}
