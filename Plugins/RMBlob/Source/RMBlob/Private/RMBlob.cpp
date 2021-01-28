// Copyright Epic Games, Inc. All Rights Reserved.

#include "RMBlob.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FRMBlobModule"

void FRMBlobModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString PluginBaseDirectory = IPluginManager::Get().FindPlugin(FString(TEXT("RMBlob")))->GetBaseDir();
	FString ShaderDiretory = FPaths::Combine(PluginBaseDirectory, TEXT("Shaders"));

	FString VirtualShaderDirectory = FString::Printf(TEXT("/Plugin/%s"), *FString(TEXT("RMBlob")) );
	AddShaderSourceDirectoryMapping(VirtualShaderDirectory, ShaderDiretory);

}

void FRMBlobModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRMBlobModule, RMBlob)