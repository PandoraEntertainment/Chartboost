
#include "ChartboostPrivatePCH.h"

void UChartboostComponent::OnRegister()
{
	Super::OnRegister();
	
	
	// rewarded videos
	
	
	UChartboostComponent::DidCacheRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidCacheRewardedVideo_Handler);
	UChartboostComponent::DidFailToLoadRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidFailToLoadRewardedVideo_Handler);
	UChartboostComponent::DidCloseRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidCloseRewardedVideo_Handler);
	//UChartboostComponent::DidClickRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidClickRewardedVideo_Handler);
	UChartboostComponent::DidCompleteRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidCompleteRewardedVideo_Handler);
	
	

}

void UChartboostComponent::OnUnregister()
{
	Super::OnUnregister();
	

	
	// rewarded videos
	
	
	UChartboostComponent::DidCacheRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidFailToLoadRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidCloseRewardedVideoDelegate.RemoveAll(this);
	//UChartboostComponent::DidClickRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidCompleteRewardedVideoDelegate.RemoveAll(this);
	
	
	
}

// rewarded videos


UChartboostComponent::FChartboostCachedRewardedVideoDelegate UChartboostComponent::DidCacheRewardedVideoDelegate;
UChartboostComponent::FChartboostFailedToLoadRewardedVideoDelegate UChartboostComponent::DidFailToLoadRewardedVideoDelegate;
UChartboostComponent::FChartboostClosedRewardedVideoDelegate UChartboostComponent::DidCloseRewardedVideoDelegate;
//UChartboostComponent::FChartboostClickedRewardedVideoDelegate UChartboostComponent::DidClickRewardedVideoDelegate;
UChartboostComponent::FChartboostCompletedRewardedVideoDelegate UChartboostComponent::DidCompleteRewardedVideoDelegate;


