#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


/*
�����жϽ����ںˣ��޸��ں�IDT��0x20���жϵ�IdtEntry0x20() eq 80b95500 0040ee00`00081040
Ϊ�˻���ַ�̶���������Ҫ�޸����ã�������-���߼�-�������ַ���񣬹̶���ַ���ǣ�
������Ҫ��release����
*/

DWORD g_R0Addr;

//�����ں�
void __declspec(naked) IdtEntry0x20()
{
	__asm
	{
		//���ں˵�ַ
		mov eax, ds:[0x80b95500]
		mov g_R0Addr,eax
		iretd
	}
}

//����0x20���ж�
void go()
{
	__asm
	{
		int 0x20
	}
}

int main()
{
	if ((DWORD)IdtEntry0x20 != 0x00401040)
	{
		printf("address error ! address:%p", IdtEntry0x20);
		return 0;
	}
	go();
	printf("%x", g_R0Addr);
	system("pause");
}