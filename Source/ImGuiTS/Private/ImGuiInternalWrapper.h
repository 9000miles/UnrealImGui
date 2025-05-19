#pragma once

#include <imgui.h>

#ifndef GImGui
#define GImGui (ImGui::GetCurrentContext())
#endif

#include <imgui_internal.h>
#include <imspinner.h>
#include <ImGuiNotify.hpp>

namespace Wrapper {

// static void ImageRounded(FImGuiTextureHandle tex_handle,
//                          const ImVec2& image_size, float rounding = 5,
//                          ImDrawFlags flags = ImDrawFlags_RoundCornersAll) {
//   auto ScrollPos = ImVec2(ImGui::GetScrollX(), ImGui::GetScrollY());
//   auto WindowPos = ImGui::GetWindowPos();
//   auto CursorPos = ImGui::GetCursorPos() + WindowPos - ScrollPos;
//   const ImRect bb(CursorPos, CursorPos + image_size);
//   ImGui::ItemSize(bb);
//   if (!ImGui::ItemAdd(bb, 0)) return;
//   auto DrawList = ImGui::GetWindowDrawList();
//   DrawList->AddImageRounded(
//       tex_handle, CursorPos, CursorPos + image_size, ImVec2(0, 0), ImVec2(1, 1),
//       ImGui::GetColorU32(ImVec4(1, 1, 1, 1)), rounding, flags);
// }

static void ColorDummy(const ImVec2& size,
                       const ImVec4& col = ImVec4(0, 0, 0, 1),
                       float rounding = 5,
                       ImDrawFlags flags = ImDrawFlags_RoundCornersAll) {
  auto pos_min = ImGui::GetCursorPos() + ImGui::GetWindowPos();
  auto pos_max = pos_min + size;
  const ImRect bb(pos_min, pos_max);
  ImGui::ItemSize(bb);
  if (!ImGui::ItemAdd(bb, 0)) return;
  auto DrawList = ImGui::GetWindowDrawList();
  DrawList->AddRectFilled(pos_min, pos_max, ImGui::GetColorU32(col), rounding,
                          flags);
}

static ImVec2 GetWindowPosByName(const std::string& name) {
  auto window = ImGui::FindWindowByName(name.c_str());
  if (window == nullptr) {
    return ImVec2(0, 0);
  }
  return window->Pos;
}

static ImVec2 GetWindowSizeByName(const std::string& name) {
  auto window = ImGui::FindWindowByName(name.c_str());
  if (window == nullptr) {
    return ImVec2(0, 0);
  }
  return window->Size;
}

static bool FindWindowByName(const std::string& name) {
  auto window = ImGui::FindWindowByName(name.c_str());
  return window != nullptr;
}
static void SpinnerRainbowBalls(const char* label, float radius,
                                float thickness, const ImVec4& color,
                                float speed, int balls = 5) {
  ImSpinner::SpinnerRainbowBalls(label, radius, thickness,
                                 ImGui::GetColorU32(color), speed, balls);
}

static ImVec2 GetCentralNodePos(ImGuiID node_id) {
  ImGuiDockNode* central_node = ImGui::DockBuilderGetCentralNode(node_id);
  if (!central_node) {
    return ImVec2(0, 0);
  }
  return central_node->Pos;
}

static ImVec2 GetCentralNodeSize(ImGuiID node_id) {
  ImGuiDockNode* central_node = ImGui::DockBuilderGetCentralNode(node_id);
  if (!central_node) {
    return ImVec2(0, 0);
  }
  return central_node->Size;
}

static void InsertNotification(int type, const std::string& content,
                               float seconds = NOTIFY_DEFAULT_DISMISS / 1000.f,
                               const std::string& title = "") {
  ImGuiToast toast((ImGuiToastType)type, static_cast<int>(seconds * 1000));
  if (title != "") {
    toast.setTitle(title.c_str());
  }
  toast.setContent(content.c_str());
  ImGui::InsertNotification(toast);
}

static void RenderNotifications() { ImGui::RenderNotifications(); }
static void SetNotifyViewportSize(const ImVec2& size) {
  ImGui::SetNotifyViewportSize(size);
}

static void SetNotifyViewportPos(const ImVec2& pos) {
  ImGui::SetNotifyViewportPos(pos);
}

struct DockID {
  ImGuiID id_at_dir;
  ImGuiID id_at_opposite_dir;
  DockID() {}
};

void DockBuilderDockWindow(std::string window_name, ImGuiID node_id) {
  return ImGui::DockBuilderDockWindow(window_name.c_str(), node_id);
}
ImGuiID DockBuilderSplitNode(ImGuiID node_id, ImGuiDir split_dir,
                             float size_ratio, DockID* dockid) {
  return ImGui::DockBuilderSplitNode(node_id, split_dir, size_ratio,
                                     &dockid->id_at_dir,
                                     &dockid->id_at_opposite_dir);
}
void SetColor(int Col, ImVec4 Color) { ImGui::GetStyle().Colors[Col] = Color; }

};  // namespace Wrapper
