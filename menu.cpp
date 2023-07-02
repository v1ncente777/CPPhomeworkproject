#include "menu.h"
#include <cstdio>


void _mainmenu()
{

    printf("\n\n");
    printf("                                        欢 迎 使 用 图 书 管 理 系 统 ！\n");
    printf("                              **************************************************\n");
    printf("                              **                    1.登录                    **\n");
    printf("                              **                                              **\n");
    printf("                              **                    2.注册                    **\n");
    printf("                              **                                              **\n");
    printf("                              **                    3.找回密码                **\n");
    printf("                              **                                              **\n");
    printf("                              **                    4.退出                    **\n");
    printf("                              **************************************************\n");
    printf("请按键选择:");
}
void Loginmenu()
{
    printf("                                                   登录页面\n");
    printf("                              **************************************************\n");
    printf("                              **                 1.管理员登录                 **\n");
    printf("                              **                                              **\n");
    printf("                              **                 2.用户登录                   **\n");
    printf("                              **                                              **\n");
    printf("                              **                 3.返回                       **\n");
    printf("                              **                                              **\n");
    printf("                              **                 4.退出                       **\n");
    printf("                              **************************************************\n");
    printf("请按键选择:");
}


void Registmenu()
{
    printf("                                                   注册页面\n");
    printf("                              **************************************************\n");
    printf("                              **                 1.管理员注册                 **\n");
    printf("                              **                                              **\n");
    printf("                              **                 2.用户注册                   **\n");
    printf("                              **                                              **\n");
    printf("                              **                 3.返回                       **\n");
    printf("                              **                                              **\n");
    printf("                              **                 4.退出                       **\n");
    printf("                              **************************************************\n");
    printf("请按键选择:");
}


void readermenu()
{
    printf("                                                  用户页面\n");
    printf("                              **************************************************\n");
    printf("                              **               1.借书                         **\n");
    printf("                              **                                              **\n");
    printf("                              **               2.还书                         **\n");
    printf("                              **                                              **\n");
    printf("                              **               3.浏览图书信息                 **\n");
    printf("                              **                                              **\n");
    printf("                              **               4.查看已借阅书籍               **\n");
    printf("                              **                                              **\n");
    printf("                              **               5.修改密码                     **\n");
    printf("                              **                                              **\n");
    printf("                              **               6.返回                         **\n");
    printf("                              **                                              **\n");
    printf("                              **               7.退出                         **\n");
    printf("                              **************************************************\n");
    printf("请按键选择:");
}

void managermenu()
{
    printf("                                                管理员页面\n");
    printf("                              **************************************************\n");
    printf("                              **               1.增加图书                     **\n");
    printf("                              **                                              **\n");
    printf("                              **               2.删除图书                     **\n");
    printf("                              **                                              **\n");
    printf("                              **               3.修改图书信息                 **\n");
    printf("                              **                                              **\n");
    printf("                              **               4.查看读者信息                 **\n");
    printf("                              **                                              **\n");
    printf("                              **               5.浏览图书信息                 **\n");
    printf("                              **                                              **\n");
    printf("                              **               6.修改密码                     **\n");
    printf("                              **                                              **\n");
    printf("                              **               7.返回                         **\n");
    printf("                              **                                              **\n");
    printf("                              **               8.退出                         **\n");
    printf("                              **************************************************\n");
    printf("请按键选择:");
}

void changebookmenu()
{
    printf("\n\n");
    printf("\t\t\t\t*******************************\n");
    printf("\t\t\t\t**      1.修改id号           **\n");
    printf("\t\t\t\t**                           **\n");
    printf("\t\t\t\t**      2.修改图书名称       **\n");
    printf("\t\t\t\t**                           **\n");
    printf("\t\t\t\t**      3.修改图书作者       **\n");
    printf("\t\t\t\t**                           **\n");
    printf("\t\t\t\t**      4.修改出版社         **\n");
    printf("\t\t\t\t**                           **\n");
    printf("\t\t\t\t**      5.修改图书数量       **\n");
    printf("\t\t\t\t**                           **\n");
    printf("\t\t\t\t**      6.修改是否可借       **\n");
    printf("\t\t\t\t**                           **\n");
    printf("\t\t\t\t**      7.返回               **\n");
    printf("\t\t\t\t*******************************");
    printf("\n\n");
}

void browsemenu()
{
    printf("\n\n\n\n");
    printf("\t\t\t\t***********************************\n");
    printf("\t\t\t\t**         1.按id号浏览          **\n");
    printf("\t\t\t\t**                               **\n");
    printf("\t\t\t\t**         2.按图书数量浏览      **\n");
    printf("\t\t\t\t**                               **\n");
    printf("\t\t\t\t**         3.返回                **\n");
    printf("\t\t\t\t**                               **\n");
    printf("\t\t\t\t**         4.退出                **\n");
    printf("\t\t\t\t***********************************\n");
    printf("请按键选择:");
}