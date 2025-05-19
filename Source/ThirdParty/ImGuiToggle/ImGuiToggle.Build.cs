using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;

public class ImGuiToggle : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
	public ImGuiToggle(ReadOnlyTargetRules Target) : base(Target)
#else
	public ImGuiToggle(TargetInfo Target)
#endif
	{
        Type = ModuleType.External;
	}
}
