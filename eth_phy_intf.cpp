// Copyright (c) 2013 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#include "eos/eth_phy_intf.h"

namespace eos {

eth_phy_intf_handler::eth_phy_intf_handler() {
}

eth_phy_intf_handler::~eth_phy_intf_handler() {
}

void
eth_phy_intf_handler::watch_all_eth_phy_intfs(bool all) {
   watching_all_intfs_ = all;
}

void
eth_phy_intf_handler::on_eth_phy_intf_create(intf_id_t) {
   // TODO: No op impl.
}

void
eth_phy_intf_handler::on_eth_phy_intf_delete(intf_id_t) {
   // TODO: No op impl.
}


eth_phy_intf_iter_t
eth_phy_intf_mgr::eth_phy_intf_iter() const {
   eth_phy_intf_iter_t * nop = 0;
   return *nop;  // TODO: No op impl.
}

void
eth_phy_intf_mgr::eth_phy_intf_foreach(bool (*handler)(intf_id_t, void *), void *) {
   // TODO: No op impl.
}

void
eth_phy_intf_mgr::eth_phy_intf_foreach(bool (*handler)(intf_id_t, void *), void *,
                                       intf_id_t bookmark) {
   // TODO: No op impl.
}

bool
eth_phy_intf_mgr::exists(intf_id_t) const {
   return false;
}

// Read the "burned in" address
eth_addr_t
eth_phy_intf_mgr::burned_in_eth_addr(intf_id_t) const {
   return eth_addr_t();
}

eth_link_speed_t
eth_phy_intf_mgr::link_speed(intf_id_t intf_id) const {
   return LINK_SPEED_UNKNOWN;  // TODO: No op impl.
}

eth_phy_intf_mgr::eth_phy_intf_mgr() {
}

class eth_phy_intf_mgr_impl : public eth_phy_intf_mgr {
 public:
   eth_phy_intf_mgr_impl() {
   }
};

eth_phy_intf_mgr * get_eth_phy_intf_mgr() {
   static eth_phy_intf_mgr_impl impl;
   return &impl;
}

}
