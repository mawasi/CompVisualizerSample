// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentVisualizer.h"


/// <summary>
/// PDIで入力を受け取るのに必要な構造体
/// </summary>
struct HSampleCompVisProxy : public HComponentVisProxy
{
	DECLARE_HIT_PROXY();

	HSampleCompVisProxy(const UActorComponent* InComponent, int32 InPointIndex)
	: HComponentVisProxy(InComponent)
	, PointIndex(InPointIndex) 
	{
		
	}

	int32 PointIndex;
};
