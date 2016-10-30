
#pragma once

#include "ChartboostSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UChartboostSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UChartboostSettings(const FObjectInitializer& ObjectInitializer);
	
	// App Ids

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "App Id"))
	FString AppId;

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "App Signature"))
	FString AppSignature;
	

};
