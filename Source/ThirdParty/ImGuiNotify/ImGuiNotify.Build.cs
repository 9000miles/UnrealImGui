using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;

public class ImGuiNotify : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
	public ImGuiNotify(ReadOnlyTargetRules Target) : base(Target)
#else
	public ImGuiNotify(TargetInfo Target)
#endif
	{
        Type = ModuleType.External;
	}
}
