
#pragma once

#include "ChartboostFunctions.generated.h"


UCLASS(NotBlueprintable)
class UChartboostFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif

	// rewarded video

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static bool ChartboostHasRewardedVideo(FString Location = "Default");
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void ChartboostShowRewardedVideo(FString Location = "Default");

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void ChartboostCacheRewardedVideo(FString Location = "Default");
};
