#ifndef __MENU_H
#define __MENU_H
#include "sys.h"
#include "stm32f1xx_hal.h"

#define MENU_MAX_ROW 5 // �˵������ʾ���� 

//����˵��й����������
#define TYPE_SUBMENU 101  //�����Ӳ˵��Ĳ˵���
#define TYPE_PARAM   102  //���������ִ�в������ã�

typedef void (*MENU_FUN)(const char *);

//����˵�
typedef struct menu
{
	uint8_t num;        //��ǰ�˵�����������
	char * title;       //��ǰ�˵�����
	char * label;       //���������
	uint8_t type;       //��ǰ�����������
	MENU_FUN Function;  //ѡ��ĳһ���ܺ�ִ�еĹ��ܺ���
	struct menu *next;  //��һ���˵�
	struct menu *prev;  //��һ���˵�

} Menu;

void DrawTestPage(u8 *str);
void DispCrtMenu(void);      //���Ƶ�ǰ�˵���
void Display(uint8_t value);

void Str_Test(const char *str);
void SetDefaultMenuHandler(MENU_FUN pFun);

