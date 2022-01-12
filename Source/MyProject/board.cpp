// Fill out your copyright notice in the Description page of Project Settings.


#include "board.h"

// Sets default values
Aboard::Aboard()
{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));		// Define a box component
	RootComponent = BoxComponent;													// Set it as RootComponent
	BoxComponent->InitBoxExtent(FVector(0, 0, 0));									// Set size to box

	
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/M_Lightwood.M_Lightwood'"));
	if (Material.Object != NULL)
	{
		LightMaterial = (UMaterial*)Material.Object;
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> Material2(TEXT("Material'/Game/Materials/M_Darkwood.M_Darkwood'"));
	if (Material2.Object != NULL)
	{
		DarkMaterial = (UMaterial*)Material2.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> Material3(TEXT("Material'/Game/Materials/M_SelectedMaterial.M_SelectedMaterial'"));
	if (Material3.Object != NULL)
	{
		HighlightedMaterial = (UMaterial*)Material3.Object;
	}

	// Calculation of coordinates
	for (int32 i = 0; i < 64; ++i)
	{
		// Set Coordinates
		int32 XCoord = (i / 8) * 400;
		int32 YCoord = (i % 8) * 400;

		// Add static mesh to component 
		StaticMeshes.Add(CreateDefaultSubobject<UStaticMeshComponent>(*FString("Mesh" + FString::FromInt(i))));
		StaticMeshes[i]->SetupAttachment(BoxComponent); // Atttach mesh to root component

		// Retrieve floor asset 
		static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/Meshes/Floor.Floor'"));
		// If floor asset is retrieved successfully 
		if (StaticMeshAsset.Succeeded())
		{
			// Set floor asset to static mesh
			StaticMeshes[i]->SetStaticMesh(StaticMeshAsset.Object);

			// Set relative location values to calculated values
			StaticMeshes[i]->SetRelativeLocation(FVector(XCoord, YCoord, 0));
		}
	}

}

// Called when the game starts or when spawned
void Aboard::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < 64; ++i)
	{
		// Calculations to set materials 
		bool First = ((i / 8) % 2) == 0 ? false : true;
		bool Second = ((i % 8) % 2) == 0 ? false : true;
		bool Result = XOR(First, Second);
		if (Result)
		{
			StaticMeshes[i]->SetMaterial(0, LightMaterial);
			DefaultMaterial = LightMaterial;
		}
		else
		{
			StaticMeshes[i]->SetMaterial(0, DarkMaterial);
			DefaultMaterial = DarkMaterial;
		}
	}
}

// Called every frame
void Aboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoard::highlightGrid(UStaticMeshComponent* Grid)
{
	Grid->SetMaterial(0, HighlightedMaterial);
}