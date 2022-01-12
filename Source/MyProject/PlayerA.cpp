// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerA.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
// Sets default values
APlayerA::APlayerA()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	CameraSpringArm->bDoCollisionTest = false;
	CameraSpringArm->TargetArmLength = 400.f;
	CameraSpringArm->bEnableCameraLag = true;
	CameraSpringArm->CameraLagSpeed = 4.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	Camera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APlayerA::BeginPlay()
{
	Super::BeginPlay();

		//PC = Cast<AChessController>(GetController()); need chess pieces for AChessController

	
}

// Called every frame
void APlayerA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
FVector APlayerA::GetCameraPanDirection()
{
	// Variable to hold mouse position
	float MousePositionX;
	float MousePositionY;
	float CameraDirectionX = 0;
	float CameraDirectionY = 0;

	PC->GetMousePosition(MousePositionX, MousePositionY);
	if (MousePositionX == 0)
	{
		CameraDirectionY = -1;
	}
	return FVector(CameraDirectionX, CameraDirectionY, 0);
}
void APlayerA::SetName(FText PlayerName)
{
	Name = PlayerName;
}

FText APlayerA::GetName()
{
	return Name;
}
int32 APlayerA::GetScore()
{
	return Score;
}



