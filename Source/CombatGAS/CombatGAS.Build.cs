// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CombatGAS : ModuleRules
{
	public CombatGAS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CombatGAS",
			"CombatGAS/Variant_Platforming",
			"CombatGAS/Variant_Platforming/Animation",
			"CombatGAS/Variant_Combat",
			"CombatGAS/Variant_Combat/AI",
			"CombatGAS/Variant_Combat/Animation",
			"CombatGAS/Variant_Combat/Gameplay",
			"CombatGAS/Variant_Combat/Interfaces",
			"CombatGAS/Variant_Combat/UI",
			"CombatGAS/Variant_SideScrolling",
			"CombatGAS/Variant_SideScrolling/AI",
			"CombatGAS/Variant_SideScrolling/Gameplay",
			"CombatGAS/Variant_SideScrolling/Interfaces",
			"CombatGAS/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
