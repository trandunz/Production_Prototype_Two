// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AsyncLoadingScreen/Public/AsyncLoadingScreenLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAsyncLoadingScreenLibrary() {}
// Cross Module References
	ASYNCLOADINGSCREEN_API UClass* Z_Construct_UClass_UAsyncLoadingScreenLibrary();
	ASYNCLOADINGSCREEN_API UClass* Z_Construct_UClass_UAsyncLoadingScreenLibrary_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AsyncLoadingScreen();
// End Cross Module References
	DEFINE_FUNCTION(UAsyncLoadingScreenLibrary::execStopLoadingScreen)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UAsyncLoadingScreenLibrary::StopLoadingScreen();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAsyncLoadingScreenLibrary::execGetIsEnableLoadingScreen)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UAsyncLoadingScreenLibrary::GetIsEnableLoadingScreen();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAsyncLoadingScreenLibrary::execSetEnableLoadingScreen)
	{
		P_GET_UBOOL(Z_Param_bIsEnableLoadingScreen);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAsyncLoadingScreenLibrary::SetEnableLoadingScreen(Z_Param_bIsEnableLoadingScreen);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAsyncLoadingScreenLibrary::execSetDisplayMovieIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_MovieIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAsyncLoadingScreenLibrary::SetDisplayMovieIndex(Z_Param_MovieIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAsyncLoadingScreenLibrary::execSetDisplayTipTextIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_TipTextIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAsyncLoadingScreenLibrary::SetDisplayTipTextIndex(Z_Param_TipTextIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAsyncLoadingScreenLibrary::execSetDisplayBackgroundIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_BackgroundIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAsyncLoadingScreenLibrary::SetDisplayBackgroundIndex(Z_Param_BackgroundIndex);
		P_NATIVE_END;
	}
	void UAsyncLoadingScreenLibrary::StaticRegisterNativesUAsyncLoadingScreenLibrary()
	{
		UClass* Class = UAsyncLoadingScreenLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetIsEnableLoadingScreen", &UAsyncLoadingScreenLibrary::execGetIsEnableLoadingScreen },
			{ "SetDisplayBackgroundIndex", &UAsyncLoadingScreenLibrary::execSetDisplayBackgroundIndex },
			{ "SetDisplayMovieIndex", &UAsyncLoadingScreenLibrary::execSetDisplayMovieIndex },
			{ "SetDisplayTipTextIndex", &UAsyncLoadingScreenLibrary::execSetDisplayTipTextIndex },
			{ "SetEnableLoadingScreen", &UAsyncLoadingScreenLibrary::execSetEnableLoadingScreen },
			{ "StopLoadingScreen", &UAsyncLoadingScreenLibrary::execStopLoadingScreen },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics
	{
		struct AsyncLoadingScreenLibrary_eventGetIsEnableLoadingScreen_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AsyncLoadingScreenLibrary_eventGetIsEnableLoadingScreen_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AsyncLoadingScreenLibrary_eventGetIsEnableLoadingScreen_Parms), &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Async Loading Screen" },
		{ "Comment", "/**\n\x09 * Get enable/disable the loading screen for next levels\n\x09 *\n\x09 **/" },
		{ "ModuleRelativePath", "Public/AsyncLoadingScreenLibrary.h" },
		{ "ToolTip", "Get enable/disable the loading screen for next levels" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAsyncLoadingScreenLibrary, nullptr, "GetIsEnableLoadingScreen", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::AsyncLoadingScreenLibrary_eventGetIsEnableLoadingScreen_Parms), Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics
	{
		struct AsyncLoadingScreenLibrary_eventSetDisplayBackgroundIndex_Parms
		{
			int32 BackgroundIndex;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_BackgroundIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::NewProp_BackgroundIndex = { "BackgroundIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AsyncLoadingScreenLibrary_eventSetDisplayBackgroundIndex_Parms, BackgroundIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::NewProp_BackgroundIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Async Loading Screen" },
		{ "Comment", "/**\n\x09 * Set which background will be displayed on the loading screen by index. The \"SetDisplayBackgroundManually\" option in Background setting needs to be \"true\" to use this function.\n\x09 * \n\x09 * @param BackgroundIndex Valid index of the Background in \"Images\" array in Background setting. If the index is not valid, then it will display random background instead.\n\x09 **/" },
		{ "ModuleRelativePath", "Public/AsyncLoadingScreenLibrary.h" },
		{ "ToolTip", "Set which background will be displayed on the loading screen by index. The \"SetDisplayBackgroundManually\" option in Background setting needs to be \"true\" to use this function.\n\n@param BackgroundIndex Valid index of the Background in \"Images\" array in Background setting. If the index is not valid, then it will display random background instead." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAsyncLoadingScreenLibrary, nullptr, "SetDisplayBackgroundIndex", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::AsyncLoadingScreenLibrary_eventSetDisplayBackgroundIndex_Parms), Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics
	{
		struct AsyncLoadingScreenLibrary_eventSetDisplayMovieIndex_Parms
		{
			int32 MovieIndex;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_MovieIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::NewProp_MovieIndex = { "MovieIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AsyncLoadingScreenLibrary_eventSetDisplayMovieIndex_Parms, MovieIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::NewProp_MovieIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Async Loading Screen" },
		{ "Comment", "/**\n\x09 * Set which movie will be displayed on the loading screen by index. The \"SetDisplayMovieIndexManually\" option needs to be \"true\" to use this function.\n\x09 *\n\x09 * @param MovieIndex Valid index of the movie in \"MoviePaths\" array.\n\x09 **/" },
		{ "ModuleRelativePath", "Public/AsyncLoadingScreenLibrary.h" },
		{ "ToolTip", "Set which movie will be displayed on the loading screen by index. The \"SetDisplayMovieIndexManually\" option needs to be \"true\" to use this function.\n\n@param MovieIndex Valid index of the movie in \"MoviePaths\" array." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAsyncLoadingScreenLibrary, nullptr, "SetDisplayMovieIndex", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::AsyncLoadingScreenLibrary_eventSetDisplayMovieIndex_Parms), Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics
	{
		struct AsyncLoadingScreenLibrary_eventSetDisplayTipTextIndex_Parms
		{
			int32 TipTextIndex;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_TipTextIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::NewProp_TipTextIndex = { "TipTextIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AsyncLoadingScreenLibrary_eventSetDisplayTipTextIndex_Parms, TipTextIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::NewProp_TipTextIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Async Loading Screen" },
		{ "Comment", "/**\n\x09 * Set which text will be displayed on the loading screen by index. The \"SetDisplayTipTextManually\" option in Tip Widget setting needs to be \"true\" to use this function.\n\x09 *\n\x09 * @param TipTextIndex Valid index of the text in \"TipText\" array in Tip Widget setting. If the index is not valid, then it will display random text instead.\n\x09 **/" },
		{ "ModuleRelativePath", "Public/AsyncLoadingScreenLibrary.h" },
		{ "ToolTip", "Set which text will be displayed on the loading screen by index. The \"SetDisplayTipTextManually\" option in Tip Widget setting needs to be \"true\" to use this function.\n\n@param TipTextIndex Valid index of the text in \"TipText\" array in Tip Widget setting. If the index is not valid, then it will display random text instead." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAsyncLoadingScreenLibrary, nullptr, "SetDisplayTipTextIndex", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::AsyncLoadingScreenLibrary_eventSetDisplayTipTextIndex_Parms), Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics
	{
		struct AsyncLoadingScreenLibrary_eventSetEnableLoadingScreen_Parms
		{
			bool bIsEnableLoadingScreen;
		};
		static void NewProp_bIsEnableLoadingScreen_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEnableLoadingScreen;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::NewProp_bIsEnableLoadingScreen_SetBit(void* Obj)
	{
		((AsyncLoadingScreenLibrary_eventSetEnableLoadingScreen_Parms*)Obj)->bIsEnableLoadingScreen = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::NewProp_bIsEnableLoadingScreen = { "bIsEnableLoadingScreen", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AsyncLoadingScreenLibrary_eventSetEnableLoadingScreen_Parms), &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::NewProp_bIsEnableLoadingScreen_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::NewProp_bIsEnableLoadingScreen,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Async Loading Screen" },
		{ "Comment", "/**\n\x09 * Set enable/disable the loading screen for next levels\n\x09 *\n\x09 * @param bIsEnableLoadingScreen Should we enable the loading screen for next level?\n\x09 **/" },
		{ "ModuleRelativePath", "Public/AsyncLoadingScreenLibrary.h" },
		{ "ToolTip", "Set enable/disable the loading screen for next levels\n\n@param bIsEnableLoadingScreen Should we enable the loading screen for next level?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAsyncLoadingScreenLibrary, nullptr, "SetEnableLoadingScreen", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::AsyncLoadingScreenLibrary_eventSetEnableLoadingScreen_Parms), Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Async Loading Screen" },
		{ "Comment", "/**\n\x09 * Stop the loading screen. To use this function, you must enable the \"bAllowEngineTick\" option.\n\x09 * Call this function in BeginPlay event to stop the Loading Screen (works with Delay node).\n\x09 *\n\x09 **/" },
		{ "ModuleRelativePath", "Public/AsyncLoadingScreenLibrary.h" },
		{ "ToolTip", "Stop the loading screen. To use this function, you must enable the \"bAllowEngineTick\" option.\nCall this function in BeginPlay event to stop the Loading Screen (works with Delay node)." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAsyncLoadingScreenLibrary, nullptr, "StopLoadingScreen", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAsyncLoadingScreenLibrary);
	UClass* Z_Construct_UClass_UAsyncLoadingScreenLibrary_NoRegister()
	{
		return UAsyncLoadingScreenLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_AsyncLoadingScreen,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_GetIsEnableLoadingScreen, "GetIsEnableLoadingScreen" }, // 3217757071
		{ &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayBackgroundIndex, "SetDisplayBackgroundIndex" }, // 827823440
		{ &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayMovieIndex, "SetDisplayMovieIndex" }, // 2054881208
		{ &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetDisplayTipTextIndex, "SetDisplayTipTextIndex" }, // 3693050228
		{ &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_SetEnableLoadingScreen, "SetEnableLoadingScreen" }, // 4136706334
		{ &Z_Construct_UFunction_UAsyncLoadingScreenLibrary_StopLoadingScreen, "StopLoadingScreen" }, // 1624763539
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Async Loading Screen Function Library\n */" },
		{ "IncludePath", "AsyncLoadingScreenLibrary.h" },
		{ "ModuleRelativePath", "Public/AsyncLoadingScreenLibrary.h" },
		{ "ToolTip", "Async Loading Screen Function Library" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAsyncLoadingScreenLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::ClassParams = {
		&UAsyncLoadingScreenLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAsyncLoadingScreenLibrary()
	{
		if (!Z_Registration_Info_UClass_UAsyncLoadingScreenLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAsyncLoadingScreenLibrary.OuterSingleton, Z_Construct_UClass_UAsyncLoadingScreenLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAsyncLoadingScreenLibrary.OuterSingleton;
	}
	template<> ASYNCLOADINGSCREEN_API UClass* StaticClass<UAsyncLoadingScreenLibrary>()
	{
		return UAsyncLoadingScreenLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAsyncLoadingScreenLibrary);
	UAsyncLoadingScreenLibrary::~UAsyncLoadingScreenLibrary() {}
	struct Z_CompiledInDeferFile_FID_Users_trand_OneDrive_Documents_GitHub_Production_Prototype_Two_Prototype2_Plugins_Marketplace_AsyncLoadingScreen_Source_AsyncLoadingScreen_Public_AsyncLoadingScreenLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_trand_OneDrive_Documents_GitHub_Production_Prototype_Two_Prototype2_Plugins_Marketplace_AsyncLoadingScreen_Source_AsyncLoadingScreen_Public_AsyncLoadingScreenLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAsyncLoadingScreenLibrary, UAsyncLoadingScreenLibrary::StaticClass, TEXT("UAsyncLoadingScreenLibrary"), &Z_Registration_Info_UClass_UAsyncLoadingScreenLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAsyncLoadingScreenLibrary), 2466615413U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_trand_OneDrive_Documents_GitHub_Production_Prototype_Two_Prototype2_Plugins_Marketplace_AsyncLoadingScreen_Source_AsyncLoadingScreen_Public_AsyncLoadingScreenLibrary_h_2216523556(TEXT("/Script/AsyncLoadingScreen"),
		Z_CompiledInDeferFile_FID_Users_trand_OneDrive_Documents_GitHub_Production_Prototype_Two_Prototype2_Plugins_Marketplace_AsyncLoadingScreen_Source_AsyncLoadingScreen_Public_AsyncLoadingScreenLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_trand_OneDrive_Documents_GitHub_Production_Prototype_Two_Prototype2_Plugins_Marketplace_AsyncLoadingScreen_Source_AsyncLoadingScreen_Public_AsyncLoadingScreenLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS