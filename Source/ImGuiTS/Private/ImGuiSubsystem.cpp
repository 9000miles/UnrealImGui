// Fill out your copyright notice in the Description page of Project Settings.
#include "ImGuiSubsystem.h"
#include "ImGuiModule.h"

void UImGuiSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UImGuiSubsystem::Instance = this;
	Super::Initialize(Collection);

	//DelegateHandle = FImGuiModule::Get().AddWorldImGuiDelegate(FImGuiDelegate::CreateUObject(this, &UImGuiSubsystem::OnImGuiRender));
}

void UImGuiSubsystem::Deinitialize()
{
	Super::Deinitialize();

	//FImGuiModule::Get().RemoveImGuiDelegate(DelegateHandle);
}

void UImGuiSubsystem::OnImGuiRender()
{
	if (OnRender.IsBound())
	{
		OnRender.Broadcast();
	}
}

UImGuiSubsystem* UImGuiSubsystem::Get()
{
	return Instance;
}

void UImGuiSubsystem::Tick(float DeltaTime)
{
	OnImGuiRender();
}

TStatId UImGuiSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UImGuiSubsystem, STATGROUP_Tickables);
}

UImGuiSubsystem* UImGuiSubsystem::Instance;
