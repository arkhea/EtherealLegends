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
#include "Magic_Master.h"

// Sets default values
AMagic_Master::AMagic_Master(const FObjectInitializer& ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//// Get Assets, References Obtained Via Right Click in Editor
	//ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Audio/Party/Dash1_Cue.Dash1_Cue'"));
	//ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/Elemental/Logo/FrozenLogo/_FX_LogoReveal_ICE._FX_LogoReveal_ICE'"));
	//ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));

	// Creates a scene component and sets it as the root
	Root = NewObject<USceneComponent>(this, TEXT("Root"));
	RootComponent = Root;

	//// Set Default Objects
	//S_CastAudio = AudioObject.Object;
	//P_CastFX = CastParticleObject.Object;
	//P_ChargeFX = ChargeParticleObject.Object;
	
	// Create
	//CastAudio = NewObject<UAudioComponent>(this, TEXT("Cast Audio"));
	//CastFX = NewObject<UParticleSystemComponent>(this, TEXT("Cast VFX"));
	//ChargeFX = NewObject<UParticleSystemComponent>(this, TEXT("Charge VFX"));
}

// Called when the game starts or when spawned
void AMagic_Master::BeginPlay()
{
	Super::BeginPlay();

	// Attachment
	//CastAudio->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	//CastFX->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	//ChargeFX->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
	//CastAudio->Sound = S_CastAudio;
	//CastAudio->bAutoActivate = false;
	//CastFX->Template = P_CastFX;
	//CastFX->bAutoActivate = false;
	//ChargeFX->Template = P_ChargeFX;
	//ChargeFX->bAutoActivate = false;
}

void AMagic_Master::StopCharge()
{
	IsCharging = false;
	ChargeFX->DeactivateSystem();
	QuitCharging.Broadcast();
}

void AMagic_Master::Charge()
{

}

void AMagic_Master::Cast()
{

}
