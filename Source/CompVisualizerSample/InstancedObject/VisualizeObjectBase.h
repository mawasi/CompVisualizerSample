// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VisualizeObjectBase.generated.h"

class USampleComponent3;

/// <summary>
/// ComponentVisualizerのデバッグ描画をInstancedObjectで行うテスト基底クラス
/// </summary>
UCLASS(Abstract, EditInlineNew)
class COMPVISUALIZERSAMPLE_API UVisualizeObjectBase : public UObject
{
	GENERATED_BODY()

public:

	/// <summary>
	/// パラメータの視覚化
	/// </summary>
	virtual void DrawVisualizetion(const USampleComponent3* InComponent, const FSceneView* InView, FPrimitiveDrawInterface* PDI){}
	
};

/// <summary>
/// Sphere描画オブジェクト
/// </summary>
UCLASS()
class COMPVISUALIZERSAMPLE_API UVisualizeSphere : public UVisualizeObjectBase
{
	GENERATED_BODY()

public:

	/// <summary>
	/// パラメータの視覚化
	/// </summary>
	virtual void DrawVisualizetion(const USampleComponent3* InComponent, const FSceneView* InView, FPrimitiveDrawInterface* PDI) override;

	UPROPERTY(EditAnywhere)
	float Radius = 10.0f;
};


/// <summary>
/// Capsule描画オブジェクト
/// </summary>
UCLASS()
class COMPVISUALIZERSAMPLE_API UVisualizeCapsule : public UVisualizeObjectBase
{
	GENERATED_BODY()

public:

	/// <summary>
	/// パラメータの視覚化
	/// </summary>
	virtual void DrawVisualizetion(const USampleComponent3* InComponent, const FSceneView* InView, FPrimitiveDrawInterface* PDI) override;

	UPROPERTY(EditAnywhere)
	float Radius = 10.0f;

	UPROPERTY(EditAnywhere)
	float HalfHeight = 15.0f;

	UPROPERTY(EditAnywhere)
	FRotator RotateOffset = FRotator(0.0f, 0.0f, 0.0f);
};
