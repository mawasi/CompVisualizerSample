// Copyright Epic Games, Inc. All Rights Reserved.

#include "DebugVisualizer.h"

#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"
#include "Modules/ModuleManager.h"
#include "CompVisualizerSample/SampleComponent.h"
#include "DebugVisualizer/SampleCompVisualizer.h"
#include "CompVisualizerSample/SampleComponent2.h"
#include "DebugVisualizer/SampleCompVisualizer2.h"

#define LOCTEXT_NAMESPACE "FDebugVisualizerModule"

void FDebugVisualizerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// GUnrealEd使うにはBuild.csに"UnrealEd"モジュールを追加
	// UnrealEdGlobals.h, Editor/UnrealEdEngine.hのインクルード
	// が必要
	if (GUnrealEd)
	{
		TSharedPtr<FSampleCompVisualizer> visualizer = MakeShared<FSampleCompVisualizer>();
		GUnrealEd->RegisterComponentVisualizer(USampleComponent::StaticClass()->GetFName(), visualizer);
		visualizer->OnRegister();

		TSharedPtr<FSampleCompVisualizer2> visualizer2 = MakeShared<FSampleCompVisualizer2>();
		GUnrealEd->RegisterComponentVisualizer(USampleComponent2::StaticClass()->GetFName(), visualizer2);
		visualizer2->OnRegister();
	}
}

void FDebugVisualizerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (GUnrealEd)
	{
		const FName& name = USampleComponent::StaticClass()->GetFName();
		GUnrealEd->UnregisterComponentVisualizer(name);

		const FName& name2 = USampleComponent2::StaticClass()->GetFName();
		GUnrealEd->UnregisterComponentVisualizer(name2);
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDebugVisualizerModule, DebugVisualizer)