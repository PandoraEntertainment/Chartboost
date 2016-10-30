
#include "ChartboostPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;


//Rewarded Video
DECLARE_JAVA_METHOD(AndroidThunkJava_Chartboost_HasRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_Chartboost_ShowRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_Chartboost_CacheRewardedVideo);

void UChartboostFunctions::InitJavaFunctions()
{
	
	// Rewarded Video
	INIT_JAVA_METHOD(AndroidThunkJava_Chartboost_HasRewardedVideo, "(Ljava/lang/String;)Z");
	INIT_JAVA_METHOD(AndroidThunkJava_Chartboost_ShowRewardedVideo, "(Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_Chartboost_CacheRewardedVideo, "(Ljava/lang/String;)V");


}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD

// Rewarded Videos //

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeChartboostDidCacheRewardedVideo(String location);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeChartboostDidCacheRewardedVideo(JNIEnv* jenv, jobject thiz, jstring locationString)
{
	const char* javaChars = jenv->GetStringUTFChars(locationString, 0);

	FString Location = FString(UTF8_TO_TCHAR(javaChars));
	//Release the string
	jenv->ReleaseStringUTFChars(locationString, javaChars);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UChartboostComponent::DidCacheRewardedVideoDelegate.Broadcast(Location);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeChartboostDidFailToLoadRewardedVideo(String location);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeChartboostDidFailToLoadRewardedVideo(JNIEnv* jenv, jobject thiz, jstring locationString)
{
	const char* javaChars = jenv->GetStringUTFChars(locationString, 0);

	FString Location = FString(UTF8_TO_TCHAR(javaChars));
	//Release the string
	jenv->ReleaseStringUTFChars(locationString, javaChars);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UChartboostComponent::DidFailToLoadRewardedVideoDelegate.Broadcast(Location);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeCbDidCloseRewardedVideo(String location);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeChartboostDidCloseRewardedVideo(JNIEnv* jenv, jobject thiz, jstring locationString)
{
	const char* javaChars = jenv->GetStringUTFChars(locationString, 0);

	FString Location = FString(UTF8_TO_TCHAR(javaChars));
	//Release the string
	jenv->ReleaseStringUTFChars(locationString, javaChars);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UChartboostComponent::DidCloseRewardedVideoDelegate.Broadcast(Location);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeCbDidCompleteRewardedVideo(String location, int reward);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeChartboostDidCompleteRewardedVideo(JNIEnv* jenv, jobject thiz, jstring locationString, jint reward)
{
	const char* javaChars = jenv->GetStringUTFChars(locationString, 0);

	FString Location = FString(UTF8_TO_TCHAR(javaChars));
	//Release the string
	jenv->ReleaseStringUTFChars(locationString, javaChars);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UChartboostComponent::DidCompleteRewardedVideoDelegate.Broadcast(Location, reward);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


#endif









bool UChartboostFunctions::ChartboostHasRewardedVideo(FString Location) {
	
#if PLATFORM_IOS
	
#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring LocationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Location));

		bool ret = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Chartboost_HasRewardedVideo, LocationArg);

		Env->DeleteLocalRef(LocationArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ChartboostHasRewardedVideo\n"));

		return ret;
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowRewardedVideo(FString Location) {
	
#if PLATFORM_IOS

#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring LocationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Location));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Chartboost_ShowRewardedVideo, LocationArg);

		Env->DeleteLocalRef(LocationArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ChartboostShowRewardedVideo\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

void UChartboostFunctions::ChartboostCacheRewardedVideo(FString Location) {

#if PLATFORM_IOS

#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring LocationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Location));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Chartboost_CacheRewardedVideo, LocationArg);

		Env->DeleteLocalRef(LocationArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ChartboostCacheRewardedVideo\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

