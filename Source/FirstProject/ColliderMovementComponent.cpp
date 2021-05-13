// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderMovementComponent.h"

void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) 
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) 
	{
		return;
	}

	FVector DesiredMovementThisFrame = ConsumeInputVector() * DeltaTime * Speed;

	if(!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(
			DesiredMovementThisFrame,
			UpdatedComponent->GetComponentRotation(),
			true, // flag to stop the pawn from moveing into a blocking volume 
			Hit
		);

		if(Hit.IsValidBlockingHit())
		{
			SlideAlongSurface(
				DesiredMovementThisFrame, 
				1.f - Hit.Time, 
				Hit.Normal, 
				Hit
			);
		}
	}
}
