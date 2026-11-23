// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InstancedObject/VisualizeObjectBase.h"


#include "SampleComponent3.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMPVISUALIZERSAMPLE_API USampleComponent3 : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USampleComponent3();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;


	[[nodiscard]] const FVector& GetXAxisBasis() const { return XAxisBasis; }
	[[nodiscard]] const FVector& GetYAxisBasis() const { return YAxisBasis; }
	[[nodiscard]] const FVector& GetZAxisBasis() const { return ZAxisBasis; }

	TWeakObjectPtr<UVisualizeObjectBase> GetVisualizeObject() const { return VisualizeObject; }
	
private:
	UPROPERTY(EditAnywhere)
	FVector XAxisBasis = FVector(1.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere)
	FVector YAxisBasis = FVector(0.0f, 1.0f, 0.0f);

	UPROPERTY(EditAnywhere)
	FVector ZAxisBasis = FVector(0.0f, 0.0f, 1.0f);

	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UVisualizeObjectBase> VisualizeObject;
	
};
