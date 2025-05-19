#pragma once

#include <imgui.h>
#include <string>
#include "ImGuiModule.h"
#include "ImGuiTextureHandle.h"

namespace Wrapper {
static void Image(FImGuiTextureHandle tex_handle, const ImVec2& image_size,
                  const ImVec2& uv0, const ImVec2& uv1, const ImVec4&
                  tint_col, const ImVec4& border_col) {
  return ImGui::Image(tex_handle, image_size, uv0, uv1, tint_col,
  border_col);
}

static void Image(FImGuiTextureHandle tex_handle, const ImVec2& image_size) {
  return ImGui::Image(tex_handle, image_size);
}

static void Image(FImGuiTextureHandle tex_handle, const ImVec2& image_size,
                  const ImVec4& tint_col) {
  return ImGui::Image(tex_handle, image_size, ImVec2(0, 0), ImVec2(1, 1),
                      tint_col);
}

static FImGuiTextureHandle RegisterTexture(const FName& Name, UTexture*
Texture,
                                           bool bMakeUnique = false) {
  return FImGuiModule::Get().RegisterTexture(Name, Texture, bMakeUnique);
}

static void ReleaseTexture(const FImGuiTextureHandle& Handle) {
  return FImGuiModule::Get().ReleaseTexture(Handle);
}

static void ClearTextures() { FImGuiModule::Get().ClearTextures(); }

static FImGuiTextureHandle FindTextureHandle(const FName& Name) {
  return FImGuiModule::Get().FindTextureHandle(Name);
}

static bool ListBox(const char* label, int* current_item, void* items,
                    int items_count, int height_in_items) {
  return ImGui::ListBox(label, current_item, (const char* const*)items,
                        items_count, height_in_items);
}

struct InputTextCallback_UserData {
  std::string* Str;
  std::function<int(ImGuiInputTextCallbackData* data)> Callback;
  ImGuiInputTextFlags Flags;
};

static int InputTextCallback(ImGuiInputTextCallbackData* data) {
  FImGuiModule::Get().NotifyActiveImGuiInputText(data);
  InputTextCallback_UserData* user_data =
      (InputTextCallback_UserData*)data->UserData;
  if (data->EventFlag == ImGuiInputTextFlags_CallbackResize) {
    std::string* str = user_data->Str;
    IM_ASSERT(data->Buf == str->c_str());
    str->resize(data->BufTextLen);
    data->Buf = (char*)str->c_str();
    // } else if (user_data->Callback) {
    //   return user_data->Callback(data);
  }
  if ((user_data->Flags & data->EventFlag) == data->EventFlag) {
    if (user_data->Callback) {
      return user_data->Callback(data);
    }
  }
  return 0;
}

bool InputText(
    const char* label, std::string* str, ImGuiInputTextFlags flags = 0,
    std::function<int(ImGuiInputTextCallbackData* data)> callback = nullptr)
    {
  InputTextCallback_UserData cb_user_data;
  cb_user_data.Str = str;
  cb_user_data.Callback = callback;
  cb_user_data.Flags = flags;
  flags |= ImGuiInputTextFlags_CallbackResize;
  return ImGui::InputText(label, (char*)str->c_str(), str->capacity() + 1,
                          flags | ImGuiInputTextFlags_Callback,
                          InputTextCallback, &cb_user_data);
}

bool InputTextMultiline(
    const char* label, std::string* str, const ImVec2& size = ImVec2(0, 0),
    ImGuiInputTextFlags flags = 0,
    std::function<int(ImGuiInputTextCallbackData* data)> callback = nullptr)
    {
  InputTextCallback_UserData cb_user_data;
  cb_user_data.Str = str;
  cb_user_data.Callback = callback;
  cb_user_data.Flags = flags;
  flags |= ImGuiInputTextFlags_CallbackResize;
  return ImGui::InputTextMultiline(
      label, (char*)str->c_str(), str->capacity() + 1, size,
      flags | ImGuiInputTextFlags_Callback, InputTextCallback,
      &cb_user_data);
}

bool InputTextWithHint(
    const char* label, const char* hint, std::string* str,
    ImGuiInputTextFlags flags,
    std::function<int(ImGuiInputTextCallbackData* data)> callback = nullptr)
    {
  InputTextCallback_UserData cb_user_data;
  cb_user_data.Str = str;
  cb_user_data.Callback = callback;
  cb_user_data.Flags = flags;
  flags |= ImGuiInputTextFlags_CallbackResize;
  return ImGui::InputTextWithHint(
      label, hint, (char*)str->c_str(), str->capacity() + 1,
      flags | ImGuiInputTextFlags_Callback, InputTextCallback,
      &cb_user_data);
}
}  // namespace Wrapper
