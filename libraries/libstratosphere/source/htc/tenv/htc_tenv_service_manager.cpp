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
#include <stratosphere.hpp>
#include "impl/htc_tenv_allocator.hpp"
#include "htc_tenv_service.hpp"

namespace ams::htc::tenv {

    Result ServiceManager::GetServiceInterface(sf::Out<sf::SharedPointer<htc::tenv::IService>> out, const sf::ClientProcessId &process_id) {
        *out = impl::SfObjectFactory::CreateSharedEmplaced<htc::tenv::IService, Service>(process_id.GetValue());
        return ResultSuccess();
    }

}
