#include "../Enums.h"

string Enums::GetElement(DWORD element)
{
	switch (element)
	{
	case 1:
		return "FIRE";
	case 2:
		return "COLD";
	case 3:
		return "LIGHTNING";
	case 4:
		return "HOLY";
	case 5:
		return "SHADOW";
	case 6:
		return "ASTRAL";
	case 7:
		return "POISON";
	case 8:
		return "DISEASE";
	case 9:
		return "ACID";
	default:
		return "PHYSICAL";
	}
	return "";
}

string Enums::GetiffPolicy(DWORD policy)
{
	switch (policy)
	{
	case 1:
		return "Friends";
	case 2:
		return "Enemies";
	case 3:
		return "FriendsEnemies";
	default:
		return "Everyone";
	}
	return "";
}

string Enums::GetTargetType(DWORD type)
{
	switch (type)
	{
	case 1:
		return "STTCurrentTarget";
	case 2:
		return "STTPoint";
	case 3:
		return "STTCurrentTargetNotSelf";
	default:
		return "STTSelf";
	}
	return "";
}

string Enums::GetuiSpellBookPageType(DWORD type)
{
	switch (type)
	{
	case 1:
		return "SPELLBOOK_PAGE_HALO";
	case 2:
		return "SPELLBOOK_PAGE_SPOUSE";
	case 3:
		return "SPELLBOOK_PAGE_OTHER";
	default:
		return "SPELLBOOK_PAGE_NORMAL";
	}
	return "";
}

string Enums::GetBBlendEffect(DWORD effect)
{
	switch (effect)
	{
	case 1:
		return "BLEND_EFFECT_ADD";
	default:
		return "BLEND_EFFECT_ALPHA";
	}
	return "";
}

string Enums::GetRenderEffect(DWORD effect)
{
	switch (effect)
	{
	case 1:
		return "Z_QUAD";
	case 2:
		return "Z_BOX";
	default:
		return "STD_MODE";
	}
	return "";
}

string Enums::GetUseSt(DWORD use)
{
	switch (use)
	{
	case 1:
		return "Secondary";
	default:
		return "Primary";
	}
	return "";
}

string Enums::GetMirrorMode(DWORD mode)
{
	switch (mode)
	{
	case 1:
		return "MIRROR";
	case 2:
		return "MIRRORONCE";
	case 3:
		return "MIRROR_HALF";
	case 4:
		return "MIRRORONCE_HALF";
	default:
		return "NO_MIRROR";
	}
	return "";
}

string Enums::GetItemPriority(DWORD item)
{
	switch (item)
	{
	case 1:
		return "RITUAL";
	case 2:
		return "GUILD";
	case 3:
		return "CUSTOM";
	case 4:
		return "OVERLAP";
	case 5:
		return "PREVIEW";
	case 6:
		return "PREVIEW_RESERVE_0";
	case 7:
		return "PREVIEW_RESERVE_1";
	case 8:
		return "PREVIEW_RESERVE_2";
	case 9:
		return "PREVIEW_RESERVE_3";
	case 10:
		return "PREVIEW_RESERVE_4";
	case 11:
		return "PREVIEW_RESERVE_5";
	case 12:
		return "HIDE_ALL";
	default:
		return "DEFAULT";
	}
	return "";
}

string Enums::GetTarget(DWORD target)
{
	switch (target)
	{
	case 1:
		return "Item";
	case 2:
		return "Creature";
	}
	return "";
}

string Enums::GetSfxMaterial(DWORD material)
{
	switch (material)
	{
	case 1:
		return "CLOTH";
	case 2:
		return "LEATHER";
	case 3:
		return "METAL";
	case 4:
		return "WOOD";
	case 5:
		return "MAGIC";
	default:
		return "GENERIC";
	}
	return "";
}

string Enums::GetUnderwear(DWORD under)
{
	switch (under)
	{
	case 1:
		return "HIDE_TOP";
	case 2:
		return "HIDE_PANTS";
	case 3:
		return "HIDE_ALL";
	default:
		return "SHOW_ALL";
	}
	return "";
}

string Enums::GetRotateArrow(DWORD rotate)
{
	switch (rotate)
	{
	case 1:
		return "ROTATE_YZ";
	default:
		return "NONE";
	}
	return "";
}

string Enums::GetStandartLocator(DWORD loc)
{
	switch (loc)
	{
	case 1:
		return "Slot_Trace_L_02";
	case 2:
		return "Slot_Trace_L_03";
	case 3:
		return "Slot_Trace_L_04";
	case 4:
		return "Slot_Trace_L_05";
	case 5:
		return "Slot_Trace_R_01";
	case 6:
		return "Slot_Trace_R_02";
	case 7:
		return "Slot_Trace_R_03";
	case 8:
		return "Slot_Trace_R_04";
	case 9:
		return "Slot_Trace_R_05";
	default:
		return "Slot_Trace_L_01";
	}
	return "";
}

string Enums::GetModelMorphControlName(DWORD morph)
{
	switch (morph)
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

string Enums::GetChargenEffect(DWORD effect)
{
	switch (effect)
	{
	case 1:
		return "CHARGEN_EFFECT_RUN_TYPE_LOOP";
	default:
		return "CHARGEN_EFFECT_RUN_TYPE_KEY";
	}
	return "";
}

string Enums::GetVisObjectSettings(DWORD settings)
{
	switch (settings)
	{
	case 1:
		return "FROM_TARGET";
	default:
		return "FROM_CASTER";
	}
	return "";
}

string Enums::GetVolume(DWORD volume)
{
	switch (volume)
	{
	case 1:
		return "MESH";
	default:
		return "BOX";
	}
	return "";
}

string Enums::GetFrom(DWORD from)
{
	switch (from)
	{
	case 1:
		return "FROM_SELF";
	case 2:
		return "FROM_TARGET";
	default:
		return "FROM_DEFALUT";
	}
	return "";
}

string Enums::GetTargetMode(DWORD mode)
{
	switch (mode)
	{
	case 1:
		return "Umbrella";
	case 2:
		return "Chains";
	default:
		return "FromCaster";
	}
	return "";
}

string Enums::GetBlendMode(DWORD mode)
{
	switch (mode)
	{
	case 1:
		return "MUL";
	case 2:
		return "ADD";
	case 3:
		return "NORMAL";
	case 4:
		return "DARKEN";
	case 5:
		return "SCREEN";
	case 6:
		return "OVERLAY";
	default:
		return "DEFAULT";
	}
	return "";
}

string Enums::GetUseOn(DWORD use)
{
	switch(use)
	{
	case 1:
		return "Mount";
	case 2:
		return "RiderAndMount";
	default:
		return "Rider";
	}
	return "";
}

string Enums::GetCategory(DWORD category)
{
	switch (category)
	{
	case 1:
		return "EFFECT_MAGE_ENTROPY";
	default:
		return "EFFECT_DEFAULT";
	}
	return "";
}

string Enums::GetFrom2(DWORD from)
{
	switch (from)
	{
	case 1:
		return "FROM_TARGET";
	default:
		return "FROM_CASTER";
	}
	return "";
}

string Enums::GetDirection(DWORD dir)
{
	switch (dir)
	{
	case 1:
		return "DIR_TO_TARGET";
	case 2:
		return "DIR_NO_TRANSFORM";
	}
	return "";
}

string Enums::GetWTE(DWORD wte)
{
	switch (wte)
	{
	case 1:
		return "RangedWeapon";
	case 2:
		return "Shield";
	default:
		return "MeleeWeapon";
	}
	return "";
}

string Enums::GetFatalityType(DWORD type)
{
	switch (type)
	{
	default:
		return "NO_FATALITY";
	case 1:
		return "BARD";
	case 2:
		return "DRUID";
	case 3:
		return "MAGE";
	case 4:
		return "NECROMANCER";
	case 5:
		return "PALADIN";
	case 6:
		return "PRIEST";
	case 7:
		return "PSIONIC";
	case 8:
		return "STALKER";
	case 9:
		return "WARRIOR";
	case 10:
		return "ENGINEER";
	}
	return "";
}

string Enums::GetHold(DWORD hold)
{
	switch (hold)
	{
	default:
		return "WEAPON_DEFAULT";
	case 1:
		return "WEAPON_NONE";
	case 2:
		return "WEAPON_MELEE";
	case 3:
		return "WEAPON_RANGED";
	}
	return "";
}

string Enums::GetCheckCreature(DWORD check)
{
	switch (check)
	{
	default:
		return "Current";
	case 1:
		return "Caster";
	}
	return "";
}

string Enums::GetFromCreature(DWORD from)
{
	switch (from)
	{
	default:
		return "Self";
	case 1:
		return "MainAvatar";
	case 2:
		return "Target";
	}
	return "";
}

string Enums::GetVisAction(DWORD action)
{
	switch (action)
	{
	default:
		return "ATTACK";
	case 1:
		return "ATTACK_OFFHAND";
	case 2:
		return "IDLE_SPECIAL";
	case 3:
		return "WALK";
	case 4:
		return "WALK_SPECIAL";
	case 5:
		return "PARRY";
	case 6:
		return "READY";
	case 7:
		return "READY_RANGED";
	case 8:
		return "RUN";
	case 9:
		return "RUN_SPECIAL";
	case 10:
		return "DEATH";
	}
	return "";
}

string Enums::GetReplace(DWORD replace)
{
	switch (replace)
	{
	default:
		return "ReplaceAlways";
	case 1:
		return "ReplaceWhenAllActive";
	case 2:
		return "ReplaceWhenAnyActive";
	}
	return "";
}

string Enums::GetVisType(DWORD type)
{
	switch (type)
	{
	default:
		return "TOP";
	case 1:
		return "BOTTOM";
	case 2:
		return "SPECIAL";
	}
	return "";
}

string Enums::GetPlay(DWORD play)
{
	switch (play)
	{
	default:
		return "InSequence";
	case 1:
		return "Simultaneously";
	}
	return "";
}

string Enums::GetActionType(DWORD type)
{
	switch (type)
	{
	default:
		return "Simple";
	case 1:
		return "Music";
	case 2:
		return "AmbientOutdoor";
	case 3:
		return "AmbientIndoor";
	case 4:
		return "MusicSource";
	case 5:
		return "GlobalParams";
	}
	return "";
}

string Enums::GetComparsionOperator(DWORD op)
{
	switch (op)
	{
	default:
		return "Less";
	case 1:
		return "LessEqual";
	case 2:
		return "Equal";
	case 3:
		return "GreaterEqual";
	case 4:
		return "Greater";
	}
	return "";
}

string Enums::GetMatch(DWORD match)
{
	switch (match)
	{
	default:
		return "List";
	case 1:
		return "Pattern";
	}
	return "";
}

string Enums::GetAmbientImpact(DWORD ambient)
{
	switch (ambient)
	{
	default:
		return "Nothing";
	case 1:
		return "Start";
	case 2:
		return "Stop";
	}
	return "";
}

string Enums::GetPriority(DWORD priority)
{
	switch (priority)
	{
	default:
		return "LOW";
	case 1:
		return "MEDIUM";
	case 2:
		return "HIGH";
	}
	return "";
}

string Enums::GetPrecastType(DWORD type)
{
	switch (type)
	{
	default:
		return "PRECAST_DEFAULT";
	case 1:
		return "PRECAST_ACTIONBARSTART";
	case 2:
		return "PRECAST_LAUNCH";
	case 3:
		return "PRECAST_CHANNELPRECAST";
	case 4:
		return "PRECAST_NONE";
	}
	return "";
}
