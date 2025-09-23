// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SampleComponent2.generated.h"

/// <summary>
/// ComponentVisualizer使ってパラメータを可視化するサンプルコンポーネントのシーンコンポーネント継承版
/// </summary>
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMPVISUALIZERSAMPLE_API USampleComponent2 : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USampleComponent2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	[[nodiscard]] const TArray<FVector>& GetVectors() const { return Vectors; }

	void SetVector(int32 InIndex, const FVector& InVector);

private:

	/// <summary>
	/// ベクターの配列
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<FVector>	Vectors;
};
