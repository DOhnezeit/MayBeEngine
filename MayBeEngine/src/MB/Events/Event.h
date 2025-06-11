#pragma once

#include "MB/Core.h"

namespace MB
{
	// Currently, events are blocking, meaning that events must be handled immediately
	// Later I want to buffer events in an event queue and process them during the event part of the update stage

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }						\
								virtual EventType GetEventType() const override { return GetStaticType(); }		\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class MB_API Event
	{

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) const
		{
			return GetCategoryFlags() & category; // Bitwise AND operation to check if the category is set
		}
	protected:
		bool m_Handled = false; // If the event has been handled, it will not be processed again
	};

	template<typename T>
	concept EventConcept = requires 
	{
		std::derived_from<T, Event>;
		{ T::GetStaticType() } -> std::convertible_to<EventType>;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<EventConcept T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event; // Reference to the event being dispatched
		bool m_Handled = false; // If the event has been handled, it will not be processed again
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString(); // Output the string representation of the event
	}
}