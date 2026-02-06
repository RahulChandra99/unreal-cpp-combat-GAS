// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Lib/BrushDatabase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBrushDatabase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DARKERNODES_API UClass* Z_Construct_UClass_UBrushDatabase();
DARKERNODES_API UClass* Z_Construct_UClass_UBrushDatabase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
UPackage* Z_Construct_UPackage__Script_DarkerNodes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBrushDatabase ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBrushDatabase;
UClass* UBrushDatabase::GetPrivateStaticClass()
{
	using TClass = UBrushDatabase;
	if (!Z_Registration_Info_UClass_UBrushDatabase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BrushDatabase"),
			Z_Registration_Info_UClass_UBrushDatabase.InnerSingleton,
			StaticRegisterNativesUBrushDatabase,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UBrushDatabase.InnerSingleton;
}
UClass* Z_Construct_UClass_UBrushDatabase_NoRegister()
{
	return UBrushDatabase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBrushDatabase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Lib/BrushDatabase.h" },
		{ "ModuleRelativePath", "Private/Lib/BrushDatabase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Materials_MetaData[] = {
		{ "ModuleRelativePath", "Private/Lib/BrushDatabase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicMaterials_MetaData[] = {
		{ "ModuleRelativePath", "Private/Lib/BrushDatabase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UBrushDatabase constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Materials_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Materials_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Materials;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicMaterials_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DynamicMaterials_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DynamicMaterials;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UBrushDatabase constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBrushDatabase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBrushDatabase_Statics

// ********** Begin Class UBrushDatabase Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBrushDatabase_Statics::NewProp_Materials_ValueProp = { "Materials", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UBrushDatabase_Statics::NewProp_Materials_Key_KeyProp = { "Materials_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UBrushDatabase_Statics::NewProp_Materials = { "Materials", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBrushDatabase, Materials), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Materials_MetaData), NewProp_Materials_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBrushDatabase_Statics::NewProp_DynamicMaterials_ValueProp = { "DynamicMaterials", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UBrushDatabase_Statics::NewProp_DynamicMaterials_Key_KeyProp = { "DynamicMaterials_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UBrushDatabase_Statics::NewProp_DynamicMaterials = { "DynamicMaterials", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBrushDatabase, DynamicMaterials), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicMaterials_MetaData), NewProp_DynamicMaterials_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBrushDatabase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBrushDatabase_Statics::NewProp_Materials_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBrushDatabase_Statics::NewProp_Materials_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBrushDatabase_Statics::NewProp_Materials,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBrushDatabase_Statics::NewProp_DynamicMaterials_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBrushDatabase_Statics::NewProp_DynamicMaterials_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBrushDatabase_Statics::NewProp_DynamicMaterials,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBrushDatabase_Statics::PropPointers) < 2048);
// ********** End Class UBrushDatabase Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UBrushDatabase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DarkerNodes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBrushDatabase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBrushDatabase_Statics::ClassParams = {
	&UBrushDatabase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UBrushDatabase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UBrushDatabase_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBrushDatabase_Statics::Class_MetaDataParams), Z_Construct_UClass_UBrushDatabase_Statics::Class_MetaDataParams)
};
void UBrushDatabase::StaticRegisterNativesUBrushDatabase()
{
}
UClass* Z_Construct_UClass_UBrushDatabase()
{
	if (!Z_Registration_Info_UClass_UBrushDatabase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBrushDatabase.OuterSingleton, Z_Construct_UClass_UBrushDatabase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBrushDatabase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBrushDatabase);
UBrushDatabase::~UBrushDatabase() {}
// ********** End Class UBrushDatabase *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_unreal_cpp_combat_GAS_Plugins_DarkerNodes_Source_DarkerNodes_Private_Lib_BrushDatabase_h__Script_DarkerNodes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBrushDatabase, UBrushDatabase::StaticClass, TEXT("UBrushDatabase"), &Z_Registration_Info_UClass_UBrushDatabase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBrushDatabase), 1898075896U) },
	};
}; // Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_unreal_cpp_combat_GAS_Plugins_DarkerNodes_Source_DarkerNodes_Private_Lib_BrushDatabase_h__Script_DarkerNodes_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_unreal_cpp_combat_GAS_Plugins_DarkerNodes_Source_DarkerNodes_Private_Lib_BrushDatabase_h__Script_DarkerNodes_2891466885{
	TEXT("/Script/DarkerNodes"),
	Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_unreal_cpp_combat_GAS_Plugins_DarkerNodes_Source_DarkerNodes_Private_Lib_BrushDatabase_h__Script_DarkerNodes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_unreal_cpp_combat_GAS_Plugins_DarkerNodes_Source_DarkerNodes_Private_Lib_BrushDatabase_h__Script_DarkerNodes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
