#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef ULONG (*DBGPRINT)(const char* Format, ...);

DBGPRINT DbgPrint = (DBGPRINT)0x83C2C41F;
//�����ں�
void __declspec(naked) IdtEntry0x20()
{
	__asm
	{
		//�޸�fs
		push 0x30
		pop fs
		//���ж�
		sti
	}
	//CALL API

	DbgPrint("hello");

	__asm
	{
		//���ж�
		cli
		//�ָ�fs
		push 0x3b
		pop fs
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
	system("pause");
}