#pragma once  

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#include <memory>  

#include "Core.h"  
#include "spdlog/spdlog.h" 

namespace MB  
{  
	class MB_API Log  
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
#define MB_CORE_TRACE(...)     ::MB::Log::GetCoreLogger()->trace(__VA_ARGS__)  
#define MB_CORE_INFO(...)      ::MB::Log::GetCoreLogger()->info(__VA_ARGS__)  
#define MB_CORE_WARN(...)      ::MB::Log::GetCoreLogger()->warn(__VA_ARGS__)  
#define MB_CORE_ERROR(...)     ::MB::Log::GetCoreLogger()->error(__VA_ARGS__)  
#define MB_CORE_CRITICAL(...)  ::MB::Log::GetCoreLogger()->critical(__VA_ARGS__)  

// Client log macros  
#define MB_TRACE(...)          ::MB::Log::GetClientLogger()->trace(__VA_ARGS__)  
#define MB_INFO(...)           ::MB::Log::GetClientLogger()->info(__VA_ARGS__)  
#define MB_WARN(...)           ::MB::Log::GetClientLogger()->warn(__VA_ARGS__)  
#define MB_ERROR(...)          ::MB::Log::GetClientLogger()->error(__VA_ARGS__)  
#define MB_CRITICAL(...)       ::MB::Log::GetClientLogger()->critical(__VA_ARGS__)







#ifdef _MSC_VER
#pragma warning(pop)
#endif