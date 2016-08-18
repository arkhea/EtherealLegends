// © 2014 - 2016 Soverance Studios
// www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http ://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "Barrier.h"

// Sets default values
ABarrier::ABarrier(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	//ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Audio/Party/Dash1_Cue.Dash1_Cue'"));
	//ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/Elemental/Logo/FrozenLogo/_FX_LogoReveal_ICE._FX_LogoReveal_ICE'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/barrier.barrier'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/barrier-small.barrier-small'"));

	// Set Default Values
	Name = EMasterGearList::GL_Barrier;
	Type = EMasterGearTypes::GT_Support;
	Description = "Raises DEF by 25% while standing within the effect radius.";
	MPCost = 45;
	ATK = 0;
	DEF = 0;
	SPD = 0;
	HP = 100;
	MP = -50;
	Duration = 20;
	CastTime = 40;
	CritMultiplier = 0;
	HasteMultiplier = 0;
	DefenseMultiplier = 0.25f;
	TargetType = EMagic_TargetTypes::TT_Player;
	AnimType = EMagic_AnimTypes::AT_Standard;

	// Set Default Objects
	//S_CastAudio = AudioObject.Object;
	//P_CastFX = CastParticleObject.Object;
	P_ChargeFX = ChargeParticleObject.Object;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	
}

// Called when the game starts or when spawned
void ABarrier::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	QuitCharging.AddDynamic(this, &ABarrier::Cancel);

	// Attachment
	//CastAudio->SetupAttachment(GetRootComponent());
	//CastAudio->Sound = S_CastAudio;
	//CastAudio->bAutoActivate = false;
	//CastFX->SetupAttachment(GetRootComponent());
	//CastFX->Template = P_CastFX;
	//CastFX->bAutoActivate = false;
	ChargeFX->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	ChargeFX->Template = P_ChargeFX;
	ChargeFX->bAutoActivate = false;
}

void ABarrier::Cancel()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Barrier casting was cancelled.");
}



