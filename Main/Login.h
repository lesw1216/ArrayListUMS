#ifndef __LOGIN_H__
#define __LOGIN_H__

#define ID_PWD_LEN  10

typedef struct _login
{
    char id[ID_PWD_LEN];
    char pwd[ID_PWD_LEN];
}Login;



void LoginInit(Login* pl);
void IdPwdInsert(Login* pl, char id, char pwd);

#endif // !__LOGIN_H__
