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
    printf("\t0. ȸ�� ����\n");
    printf("\t1. �α���\n");
    printf("\t2. ȸ�� ���\n");
    printf("\t3. ����\n");
    printf("\t4. ����\n");
    printf("=========================================\n");
    printf("\t�޴� �Է� >> ");
}

// �α��� ���� �ʱ�ȭ
void LoginInit(Login* pl)
{
    memset(pl->id, '0', ID_PWD_LEN);
    memset(pl->pwd, '0', ID_PWD_LEN);
}

// �迭 ����Ʈ �ʱ�ȭ
void ArrayInit(Array* pa)
{
    pa->curIndex = 1;
    strcpy(pa->Data[0].id, "admin");
    strcpy(pa->Data[0].pwd, "1234");
}

// ���̵�, �н����� �Է�
void IdPwdInsert(char *id, char *pwd)
{
    printf("=========================================\n");
    printf("\tID �Է� >> ");
    scanf("%s", id);


    printf("\tPWD �Է� >> ");
    scanf("%s", pwd);
    printf("=========================================\n");
}


// �α��� ����/���� ����
int LoignOk(Array *pa, char *id, char *pwd)
{
    for (int i = 1; i < MEMBER_MAX; i++)
    {
        if (!strcmp(pa->Data[i].id, id) && !strcmp(pa->Data[i].pwd, pwd))
        {
            printf("\t�α��� ����!\n");
            return TRUE;
        }
        else if (!strcmp(pa->Data[0].id, id) && !strcmp(pa->Data[0].pwd, pwd))
        {
            printf("\t������ �α��� ����!\n");
            return TRUE;
        }
        else if (i + 1 == MEMBER_MAX)
        {
            printf("���̵�/�н����带 �߸��Է��Ͽ����ϴ�.\n\n");
            return FALSE;
        }
    }
}

// ȸ������
void Join(Login* pl, Array *pa, char* id, char* pwd)
{
    printf("=========================================\n");
    printf("\t���ο� ID �Է� >> ");
    scanf("%s", id);


    printf("\t���ο� PWD �Է� >> ");
    scanf("%s", pwd);

    printf("=========================================\n");

    strcpy(pl->id, id);
    strcpy(pl->pwd, pwd);

    strcpy(pa->Data[pa->curIndex].id, pl->id);
    strcpy(pa->Data[pa->curIndex].pwd, pl->pwd);


    printf("\t**������ ȯ���մϴ�!**\n");
    printf("\t���� ���Ե� ���̵� Ȯ�� : %s\n", pa->Data[pa->curIndex].id);
    printf("\t���� ���Ե� �н����� Ȯ�� : %s\n", pa->Data[pa->curIndex].pwd);

    (pa->curIndex)++;
}

void MemShow(Array* pa)
{
    int serchIndex = 0;
    printf("=========================================\n");
    printf("\t\t��� ȸ�� ���\n");
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
        printf("������ ������ ���� �� �� �����ϴ�.!!!\n");
        printf("=========================================\n");
        return 0;
    }

    pa->curIndex -= 1;

    printf("=========================================\n");
    printf("\t\t**���� �Ϸ�**\n");
    printf("=========================================\n");
}