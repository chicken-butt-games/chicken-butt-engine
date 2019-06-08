//
// Created by Muhamed Hassan on 2019-06-06.
//

#pragma once

#include "NotAVegetable/Events/Event.h"


namespace NotAVegetable {
    class JoyStickEvent : public Event {
    public:
        inline int GetJoyStickID() const { return m_JoyStickID; }

        EVENT_CLASS_CATEGORY(EventCategoryJoyStick)

    protected:
        explicit JoyStickEvent(int jid)
                : m_JoyStickID(jid) {}

        int m_JoyStickID;
    };

    class JoyStickConnectedEvent : public JoyStickEvent {
    public:
        explicit JoyStickConnectedEvent(int jid)
                : JoyStickEvent(jid) {}


        std::string ToString() const override {
            std::stringstream ss;
            ss << "JoyStickConnectedEvent: " << m_JoyStickID;
            return ss.str();
        }

        EVENT_CLASS_TYPE(JoyStickConnected)

    };

    class JoyStickDisconnectedEvent : public JoyStickEvent {
    public:
        explicit JoyStickDisconnectedEvent(int jid)
                : JoyStickEvent(jid) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "JoyStickDisconnectedEvent: " << m_JoyStickID;
            return ss.str();
        }

        EVENT_CLASS_TYPE(JoyStickDisconnected)

    };
}
