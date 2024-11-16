// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProiectPOOv3 : ModuleRules
{
	public ProiectPOOv3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
