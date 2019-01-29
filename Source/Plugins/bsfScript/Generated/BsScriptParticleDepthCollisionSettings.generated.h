//********************************* bs::framework - Copyright 2018-2019 Marko Pintera ************************************//
//*********** Licensed under the MIT license. See LICENSE.md for full terms. This notice is not to be removed. ***********//
#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptObject.h"

namespace bs
{
	struct ParticleDepthCollisionSettings;

	class BS_SCR_BE_EXPORT ScriptParticleDepthCollisionSettings : public ScriptObject<ScriptParticleDepthCollisionSettings>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, ENGINE_NS, "ParticleDepthCollisionSettings")

		ScriptParticleDepthCollisionSettings(MonoObject* managedInstance, const SPtr<ParticleDepthCollisionSettings>& value);

		SPtr<ParticleDepthCollisionSettings> getInternal() const { return mInternal; }
		static MonoObject* create(const SPtr<ParticleDepthCollisionSettings>& value);

	private:
		SPtr<ParticleDepthCollisionSettings> mInternal;

		static void Internal_ParticleDepthCollisionSettings(MonoObject* managedInstance);
		static bool Internal_getenabled(ScriptParticleDepthCollisionSettings* thisPtr);
		static void Internal_setenabled(ScriptParticleDepthCollisionSettings* thisPtr, bool value);
		static float Internal_getrestitution(ScriptParticleDepthCollisionSettings* thisPtr);
		static void Internal_setrestitution(ScriptParticleDepthCollisionSettings* thisPtr, float value);
		static float Internal_getdampening(ScriptParticleDepthCollisionSettings* thisPtr);
		static void Internal_setdampening(ScriptParticleDepthCollisionSettings* thisPtr, float value);
		static float Internal_getradiusScale(ScriptParticleDepthCollisionSettings* thisPtr);
		static void Internal_setradiusScale(ScriptParticleDepthCollisionSettings* thisPtr, float value);
	};
}
