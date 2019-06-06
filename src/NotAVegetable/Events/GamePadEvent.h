//
// Created by Muhamed Hassan on 2019-06-06.
//

#pragma once

#include "NotAVegetable/Events/Event.h"

#include <sstream>

namespace NotAVegetable {
    class GamePadEvent : public Event {
    public:
        inline int GetButtonCode() const {return m_ButtonCode;}

        EVENT_CLASS_CATEGORY(EventCategoryGamePad | EventCategoryInput)

    protected:
        GamePadEvent(int buttoncode)
            : m_ButtonCode(buttoncode) {}

        int m_ButtonCode;
    };

    class GamePadButtonPressedEvent : public GamePadEvent {
    public:
        GamePadButtonPressedEvent(int buttoncode, int repeatCount)
            : GamePadEvent(buttoncode) , m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "GamePadButtonPressedEvent: " << m_ButtonCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(GamePadPressed)

    private:
        int m_RepeatCount;
    };

    class GamePadButtonReleasedEvent : public GamePadEvent {
    public:
        GamePadButtonReleasedEvent(int buttoncode)
            : GamePadEvent(buttoncode) {}

         std::string ToString() const override {
            std::stringstream ss;
            ss << "GamePadButtonRleasedEvent: " << m_ButtonCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(GamePadReleased)
    };
}
