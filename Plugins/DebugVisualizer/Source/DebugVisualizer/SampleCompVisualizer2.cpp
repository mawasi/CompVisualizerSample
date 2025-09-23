// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleCompVisualizer2.h"
#include "SampleCompVisProxy.h"

#include "CompVisualizerSample/SampleComponent2.h"

FSampleCompVisualizer2::FSampleCompVisualizer2()
{
}

FSampleCompVisualizer2::~FSampleCompVisualizer2()
{
}



/// <summary>
/// Draw visualization for the supplied component
/// 提供されたコンポーネントの視覚化を描画する
/// </summary>
void FSampleCompVisualizer2::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	/*
	描画用の関数は
	[PrimitiveDrawInterfrace.h]及び[PrimitiveDrawUtils.h]
	に定義されてるものが使える
	*/
	

	auto SampleComp = Cast<USampleComponent2>(Component);
	if (!IsValid(SampleComp))
	{
		return;
	}

	auto owner = SampleComp->GetOwner();
	if (!IsValid(owner))
	{
		return;
	}


	const TArray<FVector>& vectors = SampleComp->GetVectors();
	const FTransform& transform = owner->GetActorTransform();

	int32 num = vectors.Num();
	for (int32 i = 0; i < num; i++)
	{
		FVector vec = transform.TransformPosition(vectors[i]);
		// SetHitProxy, SetHitProxyで挟んだ描画をクリックしたときにVisProxyHandleClickがコールされる
		PDI->SetHitProxy(new HSampleCompVisProxy(Component, i));
		PDI->DrawPoint(vec, FLinearColor::Red, 10.0f, SDPG_Foreground);
		PDI->SetHitProxy(NULL);

		if (i > 0)
		{
			FVector pre = transform.TransformPosition(vectors[i-1]);
			PDI->DrawLine(pre, vec, FColor::Cyan, SDPG_Foreground, 0.0f);
		}
	}
	
}

/// <summary>
/// Get currently edited component, this is needed to reset the active visualizer after undo/redo
/// </summary>
UActorComponent* FSampleCompVisualizer2::GetEditedComponent() const
{
	return CurrentComponent;
}

/// <summary>
/// 登録したオブジェクトをクリックしたときにコールされる
/// </summary>
bool FSampleCompVisualizer2::VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click)
{
	if (VisProxy && VisProxy->Component.IsValid())
	{
		const HSampleCompVisProxy* CompVisProxy = static_cast<HSampleCompVisProxy*>(VisProxy);
		// const外して保存
		auto comp = Cast<const USampleComponent2>(CompVisProxy->Component.Get());
		CurrentComponent = const_cast<USampleComponent2*>(comp);
		SelectPointIndex = CompVisProxy->PointIndex;

		return true;
	}

	return false;
}

/// <summary>
///
/// </summary>
bool FSampleCompVisualizer2::GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocation) const
{
	if (IsValid(CurrentComponent))
	{
		const FTransform& transform = CurrentComponent->GetOwner()->GetActorTransform();
		OutLocation = transform.TransformPosition(CurrentComponent->GetVectors()[SelectPointIndex]);
		return true;
	}

	return false;
}

/// <summary>
/// 
/// </summary>
bool FSampleCompVisualizer2::HandleInputDelta(FEditorViewportClient* ViewportClient, FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltaRotate, FVector& DeltaScale)
{
	if (IsValid(CurrentComponent))
	{
		if (!DeltaTranslate.IsZero())
		{
			FVector vec = CurrentComponent->GetVectors()[SelectPointIndex];
			CurrentComponent->Modify(); // Undo/Redo 対応
			CurrentComponent->SetVector(SelectPointIndex, vec + DeltaTranslate);
		}
		return true;
	}

	return false;
}
