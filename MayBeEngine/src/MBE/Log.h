#pragma once  

#include <memory>  

#include "Core.h"  
#include "spdlog/spdlog.h"  

namespace MBE  
{  
	class MBE_API Log  
	{  
	public:  
		static void Init();  

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }  
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }  

	private:  
		static std::shared_ptr<spdlog::logger> s_CoreLogger;  
		static std::shared_ptr<spdlog::logger> s_ClientLogger;  
	};  
}  

// Core log macros  
#define MBE_CORE_TRACE(...)     ::MBE::Log::GetCoreLogger()->trace(__VA_ARGS__)  
#define MBE_CORE_INFO(...)      ::MBE::Log::GetCoreLogger()->info(__VA_ARGS__)  
#define MBE_CORE_WARN(...)      ::MBE::Log::GetCoreLogger()->warn(__VA_ARGS__)  
#define MBE_CORE_ERROR(...)     ::MBE::Log::GetCoreLogger()->error(__VA_ARGS__)  
#define MBE_CORE_FATAL(...)		::MBE::Log::GetCoreLogger()->fatal(__VA_ARGS__)  

// Client log macros  
#define MBE_TRACE(...)          ::MBE::Log::GetClientLogger()->trace(__VA_ARGS__)  
#define MBE_INFO(...)           ::MBE::Log::GetClientLogger()->info(__VA_ARGS__)  
#define MBE_WARN(...)           ::MBE::Log::GetClientLogger()->warn(__VA_ARGS__)  
#define MBE_ERROR(...)          ::MBE::Log::GetClientLogger()->error(__VA_ARGS__)  
#define MBE_FATAL(...)          ::MBE::Log::GetClientLogger()->fatal(__VA_ARGS__)
