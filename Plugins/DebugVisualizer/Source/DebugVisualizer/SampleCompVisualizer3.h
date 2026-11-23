// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentVisualizer.h"

/// <summary>
/// SampleComponentの内容を視覚化するビジュアライザー
/// </summary>
class DEBUGVISUALIZER_API FSampleCompVisualizer3 : public FComponentVisualizer
{
public:
	FSampleCompVisualizer3();
	virtual ~FSampleCompVisualizer3() override;

#pragma region FComponentVisualizer
	
	/// <summary>
	/// Draw visualization for the supplied component
	/// 提供されたコンポーネントの視覚化を描画する
	/// </summary>
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;

#pragma endregion FComponentVisualizer

	
};
