// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentVisualizer.h"

class USampleComponent2;

/// <summary>
/// SampleComponent2の内容を視覚化するビジュアライザー
/// </summary>
/// <remarks>
/// SceneComponent継承のコンポーネントの内容を視覚化するサンプルコンポーネント
/// </remarks>
class DEBUGVISUALIZER_API FSampleCompVisualizer2 : public FComponentVisualizer
{
public:
	FSampleCompVisualizer2() = default;
	virtual ~FSampleCompVisualizer2() override = default;

#pragma region FComponentVisualizer 

	/// <summary>
	/// Draw visualization for the supplied component
	/// 提供されたコンポーネントの視覚化を描画する
	/// </summary>
	/// <remarks>
	/// StartupModule関数で、このビジュアライザー経由で描画したいコンポーネントと紐づけが必要っぽい
	/// </remarks>
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;

	/// <summary>
	/// 登録したオブジェクトをクリックしたときにコールされる
	/// </summary>
	virtual bool VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click) override;

	/// <summary>
	///
	/// </summary>
	virtual bool GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocation) const override;

	/// <summary>
	///
	/// </summary>
	virtual bool HandleInputDelta(FEditorViewportClient* ViewportClient, FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltaRotate, FVector& DeltaScale) override;

	/// <summary>
	/// Get currently edited component, this is needed to reset the active visualizer after undo/redo
	/// </summary>
	virtual UActorComponent* GetEditedComponent() const override;
	
#pragma endregion FComponentVisualizer

	/// <summary>
	/// 
	/// </summary>
	TObjectPtr<USampleComponent2> CurrentComponent;
	
	int32 SelectPointIndex = 0;
};
