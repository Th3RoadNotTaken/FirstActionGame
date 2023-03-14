// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstProject/MainPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainPlayerController() {}
// Cross Module References
	FIRSTPROJECT_API UClass* Z_Construct_UClass_AMainPlayerController_NoRegister();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_AMainPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_FirstProject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMainPlayerController::execDisplayHUDOverlay)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisplayHUDOverlay();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMainPlayerController::execRemoveFourthIntroductionBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveFourthIntroductionBox_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMainPlayerController::execRemoveThirdIntroductionBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveThirdIntroductionBox_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMainPlayerController::execRemoveSecondIntroductionBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveSecondIntroductionBox_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMainPlayerController::execRemoveFirstIntroductionBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveFirstIntroductionBox_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMainPlayerController::execDisplayIntroductionMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisplayIntroductionMenu_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMainPlayerController::execRemovePauseMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemovePauseMenu_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMainPlayerController::execDisplayPauseMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisplayPauseMenu_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_AMainPlayerController_DisplayIntroductionMenu = FName(TEXT("DisplayIntroductionMenu"));
	void AMainPlayerController::DisplayIntroductionMenu()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMainPlayerController_DisplayIntroductionMenu),NULL);
	}
	static FName NAME_AMainPlayerController_DisplayPauseMenu = FName(TEXT("DisplayPauseMenu"));
	void AMainPlayerController::DisplayPauseMenu()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMainPlayerController_DisplayPauseMenu),NULL);
	}
	static FName NAME_AMainPlayerController_RemoveFirstIntroductionBox = FName(TEXT("RemoveFirstIntroductionBox"));
	void AMainPlayerController::RemoveFirstIntroductionBox()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMainPlayerController_RemoveFirstIntroductionBox),NULL);
	}
	static FName NAME_AMainPlayerController_RemoveFourthIntroductionBox = FName(TEXT("RemoveFourthIntroductionBox"));
	void AMainPlayerController::RemoveFourthIntroductionBox()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMainPlayerController_RemoveFourthIntroductionBox),NULL);
	}
	static FName NAME_AMainPlayerController_RemovePauseMenu = FName(TEXT("RemovePauseMenu"));
	void AMainPlayerController::RemovePauseMenu()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMainPlayerController_RemovePauseMenu),NULL);
	}
	static FName NAME_AMainPlayerController_RemoveSecondIntroductionBox = FName(TEXT("RemoveSecondIntroductionBox"));
	void AMainPlayerController::RemoveSecondIntroductionBox()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMainPlayerController_RemoveSecondIntroductionBox),NULL);
	}
	static FName NAME_AMainPlayerController_RemoveThirdIntroductionBox = FName(TEXT("RemoveThirdIntroductionBox"));
	void AMainPlayerController::RemoveThirdIntroductionBox()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMainPlayerController_RemoveThirdIntroductionBox),NULL);
	}
	void AMainPlayerController::StaticRegisterNativesAMainPlayerController()
	{
		UClass* Class = AMainPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DisplayHUDOverlay", &AMainPlayerController::execDisplayHUDOverlay },
			{ "DisplayIntroductionMenu", &AMainPlayerController::execDisplayIntroductionMenu },
			{ "DisplayPauseMenu", &AMainPlayerController::execDisplayPauseMenu },
			{ "RemoveFirstIntroductionBox", &AMainPlayerController::execRemoveFirstIntroductionBox },
			{ "RemoveFourthIntroductionBox", &AMainPlayerController::execRemoveFourthIntroductionBox },
			{ "RemovePauseMenu", &AMainPlayerController::execRemovePauseMenu },
			{ "RemoveSecondIntroductionBox", &AMainPlayerController::execRemoveSecondIntroductionBox },
			{ "RemoveThirdIntroductionBox", &AMainPlayerController::execRemoveThirdIntroductionBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "DisplayHUDOverlay", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "DisplayIntroductionMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "DisplayPauseMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "RemoveFirstIntroductionBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "RemoveFourthIntroductionBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "RemovePauseMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "RemoveSecondIntroductionBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainPlayerController, nullptr, "RemoveThirdIntroductionBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMainPlayerController_NoRegister()
	{
		return AMainPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AMainPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HUDOverlayAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_HUDOverlayAsset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HudOverlay_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HudOverlay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WEnemyHealthBar_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WEnemyHealthBar;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyHealthBar_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EnemyHealthBar;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WShieldHealthBar_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WShieldHealthBar;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShieldHealthBar_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShieldHealthBar;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasShield_MetaData[];
#endif
		static void NewProp_bHasShield_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasShield;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WPauseMenu_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WPauseMenu;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PauseMenu_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PauseMenu;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WIntroductionMenu_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WIntroductionMenu;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IntroductionMenu_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IntroductionMenu;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIntroductionMenuVisible_MetaData[];
#endif
		static void NewProp_bIntroductionMenuVisible_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIntroductionMenuVisible;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoveDone_MetaData[];
#endif
		static void NewProp_MoveDone_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_MoveDone;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotateDone_MetaData[];
#endif
		static void NewProp_RotateDone_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_RotateDone;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackDone_MetaData[];
#endif
		static void NewProp_AttackDone_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttackDone;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpDone_MetaData[];
#endif
		static void NewProp_JumpDone_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_JumpDone;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMainPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMainPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMainPlayerController_DisplayHUDOverlay, "DisplayHUDOverlay" }, // 3271298550
		{ &Z_Construct_UFunction_AMainPlayerController_DisplayIntroductionMenu, "DisplayIntroductionMenu" }, // 3699811392
		{ &Z_Construct_UFunction_AMainPlayerController_DisplayPauseMenu, "DisplayPauseMenu" }, // 3079682836
		{ &Z_Construct_UFunction_AMainPlayerController_RemoveFirstIntroductionBox, "RemoveFirstIntroductionBox" }, // 1026913536
		{ &Z_Construct_UFunction_AMainPlayerController_RemoveFourthIntroductionBox, "RemoveFourthIntroductionBox" }, // 319103360
		{ &Z_Construct_UFunction_AMainPlayerController_RemovePauseMenu, "RemovePauseMenu" }, // 3128477820
		{ &Z_Construct_UFunction_AMainPlayerController_RemoveSecondIntroductionBox, "RemoveSecondIntroductionBox" }, // 3554932942
		{ &Z_Construct_UFunction_AMainPlayerController_RemoveThirdIntroductionBox, "RemoveThirdIntroductionBox" }, // 338762608
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MainPlayerController.h" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HUDOverlayAsset_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "/** Reference to the UMG asset in the editor */" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
		{ "ToolTip", "Reference to the UMG asset in the editor" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HUDOverlayAsset = { "HUDOverlayAsset", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, HUDOverlayAsset), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HUDOverlayAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HUDOverlayAsset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HudOverlay_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "/** Variable to hold the widget after creating it */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
		{ "ToolTip", "Variable to hold the widget after creating it" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HudOverlay = { "HudOverlay", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, HudOverlay), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HudOverlay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HudOverlay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WEnemyHealthBar_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "/** Reference to the enemy health bar asset in the editor */" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
		{ "ToolTip", "Reference to the enemy health bar asset in the editor" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WEnemyHealthBar = { "WEnemyHealthBar", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, WEnemyHealthBar), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WEnemyHealthBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WEnemyHealthBar_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_EnemyHealthBar_MetaData[] = {
		{ "Category", "Widgets" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_EnemyHealthBar = { "EnemyHealthBar", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, EnemyHealthBar), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_EnemyHealthBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_EnemyHealthBar_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WShieldHealthBar_MetaData[] = {
		{ "Category", "Widgets" },
		{ "Comment", "/** Reference to the shield health bar asset in the editor */" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
		{ "ToolTip", "Reference to the shield health bar asset in the editor" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WShieldHealthBar = { "WShieldHealthBar", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, WShieldHealthBar), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WShieldHealthBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WShieldHealthBar_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_ShieldHealthBar_MetaData[] = {
		{ "Category", "Widgets" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_ShieldHealthBar = { "ShieldHealthBar", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, ShieldHealthBar), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_ShieldHealthBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_ShieldHealthBar_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bHasShield_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bHasShield_SetBit(void* Obj)
	{
		((AMainPlayerController*)Obj)->bHasShield = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bHasShield = { "bHasShield", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMainPlayerController), &Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bHasShield_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bHasShield_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bHasShield_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WPauseMenu_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WPauseMenu = { "WPauseMenu", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, WPauseMenu), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WPauseMenu_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WPauseMenu_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_PauseMenu_MetaData[] = {
		{ "Category", "Widgets" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_PauseMenu = { "PauseMenu", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, PauseMenu), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_PauseMenu_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_PauseMenu_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WIntroductionMenu_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WIntroductionMenu = { "WIntroductionMenu", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, WIntroductionMenu), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WIntroductionMenu_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WIntroductionMenu_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_IntroductionMenu_MetaData[] = {
		{ "Category", "Widgets" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_IntroductionMenu = { "IntroductionMenu", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMainPlayerController, IntroductionMenu), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_IntroductionMenu_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_IntroductionMenu_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bIntroductionMenuVisible_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bIntroductionMenuVisible_SetBit(void* Obj)
	{
		((AMainPlayerController*)Obj)->bIntroductionMenuVisible = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bIntroductionMenuVisible = { "bIntroductionMenuVisible", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMainPlayerController), &Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bIntroductionMenuVisible_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bIntroductionMenuVisible_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bIntroductionMenuVisible_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_MoveDone_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AMainPlayerController_Statics::NewProp_MoveDone_SetBit(void* Obj)
	{
		((AMainPlayerController*)Obj)->MoveDone = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_MoveDone = { "MoveDone", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMainPlayerController), &Z_Construct_UClass_AMainPlayerController_Statics::NewProp_MoveDone_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_MoveDone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_MoveDone_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_RotateDone_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AMainPlayerController_Statics::NewProp_RotateDone_SetBit(void* Obj)
	{
		((AMainPlayerController*)Obj)->RotateDone = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_RotateDone = { "RotateDone", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMainPlayerController), &Z_Construct_UClass_AMainPlayerController_Statics::NewProp_RotateDone_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_RotateDone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_RotateDone_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_AttackDone_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AMainPlayerController_Statics::NewProp_AttackDone_SetBit(void* Obj)
	{
		((AMainPlayerController*)Obj)->AttackDone = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_AttackDone = { "AttackDone", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMainPlayerController), &Z_Construct_UClass_AMainPlayerController_Statics::NewProp_AttackDone_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_AttackDone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_AttackDone_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainPlayerController_Statics::NewProp_JumpDone_MetaData[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "MainPlayerController.h" },
	};
#endif
	void Z_Construct_UClass_AMainPlayerController_Statics::NewProp_JumpDone_SetBit(void* Obj)
	{
		((AMainPlayerController*)Obj)->JumpDone = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainPlayerController_Statics::NewProp_JumpDone = { "JumpDone", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMainPlayerController), &Z_Construct_UClass_AMainPlayerController_Statics::NewProp_JumpDone_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_JumpDone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::NewProp_JumpDone_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HUDOverlayAsset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_HudOverlay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WEnemyHealthBar,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_EnemyHealthBar,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WShieldHealthBar,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_ShieldHealthBar,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bHasShield,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WPauseMenu,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_PauseMenu,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_WIntroductionMenu,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_IntroductionMenu,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_bIntroductionMenuVisible,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_MoveDone,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_RotateDone,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_AttackDone,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainPlayerController_Statics::NewProp_JumpDone,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMainPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMainPlayerController_Statics::ClassParams = {
		&AMainPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMainPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMainPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMainPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMainPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMainPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMainPlayerController, 899266866);
	template<> FIRSTPROJECT_API UClass* StaticClass<AMainPlayerController>()
	{
		return AMainPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMainPlayerController(Z_Construct_UClass_AMainPlayerController, &AMainPlayerController::StaticClass, TEXT("/Script/FirstProject"), TEXT("AMainPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMainPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
