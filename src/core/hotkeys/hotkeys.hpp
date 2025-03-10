#pragma once
#pragma push_macro("max")
#pragma push_macro("min")
#undef min
#undef max
#include <libremidi/libremidi.hpp>
#pragma pop_macro("min")
#pragma pop_macro("max")

#include "keys.hpp"
#include <atomic>
#include <string>
#include <vector>

namespace Soundux
{
    namespace Objects
    {
        class Hotkeys
        {
            libremidi::midi_in midi;

          protected:
            Hotkeys() = default;
            virtual void setup();

          protected:
            std::vector<Key> pressedKeys;
            std::atomic<bool> shouldNotify = false;
            std::atomic<bool> shouldNotifyKnob = false;

          public:
            static std::shared_ptr<Hotkeys> createInstance();

          public:
            virtual void notify(bool);
            virtual void requestKnob(bool);

            virtual void onKeyUp(const Key &);
            virtual void onKeyDown(const Key &);

            virtual void pressKeys(const std::vector<Key> &) = 0;
            virtual void releaseKeys(const std::vector<Key> &) = 0;

            virtual std::string getKeyName(const Key &);
            virtual std::string getKeySequence(const std::vector<Key> &);
        };
    } // namespace Objects
} // namespace Soundux