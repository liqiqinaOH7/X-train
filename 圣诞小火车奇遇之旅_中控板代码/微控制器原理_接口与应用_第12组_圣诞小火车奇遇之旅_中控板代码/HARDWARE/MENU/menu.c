#include "menu.h"

//�����˵�ҳ��ṹ������  
Menu menu1_main[5]; 
Menu menu2_file[4]; 
Menu menu2_edit[4]; 
Menu menu2_view[4]; 
Menu menu2_set[3]; 
Menu menu3_test[2];  
Menu menu1_main[5] = // 1�����˵�
{
	{5, "�źŵ�ѡ��", "Traffic_Light_1          >>", TYPE_SUBMENU, NULL, LIGHT_1, NULL}, 
	{5, "","Traffic_Light_2          >>", TYPE_SUBMENU, NULL, LIGHT_1, NULL}, 
	{5, "","Traffic_Light_3          >>", TYPE_SUBMENU, NULL, LIGHT_1, NULL}, 
	{5, "","Traffic_Light_4          >>", TYPE_SUBMENU, NULL, LIGHT_1, NULL}, 
	{5, "","Traffic_Light_5          --", TYPE_PARAM, NULL, LIGHT_1, NULL}, 
}; 
Menu LIGHT_1[3] =  // 2���˵�
{
	{3, "Traffic Light 1", "RED   ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "YELLOW           ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "GREEN            ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
};
Menu LIGHT_2[3] =  // 2���˵�
{
	{3, "Traffic Light 2", "RED   ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "YELLOW           ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "GREEN            ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
};
Menu LIGHT_3[3] =  // 2���˵�
{
	{3, "Traffic Light 3", "RED   ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "YELLOW           ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "GREEN            ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 

};
Menu LIGHT_4[3] =  // 2���˵�
{
	{3, "Traffic Light 4", "RED   ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "YELLOW           ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "GREEN            ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
};
Menu LIGHT_5[3] =  // 2���˵�
{
	{3, "Traffic Light 5", "RED   ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "YELLOW           ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
	{3, "",     "GREEN            ", TYPE_SUBMENU, NULL, NULL, menu1_main}, 
};

void Test_Color()
{
	u16 ColorTab[8]= {WHITE,BRED,BROWN,YELLOW,BLUE,RED,GREEN,GRAY};//������ɫ����
	char *ColorText[] = {"WHITE","BRED","BROWN","YELLOW","BLUE","RED","GREEN","GRAY"};
	//������ʾ����
	LCD_Fill(0,40,lcddev.width,lcddev.height-40,BLACK);
	for(u8 i=0;i<=7;i++)
	{
		LCD_Fill(90,250,390,550,ColorTab[i]);
		Gui_StrCenter(0,220,(u8 *)ColorText[i],24,1);delay_ms(1000);
		LCD_Fill(0,40,lcddev.width,lcddev.height-40,BLACK);
	}
}
//����ܺ���
void Str_Test(const char *str) 
{
	POINT_COLOR = WHITE;
	if(strstr((char *)str,"����"))
	{
		LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
		Gui_StrCenter(0,lcddev.height-32,"�˵����Գ���",24,1);//������ʾ
	}
	if(strstr((char *)str,"ColorText"))
	{
		LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
		Gui_StrCenter(0,lcddev.height-32,"ColorText",24,1);//������ʾ
		Test_Color();	
	}
	
	if(strstr((char *)str,"ON"))
	{
		LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
		LED01_ON();  //ʵ�ʹ��ܺ���
		Gui_StrCenter(0,lcddev.height-32,"LED�Ѵ�",24,1);//������ʾ
	}
	if(strstr((char *)str,"OFF"))
	{
		LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
		LED01_OFF(); //ʵ�ʹ��ܺ��� LED0 LED1�ر�
		Gui_StrCenter(0,lcddev.height-32,"LED�ѹر�",24,1);//������ʾ
	}
}

//������Ӧ�ȷ������ִ�еĺ���
//������Ĺ��ܺ��� ��ֵ����������
void SetDefaultMenuHandler(MENU_FUN pFun)
{
	menu1_main[4].Function = pFun;
	menu2_view[3].Function = pFun;
	
	menu3_test[0].Function = pFun;
	menu3_test[1].Function = pFun;
}


//����˵�������Ҫ��ȫ�ֱ���
Menu *cur_item = menu1_main;  //��ʼ����ǰ�˵�Ϊ��һ��(main_menu)
Menu *prev_item = NULL;	    //��ʼ����һ���˵�Ϊ��
uint8_t item_index = 0;//��ǰ�˵�������

//���Ʋ��Խ���
//str :�ַ���ָ��
void DrawTestPage(u8 *str)
{
	//���ƹ̶���up
	LCD_Fill(0,0,lcddev.width,40,BLUE);
	//���ƹ̶���down
	LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
	POINT_COLOR=WHITE;
	Gui_StrCenter(0,9,str,24,1);  //�˵��������� ������ʾ
	Gui_StrCenter(0,lcddev.height-32,"",24,1);//�˵��ײ� ������ʾ
	POINT_COLOR=RED;
	LCD_ShowString(10,lcddev.height-32,100,30,24, "�Ҽ�ȷ��",0);
	LCD_ShowString(374,lcddev.height-32,100,30,24, "���ȡ��",0);
	//������ʾ����
	LCD_Fill(0,40,lcddev.width,lcddev.height-40,BLACK);
}

void DispCrtMenu(void)//���Ƶ�ǰ�˵���
{
	uint8_t menu_num = cur_item[0].num;//��ȡ��ǰ�˵�����Ŀ���� 
	uint8_t i, num = menu_num>MENU_MAX_ROW ? MENU_MAX_ROW : menu_num;//�����������ܳ���ÿһ��������������
	if(item_index>=MENU_MAX_ROW || item_index>=menu_num)//�˵�������ѡ���Ƿ�Խ�� 
	{ 
		if(item_index==0XFF)  //�����Ϊ item_index=0 �ٰ��ϼ���0-1=0XFF
		{
			item_index = menu_num - 1;   //ѭ�����ص����һ����������ֵ
		}
		if(item_index>=menu_num)  //�����Ϊ����������һ����������ֵ
		{
			item_index = 0;  //ѭ�����ص���һ����������ֵ
		}
		if(item_index>=MENU_MAX_ROW) 
		{
			item_index = 0;
		}
	} 
	DrawTestPage((u8 *)cur_item[0].title);
	
	for (i=0; i<num; i++)//����ĳһ���˵��µĹ��ܼ� 
	{
		POINT_COLOR = RED;
		//Show_Str_1(0, (i+1)*40, (u8 *)cur_item[i].label, 32, i==item_index ? 0:1);//���Ƶ����˵���
		LCD_ShowString(144,150+(i+1)*40,200,30,24, (u8 *)cur_item[i].label,i==item_index ? 0:1);
	}
}

#define KEY_ENTER_PRESS  3 //��Ӧԭ�ӿ���������
#define KEY_RETURN_PRESS 4 //��Ӧԭ��F4����Ҽ�


void Display(uint8_t value) 
{
	if(value==KEY_UP_PRESS || value==KEY_DOWN_PRESS || value==KEY_ENTER_PRESS || value==KEY_RETURN_PRESS)
	{
		switch(value)//��ⰴ����������Ӧ����
		{
			case KEY_UP_PRESS: 
				item_index--; 
				DispCrtMenu();
				break; 
			case KEY_DOWN_PRESS: 
				item_index++; 
				DispCrtMenu();
				break; 
			case KEY_ENTER_PRESS:
				switch(cur_item[item_index].type)//��⹦��������ͣ�������Ӧ����
				{
					case TYPE_SUBMENU: //�����Ӳ˵��Ĳ˵���
						if(cur_item[item_index].next != NULL)
						{ 
							prev_item = cur_item;//�˼��˵��������һ���˵� 
							cur_item = cur_item[item_index].next;//��ָ�����һ���˵�����Ϊ��ǰ�˵� 
							item_index = 0;//�����Ӳ˵������� 
							DispCrtMenu();
						}
						else
						{
							POINT_COLOR = WHITE;
							LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
							Gui_StrCenter(0,lcddev.height-32,"������~~~",24,1);//������ʾ
						}
						break; 
					case TYPE_PARAM:  //���в������õĲ˵���
						if(cur_item[item_index].Function != NULL)
						{ 
							//������Ӧ�Ķ�������,�����ݲ���
							cur_item[item_index].Function((const char *)cur_item[item_index].label);
						}
						else
						{
							POINT_COLOR = WHITE;
							LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
							Gui_StrCenter(0,lcddev.height-32,"������~~~",24,1);//������ʾ
						}
						break; 
					default: 
						break;
				}
				break; 
			case KEY_RETURN_PRESS: 
				if (prev_item != NULL)//������һ���˵��Ĳ��� 
				{
					cur_item = prev_item;  //������һ���˵�Ϊ��ǰ�˵� 
					prev_item = cur_item[0].prev;  //���õ�ǰ�˵�����һ���˵� 
					item_index = 0;  //�����Ӳ˵�������
					DispCrtMenu();
				} 
				else
				{
					POINT_COLOR = WHITE;
					LCD_Fill(0,lcddev.height-40,lcddev.width,lcddev.height,BLUE);
					Gui_StrCenter(0,lcddev.height-32,"�������˵�",24,1);//������ʾ
				}
				break; 
		    default: 
		        break;
		}
	}
} 





