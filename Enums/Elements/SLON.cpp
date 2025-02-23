#include "../Enums.h"

string Enums::GetControlName(DWORD name)
{
	switch (name)
	{
	case 1:
		return "Head";
	case 2:
		return "NeckThickness";
	case 3:
		return "NeckLength";
	case 4:
		return "Shoulders";
	case 5:
		return "Torso";
	case 6:
		return "Breast";
	case 7:
		return "Waist";
	case 8:
		return "Basin";
	case 9:
		return "Hands";
	case 10:
		return "Forearms";
	case 11:
		return "Palm";
	case 12:
		return "Hips";
	case 13:
		return "Shins";
	case 14:
		return "Feet";
	default:
		return "Height";
	}
	return "";
}

string Enums::GetLocatorSlot(DWORD slot)
{
	switch (slot)
	{
	case 1:
		return "Head";
	case 2:
		return "Chest";
	case 3:
		return "Slot_Hand_L";
	case 4:
		return "Slot_Hand_R";
	case 5:
		return "Slot_Shoulder_L";
	case 6:
		return "Slot_Shoulder_R";
	case 7:
		return "Slot_FX";
	case 8:
		return "Slot_TopFX";
	case 9:
		return "Slot_Mouth";
	case 10:
		return "Slot_Global";
	case 11:
		return "Slot_Head";
	case 12:
		return "Slot_BodyFX";
	case 13:
		return "Wand_Slot_FX";
	case 14:
		return "UsedObject_Slot_FX";
	case 15:
		return "Slot_Glove_L";
	case 16:
		return "Slot_Glove_R";
	case 17:
		return "Slot_Locket";
	case 18:
		return "Slot_Belt";
	case 19:
		return "FROM_LOCATOR_NAME";
	default:
		return "Global";
	}
	return "";
}

string Enums::GetMember(DWORD member)
{
	switch (member)
	{
	case 1:
		return "Assaulter";
	case 2:
		return "Defender";
	case 3:
		return "Caster";
	case 4:
		return "Group";
	case 5:
		return "Random";
	case 6:
		return "Mount";
	case 7:
		return "All_Members_WithoutMount";
	case 8:
		return "All_Members";
	default:
		return "Default_Member";
	}
	return "";
}

string Enums::GetShapes(DWORD shape)
{
	if (shape == 1)
		return "All";
	return "FromShapeNames";
}