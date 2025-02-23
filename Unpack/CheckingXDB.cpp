#include "Module.h"
#include "../client/client.h"
#include "../gameMechanics/gameMechanics.h"

#define MOD(constr, con_class) if(con == constr) return true;

//vector<char*> cons = {
//	//"client.VisualConstructor.VisualMob",
//	//"client.VisualConstructor.VisualMount",
//	//"client.VisualConstructor.VisCharacterTemplate",
//	//"client.Scene.VisObjectTemplate",
//	//"client.Sound.FMODProject",
//	//"client.Scene3D.Geometry",
//	"client.Scene3D.SkeletalAnimation"
//};

bool Module::CheckXDB(Item item)
{
	if (item.struct_addr == NULL) return false;
	string con = item.constructor_name;

	MOD("client.VisualConstructor.VisualMob", VisualMob);
	MOD("client.VisualConstructor.VisualMount", VisualMount);
	MOD("client.VisualConstructor.VisCharacterTemplate", VisCharacterTemplate);
	MOD("client.Scene.VisObjectTemplate", VisObjectTemplate);
	MOD("client.Sound.FMODProject", FMODProject);
	MOD("client.Scene3D.Geometry", Geometry);
	MOD("client.Scene3D.SkeletalAnimation", SkeletalAnimation);
	MOD("client.VisualConstructor.AnimationProperties", AnimationProperties);
	MOD("client.RenderCommon.Texture", Texture);
	MOD("client.VisualConstructor.MobAnimations", MobAnimations);
	MOD("client.Widgets.UISingleTexture", UISingleTexture);
	MOD("client.Widgets.UITexture", UITexture);
	MOD("gameMechanics.constructor.schemes.mount.MountSkin", MountSkin);
	MOD("client.VisualConstructor.VisualMountClass", VisualMountClass);
	MOD("gameMechanics.constructor.schemes.item.ItemResource", ItemResource);
	MOD("gameMechanics.constructor.schemes.unlock.UnlockResource", UnlockResource$);
	MOD("gameMechanics.constructor.schemes.mount.MountResource", MountResource);
	MOD("gameMechanics.constructor.schemes.spell.Spell", Spell);
	MOD("gameMechanics.constructor.schemes.mount.SkinListResource", SkinListResource);
	MOD("gameMechanics.constructor.schemes.mount.MountGroupResource", MountGroupResource);
	MOD("client.Animation.ParticleAnimation", ParticleAnimation);
	MOD("client.RenderCommon.TextureSingleElement", TextureSingleElement);
	MOD("client.VisualConstructor.CharacterVariations", CharacterVariations);
	MOD("gameMechanics.constructor.schemes.item.VisualItem", VisualItem);
	MOD("client.VisualConstructor.VisCharacterTraceProperties", VisCharacterTraceProperties);
	MOD("client.VisualConstructor.VisEffectBaseList", VisEffectBaseList);
	MOD("client.RenderCommon.MaterialTemplate", MaterialTemplate);
	MOD("client.VisualConstructor.TexturePatch", TexturePatch);
	MOD("client.VisualConstructor.ModelMorphSettings", ModelMorphSettings);
	MOD("client.SLON.EffectsList", EffectsList);
	MOD("client.VisualConstructor.CharacterSoundVariation", CharacterSoundVariation);
	MOD("client.VisualConstructor.IndexedTexture", IndexedTexture);
	MOD("gameMechanics.world.characterVariations.CharacterRoot", CharacterRoot);
	MOD("gameMechanics.world.avatar.Character", Character);
	MOD("gameMechanics.constructor.schemes.buff.BuffResource", BuffResource);
	MOD("client.VisualConstructor.TrailTemplate", TrailTemplate);
	MOD("mapLoader.StaticObject", StaticObject);
	MOD("client.Collision.Collision", Collision);
	MOD("client.Collision.CollisionMesh", CollisionMesh);
	MOD("client.Collision.PhysicMaterial", PhysicMaterial);
	MOD("client.Terrain.FoliageGeometry", FoliageGeometry);
	MOD("client.VisualConstructor.SkyMesh", SkyMesh);
	MOD("client.Scene3D.AnimationController", AnimationController);
	MOD("gameMechanics.world.creature.Faction", Faction);
	MOD("client.VisualConstructor.SpellVisScripts", SpellVisScripts);
	MOD("client.VisualConstructor.UserPostEffect", UserPostEffect);
	MOD("client.VisualConstructor.CameraShakeParameters", CameraShakeParameters);
	MOD("client.VisualConstructor.AreaEffect", AreaEffect);
	MOD("client.Replica.BuffVisScripts", BuffVisScripts);
	MOD("client.SLON.SlonRoot", SlonRoot);
	MOD("gameMechanics.world.ship.ShipResource", ShipResource);
	MOD("gameMechanics.world.ship.VisualShip", VisualShip);
	MOD("client.GameMechanics.ShipSteeringParams", ShipSteeringParams);
	MOD("gameMechanics.world.ship.ShipSkin", ShipSkin);
	MOD("client.SLON.ShipBuildStatusResource", ShipBuildStatusResource);
	MOD("client.VisualConstructor.TransportVisualItem", TransportVisualItem);
	MOD("gameMechanics.world.projectile.ProjectileResource", ProjectileResource);
	MOD("client.VisualConstructor.VICPack", VICPack);
	MOD("client.Map.ZoneLights", ZoneLights);
	MOD("client.Scene3D.AnimatedLight", AnimatedLight);
	MOD("client.VisualConstructor.PostEffectParams", PostEffectParams);
	MOD("client.Map.WeatherType", WeatherType);
	MOD("client.VisualConstructor.AstralObject", AstralObject);
	return false;
}
