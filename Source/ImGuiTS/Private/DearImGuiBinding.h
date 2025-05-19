#pragma once

#include <imgui.h>
#include <imgui_toggle.h>

#include <string>

#include "CoreMinimal.h"
#include "Binding.hpp"
#include "UEDataBinding.hpp"
#include "Object.hpp"
#include "ImGuiTextureHandle.h"
#include "ImGuiModule.h"

#define MakeFunctionWithScriptTypePtr(M, ...)                               \
  [](::PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API::CallbackInfoType info) {                                     \
    ::puerts::FuncCallWrapper<PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API,   \
                              decltype(M), M, false,                        \
                              false>::callWithDefaultValues(info,           \
                                                            ##__VA_ARGS__); \
  },                                                                        \
      ::puerts::FuncCallWrapper<                                            \
          PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API, decltype(M), M, false,  \
          false>::info(puerts::Count(__VA_ARGS__))

#define MakeFunction_PtrRet(M, ...)                                        \
  [](::PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API::CallbackInfoType info) {                                    \
    ::puerts::FuncCallWrapper<PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API,  \
                              decltype(M), M,                              \
                              true>::callWithDefaultValues(info,           \
                                                           ##__VA_ARGS__); \
  },                                                                       \
      ::puerts::FuncCallWrapper<                                           \
          PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API, decltype(M), M,        \
          true>::info(puerts::Count(__VA_ARGS__))

#define MakeOverloadWithScriptTypePtr(SIGNATURE, M) \
  puerts::FuncCallWrapper<SIGNATURE, M, false, false>

#define DeclareOverload(Name, SIGNATURE, M, ...)                                  \
  template <>                                                                  \
  struct Name##PuertsOverloads<SIGNATURE> {                                    \
    static bool overloadCall(                                                  \
        ::PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API::CallbackInfoType info) { \
      return ::PUERTS_NAMESPACE::FuncCallWrapper<                              \
          PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API, SIGNATURE, M,            \
          true>::overloadCallWithDefaultValues(info, ##__VA_ARGS__);           \
    }                                                                          \
    static const ::PUERTS_NAMESPACE::CFunctionInfo* info() {                   \
      return ::PUERTS_NAMESPACE::FuncCallWrapper<                              \
          PUERTS_NAMESPACE::PUERTS_BINDING_IMPL::API, SIGNATURE,               \
          M>::info(PUERTS_NAMESPACE::Count(__VA_ARGS__));                      \
    }                                                                          \
  };
