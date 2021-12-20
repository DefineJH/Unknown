// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Final : ModuleRules
{
	public Final(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",
															//For AI...
															"AIModule", "GameplayTasks", "NavigationSystem",
															//For UI...
                                                            "UMG"});

		PrivateDependencyModuleNames.AddRange(new string[] { //For UI...
                                                             "Slate", "SlateCore" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
