// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DarkerNodesSettings.h"

#ifdef DARKERNODES_DarkerNodesSettings_generated_h
#error "DarkerNodesSettings.generated.h already included, missing '#pragma once' in DarkerNodesSettings.h"
#endif
#define DARKERNODES_DarkerNodesSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDarkerNodesSettings *****************************************************
struct Z_Construct_UClass_UDarkerNodesSettings_Statics;
DARKERNODES_API UClass* Z_Construct_UClass_UDarkerNodesSettings_NoRegister();

#define FID_Users_Felix_Documents_Unreal_Projects_UE57_Plugins_DarkerNodes_5_7_DarkerNodes_Source_DarkerNodes_Public_DarkerNodesSettings_h_103_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDarkerNodesSettings(); \
	friend struct ::Z_Construct_UClass_UDarkerNodesSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DARKERNODES_API UClass* ::Z_Construct_UClass_UDarkerNodesSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UDarkerNodesSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DarkerNodes"), Z_Construct_UClass_UDarkerNodesSettings_NoRegister) \
	DECLARE_SERIALIZER(UDarkerNodesSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_Users_Felix_Documents_Unreal_Projects_UE57_Plugins_DarkerNodes_5_7_DarkerNodes_Source_DarkerNodes_Public_DarkerNodesSettings_h_103_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDarkerNodesSettings(UDarkerNodesSettings&&) = delete; \
	UDarkerNodesSettings(const UDarkerNodesSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDarkerNodesSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDarkerNodesSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDarkerNodesSettings) \
	NO_API virtual ~UDarkerNodesSettings();


#define FID_Users_Felix_Documents_Unreal_Projects_UE57_Plugins_DarkerNodes_5_7_DarkerNodes_Source_DarkerNodes_Public_DarkerNodesSettings_h_100_PROLOG
#define FID_Users_Felix_Documents_Unreal_Projects_UE57_Plugins_DarkerNodes_5_7_DarkerNodes_Source_DarkerNodes_Public_DarkerNodesSettings_h_103_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Felix_Documents_Unreal_Projects_UE57_Plugins_DarkerNodes_5_7_DarkerNodes_Source_DarkerNodes_Public_DarkerNodesSettings_h_103_INCLASS_NO_PURE_DECLS \
	FID_Users_Felix_Documents_Unreal_Projects_UE57_Plugins_DarkerNodes_5_7_DarkerNodes_Source_DarkerNodes_Public_DarkerNodesSettings_h_103_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDarkerNodesSettings;

// ********** End Class UDarkerNodesSettings *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Felix_Documents_Unreal_Projects_UE57_Plugins_DarkerNodes_5_7_DarkerNodes_Source_DarkerNodes_Public_DarkerNodesSettings_h

// ********** Begin Enum EPresets ******************************************************************
#define FOREACH_ENUM_EPRESETS(op) \
	op(EPresets::SelectPreset) \
	op(EPresets::Coolest) \
	op(EPresets::Cooler) \
	op(EPresets::Cool) \
	op(EPresets::Default) \
	op(EPresets::Warm) \
	op(EPresets::Warmer) \
	op(EPresets::Warmest) \
	op(EPresets::CoolLight) \
	op(EPresets::DefaultLight) \
	op(EPresets::WarmLight) 

enum class EPresets : uint8;
template<> struct TIsUEnumClass<EPresets> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EPresets>();
// ********** End Enum EPresets ********************************************************************

// ********** Begin Enum EHeaderStyle **************************************************************
#define FOREACH_ENUM_EHEADERSTYLE(op) \
	op(EHeaderStyle::Gradient) \
	op(EHeaderStyle::Plain) \
	op(EHeaderStyle::Outline) 

enum class EHeaderStyle : uint8;
template<> struct TIsUEnumClass<EHeaderStyle> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EHeaderStyle>();
// ********** End Enum EHeaderStyle ****************************************************************

// ********** Begin Enum EButtonPadding ************************************************************
#define FOREACH_ENUM_EBUTTONPADDING(op) \
	op(EButtonPadding::None) \
	op(EButtonPadding::Small) \
	op(EButtonPadding::Normal) \
	op(EButtonPadding::Big) 

enum class EButtonPadding : uint8;
template<> struct TIsUEnumClass<EButtonPadding> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EButtonPadding>();
// ********** End Enum EButtonPadding **************************************************************

// ********** Begin Enum EButtonBorder *************************************************************
#define FOREACH_ENUM_EBUTTONBORDER(op) \
	op(EButtonBorder::None) \
	op(EButtonBorder::Dark) \
	op(EButtonBorder::Light) 

enum class EButtonBorder : uint8;
template<> struct TIsUEnumClass<EButtonBorder> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EButtonBorder>();
// ********** End Enum EButtonBorder ***************************************************************

// ********** Begin Enum EFontFamily ***************************************************************
#define FOREACH_ENUM_EFONTFAMILY(op) \
	op(EFontFamily::BalsamiqSans) \
	op(EFontFamily::Cannonade) \
	op(EFontFamily::CaskaydiaCove) \
	op(EFontFamily::EudoxusSans) \
	op(EFontFamily::GolosUI) \
	op(EFontFamily::Jua) \
	op(EFontFamily::Junction) \
	op(EFontFamily::NewTelegraph) \
	op(EFontFamily::Roboto) \
	op(EFontFamily::XXIIAven) 

enum class EFontFamily : uint8;
template<> struct TIsUEnumClass<EFontFamily> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EFontFamily>();
// ********** End Enum EFontFamily *****************************************************************

// ********** Begin Enum EFontSize *****************************************************************
#define FOREACH_ENUM_EFONTSIZE(op) \
	op(EFontSize::Small) \
	op(EFontSize::Normal) \
	op(EFontSize::Big) \
	op(EFontSize::Bigger) 

enum class EFontSize : uint8;
template<> struct TIsUEnumClass<EFontSize> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EFontSize>();
// ********** End Enum EFontSize *******************************************************************

// ********** Begin Enum EBlueprintVarNodeLine *****************************************************
#define FOREACH_ENUM_EBLUEPRINTVARNODELINE(op) \
	op(EBlueprintVarNodeLine::Thin) \
	op(EBlueprintVarNodeLine::Thick) 

enum class EBlueprintVarNodeLine : uint8;
template<> struct TIsUEnumClass<EBlueprintVarNodeLine> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EBlueprintVarNodeLine>();
// ********** End Enum EBlueprintVarNodeLine *******************************************************

// ********** Begin Enum EBlueprintVarNodeStyle ****************************************************
#define FOREACH_ENUM_EBLUEPRINTVARNODESTYLE(op) \
	op(EBlueprintVarNodeStyle::DarkSolid) \
	op(EBlueprintVarNodeStyle::LightSolid) \
	op(EBlueprintVarNodeStyle::DarkGlass) \
	op(EBlueprintVarNodeStyle::LightGlass) 

enum class EBlueprintVarNodeStyle : uint8;
template<> struct TIsUEnumClass<EBlueprintVarNodeStyle> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EBlueprintVarNodeStyle>();
// ********** End Enum EBlueprintVarNodeStyle ******************************************************

// ********** Begin Enum EIconStyle ****************************************************************
#define FOREACH_ENUM_EICONSTYLE(op) \
	op(EIconStyle::Line) \
	op(EIconStyle::Solid) 

enum class EIconStyle : uint8;
template<> struct TIsUEnumClass<EIconStyle> { enum { Value = true }; };
template<> DARKERNODES_NON_ATTRIBUTED_API UEnum* StaticEnum<EIconStyle>();
// ********** End Enum EIconStyle ******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
