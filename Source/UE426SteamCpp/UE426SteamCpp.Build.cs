// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE426SteamCpp : ModuleRules
{
	public UE426SteamCpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"HeadMountedDisplay",
			"OnlineSubsystem",
			"OnlineSubsystemSteam"
		});
	}
}
