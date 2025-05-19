// Fill out your copyright notice in the Description page of Project Settings.
#include "ImGuiSubsystem.h"
#include "ImGuiModule.h"

void UImGuiSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UImGuiSubsystem::Instance = this;
	Super::Initialize(Collection);
}

void UImGuiSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UImGuiSubsystem::TickDraw()
{
	if (OnDraw.IsBound())
	{
		OnDraw.Broadcast();
	}
}

UImGuiSubsystem* UImGuiSubsystem::Get()
{
	return Instance;
}

void UImGuiSubsystem::Tick(float DeltaTime)
{
	TickDraw();
}

TStatId UImGuiSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UImGuiSubsystem, STATGROUP_Tickables);
}

UImGuiSubsystem* UImGuiSubsystem::Instance;
