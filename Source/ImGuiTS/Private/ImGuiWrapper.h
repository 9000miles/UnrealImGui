#pragma once

#include <imgui.h>
#include <imgui_toggle.h>
#include <string>

namespace Wrapper {

static bool Toggle(const char* label, bool* v, ImGuiToggleFlags flags,
                   float animation_duration, float frame_rounding,
                   float knob_rounding, const ImVec2& size = ImVec2()) {
  return ImGui::Toggle(label, v, flags, animation_duration, frame_rounding,
                       knob_rounding, size);
}

static void SetNextWindowSizeConstraints(const ImVec2& size_min,
                                         const ImVec2& size_max) {
  return ImGui::SetNextWindowSizeConstraints(size_min, size_max);
}

static void Bg(const ImVec2& image_size, const ImVec4& tint_col,
               float rounding) {
  auto DrawList = ImGui::GetWindowDrawList();
  auto RectMin = ImGui::GetWindowPos();
  auto RectMax = RectMin + ImGui::GetContentRegionAvail();
  DrawList->AddRectFilled(RectMin, RectMax, ImGui::GetColorU32(tint_col),
                          rounding, ImDrawFlags_RoundCornersAll);
  // return ImGui::Image(nullptr, image_size, ImVec2(0, 0), ImVec2(1, 1),
  // tint_col);
}

static void Shadow(const ImVec2& image_size, const ImVec4& tint_col,
                   float rounding, float thickness) {
  auto DrawList = ImGui::GetWindowDrawList();
  auto RectMin = ImGui::GetWindowPos();
  auto RectMax = RectMin + ImGui::GetContentRegionAvail();
  DrawList->AddRect(RectMin, RectMax, ImGui::GetColorU32(tint_col), rounding,
                    ImDrawFlags_RoundCornersAll, thickness);
}

static std::string GetPayloadData(const ImGuiPayload* payload) {
  if (payload == nullptr) {
    return std::string();
  }
  return std::string((char*)payload->Data, payload->DataSize);
}

static void SetDragDropPayload(std::string type, const std::string& data) {
  ImGui::SetDragDropPayload(type.c_str(), (void*) data.data(), data.size());
}

static void SetScrollX(float scroll_x) {
  ImGui::SetScrollX(scroll_x);
}

static void SetScrollY(float scroll_y) {
  ImGui::SetScrollY(scroll_y);
}

static bool IsKeyDown(int key) {
  return ImGui::IsKeyDown((ImGuiKey)key);
}
static bool IsKeyPressed(int key, bool repeat) {
  return ImGui::IsKeyPressed((ImGuiKey)key, repeat);
}
static bool IsKeyReleased(int key) {
  return ImGui::IsKeyReleased((ImGuiKey)key);
}
static bool IsMouseDown(ImGuiMouseButton button) {
  return ImGui::IsMouseDown(button);
}
static bool IsMouseClicked(ImGuiMouseButton button, bool repeat) {
  return ImGui::IsMouseClicked(button, repeat);
}
static bool IsMouseReleased(ImGuiMouseButton button) {
  return ImGui::IsMouseReleased(button);
}
static bool IsMouseDoubleClicked(ImGuiMouseButton button) {
  return ImGui::IsMouseDoubleClicked(button);
}

static ImVec2 CalcTextSize(std::string text, std::string text_end, bool hide_text_after_double_hash, float wrap_width) {
  return ImGui::CalcTextSize(text.c_str(), text_end == "" ? NULL : text_end.c_str(), hide_text_after_double_hash, wrap_width);
}
}  // namespace Wrapper
