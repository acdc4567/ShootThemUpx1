// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ASTUBaseCharacter::ASTUBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation=1;

	CameraComponent=CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);


}

// Called when the game starts or when spawned
void ASTUBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTUBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASTUBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ASTUBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ASTUBaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &ASTUBaseCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &ASTUBaseCharacter::AddControllerPitchInput);
	
	PlayerInputComponent->BindAction("Jumpx",IE_Pressed,this,&ASTUBaseCharacter::Jump);
	
}

void ASTUBaseCharacter::MoveForward(float Amount){
	AddMovementInput(GetActorForwardVector(),Amount);
}


void ASTUBaseCharacter::MoveRight(float Amount){
	AddMovementInput(GetActorRightVector(),Amount);
}












//


















//ASTUBaseCharacter
