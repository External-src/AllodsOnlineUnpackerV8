#include "../Enums.h"

enum Slot
{
	HELM = 0,
	ARMOR = 1,
	PANTS = 2,
	BOOTS = 3,
	MANTLE = 4,
	GLOVES = 5,
	BRACERS = 6,
	BELT = 7,
	RING1 = 8,
	RING2 = 9,
	EARRING1 = 10,
	NECKLACE = 11,
	CLOAK = 12,
	SHIRT = 13,
	MAINHAND = 14,
	OFFHAND = 15,
	RANGED = 16,
	AMMO = 17,
	TABARD = 18,
	TRINKET = 19,
	BAG = 20,
	DEATHINSURANCE = 21,
	LIFESTYLEHEAD = 22,
	LIFESTYLEBACK = 23,
	LIFESTYLESUIT = 24,
	LIFESTYLEUNDERWEAR = 25,
	EARRING2 = 26,
	DEPOSITBOX = 27,
	OFFENSIVERUNE1 = 28,
	OFFENSIVERUNE2 = 29,
	OFFENSIVERUNE3 = 30,
	DEFENSIVERUNE1 = 31,
	DEFENSIVERUNE2 = 32,
	DEFENSIVERUNE3 = 33,
	LIFESTYLESHOULDER = 34,
	LSWEAPON = 35,
	HIDDENPOWER = 36,
	LIFESTYLEPET = 37,
	UNDRESSABLE = 38,
	TWOHANDED = 39,
	DUALWIELD = 40,
	RING = 41,
	EARRINGS = 42,
	RUNE = 43
};
string Enums::GetSlot(DWORD slot)
{
	switch (slot)
	{
	case 1:
		return "ARMOR";
	case 2:
		return "PANTS";
	case 3:
		return "BOOTS";
	case 4:
		return "MANTLE";
	case 5:
		return "GLOVES";
	case 6:
		return "BRACERS";
	case 7:
		return "BELT";
	case 8:
		return "RING1";
	case 9:
		return "RING2";
	case 10:
		return "EARRING1";
	case 11:
		return "NECKLACE";
	case 12:
		return "CLOAK";
	case 13:
		return "SHIRT";
	case 14:
		return "MAINHAND";
	case 15:
		return "OFFHAND";
	case 16:
		return "RANGED";
	case 17:
		return "AMMO";
	case 18:
		return "TABARD";
	case 19:
		return "TRINKET";
	case 20:
		return "BAG";
	case 21:
		return "DEATHINSURANCE";
	case 22:
		return "LIFESTYLEHEAD";
	case 23:
		return "LIFESTYLEBACK";
	case 24:
		return "LIFESTYLESUIT";
	case 25:
		return "LIFESTYLEUNDERWEAR";
	case 26:
		return "EARRING2";
	case 27:
		return "DEPOSITBOX";
	case 28:
		return "OFFENSIVERUNE1";
	case 29:
		return "OFFENSIVERUNE2";
	case 30:
		return "OFFENSIVERUNE3";
	case 31:
		return "DEFENSIVERUNE1";
	case 32:
		return "DEFENSIVERUNE2";
	case 33:
		return "DEFENSIVERUNE3";
	case 34:
		return "LIFESTYLESHOULDER";
	case 35:
		return "LSWEAPON";
	case 36:
		return "HIDDENPOWER";
	case 37:
		return "LIFESTYLEPET";
	case 38:
		return "ARTIFACT1";
	case 39:
		return "ARTIFACT2";
	case 40:
		return "ARTIFACT3";
	case 41:
		return "UNDRESSABLE";
	case 42:
		return "TWOHANDED";
	case 43:
		return "DUALWIELD";
	case 44:
		return "RING";
	case 45:
		return "EARRINGS";
	case 46:
		return "RUNE";
	case 47:
		return "ARTIFACT";
	default:
		return "HELM";
	}
	return "";
}

enum ShowItemContextAction
{
	Default = 0,
	Always = 1,
	OnlyCurrentQuest = 2,
	Never = 3
};

enum ItemMallType
{
	NOTITEMMALLABLE = 0,
	ITEMMALLABLE = 1,
	SELLABLE = 2
};
enum Binding
{
	BindNone = 0,
	BindOnPickup = 1,
	BindOnEquip = 2,
	BindOnUse = 3
};
string Enums::GetBinding(DWORD bind)
{
	switch (bind)
	{
	case BindNone:
		return "BindNone";
	case BindOnPickup:
		return "BindOnPickup";
	case BindOnEquip:
		return "BindOnEquip";
	case BindOnUse:
		return "BindOnUse";
	}
	return "";
}

enum ItemSource
{
	Quest = 0,
	FixedDrop = 1,
	WorldDrop = 2,
	Crafted = 3,
	Conjured = 4,
	Vendor = 5,
	QuestItem = 6
};
enum Reputation
{
	Hostility = 0,
	Enemy = 1,
	Unfriendly = 2,
	Neutral = 3,
	Kindly = 4,
	Friendly = 5,
	Confidential = 6
};

string Enums::GetItemMallType(DWORD type)
{
	switch (type)
	{
	case NOTITEMMALLABLE:
		return "NOTITEMMALLABLE";
	case ITEMMALLABLE:
		return "ITEMMALLABLE";
	case SELLABLE:
		return "SELLABLE";
	}
	return "";
}
string Enums::GetAction(DWORD action)
{
	switch (action)
	{
	case 1:
		return "Always";
	case 2:
		return "OnlyCurrentQuest";
	case 3:
		return "Never";
	default:
		return "Default";
	}
	return "";
}
string Enums::GetSource(DWORD source)
{
	switch (source)
	{
	case Quest:
		return "Quest";
	case FixedDrop:
		return "FixedDrop";
	case WorldDrop:
		return "WorldDrop";
	case Crafted:
		return "Crafted";
	case Conjured:
		return "Conjured";
	case Vendor:
		return "Vendor";
	case QuestItem:
		return "QuestItem";
	}
	return "";
}
string Enums::GetReputation(DWORD rep)
{
	switch (rep)
	{
	case Hostility:
		return "Hostility";
	case Enemy:
		return "Enemy";
	case Unfriendly:
		return "Unfriendly";
	case Neutral:
		return "Neutral";
	case Kindly:
		return "Kindly";
	case Friendly:
		return "Friendly";
	case Confidential:
		return "Confidential";
	}
	return "";
}