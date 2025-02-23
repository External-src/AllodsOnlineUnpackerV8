#include "Module.h"
#include "../client/client.h"
#include "../gameMechanics/gameMechanics.h"
#include "../mapLoader/mapLoader.h"

#define PARAMS addr, name, doc
#define CHECK(constr, con_class) if(con == constr) return new con_class(addr, name, doc)

extern ofstream fout;

void check_attrib(tinyxml2::XMLElement * el)
{
	string attr(el->Attribute("type"));
	if (attr.find("client") != string::npos)
	{
		string new_attr = attr.substr(attr.rfind('.') + 1);
		el->SetAttribute("type", new_attr.c_str());
	}
}

Module * Module::OpenCon(string name, DWORD offset)
{
	Module * mod;
	DWORD addr = *(DWORD*)(main + offset);
	if (addr == NULL) return NULL;

	if (IsBadReadPtr((LPVOID)*(DWORD*)(main + offset), 4))
	{
		fout << "=====================" << endl;
		fout << "Error OpenCon" << endl;
		fout << "BAD POINTER: " << std::hex << *(DWORD*)(main + offset) << endl;
		fout << "EXCEPT ADDRESS: " << std::hex << main + offset << endl;
		fout << "OFFSET: +" << std::hex << offset << endl;
		return NULL;
	}

	string con = GetConstructorFromAddr(addr);
	mod = CheckMod(con, name, addr);
	if (mod != NULL)
	{
		check_attrib(mod->root);
		root->InsertEndChild(mod->GetRoot());
	}
	return mod;
}

DWORD Module::Read(DWORD offset)
{
	return *(DWORD*)(main + offset);
}

Module * Module::CheckMod(string con, string name, DWORD addr)
{
	CHECK("client.Map.ZoneInfo", ZoneInfo);
	//
	CHECK("client.Scene3D.AstralMaterialParams", AstralMaterialParams);
	CHECK("client.Scene3D.CommonMaterialParams", CommonMaterialParams);
	CHECK("client.Scene3D.PointLitMaterialParams", PointLitMaterialParams);
	CHECK("client.Scene3D.SkyMaterialParams", SkyMaterialParams);
	//visObjComponents
	CHECK("client.SLON.AlignCollisionComponent", AlignCollisionComponent);
	CHECK("client.VisualConstructor.AnimationFromParentComponent", AnimationFromParentComponent);
	CHECK("client.VisualConstructor.AstralComponent", AstralComponent);
	CHECK("client.SLON.AttachCameraSlotComponent", AttachCameraSlotComponent);
	CHECK("client.Scene.AttachedVisObjectComponent", AttachedVisObjectComponent);
	CHECK("client.SLON.CameraPathComponent", CameraPathComponent);
	CHECK("client.SLON.CameraShakerComponent", CameraShakerComponent);
	CHECK("client.Scene.ChainAnimatorComponent", ChainAnimatorComponent);
	CHECK("client.SLON.ChannelingComponent", ChannelingComponent);
	CHECK("client.Scene.ColorMaskComponent", ColorMaskComponent);
	CHECK("client.SLON.CustomIdleComponent", CustomIdleComponent);
	CHECK("client.VisualConstructor.DayTimeComponent", DayTimeComponent);
	CHECK("client.Scene.DelayComponent", DelayComponent);
	CHECK("client.SLON.GuildColorsMaskComponent", GuildColorsMaskComponent);
	CHECK("client.Scene.LightComponent", LightComponent);
	CHECK("client.VisualConstructor.LightMutatorComponent", LightMutatorComponent);
	CHECK("client.Scene.RandomComponent", RandomComponent);
	CHECK("client.SLON.ServerTimeComponent", ServerTimeComponent);
	CHECK("client.VisualConstructor.SkyObject", SkyObject);
	CHECK("client.VisualConstructor.StateComponent", StateComponent);
	CHECK("client.Scene.StopVisObjectComponents", StopVisObjectComponents);
	CHECK("client.VisualConstructor.SunShaftsComponent", SunShaftsComponent);
	CHECK("client.Scene.TimeTransparencyComponent", TimeTransparencyComponent);
	CHECK("client.SLON.TLVisualComponent", TLVisualComponent);
	CHECK("client.VisualConstructor.TrailComponent", TrailComponent);
	CHECK("client.Scene.VisObjComponentsFile", VisObjComponentsFile);
	CHECK("client.Map.WeatherVisObjComponent", WeatherVisObjComponent);
	//mobExtension
	CHECK("client.VisualConstructor.VisualMobTroopExtension", VisualMobTroopExtension);
	//visualScript
	CHECK("client.Replica.CameraParametersAction", CameraParametersAction);
	CHECK("client.SLON.CameraTrackAction", CameraTrackAction);
	CHECK("client.Replica.CreatureAnimationAction", CreatureAnimationAction);
	CHECK("client.Replica.CreatureAnimationFromCasterAction", CreatureAnimationFromCasterAction);
	CHECK("client.Replica.CreatureAnimationSetModeAction", CreatureAnimationSetModeAction);
	CHECK("client.Replica.CreatureAnimationSetSpeedAction", CreatureAnimationSetSpeedAction);
	CHECK("client.Replica.CreatureAnimationStopAction", CreatureAnimationStopAction);
	CHECK("client.Replica.CreatureAstralSpellFXVisAction", CreatureAstralSpellFXVisAction);
	//astralSpell
	CHECK("client.Replica.AstralSpellChanneling", AstralSpellChanneling);
	CHECK("client.Replica.AstralSpellProjectile", AstralSpellProjectile);
	//visualScript
	CHECK("client.Replica.CreatureAttachSelfAction", CreatureAttachSelfAction);
	CHECK("client.Replica.CreatureAttackTargetVisAction", CreatureAttackTargetVisAction);
	CHECK("client.Replica.CreatureCancelMountHidingVisAction", CreatureCancelMountHidingVisAction);
	CHECK("client.Replica.CreatureChangeAppearanceAction", CreatureChangeAppearanceAction);
	CHECK("client.Replica.CreatureChangeVisItemsAction", CreatureChangeVisItemsAction);
	CHECK("gameMechanics.elements.calcers.OverLevelPenaltyCalcer", OverLevelPenaltyCalcer);
	CHECK("client.Scene.ClolorFromPrimeSecondary", ClolorFromPrimeSecondary);
	CHECK("client.VisualConstructor.VICAttachedComponentByCharFiltered", VICAttachedComponentByCharFiltered);
	CHECK("client.VisualConstructor.VICDynamic", VICDynamic);
	CHECK("client.VisualConstructor.VICHideAttachedObj", VICHideAttachedObj);
	CHECK("client.VisualConstructor.VICReplaceTexture", VICReplaceTexture);
	CHECK("client.VisualConstructor.VICStatic", VICStatic);
	CHECK("client.VisualConstructor.VICVisObjectByCharComponent", VICVisObjectByCharComponent);
	CHECK("client.VisualConstructor.VICCancelDefaultDressSlotSettings", VICCancelDefaultDressSlotSettings);
	CHECK("client.VisualConstructor.VICHideGeosets", VICHideGeosets);
	CHECK("client.VisualConstructor.VICHideUnderwear", VICHideUnderwear);
	CHECK("client.VisualConstructor.VICOverride", VICOverride);
	CHECK("client.VisualConstructor.VICSelectByChar", VICSelectByChar);
	CHECK("client.VisualConstructor.VICSelectComponentByChar", VICSelectComponentByChar);
	CHECK("client.VisualConstructor.VICSelectComponentByGuildLevel", VICSelectComponentByGuildLevel);
	CHECK("client.VisualConstructor.VICSelectComponentByRankInGuild", VICSelectComponentByRankInGuild);
	CHECK("client.VisualConstructor.VICUsePack", VICUsePack);
	CHECK("client.VisualConstructor.VICVisObjectComponents", VICVisObjectComponents);
	CHECK("client.VisualConstructor.VisualItemGrades", VisualItemGrades);
	CHECK("client.Replica.VisItemEffectsRanged", VisItemEffectsRanged);
	CHECK("client.Map.SoundObjectData", SoundObjectData);
	CHECK("client.Replica.CreatureChannelDirectAction", CreatureChannelDirectAction);
	CHECK("client.Replica.VisPointFromEventClientDataPlus", VisPointFromEventClientDataPlus);
	CHECK("client.Replica.VisPointLocator", VisPointLocator);
	CHECK("client.Replica.EffectOffendConstDelay", EffectOffendConstDelay);
	CHECK("client.Replica.EffectOffendConstVelocity", EffectOffendConstVelocity);
	CHECK("client.Replica.CreatureChargedSpellAction", CreatureChargedSpellAction);
	CHECK("client.Replica.CreatureColorAction", CreatureColorAction);
	CHECK("client.SLON.CreatureDisableEmotesAction", CreatureDisableEmotesAction);
	CHECK("client.SLON.CreatureDisableHitsAction", CreatureDisableHitsAction);
	CHECK("client.Replica.CreatureDisableSpecialIdlesAction", CreatureDisableSpecialIdlesAction);
	CHECK("client.Replica.CreatureEffectsAction", CreatureEffectsAction);
	CHECK("client.Replica.CreatureEffectsOnTarget", CreatureEffectsOnTarget);
	CHECK("client.Replica.CreatureEnchantWeaponAction", CreatureEnchantWeaponAction);
	CHECK("client.SLON.CreatureEnlargeFovAction", CreatureEnlargeFovAction);
	CHECK("client.Replica.CreatureEventPlaybackEnded", CreatureEventPlaybackEnded);
	CHECK("client.SLON.CreatureFatalityAbilityAction", CreatureFatalityAbilityAction);
	CHECK("client.Replica.CreatureFixedPointProjectileAction", CreatureFixedPointProjectileAction);
	CHECK("client.Replica.CreatureFixedTimeProjectileAction", CreatureFixedTimeProjectileAction);
	CHECK("client.SLON.CreatureForceMoveAction", CreatureForceMoveAction);
	CHECK("client.SLON.CreatureGridViewAction", CreatureGridViewAction);
	CHECK("client.Replica.CreatureHeavyProjectileAction", CreatureHeavyProjectileAction);
	CHECK("client.Replica.CreatureHideMountVisAction", CreatureHideMountVisAction);
	CHECK("client.Replica.CreatureHoldWeaponAction", CreatureHoldWeaponAction);
	CHECK("client.Replica.CreatureIfFlagVisAction", CreatureIfFlagVisAction);
	CHECK("client.Replica.CreatureIfMainAvatarRunAction", CreatureIfMainAvatarRunAction);
	CHECK("client.SLON.CreatureIndependentFxAction", CreatureIndependentFxAction);
	CHECK("client.Replica.CreatureItemAnimationAction", CreatureItemAnimationAction);
	CHECK("client.Replica.CreatureItemAttachBoneAction", CreatureItemAttachBoneAction);
	CHECK("client.SLON.CreatureLockTargetAction", CreatureLockTargetAction);
	CHECK("client.Replica.CreatureMountVisAction", CreatureMountVisAction);
	CHECK("client.Replica.CreatureMusicParamAction", CreatureMusicParamAction);
	CHECK("client.Replica.DayTimeParameter", DayTimeParameter);
	CHECK("client.Replica.GuildLevelParameter", GuildLevelParameter);
	CHECK("client.Replica.HaloRankParameter", HaloRankParameter);
	CHECK("client.Replica.HealthParameter", HealthParameter);
	CHECK("client.Replica.LevelParameter", LevelParameter);
	CHECK("client.Replica.RankInGuildParameter", RankInGuildParameter);
	CHECK("client.Replica.ThreatParameter", ThreatParameter);
	CHECK("client.Replica.CreatureOnCreationVisAction", CreatureOnCreationVisAction);
	CHECK("client.Replica.CreatureOnParameterChangedAction", CreatureOnParameterChangedAction);
	CHECK("client.Replica.CreatureParalyzeAction", CreatureParalyzeAction);
	CHECK("client.Replica.CreaturePetVisAction", CreaturePetVisAction);
	CHECK("client.Replica.CreatureProjectileAction", CreatureProjectileAction);
	CHECK("client.Replica.CreatureReplaceAnimationAction", CreatureReplaceAnimationAction);
	CHECK("client.Replica.CreatureReplaceAnimationsAction", CreatureReplaceAnimationsAction);
	CHECK("client.Replica.CreatureRunActionOnSpellTargets", CreatureRunActionOnSpellTargets);
	CHECK("client.SLON.CreatureRunOnAllAction", CreatureRunOnAllAction);
	CHECK("client.Replica.CreatureRunVisActionResource", CreatureRunVisActionResource);
	CHECK("client.Replica.CreatureSayAction", CreatureSayAction);
	CHECK("client.Replica.CreatureScaleAction", CreatureScaleAction);
	CHECK("client.SLON.CreatureSceneDesaturationAction", CreatureSceneDesaturationAction);
	CHECK("client.Replica.CreatureSetAnimationPropertiesAction", CreatureSetAnimationPropertiesAction);
	CHECK("client.SLON.CreatureSetFlagAction", CreatureSetFlagAction);
	CHECK("client.Replica.CreatureSetFlagVisAction", CreatureSetFlagVisAction);
	CHECK("client.SLON.CreatureSetPortraitAction", CreatureSetPortraitAction);
	CHECK("client.SLON.CreatureSetSwimHeightAction", CreatureSetSwimHeightAction);
	CHECK("client.Replica.CreatureSetTransparencyAction", CreatureSetTransparencyAction);
	CHECK("client.SLON.CreatureSheathAction", CreatureSheathAction);
	CHECK("client.Replica.CreatureShowHaloAction", CreatureShowHaloAction);
	CHECK("client.SLON.CreatureStepSoundParamAction", CreatureStepSoundParamAction);
	CHECK("client.Replica.CreatureSwitchDistToTargetAction", CreatureSwitchDistToTargetAction);
	CHECK("client.Replica.CreatureTakeArrowAction", CreatureTakeArrowAction);
	CHECK("client.Replica.CreatureTakeBowStringAction", CreatureTakeBowStringAction);
	CHECK("client.Replica.CreatureThrowArrowAction", CreatureThrowArrowAction);
	CHECK("client.Replica.CreatureTimeIntervalChannelPosAction", CreatureTimeIntervalChannelPosAction);
	CHECK("client.Replica.CreatureTimeIntervalChannelSpeedAction", CreatureTimeIntervalChannelSpeedAction);
	CHECK("client.Replica.CreatureTimeIntervalEndAnimationAction", CreatureTimeIntervalEndAnimationAction);
	CHECK("client.Replica.CreatureTrailAction", CreatureTrailAction);
	CHECK("client.Replica.CreatureTurnToMainAvatarAction", CreatureTurnToMainAvatarAction);
	CHECK("client.Replica.CreatureTurnToTargetAction", CreatureTurnToTargetAction);
	CHECK("client.Replica.CreatureUseIntervalsVisAction", CreatureUseIntervalsVisAction);
	CHECK("client.Replica.CreatureVisActionCreateController", CreatureVisActionCreateController);
	CHECK("client.Replica.CreatureVisActionIgnoreDisarm", CreatureVisActionIgnoreDisarm);
	CHECK("client.Replica.CreatureVisActionOnSelectableTargets", CreatureVisActionOnSelectableTargets);
	CHECK("client.Replica.CreatureVisActionPlayOnUsedDevice", CreatureVisActionPlayOnUsedDevice);
	CHECK("client.Replica.DeviceAnimationAction", DeviceAnimationAction);
	CHECK("client.Replica.DeviceCannonLaunchedAction", DeviceCannonLaunchedAction);
	CHECK("client.Replica.DeviceChannelAction", DeviceChannelAction);
	CHECK("client.Replica.DeviceColorAction", DeviceColorAction);
	CHECK("client.Replica.DeviceFixedPointProjectileAction", DeviceFixedPointProjectileAction);
	CHECK("client.Replica.DeviceIfFlagVisAction", DeviceIfFlagVisAction);
	CHECK("client.Replica.DeviceVisActionAutoStop", DeviceVisActionAutoStop);
	CHECK("client.Replica.DeviceVisActionChangeModel", DeviceVisActionChangeModel);
	CHECK("client.Replica.DeviceVisActionDelay", DeviceVisActionDelay);
	CHECK("client.Replica.DeviceVisActionList", DeviceVisActionList);
	CHECK("client.Replica.DeviceVisActionLoopAction", DeviceVisActionLoopAction);
	CHECK("client.Replica.DeviceVisEffectsAction", DeviceVisEffectsAction);
	CHECK("client.Replica.EntityVisActionIfVisObject", EntityVisActionIfVisObject);
	CHECK("client.Replica.ShowSceneAction", ShowSceneAction);
	CHECK("client.Replica.Sound3DActionDevice", Sound3DActionDevice);
	CHECK("client.Replica.CreatureVisActionStartThrow", CreatureVisActionStartThrow);
	CHECK("client.SLON.CreatureVisObjectComponentsAction", CreatureVisObjectComponentsAction);
	CHECK("client.Replica.CreatureWaitReadyAction", CreatureWaitReadyAction);
	CHECK("client.Replica.CreatureWaitThrowDurationAction", CreatureWaitThrowDurationAction);
	CHECK("client.SLON.DisableNavigationTeleportAction", DisableNavigationTeleportAction);
	CHECK("client.SLON.HighlightCreatureVisAction", HighlightCreatureVisAction);
	CHECK("client.Replica.LooterEmoteAction", LooterEmoteAction);
	CHECK("client.Replica.PostEffectVisAction", PostEffectVisAction);
	CHECK("client.SLON.PredicateCreatureFlagAction", PredicateCreatureFlagAction);
	CHECK("client.Replica.ProceduralEffectVisAction", ProceduralEffectVisAction);
	CHECK("client.Replica.ShakeAction", ShakeAction);
	CHECK("client.Replica.ShiftAction", ShiftAction);
	CHECK("client.Replica.Sound2DAction", Sound2DAction);
	CHECK("client.Replica.Sound2DMatchAction", Sound2DMatchAction);
	CHECK("client.Replica.Sound3DAction", Sound3DAction);
	CHECK("client.Replica.VisActionChangeVisObject", VisActionChangeVisObject);
	CHECK("client.Replica.VisActionDelay", VisActionDelay);
	CHECK("client.Replica.VisActionList", VisActionList);
	CHECK("client.Replica.VisActionLoopAction", VisActionLoopAction);
	CHECK("client.Replica.VisActionRandom", VisActionRandom);
	CHECK("client.Replica.VisActionRefCounter", VisActionRefCounter);
	CHECK("client.Replica.VisActionStopAction", VisActionStopAction);
	CHECK("client.SLON.WeatherCreatureVisAction", WeatherCreatureVisAction);
	CHECK("client.GMUIHelper.AstralHubObjectPart", AstralHubObjectPart);
	CHECK("client.SLON.AstralMobHitLocator", AstralMobHitLocator);
	CHECK("client.SLON.DamageDecalManager", DamageDecalManager);
	CHECK("client.GameMechanics.DeathHandler", DeathHandler);
	CHECK("client.Replica.DeviceActiveActionComponent", DeviceActiveActionComponent);
	CHECK("client.Replica.DeviceHealthComponent", DeviceHealthComponent);
	CHECK("client.Replica.DeviceOfflineComponent", DeviceOfflineComponent);
	CHECK("client.GameMechanics.DeviceRotationPart", DeviceRotationPart);
	CHECK("client.Replica.DeviceVisibilityComponent", DeviceVisibilityComponent);
	CHECK("client.Replica.ForagingVisualizerComponent", ForagingVisualizerComponent);
	CHECK("client.SLON.HideGeoPart", HideGeoPart);
	CHECK("client.SLON.HitLocators", HitLocators);
	CHECK("client.SLON.InteractionAnimationPart", InteractionAnimationPart);
	CHECK("client.SLON.MimicSlotPart", MimicSlotPart);
	CHECK("client.Replica.NavigatorZoomPartResource", NavigatorZoomPartResource);
	CHECK("client.SLON.PirateSailsPart", PirateSailsPart);
	CHECK("client.SLON.PositionSynchronizer", PositionSynchronizer);
	CHECK("client.SLON.ProjectileHolderPart", ProjectileHolderPart);
	CHECK("client.SLON.RotationAnimationPart", RotationAnimationPart);
	CHECK("client.SLON.ScanerDevicePart", ScanerDevicePart);
	CHECK("client.SLON.ShipBuildStatus", ShipBuildStatus);
	CHECK("client.GameMechanics.ShipDeviceManager", ShipDeviceManager);
	CHECK("client.Replica.ShipEngineComponent", ShipEngineComponent);
	CHECK("client.SLON.ShipHealthComponent", ShipHealthComponent);
	CHECK("client.SLON.ShipProximityChecker", ShipProximityChecker);
	CHECK("client.SLON.SingleHitSlot", SingleHitSlot);
	CHECK("client.SLON.SlotLink", SlotLink);
	CHECK("client.GameMechanics.SphereCollisionHandler", SphereCollisionHandler);
	CHECK("client.SLON.TeleportEffect", TeleportEffect);
	CHECK("client.SLON.TLScriptsPart", TLScriptsPart);
	CHECK("client.Replica.UsableDeviceClientPart", UsableDeviceClientPart);
	CHECK("client.SLON.VisEntityVisualizer", VisEntityVisualizer);
	CHECK("client.Replica.SlotInterfaceData", SlotInterfaceData);
	return NULL;
}

