// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Platform")
	UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
