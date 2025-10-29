// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleCompVisualizer.h"
#include "SampleCompVisProxy.h"

#include "CompVisualizerSample/SampleComponent.h"



FSampleCompVisualizer::FSampleCompVisualizer()
{
}

FSampleCompVisualizer::~FSampleCompVisualizer()
{
}

/// <summary>
/// Draw visualization for the supplied component
/// 提供されたコンポーネントの視覚化を描画する
/// </summary>
void FSampleCompVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	/*
	描画用の関数は
	[PrimitiveDrawInterfrace.h]及び[PrimitiveDrawUtils.h]
	に定義されてるものが使える
	*/
	

	auto SampleComp = Cast<USampleComponent>(Component);
	if (!IsValid(SampleComp))
	{
		return;
	}

	auto owner = SampleComp->GetOwner();
	if (!IsValid(owner))
	{
		return;
	}

	// Radiusパラメータを使ってオーナーアクターの座標を中心にSphereを描画
	float radius = SampleComp->GetRadius();
	DrawWireSphere(PDI, owner->GetActorLocation(), FLinearColor::Green, radius, 16, SDPG_World, 0.0f);

	// なんでカプセルの向きをわざわざ各軸で渡す必要がある？Rotation渡して関数内で勝手にいい感じにしてくれたらいいのに
	FVector X = owner->GetActorForwardVector();
	FVector Y = owner->GetActorRightVector();
	FVector Z = owner->GetActorUpVector();
	DrawWireCapsule(PDI, owner->GetActorLocation(), X, Y, Z, FLinearColor::Blue, radius, SampleComp->GetHalfHeight(), 16, SDPG_World, 0.0f);
	
	const TArray<FVector>& vectors = SampleComp->GetVectors();
	const FTransform& transform = owner->GetActorTransform();

	int32 num = vectors.Num();
	for (int32 i = 0; i < num; i++)
	{
		FVector vec = transform.TransformPosition(vectors[i]);
		// SetHitProxy, SetHitProxyで挟んだ描画をクリックしたときにVisProxyHandleClickがコールされる
		PDI->SetHitProxy(new HSampleCompVisProxy(Component, i));
		PDI->DrawPoint(vec, FLinearColor::Red, 10.0f, SDPG_Foreground);
		PDI->SetHitProxy(nullptr);

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
UActorComponent* FSampleCompVisualizer::GetEditedComponent() const
{
	return CurrentComponent;
}

/// <summary>
/// 登録したオブジェクトをクリックしたときにコールされる
/// </summary>
bool FSampleCompVisualizer::VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click)
{
	if (VisProxy && VisProxy->Component.IsValid())
	{
		const HSampleCompVisProxy* CompVisProxy = static_cast<HSampleCompVisProxy*>(VisProxy);
		// const外して保存
		auto comp = Cast<const USampleComponent>(CompVisProxy->Component.Get());
		CurrentComponent = const_cast<USampleComponent*>(comp);
		SelectPointIndex = CompVisProxy->PointIndex;

		return true;
	}

	return false;
}

/// <summary>
///
/// </summary>
bool FSampleCompVisualizer::GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocation) const
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
bool FSampleCompVisualizer::HandleInputDelta(FEditorViewportClient* ViewportClient, FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltaRotate, FVector& DeltaScale)
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



