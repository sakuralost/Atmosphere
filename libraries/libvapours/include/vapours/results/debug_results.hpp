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
#include <vapours/results/results_common.hpp>

namespace ams::dbg {

    R_DEFINE_NAMESPACE_RESULT_MODULE(183);

    R_DEFINE_ERROR_RESULT(CannotDebug,     1);
    R_DEFINE_ERROR_RESULT(AlreadyAttached, 2);
    R_DEFINE_ERROR_RESULT(Cancelled,       3);

}
