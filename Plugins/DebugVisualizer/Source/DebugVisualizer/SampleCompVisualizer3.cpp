// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleCompVisualizer3.h"

#include "CompVisualizerSample/SampleComponent3.h"


FSampleCompVisualizer3::FSampleCompVisualizer3()
{
}

FSampleCompVisualizer3::~FSampleCompVisualizer3()
{
}


/// <summary>
/// Draw visualization for the supplied component
/// 提供されたコンポーネントの視覚化を描画する
/// </summary>
void FSampleCompVisualizer3::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	/*
	描画用の関数は
	[PrimitiveDrawInterfrace.h]及び[PrimitiveDrawUtils.h]
	に定義されてるものが使える
	*/

	auto SampleComp = Cast<USampleComponent3>(Component);
//	auto SampleComp = owner->GetComponentByClass<USampleComponent3>();
	if (!IsValid(SampleComp))
	{
		return;
	}


#if 0
	FVector X = SampleComp->GetXAxisBasis();
	FVector Y = SampleComp->GetYAxisBasis();
	FVector Z = SampleComp->GetZAxisBasis();

	FVector location = owner->GetActorLocation();
	float len = 50.0f;
	PDI->DrawLine(location, location + X * len, FLinearColor::Red, SDPG_World);
	PDI->DrawLine(location, location + Y * len, FLinearColor::Green, SDPG_World);
	PDI->DrawLine(location, location + Z * len, FLinearColor::Blue, SDPG_World);

	FVector location2 = location + FVector(0.0f, 0.0f, 10.0f);
	FVector::CreateOrthonormalBasis(X, Y, Z);
	PDI->DrawLine(location2, location2 + X * len, FLinearColor::Red, SDPG_World);
	PDI->DrawLine(location2, location2 + Y * len, FLinearColor::Green, SDPG_World);
	PDI->DrawLine(location2, location2 + Z * len, FLinearColor::Blue, SDPG_World);

#endif

	// レベルエディター上だとInstancedObject切り替えがちゃんとリアルタイムに反映されるけど
	// BPエディター上ではうまく反映されない
	
#if 01
	auto VisualizeObject = SampleComp->GetVisualizeObject();
	
	if (VisualizeObject.IsValid())
	{
		VisualizeObject.Get()->DrawVisualizetion(SampleComp, View, PDI);
	}
#else
	static FName InstancedPropName(TEXT("VisualizeObject"));
	
	UClass* Class = SampleComp->GetClass();
	FProperty* Prop = FindFProperty<FProperty>(Class, InstancedPropName);
	if (FObjectProperty* ObjProp = CastField<FObjectProperty>(Prop))
	{
		const void* Container = static_cast<const void*>(Component);
		UObject* InstancedObj = ObjProp->GetObjectPropertyValue_InContainer(Container);
		if (InstancedObj)
		{
			UVisualizeObjectBase* VObj = Cast<UVisualizeObjectBase>(InstancedObj);
			if (VObj)
			{
				VObj->DrawVisualizetion(SampleComp, View, PDI);
			}
		}
	}
#endif
}

