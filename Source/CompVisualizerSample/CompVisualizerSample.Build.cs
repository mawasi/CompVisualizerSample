// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CompVisualizerSample : ModuleRules
{
	public CompVisualizerSample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

#if false
		// メインモジュールに依存するプラグインモジュールをメインモジュールが依存すると循環依存になり、ビルドエラーになる
		// 以下UnrealBuildToolがビルド時にデータ生成中に例外発生
		// Break this loop by moving dependencies into a separate module or using Private/PublicIncludePathModuleNames to reference declarations
		// Exception while generating include data for Target:CompVisualizerSampleEditor, Platform: Win64, Configuration: Development
		PrivateDependencyModuleNames.AddRange(new string[] {});

		// Debug,Developmentのエディタービルドのみプラグイン追加
		if (Target.Configuration == UnrealTargetConfiguration.Debug
		    || Target.Configuration == UnrealTargetConfiguration.Development)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "DebugVisualizer" });
		}
#endif
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
