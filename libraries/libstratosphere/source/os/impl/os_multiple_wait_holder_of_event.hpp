/*
 * Copyright (c) Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include "os_multiple_wait_holder_base.hpp"
#include "os_multiple_wait_object_list.hpp"

namespace ams::os::impl {

    class MultiWaitHolderOfEvent : public MultiWaitHolderOfUserObject {
        private:
            EventType *m_event;
        private:
            TriBool IsSignaledImpl() const {
                return m_event->signaled ? TriBool::True : TriBool::False;
            }
        public:
            explicit MultiWaitHolderOfEvent(EventType *e) : m_event(e) { /* ... */ }

            /* IsSignaled, Link, Unlink implemented. */
            virtual TriBool IsSignaled() const override {
                std::scoped_lock lk(GetReference(m_event->cs_event));
                return this->IsSignaledImpl();
            }

            virtual TriBool LinkToObjectList() override {
                std::scoped_lock lk(GetReference(m_event->cs_event));

                GetReference(m_event->multi_wait_object_list_storage).LinkMultiWaitHolder(*this);
                return this->IsSignaledImpl();
            }

            virtual void UnlinkFromObjectList() override {
                std::scoped_lock lk(GetReference(m_event->cs_event));

                GetReference(m_event->multi_wait_object_list_storage).UnlinkMultiWaitHolder(*this);
            }
    };

}
