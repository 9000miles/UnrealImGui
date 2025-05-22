// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ImGuiDelegates.h"
#include "ImGuiSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnImGuiDraw);

/**
 * $Comment$
 */
UCLASS()
class UImGuiSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()
public:
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	void Tick(float DeltaTime) override;
	TStatId GetStatId() const override;

protected:
	void TickDraw();

public:
	UFUNCTION(BlueprintPure, Category = "ImGui")
	static UImGuiSubsystem* Get();

private:
	UPROPERTY()
	FOnImGuiDraw OnDraw;

private:
	static UImGuiSubsystem* Instance;
};