#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_PWD_LEN  50
#define MEMBER_MAX  100
#define TRUE    1
#define FALSE   0


typedef struct _login
{
    char id[ID_PWD_LEN];
    char pwd[ID_PWD_LEN];
}Login;

typedef struct _array
{
    Login Data[MEMBER_MAX];
    int curIndex;
}Array;

void LoginInit(Login* pl);
void ArrayInit(Array* pa);
void IdPwdInsert(char* id, char* pwd);
int LoignOk(Array* pa, char* id, char* pwd);
void Join(Login* pl, Array* pa, char* id, char* pwd);
void MenuDispaly();
void MemShow(Array* pa);
void Delete(Array* pa);
void BackDisplay();



int main(void)
{
    Login login;
    Array array;
    char id[ID_PWD_LEN] = { '\n', };
    char pwd[ID_PWD_LEN] = { '\n', };
    int iMenu = -1;
    LoginInit(&login);
    ArrayInit(&array);

    while (TRUE)
    {
        MenuDispaly();
        scanf("%d", &iMenu);

        if (iMenu == 4)
            break;

        switch (iMenu)
        {
        case 0:
            system("cls");
            Join(&login, &array, id, pwd);
            system("pause");
            break;

        case 1:
            system("cls");
            IdPwdInsert(id, pwd);
            LoignOk(&array, id, pwd);
            system("pause");
            break;

        case 2:
            system("cls");
            MemShow(&array);
            system("pause");
            break;
            
        case 3:
            system("cls");
            Delete(&array);
            system("pause");
            break;
        }

        
        system("cls");
    }
    return 0;
}

void MenuDispaly()
{
    printf("=========================================\n");
    printf("\t0. 회원 가입\n");
    printf("\t1. 로그인\n");
    printf("\t2. 회원 목록\n");
    printf("\t3. 삭제\n");
    printf("\t4. 종료\n");
    printf("=========================================\n");
    printf("\t메뉴 입력 >> ");
}

// 로그인 정보 초기화
void LoginInit(Login* pl)
{
    memset(pl->id, '0', ID_PWD_LEN);
    memset(pl->pwd, '0', ID_PWD_LEN);
}

// 배열 리스트 초기화
void ArrayInit(Array* pa)
{
    pa->curIndex = 1;
    strcpy(pa->Data[0].id, "admin");
    strcpy(pa->Data[0].pwd, "1234");
}

// 아이디, 패스워드 입력
void IdPwdInsert(char *id, char *pwd)
{
    printf("=========================================\n");
    printf("\tID 입력 >> ");
    scanf("%s", id);


    printf("\tPWD 입력 >> ");
    scanf("%s", pwd);
    printf("=========================================\n");
}


// 로그인 성공/실패 여부
int LoignOk(Array *pa, char *id, char *pwd)
{
    for (int i = 1; i < MEMBER_MAX; i++)
    {
        if (!strcmp(pa->Data[i].id, id) && !strcmp(pa->Data[i].pwd, pwd))
        {
            printf("\t로그인 성공!\n");
            return TRUE;
        }
        else if (!strcmp(pa->Data[0].id, id) && !strcmp(pa->Data[0].pwd, pwd))
        {
            printf("\t관리자 로그인 성공!\n");
            return TRUE;
        }
        else if (i + 1 == MEMBER_MAX)
        {
            printf("아이디/패스워드를 잘못입력하였습니다.\n\n");
            return FALSE;
        }
    }
}

// 회원가입
void Join(Login* pl, Array *pa, char* id, char* pwd)
{
    printf("=========================================\n");
    printf("\t새로운 ID 입력 >> ");
    scanf("%s", id);


    printf("\t새로운 PWD 입력 >> ");
    scanf("%s", pwd);

    printf("=========================================\n");

    strcpy(pl->id, id);
    strcpy(pl->pwd, pwd);

    strcpy(pa->Data[pa->curIndex].id, pl->id);
    strcpy(pa->Data[pa->curIndex].pwd, pl->pwd);


    printf("\t**가입을 환영합니다!**\n");
    printf("\t새로 가입된 아이디 확인 : %s\n", pa->Data[pa->curIndex].id);
    printf("\t새로 가입된 패스워드 확인 : %s\n", pa->Data[pa->curIndex].pwd);

    (pa->curIndex)++;
}

void MemShow(Array* pa)
{
    int serchIndex = 0;
    printf("=========================================\n");
    printf("\t\t모든 회원 목록\n");
    while (serchIndex < pa->curIndex)
    {
        printf("\tID : %s\tPWD : %s\n", pa->Data[serchIndex].id, pa->Data[serchIndex].pwd);
        serchIndex++;
    }
    printf("=========================================\n");
}

void Delete(Array* pa)
{
    if (pa->curIndex == 1)
    {
        printf("=========================================\n");
        printf("관리자 계정은 삭제 할 수 없습니다.!!!\n");
        printf("=========================================\n");
        return 0;
    }

    pa->curIndex -= 1;

    printf("=========================================\n");
    printf("\t\t**삭제 완료**\n");
    printf("=========================================\n");
}