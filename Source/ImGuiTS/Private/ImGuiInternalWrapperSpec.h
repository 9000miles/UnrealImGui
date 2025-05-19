#pragma once

#include <imgui.h>

#ifndef GImGui
#define GImGui (ImGui::GetCurrentContext())
#endif

#include <imgui_internal.h>

#include "ImGuiModule.h"
#include "ImGuiTextureHandle.h"

namespace Wrapper {
static void ImageRounded(FImGuiTextureHandle tex_handle,
                         const ImVec2& image_size, float rounding = 5,
                         ImDrawFlags flags = ImDrawFlags_RoundCornersAll) {
  auto ScrollPos = ImVec2(ImGui::GetScrollX(), ImGui::GetScrollY());
  auto WindowPos = ImGui::GetWindowPos();
  auto CursorPos = ImGui::GetCursorPos() + WindowPos - ScrollPos;
  const ImRect bb(CursorPos, CursorPos + image_size);
  ImGui::ItemSize(bb);
  if (!ImGui::ItemAdd(bb, 0)) return;
  auto DrawList = ImGui::GetWindowDrawList();
  DrawList->AddImageRounded(
      tex_handle, CursorPos, CursorPos + image_size, ImVec2(0, 0), ImVec2(1, 1),
      ImGui::GetColorU32(ImVec4(1, 1, 1, 1)), rounding, flags);
}
};  // namespace ImGuiInternal
