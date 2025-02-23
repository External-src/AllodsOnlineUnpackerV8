#include "../Enums.h"

string Enums::GetAutoHasten(DWORD hasten)
{
	switch (hasten)
	{
	case 1:
		return "AUTOHASTEN_FIRSTKEY";
	case 2:
		return "AUTOHASTEN_FULLPLAYBACK";
	}
	return "AUTOHASTEN_NONE";
}

string Enums::GetChangeChannel(DWORD change)
{
	switch (change)
	{
	case 1:
		return "CHANGE";
	case 2:
		return "NOT_CHANGE";
	}
	return "CHANGE_If_Background";
}

string Enums::GetChannel(DWORD channel)
{
	switch (channel)
	{
	case 1:
		return "CHANNEL_DEATH";
	case 2:
		return "CHANNEL_KNOCKDOWN";
	case 3:
		return "CHANNEL_ABILITY";
	case 4:
		return "CHANNEL_ATTACK";
	case 5:
		return "CHANNEL_HITCRITICAL";
	case 6:
		return "CHANNEL_HIT";
	case 7:
		return "CHANNEL_DODGEBLOCKPARRY";
	case 8:
		return "CHANNEL_RETURNING";
	case 9:
		return "CHANNEL_ACTIONBAR";
	case 10:
		return "CHANNEL_BUFF";
	case 11:
		return "CHANNEL_EMOTE";
	case 12:
		return "CHANNEL_EMOTE_BOTTOM";
	case 13:
		return "CHANNEL_EMOTE_SPECIAL";
	case 14:
		return "CHANNEL_MOVE";
	case 15:
		return "CHANNEL_READY";
	case 16:
		return "CHANNEL_IDLESPECIAL";
	case 17:
		return "CHANNEL_IDLE";
	case 18:
		return "CHANNEL_CARRY";
	case 19:
		return "CHANNEL_TURNSPECIAL";
	default:
		return "CHANNEL_DEFAULT";
	}
	return "";
}

string Enums::GetOffend(DWORD offend)
{
	switch (offend)
	{
	case 1:
		return "ONEOFFEND_ONETARGET";
	case 2:
		return "EVERYKEY_OFFEND";
	case 3:
		return "WHIRLWIND_OFFEND";
	case 4:
		return "EVERYKEY_ALLOFFENDS";
	default:
		return "NO_OFFEND";
	}
	return "";
}

string Enums::GetTurn(DWORD turn)
{
	switch (turn)
	{
	case 1:
		return "NO_TURN";
	case 2:
		return "BEFORE_ANIMATIONEND";
	case 3:
		return "BEFORE_FIRSTKEY";
	case 4:
		return "BEFORE_SECONDKEY";
	default:
		return "TURN_DEFAULT";
	}
	return "";
}

string Enums::GetWaitEvent(DWORD wait)
{
	switch (wait)
	{
	case 1:
		return "NO_WAIT";
	case 2:
		return "WAIT_FROMSTART";
	case 3:
		return "WAIT_FROMFIRSTKEY";
	default:
		return "WAIT_DEFAULT";
	}
	return "";
}

string Enums::GetChannelOverControll(DWORD control)
{
	switch (control)
	{
	case 1:
		return "TOP_ONLY";
	case 2:
		return "BOTTOM_ONLY";
	case 3:
		return "TOP_AND_BOTTOM";
	default:
		return "DEFAULT_CONTROLLERS";
	}
	return "";
}

string Enums::GetOverrideMode(DWORD mode)
{
	switch (mode)
	{
	case 1:
		return "OVERRIDE_STOP";
	case 2:
		return "OVERRIDE_IGNORE";
	}
	return "OVERRIDE_DEFAULT";
}

string Enums::GetAnimMode(DWORD mode)
{
	switch (mode)
	{
	case 1:
		return "LOOP";
	case 2:
		return "CLAMP";
	}
	return "DIE";
}

string Enums::GetUse(DWORD use)
{
	switch (use)
	{
	case 1:
		return "USE_CURRENT_ATTACK";
	case 2:
		return "USE_CURRENT_ATTACK00";
	case 3:
		return "USE_CURRENT_ATTACK01";
	case 4:
		return "USE_CURRENT_ATTACK02";
	case 5:
		return "USE_CURRENT_ATTACK_SPECIAL";
	case 6:
		return "USE_CURRENT_BASE_ATTACK";
	case 7:
		return "USE_CURRENT_RANGED_READY";
	case 8:
		return "USE_CURRENT_RANGED_LOADHOLD";
	case 9:
		return "USE_CURRENT_RANGED_LOAD";
	case 10:
		return "USE_CURRENT_RANGED_HOLD";
	case 11:
		return "USE_CURRENT_RANGED_ATTACK";
	case 12:
		return "USE_CURRENT_RANGED_RAPIDFIRE";
	case 13:
		return "USE_CURRENT_RANGED_CHEAPSHOTSTART";
	case 14:
		return "USE_CURRENT_RANGED_CHEAPSHOT";
	case 15:
		return "USE_CURRENT_THROWING";
	case 16:
		return "USE_RANDOM_FROM_LIST";
	case 17:
		return "USE_RANDOM_WITH_AUTOCOMPLITION";
	default:
		return "USE_ANIMATIONS";
	}
	return "";
}

string Enums::GetTargetSettings(DWORD settings)
{
	switch (settings)
	{
	case 1:
		return "IGNORE_SHIELD";
	case 2:
		return "IGNORE_HULL";
	}
	return "DEFAULT";
}

string Enums::GetAttachTo(DWORD attach)
{
	switch (attach)
	{
	case 1:
		return "Target_MainOrFirst";
	case 2:
		return "Caster_Mount";
	}
	return "Caster";
}

string Enums::GetUseJump(DWORD jump)
{
	switch (jump)
	{
	case 1:
		return "RUN_FORWARD";
	default:
		return "ALWAIS";
	}
	return "";
}

string Enums::GetRiderOrient(DWORD rider)
{
	switch (rider)
	{
	case 1:
		return "All_FromMountSlot";
	default:
		return "Yaw_FromMountSlot";
	}
	return "";
}

string Enums::GetUBinding(DWORD bind)
{
	switch (bind)
	{
	case 1:
		return "Soul";
	case 2:
		return "Account";
	default:
		return "Avatar";
	}
	return "";
}
