#include "Babylon/RuntimeApple.h"
#include "RuntimeImpl.h"
#include "NativeEngine.h"

namespace Babylon
{

    RuntimeApple::RuntimeApple(void* nativeWindowPtr)
        : RuntimeApple{nativeWindowPtr, "."} // todo : use parent module path. std::filesystem or std::experimental::filesystem not supported
    {
    }

    RuntimeApple::RuntimeApple(void* nativeWindowPtr, const std::string& rootUrl)
        : Runtime{std::make_unique<RuntimeImpl>(nativeWindowPtr, rootUrl)}
    {
        NativeEngine::InitializeDeviceContext(nativeWindowPtr, 32, 32);
    }

    void RuntimeImpl::ThreadProcedure()
    {
        RuntimeImpl::BaseThreadProcedure();
    }
}
