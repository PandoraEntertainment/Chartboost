
#pragma once

#include "ChartboostFunctions.h"
#include "ChartboostComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UChartboostComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	
	
	// rewarded videos
	
	//Cache Rewarded video
	DECLARE_MULTICAST_DELEGATE_OneParam(FChartboostCachedRewardedVideoDelegate, FString);

	static FChartboostCachedRewardedVideoDelegate DidCacheRewardedVideoDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChartboostCachedRewardedVideoDynDelegate, FString, Location);
	
	UPROPERTY(BlueprintAssignable)
	FChartboostCachedRewardedVideoDynDelegate DidCacheRewardedVideo;

	//Fail to load rewarded video
	DECLARE_MULTICAST_DELEGATE_OneParam(FChartboostFailedToLoadRewardedVideoDelegate, FString);

	static FChartboostFailedToLoadRewardedVideoDelegate DidFailToLoadRewardedVideoDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChartboostFailedToLoadRewardedVideoDynDelegate, FString, Location);
	
	UPROPERTY(BlueprintAssignable)
	FChartboostFailedToLoadRewardedVideoDynDelegate DidFailToLoadRewardedVideo;

	//Close Rewarded video
	DECLARE_MULTICAST_DELEGATE_OneParam(FChartboostClosedRewardedVideoDelegate, FString);

	static FChartboostClosedRewardedVideoDelegate DidCloseRewardedVideoDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChartboostClosedRewardedVideoDynDelegate, FString, Location);
	
	UPROPERTY(BlueprintAssignable)
	FChartboostClosedRewardedVideoDynDelegate DidCloseRewardedVideo;

	// Click Rewarded video
	//DECLARE_MULTICAST_DELEGATE_OneParam(FChartboostClickedRewardedVideoDelegate, FString);

	//static FChartboostClickedRewardedVideoDelegate DidClickRewardedVideoDelegate;

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChartboostClickedRewardedVideoDynDelegate, FString, Location);
	
	//UPROPERTY(BlueprintAssignable)
	//FChartboostClickedRewardedVideoDynDelegate DidClickRewardedVideo;

	//Completed Rewarded video
	DECLARE_MULTICAST_DELEGATE_TwoParams(FChartboostCompletedRewardedVideoDelegate, FString, int32);

	static FChartboostCompletedRewardedVideoDelegate DidCompleteRewardedVideoDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChartboostCompletedRewardedVideoDynDelegate, FString, Location, int32, Reward);
	
	UPROPERTY(BlueprintAssignable)
	FChartboostCompletedRewardedVideoDynDelegate DidCompleteRewardedVideo;
	
	
	void OnRegister() override;
	void OnUnregister() override;
	
private:	
	
	// rewarded videos
	
	void DidCacheRewardedVideo_Handler(FString Location) { DidCacheRewardedVideo.Broadcast(Location); }
	void DidFailToLoadRewardedVideo_Handler(FString Location) { DidFailToLoadRewardedVideo.Broadcast(Location); }
	void DidCloseRewardedVideo_Handler(FString Location) { DidCloseRewardedVideo.Broadcast(Location); }
	//void DidClickRewardedVideo_Handler(FString Location) { DidClickRewardedVideo.Broadcast(Location); }
	void DidCompleteRewardedVideo_Handler(FString Location, int Reward) { DidCompleteRewardedVideo.Broadcast(Location, Reward); }
	
	
};
