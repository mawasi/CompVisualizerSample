// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"


#include "SampleComponent.generated.h"


/// <summary>
/// ComponentVisualizer使ってパラメータを可視化するサンプルコンポーネント
/// </summary>
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMPVISUALIZERSAMPLE_API USampleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USampleComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;


	[[nodiscard]] float GetRadius() const { return Radius; }

	[[nodiscard]] const TArray<FVector>& GetVectors() const { return Vectors; }

	void SetVector(int32 InIndex, const FVector& InVector);
	
private:

	/// <summary>
	/// コンポーネントを中心とした半径
	/// </summary>
	UPROPERTY(EditAnywhere)
	float Radius = 1.0f;

	/// <summary>
	/// ベクターの配列
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<FVector>	Vectors;
};
