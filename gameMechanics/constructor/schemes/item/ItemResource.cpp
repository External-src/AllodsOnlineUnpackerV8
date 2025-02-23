#include "ItemResource.h"

ItemResource::ItemResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ItemResource::~ItemResource()
{
}

void ItemResource::Init()
{
	FORCON("actionGroupsBonuses", 0x1C, 0x1C)
	{
		m->AddHref("actionGroup", 0x4);
		//
	}
	OPENEX("actionPreviewInfo", 0x2C)
	{
		OPENEX_X("elseInfo", 0x4)
		{
			m->AddHref("mount", 0x4);
			m->AddHref("mountSkin", 0x0C);
			m->AddHref("mountSkinUnlock", 0x14);
		}
		OPENEX_X("info", 0x20)
		{
			m->AddHref("mount", 0x4);
			m->AddHref("mountSkin", 0x0C);
			m->AddHref("mountSkinUnlock", 0x14);
		}
		FORTYPEX("predicates", 0x3C, 0x4);
	}
	//AddTxt("bindDescription", 0x78);
	AddText("binding", Enums::GetBinding(Read(0x88)));
	//FORCON("calcers", 0x8C, 0x14)
	//{
	//	m->OpenCon("calcer", 0x4);
	//	m->AddSource("name", 0x8);
	//}
	AddHref("category", 0x9C);
	OpenCon("counter", 0xA4);
	//FORCON("descVars", 0xA8, 0x28)
	//{
	//	m->AddSource("name", 0x4);
	//	m->OpenCon("scaler", 0x10);
	//	m->AddTxt("text", 0x14);
	//	m->AddFloat("value", 0x24);
	//}
	AddTxt("description", 0xB8);
	FORNOT("dressSet", 0xC8, 0x8)
	{
		m->AddHref("Item", i);
	}
	//FORCON("extraDescParts", 0xD8, 0x1C)
	//{
	//	m->AddTxt("descPart", 0x4);
	//	m->AddHref("descVarsSource", 0x14);
	//}
	OpenCon("functionalPart", 0xE8);
	AddHref("image", 0xEC);
	OpenCon("interactions", 0xF4);
	AddHref("itemClass", 0xF8);
	//AddTxt("itemMallDescription", 0x100);
	AddHref("itemMallImage", 0x110);
	AddText("itemMallType", Enums::GetItemMallType(Read(0x118)));
	AddInt("level", 0x11C);
	AddLong("lifeLengthCap", 0x120);
	AddHref("lifestyleCollection", 0x128);
	FORTYPE("lifestylePredicates", 0x130, 0x4);
	AddTxt("name", 0x140);
	FORCON("names", 0x160, 0x18)
	{
		m->AddInt("level", 0x4);
		m->AddTxt("name", 0x8);
	}
	OpenCon("onExpire", 0x170);
	AddInt("ownershipLimit", 0x174);
	OpenCon("prices", 0x178);
	AddHref("quality", 0x17C);
	AddInt("requiredLevel", 0x184);
	AddText("requiredReputation", Enums::GetReputation(Read(0x188)));
	AddText("showItemContextAction", Enums::GetAction(Read(0x18C)));
	AddText("slot", Enums::GetSlot(Read(0x190)));
	AddText("source", Enums::GetSource(Read(0x194)));
	AddHref("spell", 0x198);
	AddInt("stackLimit", 0x1A0);
	AddSource("sysName", 0x1A4);
	AddHref("visualElement", 0x1B0);
	AddHref("visualElementAlias", 0x1B8);
	//AddTxt("worldDropNamePrefix", 0x1C0);
	//AddTxt("worldDropNameRoot", 0x1D0);
	//AddTxt("worldDropNameSuffix", 0x1E0);
	AddBool("canBeDeposited", 0x1F0);
	AddBool("clearAllOnTry", 0x1F1);
	AddBool("forceShowQuality", 0x1F2);
	AddBool("ignoreDressSlotLevel", 0x1F3);
	AddBool("isHideLifestyleWhileNotEquipped", 0x1F4);
	AddBool("isProbe", 0x1F5);
	AddBool("isQuestRelated", 0x1F6);
	AddBool("needCheckPredicates", 0x1F7);
	AddBool("ritual", 0x1F8);
	AddBool("showOnlyIconInLink", 0x1F9);
	AddBool("soldForAltCurrency", 0x1FA);
}