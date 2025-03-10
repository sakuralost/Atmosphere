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
#include <vapours.hpp>
#include <stratosphere/os/impl/os_internal_critical_section.hpp>

namespace ams::os {

    struct ThreadType;

    struct MutexType {
        enum State {
            State_NotInitialized = 0,
            State_Initialized    = 1,
        };

        u8 state;
        bool is_recursive;
        s32 lock_level;
        s32 nest_count;
        ThreadType *owner_thread;
        union {
            s32 _arr[sizeof(impl::InternalCriticalSectionStorage) / sizeof(s32)];
            impl::InternalCriticalSectionStorage _storage;
        };
    };
    static_assert(std::is_trivial<MutexType>::value);

}
