#pragma once
#include "../Header.h"

#define OPENIN(name, offset) if(Module * m = OpenIn((name), (offset)))
#define OPENIN_B(name, offset) if(Module * b = m->OpenIn((name), (offset)))
#define OPENIN_C(name, offset) if(Module * c = b->OpenIn((name), (offset)))
#define OPENIN_D(name, offset) if(Module * d = c->OpenIn((name), (offset)))
#define OPENIN_E(name, offset) if(Module * e = d->OpenIn((name), (offset)))
#define OPENEX_F(name, offset) if(Module * f = e->OpenEx((name), (offset)))

#define OPENEX(name, offset) if(Module * m = OpenEx((name), (offset)))
#define OPENEX_B(name, offset) if(Module * b = m->OpenEx((name), (offset)))
#define OPENEX_C(name, offset) if(Module * c = b->OpenEx((name), (offset)))
#define OPENEX_D(name, offset) if(Module * d = c->OpenEx((name), (offset)))
#define OPENEX_E(name, offset) if(Module * e = d->OpenEx((name), (offset)))
#define OPENEX_F(name, offset) if(Module * f = e->OpenEx((name), (offset)))

//--------UNIVERSAL--------//
#define OPENIN_X(name, offset) if(Module * x = m->OpenIn((name), (offset))) if(Module * m = x)
#define OPENEX_X(name, offset) if(Module * x = m->OpenEx((name), (offset))) if(Module * m = x)

#define FORNOTX(name, offset, step) \
if(Module * x = m->OpenIn(name, offset)) \
for (DWORD i = 0x0, size = m->GetForSize(offset); i < size; i += step)  if(Module * m = x)

#define FORCONX(name, offset, step) \
if(Module * x = m->OpenIn(name, offset)) \
for (DWORD i = 0x0, size = m->GetForSize(offset); i < size; i += step) \
	if (Module * m = x->OpenEx("Item", i))

#define FORTYPEX(name, offset, step) \
if(Module * x = m->OpenIn(name, offset)) \
for (DWORD i = 0x0, size = m->GetForSize(offset); i < size; i += step) \
	x->OpenCon("Item", i)
//--------UNIVERSAL--------//

#define FORNOT(name, offset, step) \
if(Module * m = OpenIn(name, offset)) \
for (DWORD i = 0x0, size = GetForSize(offset); i < size; i += step)

#define FORCON(name, offset, step) \
if(Module * x = OpenIn(name, offset)) \
for (DWORD i = 0x0, size = GetForSize(offset); i < size; i += step) \
	if (Module * m = x->OpenEx("Item", i))

#define FORTYPE(name, offset, step) \
if(Module * x = OpenIn(name, offset)) \
for (DWORD i = 0x0, size = GetForSize(offset); i < size; i += step) \
	x->OpenCon("Item", i)

#define FORCON_BC(name, offset, step) \
if(Module * x = b->OpenIn(name, offset)) \
for (DWORD i = 0x0; i < b->GetForSize(offset); i += step) \
	if (Module * c = x->OpenEx("Item", i))

#define FORCON_CD(name, offset, step) \
if(Module * x = c->OpenIn((name), (offset))) \
for (DWORD i = 0x0; i < c->GetForSize((offset)); i += (step)) \
	if (Module * d = x->OpenEx("Item", i))


class Module
{
private:
	XElement Href(string name, string href);
	XElement Type(string name, string type);
	XElement Value(string name, string value);

	Module(string name, DWORD offset, XDocument * d, XElement elem);
	Module(DWORD struct_addr, string mod_name);
	Module(DWORD struct_addr, string mod_name, XDocument * d, XElement elem);

protected:
	DWORD main;
	XElement root = NULL;
	XDocument * doc = NULL;

	Module * CheckMod(string con, string name, DWORD addr);

public:
	Module();
	Module(Item item, long * count);
	~Module();

	bool CheckXDB(Item item);
	//===================================================================================================//
	Module * GetXDB(Item item); // Извлечь указатель на конструктор в XDB
	XElement GetRoot(); // Главный заголовок
	XDocument * GetDocument(); // Главный документ
	string GetPatch(); // Имя XDB
	DWORD GetMain(); // Контейнер
	//===================================================================================================//

	//===================================================================================================//
	DWORD Read(DWORD offset); // Считать значение под сдвигом
	string GetHref(DWORD offset); // Выброс ссылки
	string GetBool(DWORD offset); // Выброс булеан
	string GetFloat(DWORD offset); // Выброс плавающей точки
	string GetInt(DWORD offset); // Выброс десятичного
	string GetLong(DWORD offset); // Выброс десятичного 8 байтового
	string GetTxt(DWORD offset); // Выброс ссылки на txt
	string GetText(DWORD offset); // Выброс текста
	//===================================================================================================//

	//===================================================================================================//
	void AddHref(string name, DWORD offset); //Извлечь ссылку на xdb
	void AddHrefSource(string name, DWORD offset); // Извлечь текст и подставить в href

	void AddBool(string name, DWORD offset); // Добавить булеан тип
	void AddInt(string name, DWORD offset); // Добавить десятичное
	void AddLong(string name, DWORD offset); // Добавить десятичное 8 байтовое
	void AddFloat(string name, DWORD offset); // Добавить плавающее
	void AddTxt(string name, DWORD offset); // Добавить ссылку на txt
	void AddSource(string name, DWORD offset); // Добавить строку из указателя под сдвигом
	void AddText(string name, string text); // Добавить простой текст
	void AddAttribute(string attribute, string value); // Добавить аттрибут
	void AddContainer(XElement container); // Добавить контейнер\модуль

	void AddBinFile(string name, DWORD offset); // Математический поиск бинарного файла, для txt пока неизвестно
	//===================================================================================================//
	void AddVector2(string name, DWORD offset);
	void AddVector3(string name, DWORD offset);
	void AddRotation3(string name, DWORD offset);
	void AddSFX(string name, DWORD offset);
	void AddSFX2(string name, DWORD offset);
	void AddAABB(string name, DWORD offset);
	//void AddBinSize(string xdb);
	//===================================================================================================//

	//===================================================================================================//
	// Открывает внутренний контейнер
	// Автоматический добавляется в начальный контейнер
	// Name = Имя контейнера
	Module * OpenIn(string name, DWORD offset);
	// Открывает внешний контейнер. MoveOffset - сместить ли указатель на начало контейнера?
	// Автоматический добавляется в начальный контейнер
	// Name = Имя контейнера
	Module * OpenEx(string name, DWORD offset, bool MoveOffset = true);
	// Открывает контейнер по типу конструктора и заполняет его
	// Value_name = Имя контейнера под который встанет тип
	// Вернет NULL если не нашел тип
	Module * OpenCon(string name, DWORD offset);
	//===================================================================================================//

	DWORD GetForSize(DWORD offset); // Получает размер массива подконструкторов
	string GetConstructor(DWORD offset); // NOT XDB CONSTRUCTOR!!!
	string GetConstructorFromAddr(DWORD Addr); // NOT XDB CONSTRUCTOR!!!

	void SaveXDB();
};

