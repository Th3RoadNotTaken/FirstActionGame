// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMain;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef FIRSTPROJECT_Shield_generated_h
#error "Shield.generated.h already included, missing '#pragma once' in Shield.h"
#endif
#define FIRSTPROJECT_Shield_generated_h

#define FirstProject_Source_FirstProject_Shield_h_24_SPARSE_DATA
#define FirstProject_Source_FirstProject_Shield_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDeactivateCollision); \
	DECLARE_FUNCTION(execActivateCollision); \
	DECLARE_FUNCTION(execEquip); \
	DECLARE_FUNCTION(execShieldOnOverlapEnd); \
	DECLARE_FUNCTION(execShieldOnOverlapBegin);


#define FirstProject_Source_FirstProject_Shield_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDeactivateCollision); \
	DECLARE_FUNCTION(execActivateCollision); \
	DECLARE_FUNCTION(execEquip); \
	DECLARE_FUNCTION(execShieldOnOverlapEnd); \
	DECLARE_FUNCTION(execShieldOnOverlapBegin);


#define FirstProject_Source_FirstProject_Shield_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShield(); \
	friend struct Z_Construct_UClass_AShield_Statics; \
public: \
	DECLARE_CLASS(AShield, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstProject"), NO_API) \
	DECLARE_SERIALIZER(AShield)


#define FirstProject_Source_FirstProject_Shield_h_24_INCLASS \
private: \
	static void StaticRegisterNativesAShield(); \
	friend struct Z_Construct_UClass_AShield_Statics; \
public: \
	DECLARE_CLASS(AShield, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstProject"), NO_API) \
	DECLARE_SERIALIZER(AShield)


#define FirstProject_Source_FirstProject_Shield_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShield(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShield) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShield); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShield); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShield(AShield&&); \
	NO_API AShield(const AShield&); \
public:


#define FirstProject_Source_FirstProject_Shield_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShield(AShield&&); \
	NO_API AShield(const AShield&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShield); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShield); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShield)


#define FirstProject_Source_FirstProject_Shield_h_24_PRIVATE_PROPERTY_OFFSET
#define FirstProject_Source_FirstProject_Shield_h_21_PROLOG
#define FirstProject_Source_FirstProject_Shield_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FirstProject_Source_FirstProject_Shield_h_24_PRIVATE_PROPERTY_OFFSET \
	FirstProject_Source_FirstProject_Shield_h_24_SPARSE_DATA \
	FirstProject_Source_FirstProject_Shield_h_24_RPC_WRAPPERS \
	FirstProject_Source_FirstProject_Shield_h_24_INCLASS \
	FirstProject_Source_FirstProject_Shield_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FirstProject_Source_FirstProject_Shield_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FirstProject_Source_FirstProject_Shield_h_24_PRIVATE_PROPERTY_OFFSET \
	FirstProject_Source_FirstProject_Shield_h_24_SPARSE_DATA \
	FirstProject_Source_FirstProject_Shield_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FirstProject_Source_FirstProject_Shield_h_24_INCLASS_NO_PURE_DECLS \
	FirstProject_Source_FirstProject_Shield_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FIRSTPROJECT_API UClass* StaticClass<class AShield>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FirstProject_Source_FirstProject_Shield_h


#define FOREACH_ENUM_ESHIELDSTATE(op) \
	op(EShieldState::EWS_Pickup) \
	op(EShieldState::EWS_Equipped) 

enum class EShieldState : uint8;
template<> FIRSTPROJECT_API UEnum* StaticEnum<EShieldState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
