#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Login.h"
#include <string.h>

void LoginInit(Login* pl)
{
    memset(pl->id, '0', ID_PWD_LEN);
    memset(pl->pwd, '0', ID_PWD_LEN);
}

void IdPwdInsert(Login* pl, char *id, char *pwd)
{
    strcpy(pl->id, id);
    strcpy(pl->pwd, pwd);

    printf("id : %s\n", &pl->id);
    printf("pwd : %s", &pl->pwd);
}