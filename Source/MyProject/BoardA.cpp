// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardA.h"

// Sets default values
ABoardA::ABoardA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoardA::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoardA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

