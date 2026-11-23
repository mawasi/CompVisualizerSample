// Fill out your copyright notice in the Description page of Project Settings.


#include "VisualizeObjectBase.h"

#include "CompVisualizerSample/SampleComponent3.h"


void UVisualizeSphere::DrawVisualizetion(const USampleComponent3* InComponent, const FSceneView* InView, FPrimitiveDrawInterface* PDI)
{

	DrawWireSphere(PDI, InComponent->GetComponentLocation(), FLinearColor::Green, Radius, 16, SDPG_World, 0.0f);
}



void UVisualizeCapsule::DrawVisualizetion(const USampleComponent3* InComponent, const FSceneView* InView, FPrimitiveDrawInterface* PDI)
{
	FVector X = InComponent->GetForwardVector();
	FVector Y = InComponent->GetRightVector();
	FVector Z = InComponent->GetUpVector();
	DrawWireCapsule(PDI, InComponent->GetComponentLocation(), X, Y, Z, FLinearColor::Blue, Radius, HalfHeight, 16, SDPG_World, 0.0f);
}
