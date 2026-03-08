// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AbilityCombatSystem : ModuleRules
{
	public AbilityCombatSystem(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"AbilityCombatSystem",
			"AbilityCombatSystem/Variant_Platforming",
			"AbilityCombatSystem/Variant_Platforming/Animation",
			"AbilityCombatSystem/Variant_Combat",
			"AbilityCombatSystem/Variant_Combat/AI",
			"AbilityCombatSystem/Variant_Combat/Animation",
			"AbilityCombatSystem/Variant_Combat/Gameplay",
			"AbilityCombatSystem/Variant_Combat/Interfaces",
			"AbilityCombatSystem/Variant_Combat/UI",
			"AbilityCombatSystem/Variant_SideScrolling",
			"AbilityCombatSystem/Variant_SideScrolling/AI",
			"AbilityCombatSystem/Variant_SideScrolling/Gameplay",
			"AbilityCombatSystem/Variant_SideScrolling/Interfaces",
			"AbilityCombatSystem/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
