// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }


	auto PlayerTank = Cast<ATank>(PlayerPawn);
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}*/
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//if (!PlayerPawn) { return nullptr; }
	auto PlayerTank = Cast<ATank>(PlayerPawn);

	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if ( ensure(PlayerTank) ) 
	{
		//Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation() );

		ControlledTank->Fire(); // TODO limit firing rate
	}
	
}




//ATank* ATankAIController::GetControlledTank() const
//{
//
//	return Cast<ATank>( GetPawn() );
//
//}
//
//ATank* ATankAIController::GetPlayerTank() const
//{
//	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
//
//	if (!PlayerPawn) { return nullptr; }
//	return Cast<ATank>(PlayerPawn);
//
//}

