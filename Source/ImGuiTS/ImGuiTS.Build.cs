// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ImGuiTS : ModuleRules
{
    public ImGuiTS(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;

        PublicIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "../ThirdParty/ImGuiLibrary/Include"),
                Path.Combine(ModuleDirectory, "../ThirdParty/ImPlotLibrary/Public"),
				// Path.Combine(ModuleDirectory, "../ThirdParty/ImCoolBar/Public"),
				Path.Combine(ModuleDirectory, "../ThirdParty/ImGuiToggle/Public"),
                Path.Combine(ModuleDirectory, "../ThirdParty/ImGuiNotify/Public"),
			    // ... add public include paths required here ...
		    }
            );

        PrivateIncludePaths.AddRange(
            new string[] {
                "ThirdParty/ImGuiLibrary/Private",
                "ThirdParty/ImPlotLibrary/Private",
				// "ThirdParty/ImCoolBar/Private",
				"ThirdParty/ImGuiToggle/Private",
			    // ... add other private include paths required here ...
		    }
            );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
			    // ... add other public dependencies that you statically link with here ...
		    }
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "ImGui",
                "JsEnv",
			    // ... add private dependencies that you statically link with here ...
		    }
            );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
			    // ... add any modules that your module loads dynamically here ...
		    }
            );

        if (Target.bBuildEditor)
        {
        }

        bEnableUndefinedIdentifierWarnings = false;
    }
}