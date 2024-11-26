#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef min
#undef max
#undef GetCurrentTime

#include <mddbootstrap.h>
#include <windowsappsdk-versioninfo.h>
#include <winrt/base.h>
#include <winrt/microsoft.ui.xaml.h>

struct mddbootstapper {
  explicit mddbootstapper() noexcept {
    auto hr = MddBootstrapInitialize2(
        WINDOWSAPPSDK_RELEASE_MAJORMINOR, WINDOWSAPPSDK_RELEASE_VERSION_TAG_W,
        PACKAGE_VERSION{WINDOWSAPPSDK_RUNTIME_VERSION_UINT64},
        MddBootstrapInitializeOptions_OnNoMatch_ShowUI);

    if (FAILED(hr))
      std::abort();
  }
  mddbootstapper(mddbootstapper const &) = delete;
  mddbootstapper &operator=(mddbootstapper const &) = delete;
  ~mddbootstapper() { MddBootstrapShutdown(); }
};
