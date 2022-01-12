// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "board.generated.h"

UCLASS()
class MYPROJECT_API Aboard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aboard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void highlightGrid(UStaticMeshComponent* Grid);

public: 
	UPROPERTY()
		class UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere)
		class UMaterial* LightMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterial* DarkMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterial* HighlightedMaterial;
	UPROPERTY()
		class UMaterial* DefaultMaterial;
};
